#include <QHBoxLayout>
#include <QDir>
#include <QFile>

#include "view/mainWidget/help.h"
#include "control/codeEditor.h"
#include "view/guiFunctions.h"

view::mainWidget::help::help(void)
{
    // Setup controller
    setupEditor();

    // layout for document-area
    documentArea = new QVBoxLayout();
    documentArea->addWidget(editor);

    this->setLayout(documentArea);

    QString startPage = QDir::currentPath() + "/" + "binSpector.app/Contents/Resources/README.md";
    QFile startPageFile(startPage);

    if (startPageFile.open(QFile::ReadOnly | QFile::Text))
    {
        startPageFile.close();
        QString cmd = "/usr/local/bin/pandoc " + startPage;
        setHelpPage(view::exec(cmd));
    }
    else
        setText("<h1>Error!</h1><br>File " + startPage + " not found!");
}

view::mainWidget::help::~help(void) {}

void view::mainWidget::help::setupEditor(void)
{
    //editor = new control::codeEditor(this, "markdown");
    editor = new QTextEdit(this);
    editor->setReadOnly(true);
    editor->setTextInteractionFlags(editor->textInteractionFlags() | Qt::TextSelectableByKeyboard);
}

void view::mainWidget::help::append(QString text)
{
}

void view::mainWidget::help::setText(QString text)
{
    editor->setHtml(text);
}

void view::mainWidget::help::setHelpPage(QString result)
{
    // NOT WORKING!
    // QString html = "<html><head><link rel='stylesheet' type='text/css' href='format.css'></head><body>" + result + "</body></html>";
    QString html = "<html><head></head><body>" + result + "</body></html>";
    
    html.replace("\"", "'");
    html.replace("<p class='caption'>faked disassembly</p>", "");

    QTextDocument *doc = new QTextDocument;

    // NOT WORKING!
    // /*
    // * This shows how to bind the images, where the name for QUrl is the same name
    // * which you use in your HTML and CSS. In QPixmap just use the normal syntax of
    // * the Qt resource system.
    // */
    // QPixmap image = QPixmap( ":fakeDisassembly");
    // doc->addResource( QTextDocument::ImageResource, QUrl( "https://raw.github.com/gismo141/binSpector/master/docs/images/fakeDisassembly.png" ), image.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    // QString css;
    // css  =  "";
    // /* And now bind the css, which you have defined in the QString css. */
    // doc->addResource( QTextDocument::StyleSheetResource, QUrl( "format.css" ), css );

    doc->setHtml( html );
    editor->setDocument( doc );
    editor->setText(html);
}