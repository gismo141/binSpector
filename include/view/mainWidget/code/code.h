#ifndef CODE_H
#define CODE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QLabel>

namespace view
{
namespace mainWidget
{
class code : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout 						*codeArea;
    QLabel      						*activeCodeLabel;
    QPlainTextEdit   					*editor;

    void setupEditor(void);
protected:
public:
    code(void);
    ~code(void);
    void append(QString text);
    void setText(QString text);
};
} // mainWidget
} // view

#endif // CODE_H
