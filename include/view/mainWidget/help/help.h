#ifndef HELP_H
#define HELP_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QLabel>

namespace view
{
namespace mainWidget
{
class help : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout 						*documentArea;
    QLabel      						*activeCodeLabel;
    QPlainTextEdit   					*editor;

    void setupEditor(void);
protected:
public:
    help(void);
    ~help(void);
    void append(QString text);
    void setText(QString text);
};
} // mainWidget
} // view

#endif // HELP_H