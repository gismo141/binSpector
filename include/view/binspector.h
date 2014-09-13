#ifndef BINSPECTOR_H
#define BINSPECTOR_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include <QDockWidget>
#include <QMessageBox>
#include <QTextEdit>

#include "view/binary/basicInfo.h"
#include "view/visualizer/callGraph.h"
#include "view/visualizer/controlFlowGraph.h"
#include "view/visualizer/controlAndDataFlowGraph.h"
#include "view/visualizer/memoryDependence.h"

namespace view
{
class binspector : public QMainWindow
{
    Q_OBJECT
private:
    void                    setupFileDialogs(void);
    QMenu                   *setupFileMenu(void);
    QMenu                   *setupEditMenu(void);
    QMenu                   *setupViewMenu(void);
    QMenu                   *setupHelpMenu(void);

    void                    setupBinaryDock(void);
    void                    setupVisualizerDock(void);

    bool                    parseAnalysisFile(QString line);
    bool                    writeAnalysisFile(QString analysisFilePath);
protected:
    QMenuBar                *myMenu;
    QFileDialog             *myFileDialog;
    QFileDialog             *myProjectDialog;

    QFileInfo               *activeBinary;

    QString                 temporaryFolder;
    QString                 targetFolder;
    QString                 projectExtension;
    QString                 analysisExtension;

    QTabWidget              *tabbedCentralWidget;
    QWidget                 *helpWidget;
    QDockWidget             *binaryDock;
    QDockWidget             *visualizerDock;

    view::binary::basicInfo                     *basicInfoTab;
    view::visualizer::callGraph                 *callTab;
    view::visualizer::controlFlowGraph          *cfgTab;
    view::visualizer::controlAndDataFlowGraph   *cfgDfgTab;
    view::visualizer::memoryDependence          *memTab;
public:
    /**
     * @brief std. ctor
     */
    binspector(void);
    ~binspector(void);

    void addBinaryTab(QWidget *newTab, const char *tabName);
    void addVisualizerTab(QWidget *newTab, const char *tabName);
    void showCentralWidget(QWidget *newCentralWidget, QString tabName);

    QString getActiveAnalysisPath(void);
    QString getActiveBinaryPath(void);
    QString getActiveBinaryArchitecture(void);
public slots:
    /**
     * @brief This function shows a messagebox.
     * @details At the moment there is only an `about`-box implemented.
     */
    void messageBox(void)
    {
        QMessageBox::about(this, "binSpector", "binSpector is a fast, simple and extensable binary inspector GUI using the projects LLVM, dagger and fracture.\n\n\t(C) by Michael Riedel, 2014");
    }
    void openFile(const QString &name);
    void openProject(const QString &name);
    void showHelp(void);
    void saveProject(void);
};
} // view

#endif // BINSPECTOR_H