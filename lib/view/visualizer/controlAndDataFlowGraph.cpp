#include <QStylePainter>
#include <QStyleOption>

#include "view/visualizer/controlAndDataFlowGraph.h"
#include "view/binspector.h"

view::visualizer::controlAndDataFlowGraph::controlAndDataFlowGraph(QMainWindow *parent)
{
    thisParent = parent;
}

view::visualizer::controlAndDataFlowGraph::~controlAndDataFlowGraph(void) {}

void view::visualizer::controlAndDataFlowGraph::paintEvent(QPaintEvent *)
{
    QString filename = QString(((binspector *)thisParent)->getActiveAnalysisPath() + "/graphs/cfg_dfg.png");

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