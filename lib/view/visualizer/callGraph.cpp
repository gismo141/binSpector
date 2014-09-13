#include <QStylePainter>
#include <QStyleOption>


#include "view/visualizer/callGraph.h"
#include "view/binspector.h"

view::visualizer::callGraph::callGraph(QMainWindow *parent)
{
    thisParent = parent;
}

view::visualizer::callGraph::~callGraph(void) {}

void view::visualizer::callGraph::paintEvent(QPaintEvent *)
{
    QString filename = QString(((binspector *)thisParent)->getActiveAnalysisPath() + "/graphs/callGraph.png");

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