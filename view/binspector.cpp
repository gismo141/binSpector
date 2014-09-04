#include <QtCore/QDir.h>

#include "binspector.h"

#include "view/mainWidget/help/help.h"
#include "view/mainWidget/llvm_ir/llvm_ir.h"

#include "view/guiFunctions.cpp"

view::binspector::binspector() : QMainWindow(NULL)
{
    setWindowTitle("New Analysation - binSpector");

    myMenu = new QMenuBar(this);
    setupFileDialogs();
    myMenu->addMenu(setupFileMenu());
    myMenu->addMenu(setupEditMenu());
    myMenu->addMenu(setupViewMenu());
    myMenu->addMenu(setupHelpMenu());
    this->setMenuBar(myMenu);

    if (!QDir("/tmp/binSpector/").exists())
        QDir().mkdir("/tmp/binSpector/");

    setupBinaryDock();
    setupVisualizerDock();
    setupMainWidget();
}

void view::binspector::setupFileDialogs(void)
{
    myProjectDialog = new QFileDialog(this);
    myProjectDialog->setNameFilter("Project (*" + projectExtension + ")");

    myFileDialog = new QFileDialog(this);
    myFileDialog->setNameFilter("Applications (*.app *)");

    connect (myProjectDialog, SIGNAL(fileSelected(const QString &)), this, SLOT(openProject(const QString &)));
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

    QAction *a_openProject = new QAction("Open Project", this);
    a_openProject->setShortcut(Qt::CTRL + Qt::Key_P);
    connect (a_openProject, SIGNAL(triggered()), myProjectDialog, SLOT(exec()));
    a_openProject->setEnabled(true);

    myFileMenu->addAction(a_openProject);
    myFileMenu->addAction("Open Binary", myFileDialog, SLOT(exec()), Qt::CTRL + Qt::Key_O);
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
    myViewMenu->addAction("Windowed", this, SLOT(showNormal()), Qt::CTRL + Qt::Key_N);
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
    addDockWidget(Qt::RightDockWidgetArea, visualizerDock);

    callTab = new view::visualizer::callGraph(this);
    visualizerDock->setWidget(callTab);

    cfgTab = new view::visualizer::controlFlowGraph(this);
    addVisualizerTab(cfgTab, "CFG");

    cfgDfgTab = new view::visualizer::controlAndDataFlowGraph(this);
    addVisualizerTab(cfgDfgTab, "CFG+DFG");

    memTab = new view::visualizer::memoryAllocation(this);
    addVisualizerTab(memTab, "Memory Allocation");
}

void view::binspector::setupMainWidget(void)
{
    mainWidget = new view::mainWidget::llvm_ir(this);
    this->setCentralWidget(mainWidget);
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
    activeBinary = QString();
    // Create temporary project-folder-structure
    QFileInfo file(name);
    if (!file.isExecutable())
        return;
    activeBinary = file.baseName();
    if (!QDir("/tmp/binSpector/" + activeBinary).exists())
        QDir().mkdir("/tmp/binSpector/" + activeBinary);

    basicInfoTab->setFilename(activeBinary + "." + file.suffix());
}

void view::binspector::saveProject()
{
    // Save Project Dialog
    targetFolder = QFileDialog::getSaveFileName(this, "Save file", "", projectExtension);
    if (!view::copyRecursively(temporaryFolder + activeBinary, targetFolder + projectExtension))
        QMessageBox::critical(this, "Error", "Error!\nProject could not be saved!");
}

void view::binspector::showHelp(void)
{
    mainWidget = new view::mainWidget::help(this);
    this->setCentralWidget(mainWidget);
}

QString view::binspector::getActiveBinary(void)
{
    if(targetFolder.isNull())
        return temporaryFolder + activeBinary;
    return targetFolder;
}