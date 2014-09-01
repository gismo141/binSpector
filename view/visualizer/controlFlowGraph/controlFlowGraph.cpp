#include <QStylePainter>
#include <QStyleOption>

#include "controlFlowGraph.h"
#include "../../binspector.h"

view::visualizer::controlFlowGraph::controlFlowGraph(QMainWindow *parent) {
	thisParent = parent;
}

void view::visualizer::controlFlowGraph::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    QString filename = QString(((binspector *)thisParent)->getActiveBinary()+"/graphs/cfg.png");
    p.drawPixmap(0, 0, QPixmap(filename).scaled(size()));

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}