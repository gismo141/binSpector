#include <QFile>

#include "llvm_ir.h"
#include "../../../control/syntax/llvm_ir/llvmHighlighter.h"
#include "../../../control/codeEditor/codeEditor.h"

view::mainWidget::llvm_ir::llvm_ir(QMainWindow *parent)
{
    thisParent = parent;

    // create document-area
    activeCodeLabel = new QLabel("Disassembled LLVM-IR");
    activeCodeLabel->setAlignment(Qt::AlignCenter);
    setupEditor();
    
    // layout for document-area
    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(activeCodeLabel);
    codeArea = new QVBoxLayout();
    codeArea->addLayout(labelLayout);
    codeArea->addWidget(editor);

    this->setLayout(codeArea);
}

void view::mainWidget::llvm_ir::setupEditor(void)
{
    editor = new control::codeEditor(this);
    editor->setReadOnly(true);
    editor->setTextInteractionFlags(editor->textInteractionFlags() | Qt::TextSelectableByKeyboard);

    QFile file("/Users/michaelriedel/Developer/main.ll");
    if (file.open(QFile::ReadOnly | QFile::Text))
        editor->setPlainText(file.readAll());
    else
        editor->setPlainText("File not found!");
}

void view::mainWidget::llvm_ir::append(QString text)
{
    editor->appendPlainText(text);
}