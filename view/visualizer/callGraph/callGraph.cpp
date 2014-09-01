#include <QStylePainter>
#include <QStyleOption>

#include "callGraph.h"
#include "../../binspector.h"

view::visualizer::callGraph::callGraph(QMainWindow *parent) {
	thisParent = parent;
}

void view::visualizer::callGraph::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    QString filename = QString(((binspector *)thisParent)->getActiveBinary()+"/graphs/callGraph.png");
    p.drawPixmap(0, 0, QPixmap(filename).scaled(size()));

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}