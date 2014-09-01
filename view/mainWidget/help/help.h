#ifndef HELP_H
#define HELP_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>

namespace view
{
namespace mainWidget
{
class help : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *documentArea;
    QLabel      *activeCodeLabel;
    QTextEdit   *myMainWidget;
protected:
    QMainWindow *thisParent;
public:
    help(QMainWindow *parent = 0);
    void append(QString text);
};
} // mainWidget
} // view

#endif // HELP_H