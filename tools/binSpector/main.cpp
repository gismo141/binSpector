#include <iostream>

#include <QApplication>
#include "view/binspector.h"

int main(int argc, char **argv)
{
    QApplication::setOrganizationName("UniBw - Muenchen");
    QApplication::setApplicationName("binspector");
    QApplication app(argc, argv);

    view::binspector mainWindow;
    mainWindow.show();
    return app.exec();
}