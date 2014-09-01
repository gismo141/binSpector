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
#include "view/visualizer/callGraph/callGraph.h"
#include "view/visualizer/controlFlowGraph/controlFlowGraph.h"
#include "view/visualizer/controlAndDataFlowGraph/controlAndDataFlowGraph.h"
#include "view/visualizer/memoryAllocation/memoryAllocation.h"

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
protected:
    QMenuBar                *myMenu;
    QFileDialog             *myFileDialog;
    QFileDialog             *myProjectDialog;

    QString                 activeBinary;
    QString                 temporaryFolder = "/tmp/binSpector/";
    QString                 targetFolder;
    QString                 projectExtension = ".binsp";

    QWidget                 *mainWidget;
    QDockWidget             *binaryDock;
    QDockWidget             *visualizerDock;

    view::binary::basicInfo                     *basicInfoTab;
    view::visualizer::callGraph                 *callTab;
    view::visualizer::controlFlowGraph          *cfgTab;
    view::visualizer::controlAndDataFlowGraph   *cfgDfgTab;
    view::visualizer::memoryAllocation          *memTab;
public:
    /**
     * @brief std. ctor
     */
    binspector(void);
    void addBinaryTab(QWidget *newTab, const char *tabName);
    void addVisualizerTab(QWidget *newTab, const char *tabName);
    QString getActiveBinary(void);
public slots:
    /**
     * @brief This function shows a messagebox.
     * @details At the moment there is only an `about`-box implemented.
     */
    void messageBox(void)
    {
        QMessageBox::about(this, "binSpector", "binSpector is a fast, simple and extensable binary inspector GUI using the projects LLVM, dagger and fracture.\n\n\t(C) by Michael Riedel, 2014");
    }
    void setupMainWidget(void);
    void openFile(const QString &name);
    void showHelp(void);
    void saveProject(void);
};
}
#endif // BINSPECTOR_H