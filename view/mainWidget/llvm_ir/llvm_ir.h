#ifndef LLVM_IR_H
#define LLVM_IR_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QLabel>

#include "../../../control/syntax/clang/clangHighlighter.h"

namespace view
{
namespace mainWidget
{
class llvm_ir : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout 						*codeArea;
    QLabel      						*activeCodeLabel;
    QPlainTextEdit   					*editor;

    void setupEditor(void);
protected:
    QMainWindow *thisParent;
public:
    llvm_ir(QMainWindow *parent = 0);
    void append(QString text);
    void setText(QString text);
};
} // mainWidget
} // view

#endif // LLVM_IR_H
