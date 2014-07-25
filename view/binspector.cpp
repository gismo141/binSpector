#include "binspector.h"

binspector::binspector() : QMainWindow(NULL) {
	setWindowTitle("New Analysation - binSpector");

	myMenu = new QMenuBar(this);
    myMenu->addMenu(setupFileMenu());
    myMenu->addMenu(setupEditMenu());
    myMenu->addMenu(setupViewMenu());
    myMenu->addMenu(setupHelpMenu());
    this->setMenuBar(myMenu);

    setupMainWidget();
    this->setCentralWidget(myMainWidget);
}

/*
 *
 * SETUP ALL MENUS
 *
 */

QMenu *binspector::setupFileMenu(void) {
    // Install Project Dialog
    myProjectDialog = new QFileDialog(this);
    myProjectDialog->setNameFilter("Project (*.db *.txt *binspector-project)");
    // Install File Dialog
    myFileDialog = new QFileDialog(this);
    myFileDialog->setNameFilter("Documents (*.app *.out *o)");
    
    QMenu *myFileMenu  = new QMenu("File", this);

    QAction *a_openProject = new QAction("Open Project", this);
    a_openProject->setShortcut(Qt::CTRL + Qt::Key_O);
    connect (a_openProject, SIGNAL(triggered()), myProjectDialog, SLOT(exec()));
    a_openProject->setEnabled(false);

    myFileMenu->addAction(a_openProject);
    myFileMenu->addAction("Import Binary", myFileDialog, SLOT(exec()), Qt::CTRL + Qt::Key_I);
    myFileMenu->addAction("Save Project", this, SLOT(saveProject()), Qt::CTRL + Qt::Key_S);
    myFileMenu->addSeparator();
    myFileMenu->addAction("Close", this, SLOT(close()), Qt::CTRL + Qt::Key_Q);

    /* Connect Signals */
    connect (myFileDialog, SIGNAL(fileSelected(const QString&)), this, SLOT(importFile(const QString&)));
    
    return myFileMenu;
}

QMenu *binspector::setupEditMenu(void) {
    QMenu *myEditMenu  = new QMenu("Edit", this);
    myEditMenu->addAction("Undo", this, SLOT(showFullScreen()), Qt::CTRL + Qt::Key_Z);
    myEditMenu->addAction("Repeat", this, SLOT(showNormal()), Qt::CTRL + Qt::Key_Y);
    return myEditMenu;
}

QMenu *binspector::setupViewMenu(void) {
    QMenu *myViewMenu  = new QMenu("View", this);
    myViewMenu->addAction("Fullscreen", this, SLOT(showFullScreen()), Qt::CTRL + Qt::Key_F);
    myViewMenu->addAction("Windowed", this, SLOT(showNormal()), Qt::CTRL + Qt::Key_N);
    return myViewMenu;
}

QMenu *binspector::setupHelpMenu(void) {
    QMenu *myHelpMenu  = new QMenu("Help", this);
    myHelpMenu->addAction("About...", this, SLOT(messageBox()), Qt::CTRL + Qt::Key_H);
    return myHelpMenu;
}

void binspector::setupMainWidget(void) {
    myMainWidget = new QTextEdit;
    myMainWidget->setText("Hallo Welt");
}

void binspector::importFile(const QString& name) {
    std::string import = "file " + name.toStdString();
    QString output = QString::fromStdString(exec(import.c_str()));
    myMainWidget->append(output);
}

std::string binspector::exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}