#include <QHBoxLayout>
#include <QDir>
#include <QFile>

#include "view/mainWidget/help/help.h"
#include "control/codeEditor/codeEditor.h"

view::mainWidget::help::help(void)
{
    // create document-area
    activeCodeLabel = new QLabel("Welcome to binSpector");
    activeCodeLabel->setAlignment(Qt::AlignCenter);

    // Setup controller
    setupEditor();

    // layout for document-area
    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(activeCodeLabel);
    documentArea = new QVBoxLayout();
    documentArea->addLayout(labelLayout);
    documentArea->addWidget(editor);

    this->setLayout(documentArea);

    QFile file(QDir::homePath() + "/Developer/binSpector/README.md");
    if (file.open(QFile::ReadOnly | QFile::Text))
        setText(file.readAll());
    else
        setText("File " + QDir::homePath() + "/Developer/binSpector/README.md" + " not found!");
}

view::mainWidget::help::~help(void) {}

void view::mainWidget::help::setupEditor(void)
{
    editor = new control::codeEditor(this, "markdown");
    editor->setReadOnly(true);
    editor->setTextInteractionFlags(editor->textInteractionFlags() | Qt::TextSelectableByKeyboard);
}

void view::mainWidget::help::append(QString text)
{
}

void view::mainWidget::help::setText(QString text)
{
    editor->setPlainText(text);
}