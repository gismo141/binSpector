#include "view/mainWidget/codeViewer.h"
#include "control/codeEditor.h"
#include "view/guiFunctions.h"

view::mainWidget::codeViewer::codeViewer(bool enableEditor, bool wrapLines, QString language)
{
    m_enableEditor = enableEditor;
    m_wrapLines = wrapLines;
    m_language = language;

    // layout for document-area
    codeArea = new QVBoxLayout();
    if (m_wrapLines)
        codeArea->setAlignment(Qt::AlignCenter);

    // Setup controller
    setupEditor();

    this->setLayout(codeArea);
}

view::mainWidget::codeViewer::~codeViewer(void) {}

void view::mainWidget::codeViewer::setupEditor(void)
{
    if (m_enableEditor)
    {
        editor = new control::codeEditor(this, m_language);
        editor->setReadOnly(false);
        editor->setTextInteractionFlags(editor->textInteractionFlags() | Qt::TextSelectableByKeyboard);
        codeArea->addWidget(editor);
    }
    else
    {
        viewer = new QTextEdit(this);
        viewer->setReadOnly(true);
        viewer->setTextInteractionFlags(viewer->textInteractionFlags() | Qt::TextSelectableByKeyboard);
        if (m_wrapLines)
            viewer->setFixedWidth(1000);
        codeArea->addWidget(viewer);
    }
}

void view::mainWidget::codeViewer::append(QString text)
{
    if (m_enableEditor)
        editor->appendPlainText(text);
    else
        viewer->setText(text);
}

void view::mainWidget::codeViewer::setText(QString text)
{
    if (m_enableEditor)
        editor->setPlainText(text);
    else
        viewer->setHtml(text);
}

void view::mainWidget::codeViewer::highlightFile(QString inputFilePath, QString outPutFilePath)
{
    if (m_enableEditor)
        showFile(outPutFilePath);
    else
    {
        QString highlight;

        if (m_wrapLines)
        {
            QString foldedInputFilePath = inputFilePath + ".folded";
            QString fold = "fold -w 110 " + inputFilePath + " > " + foldedInputFilePath;
            view::exec(fold);

            highlight = "/usr/local/bin/pygmentize -f html -l " + m_language + " -O full,style=emacs,linenos=1 -o " + outPutFilePath + " " + foldedInputFilePath;
        }
        else
            highlight = "/usr/local/bin/pygmentize -f html -l " + m_language + " -O full,style=emacs,linenos=1 -o " + outPutFilePath + " " + inputFilePath;
        view::exec(highlight);

        showFile(outPutFilePath);
    }
}

void view::mainWidget::codeViewer::showFile(QString filePath)
{
    QFile file(filePath);
    if (file.open(QFile::ReadOnly | QFile::Text))
        setText(file.readAll());
    else
        setText("Error! File " + filePath + " not found!");
}







