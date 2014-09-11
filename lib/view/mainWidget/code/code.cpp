#include "view/mainWidget/code/code.h"
#include "control/codeEditor/codeEditor.h"

view::mainWidget::code::code(void)
{
    // create document-area
    activeCodeLabel = new QLabel("Disassembled LLVM-IR");
    activeCodeLabel->setAlignment(Qt::AlignCenter);

    // Setup controller
    setupEditor();

    // layout for document-area
    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(activeCodeLabel);
    codeArea = new QVBoxLayout();
    codeArea->addLayout(labelLayout);
    codeArea->addWidget(editor);

    this->setLayout(codeArea);
}

view::mainWidget::code::~code(void) {}

void view::mainWidget::code::setupEditor(void)
{
    editor = new control::codeEditor(this, "llvm");
    editor->setReadOnly(true);
    editor->setTextInteractionFlags(editor->textInteractionFlags() | Qt::TextSelectableByKeyboard);
}

void view::mainWidget::code::append(QString text)
{
    editor->appendPlainText(text);
}

void view::mainWidget::code::setText(QString text)
{
    editor->setPlainText(text);
}