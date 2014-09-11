#include <QStylePainter>
#include <QStyleOption>

#include "view/visualizer/controlFlowGraph/controlFlowGraph.h"
#include "view/binspector.h"

view::visualizer::controlFlowGraph::controlFlowGraph(QMainWindow *parent)
{
    thisParent = parent;
}

view::visualizer::controlFlowGraph::~controlFlowGraph(void) {}

void view::visualizer::controlFlowGraph::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    QString filename = QString(((binspector *)thisParent)->getActiveAnalysis() + "/graphs/cfg.png");
    p.drawPixmap(0, 0, QPixmap(filename).scaled(size()));

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}