#ifndef CONTROL_FLOW_GRAPH_H
#define CONTROL_FLOW_GRAPH_H

#include <QMainWindow>

namespace view
{
namespace visualizer
{
class controlFlowGraph : public QWidget
{
    Q_OBJECT
private:
protected:
    QMainWindow             *thisParent;
public:
    controlFlowGraph(QMainWindow *parent = 0);
    ~controlFlowGraph(void);
    void paintEvent(QPaintEvent *);
};
} // visualizer
} // view

#endif // CONTROL_FLOW_GRAPH_H