#include <QtCore/QDir.h>
#include <QTextStream>

#include "view/binspector.h"
#include "view/mainWidget/help.h"
#include "view/guiFunctions.h"

view::binspector::binspector(void)
{
    setWindowTitle("New Analysis - binSpector");
    activeBinary = new QFileInfo();

    myMenu = new QMenuBar(this);
    setupFileDialogs();
    myMenu->addMenu(setupFileMenu());
    myMenu->addMenu(setupEditMenu());
    myMenu->addMenu(setupViewMenu());
    myMenu->addMenu(setupHelpMenu());
    this->setMenuBar(myMenu);

    temporaryFolder = "/tmp/binSpector/";
    projectExtension = ".binsp";
    analysisExtension = ".analysis";

    if (!QDir(temporaryFolder).exists())
        QDir().mkdir(temporaryFolder);

    setupBinaryDock();
    setupVisualizerDock();

    tabbedCentralWidget = new QTabWidget(this);
    helpWidget = new view::mainWidget::help();
    showCentralWidget(helpWidget, "Manual");

    this->setCentralWidget(tabbedCentralWidget);

    myFileDialog->open();
}

view::binspector::~binspector(void)
{

}

void view::binspector::setupFileDialogs(void)
{
    myFileDialog = new QFileDialog(this);
    myFileDialog->setNameFilter("Applications (*.app *)");

    connect (myFileDialog, SIGNAL(fileSelected(const QString &)), this, SLOT(openFile(const QString &)));
}

/*
 *
 * SETUP ALL MENUS
 *
 */

QMenu *view::binspector::setupFileMenu(void)
{
    QMenu *myFileMenu  = new QMenu("File", this);

    myFileMenu->addAction("New Binary-Analysis", myFileDialog, SLOT(exec()), Qt::CTRL + Qt::Key_N);
    myFileMenu->addAction("Open Project", myFileDialog, SLOT(exec()), Qt::CTRL + Qt::Key_O);
    myFileMenu->addAction("Save Project", this, SLOT(saveProject()), Qt::CTRL + Qt::Key_S);
    myFileMenu->addSeparator();
    myFileMenu->addAction("Close", this, SLOT(close()), Qt::CTRL + Qt::Key_Q);

    return myFileMenu;
}

QMenu *view::binspector::setupEditMenu(void)
{
    QMenu *myEditMenu  = new QMenu("Edit", this);
    myEditMenu->addAction("Undo", this, SLOT(showFullScreen()), Qt::CTRL + Qt::Key_Z);
    myEditMenu->addAction("Repeat", this, SLOT(showNormal()), Qt::CTRL + Qt::Key_Y);
    return myEditMenu;
}

QMenu *view::binspector::setupViewMenu(void)
{
    QMenu *myViewMenu  = new QMenu("View", this);
    myViewMenu->addAction("Fullscreen", this, SLOT(showFullScreen()), Qt::CTRL + Qt::Key_F);
    myViewMenu->addAction("Windowed", this, SLOT(showNormal()), Qt::CTRL + Qt::Key_Escape);
    return myViewMenu;
}

QMenu *view::binspector::setupHelpMenu(void)
{
    QMenu *myHelpMenu  = new QMenu("Help", this);
    myHelpMenu->addAction("About...", this, SLOT(messageBox()), Qt::CTRL + Qt::Key_A);
    myHelpMenu->addAction("Manual", this, SLOT(showHelp()), Qt::CTRL + Qt::Key_H);
    return myHelpMenu;
}

/*
 *
 * SETUP THE PROGRAM-VIEW
 *
 */

/**
 * @brief This creates the left tabbed-dock containing binary-information
 * @details In this process also the code-mainWidget is beeing created
 * @return nth.
 */
void view::binspector::setupBinaryDock(void)
{
    binaryDock = new QDockWidget(tr("Information"), this);
    binaryDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    binaryDock->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    addDockWidget(Qt::LeftDockWidgetArea, binaryDock);

    basicInfoTab = new view::binary::basicInfo(this);
    binaryDock->setWidget(basicInfoTab);
}

void view::binspector::setupVisualizerDock(void)
{
    visualizerDock = new QDockWidget(tr("Call Graph"), this);
    visualizerDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    binaryDock->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    addDockWidget(Qt::RightDockWidgetArea, visualizerDock);

    callTab = new view::visualizer::callGraph(this);
    visualizerDock->setWidget(callTab);

    cfgTab = new view::visualizer::controlFlowGraph(this);
    addVisualizerTab(cfgTab, "CFG");

    cfgDfgTab = new view::visualizer::controlAndDataFlowGraph(this);
    addVisualizerTab(cfgDfgTab, "CFG+DFG");

    memTab = new view::visualizer::memoryDependence(this);
    addVisualizerTab(memTab, "Memory Dependence");
}

