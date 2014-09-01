#ifndef MEMORY_ALLOCATION_H
#define MEMORY_ALLOCATION_H

#include <QMainWindow>

namespace view
{
namespace visualizer
{
class memoryAllocation : public QWidget
{
    Q_OBJECT
private:
protected:
	QMainWindow             *thisParent;
public:
	memoryAllocation(QMainWindow *parent = 0);
	void paintEvent(QPaintEvent *);
};
} // visualizer
} // view

#endif // MEMORY_ALLOCATION_H