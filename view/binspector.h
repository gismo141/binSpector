#pragma once

#ifndef BINSPECTOR_H
#define BINSPECTOR_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include <QDockWidget>
#include <QMessageBox>
#include <QTextEdit>

class binspector : public QMainWindow {
	Q_OBJECT
private:
	QMenu                   *setupFileMenu(void);
    QMenu                   *setupEditMenu(void);
    QMenu                   *setupViewMenu(void);
    QMenu                   *setupHelpMenu(void);
    std::string             exec(const char* cmd);
protected:
	QMenuBar                *myMenu;
	QFileDialog             *myFileDialog;
    QFileDialog             *myProjectDialog;
    QTextEdit               *myMainWidget;
    QDockWidget             *binaryBrowser;
    QDockWidget             *codeBrowser;
public:
	/**
	 * @brief std. ctor
	 */
	binspector(void);
public slots:
	/**
     * @brief This function shows a messagebox.
     * @details At the moment there is only a `about`-box implemented.
     */
    void messageBox(void) {
        QMessageBox::about(this, "binSpector", "binSpector is a fast and simple alternative to IDA PRO.\n\n\t(C) by Michael Riedel, 2014");
    }
    void setupMainWidget(void);
    void importFile(const QString& name);
};

#endif // BINSPECTOR_H