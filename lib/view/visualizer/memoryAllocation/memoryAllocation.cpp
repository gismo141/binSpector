#include <QStylePainter>
#include <QStyleOption>

#include "view/visualizer/memoryAllocation/memoryAllocation.h"
#include "view/binspector.h"

view::visualizer::memoryAllocation::memoryAllocation(QMainWindow *parent)
{
    thisParent = parent;
}

view::visualizer::memoryAllocation::~memoryAllocation(void) {}

void view::visualizer::memoryAllocation::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    QString filename = QString(((binspector *)thisParent)->getActiveAnalysis() + "/graphs/memoryAllocation.png");
    p.drawPixmap(0, 0, QPixmap(filename).scaled(size()));

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
