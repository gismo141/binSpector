#include <QApplication>
#include <QTextStream>

#include "binspector.h"

int main(int argc, char **argv)
{
    QApplication::setOrganizationName("UniBw - Muenchen");
    QApplication::setApplicationName("binspector");
    QApplication app(argc, argv);

    // STYLESHEET IS BUGGY!!!
    /*QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        app.setStyleSheet(ts.readAll());
    }*/

    view::binspector mainWindow;
    mainWindow.show();
    return app.exec();
}