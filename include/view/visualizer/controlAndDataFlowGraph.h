#ifndef CONTROL_AND_DATA_FLOW_GRAPH_H
#define CONTROL_AND_DATA_FLOW_GRAPH_H

#include <QMainWindow>
#include <QPaintEvent>

namespace view
{
namespace visualizer
{
class controlAndDataFlowGraph : public QWidget
{
    Q_OBJECT
private:
protected:
    QMainWindow             *thisParent;
public:
    controlAndDataFlowGraph(QMainWindow *parent = 0);
    ~controlAndDataFlowGraph(void);
    void paintEvent(QPaintEvent *);
};
} // visualizer
} // view

#endif // CONTROL_AND_DATA_FLOW_GRAPH_H