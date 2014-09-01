#ifndef CALL_GRAPH_H
#define CALL_GRAPH_H

#include <QMainWindow>

namespace view
{
namespace visualizer
{
class callGraph : public QWidget
{
    Q_OBJECT
private:
protected:
    QMainWindow             *thisParent;
public:
    callGraph(QMainWindow *parent = 0);
    void paintEvent(QPaintEvent *);
};
} // visualizer
} // view

#endif // CALL_GRAPH_H