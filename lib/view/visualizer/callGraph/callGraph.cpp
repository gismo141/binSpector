#include <QStylePainter>
#include <QStyleOption>

#include "view/visualizer/callGraph/callGraph.h"
#include "view/binspector.h"

view::visualizer::callGraph::callGraph(QMainWindow *parent)
{
    thisParent = parent;
}

view::visualizer::callGraph::~callGraph(void) {}

void view::visualizer::callGraph::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    QString filename = QString(((binspector *)thisParent)->getActiveAnalysis() + "/graphs/callGraph.png");
    p.drawPixmap(0, 0, QPixmap(filename).scaled(size()));

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}