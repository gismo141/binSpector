#include <QStylePainter>
#include <QStyleOption>

#include "view/visualizer/controlFlowGraph.h"
#include "view/binspector.h"

view::visualizer::controlFlowGraph::controlFlowGraph(QMainWindow *parent)
{
    thisParent = parent;
}

view::visualizer::controlFlowGraph::~controlFlowGraph(void) {}

void view::visualizer::controlFlowGraph::paintEvent(QPaintEvent *)
{
    QString filename = QString(((binspector *)thisParent)->getActiveAnalysisPath() + "/graphs/cfg.png");

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