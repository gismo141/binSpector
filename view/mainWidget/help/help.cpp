#include <QHBoxLayout>

#include "help.h"

view::mainWidget::help::help(QMainWindow *parent)
{
    thisParent = parent;

    // create document-area
    activeCodeLabel = new QLabel("Welcome to binSpector");
    activeCodeLabel->setAlignment(Qt::AlignCenter);
    myMainWidget = new QTextEdit();
    myMainWidget->setReadOnly(true);
    myMainWidget->setTextInteractionFlags(myMainWidget->textInteractionFlags() | Qt::TextSelectableByKeyboard);
    myMainWidget->setText("<h1>This will later be the README-page!</h1>");
    // layout for document-area
    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(activeCodeLabel);
    documentArea = new QVBoxLayout();
    documentArea->addLayout(labelLayout);
    documentArea->addWidget(myMainWidget);

    this->setLayout(documentArea);
}

void view::mainWidget::help::append(QString text)
{
}