#include <QStylePainter>
#include <QStyleOption>

#include "memoryAllocation.h"
#include "../../binspector.h"

view::visualizer::memoryAllocation::memoryAllocation(QMainWindow *parent)
{
	thisParent = parent;
}

void view::visualizer::memoryAllocation::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    QString filename = QString(((binspector *)thisParent)->getActiveBinary()+"/graphs/memoryAllocation.png");
    p.drawPixmap(0, 0, QPixmap(filename).scaled(size()));

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}