void view::binspector::showCentralWidget(QWidget *newWidget, QString tabName)
{
    tabbedCentralWidget->addTab(newWidget, tabName);
    tabbedCentralWidget->setCurrentWidget(newWidget);
}

/*
 *
 * GUI MANIPULATION
 *
 */

void view::binspector::addBinaryTab(QWidget *newTab, const char *tabName)
{
    QDockWidget *newDockWidget = new QDockWidget(tr(tabName), this);
    newDockWidget->setWidget(newTab);
    this->tabifyDockWidget(binaryDock, newDockWidget);
}

void view::binspector::addVisualizerTab(QWidget *newTab, const char *tabName)
{
    QDockWidget *newDockWidget = new QDockWidget(tr(tabName), this);
    newDockWidget->setWidget(newTab);
    this->tabifyDockWidget(visualizerDock, newDockWidget);
}

/*
 *
 * PROJECT INTERACTION
 *
 */

void view::binspector::openFile(const QString &name)
{
    if (QString(name).contains(projectExtension))
        return openProject(name);
    activeBinary = new QFileInfo(name);
    QString binaryInfo = view::exec("file " + name);

    if (activeBinary->isBundle())
    {
        activeBinary = new QFileInfo(name + "/Contents/MacOS/" + activeBinary->baseName());
        binaryInfo = view::exec("file " + name + "/Contents/MacOS/" + activeBinary->baseName());
    }

    // Create temporary project-folder-structure if it doesn't exist
    if (!QDir("/tmp/binSpector/" + activeBinary->fileName()).exists())
    {
        QDir().mkdir("/tmp/binSpector/" + activeBinary->fileName());
        QDir().mkdir("/tmp/binSpector/" + activeBinary->fileName() + "/graphs");
        QDir().mkdir("/tmp/binSpector/" + activeBinary->fileName() + "/texts");
    }

    setWindowTitle("Analysing " + activeBinary->fileName() + " - binSpector");

    basicInfoTab->setFilename(activeBinary->fileName());
    //basicInfoTab->setbinaryInfo(binaryInfo.remove(activeBinary->fileName() + ": "));

    if (binaryInfo.contains("ARM"))
        basicInfoTab->setArchitecture("ARM");
    if (binaryInfo.contains("i386"))
        basicInfoTab->setArchitecture("i386");
    if (binaryInfo.contains("x86_64"))
        basicInfoTab->setArchitecture("x86_64");
    if (binaryInfo.contains("ppc"))
        basicInfoTab->setArchitecture("ppc");
    if (binaryInfo.contains("library"))
        basicInfoTab->setArchitecture("library");
}

void view::binspector::openProject(const QString &name)
{
    QString analysisFilePath = name + "/.analysis";

    QFile analysisFile(analysisFilePath);
    if (analysisFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&analysisFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            parseAnalysisFile(line);
        }
        analysisFile.close();
    }
    else
        QMessageBox::critical(this, "Error", "Error!\nProject could not be opened!\n'.analysis'-file is missing.");
}

bool view::binspector::parseAnalysisFile(QString line)
{
    bool result = true;
    if (line.contains("activeBinaryPath="))
    {
        line.remove("activeBinaryPath=");
        openFile(line);
    }
    if (line.contains("temporaryFolder="))
    {
        line.remove("temporaryFolder=");
        temporaryFolder = line;
    }
    else
        result = false;
    return result;
}

void view::binspector::saveProject()
{
    // Save Project Dialog
    targetFolder = QFileDialog::getSaveFileName(this, "Save file", "", projectExtension)  + projectExtension;
    if (!view::copyRecursively(getActiveAnalysisPath(), targetFolder))
    {
        QMessageBox::critical(this, "Error", "Error!\nProject could not be saved!");
        return;
    }
    temporaryFolder = targetFolder + projectExtension;

    QString analysisFilePath = targetFolder + "/" + analysisExtension;
    writeAnalysisFile(analysisFilePath);
}

bool view::binspector::writeAnalysisFile(QString analysisFilePath)
{
    QFile analysisFile( analysisFilePath );
    if ( analysisFile.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &analysisFile );
        stream << "activeBinaryPath=" << getActiveBinaryPath() << endl;
        stream << "temporaryFolder=" << targetFolder << endl;

        analysisFile.close();
        return true;
    }
    return false;
}

void view::binspector::showHelp(void)
{
    tabbedCentralWidget->setCurrentWidget(helpWidget);
}

QString view::binspector::getActiveBinaryPath(void)
{
    return activeBinary->absolutePath() + "/" + activeBinary->fileName();
}

QString view::binspector::getActiveAnalysisPath(void)
{
    if (activeBinary == NULL)
        return "";
    if (temporaryFolder == "/tmp/binSpector/")
        return temporaryFolder + activeBinary->fileName();
    return temporaryFolder;
}

QString view::binspector::getActiveBinaryArchitecture(void)
{
    return basicInfoTab->getArchitecture();
}