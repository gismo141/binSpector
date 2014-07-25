#include <QApplication>

#include "view/binspector.h"

int main(int argc, char** argv) {
	QApplication::setOrganizationName("MyCompany");
QApplication::setApplicationName("MyApp");
	QApplication app(argc, argv);

    binspector mainWindow;
    mainWindow.show();
    
    return app.exec();
}