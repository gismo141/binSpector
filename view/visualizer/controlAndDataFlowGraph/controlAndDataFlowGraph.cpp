#include <QStylePainter>
#include <QStyleOption>

#include "controlAndDataFlowGraph.h"
#include "../../binspector.h"

view::visualizer::controlAndDataFlowGraph::controlAndDataFlowGraph(QMainWindow *parent)
{
    thisParent = parent;
}

void view::visualizer::controlAndDataFlowGraph::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    QString filename = QString(((binspector *)thisParent)->getActiveBinary()+"/graphs/cfg_dfg.png");
    p.drawPixmap(0, 0, QPixmap(filename).scaled(size()));

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}