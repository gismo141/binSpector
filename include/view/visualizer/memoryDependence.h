#ifndef MEMORY_ALLOCATION_H
#define MEMORY_ALLOCATION_H

#include <QMainWindow>

namespace view
{
namespace visualizer
{
class memoryDependence : public QWidget
{
    Q_OBJECT
private:
protected:
	QMainWindow             *thisParent;
public:
	memoryDependence(QMainWindow *parent = 0);
	~memoryDependence(void);
	void paintEvent(QPaintEvent *);
};
} // visualizer
} // view

#endif // MEMORY_ALLOCATION_H
