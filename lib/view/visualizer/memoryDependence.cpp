#include <QStylePainter>
#include <QStyleOption>

#include "view/visualizer/memoryDependence.h"
#include "view/binspector.h"

view::visualizer::memoryDependence::memoryDependence(QMainWindow *parent)
{
    thisParent = parent;
}

view::visualizer::memoryDependence::~memoryDependence(void) {}

void view::visualizer::memoryDependence::paintEvent(QPaintEvent *)
{
    QString filename = QString(((binspector *)thisParent)->getActiveAnalysisPath() + "/graphs/memoryDependence.png");

    QFile file(filename);
    if (file.exists())
    {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);

        QPixmap graph(filename);
        p.drawPixmap(0, 0, graph.scaled(size()));

        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
}
