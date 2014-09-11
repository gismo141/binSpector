#ifndef CODE_EDITOR_H
#define CODE_EDITOR_H

/*
 *
 * Code borrowed from: http://qt-project.org/doc/qt-4.8/widgets-codeeditor.html
 *
 */

#include <QWidget>
#include <QPlainTextEdit>
#include <QSyntaxHighlighter>

// HIER MUSS EIN INTERFACE HER UM DIE SYNTAXE ZU WECHSELN !!!

namespace control
{
class codeEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    codeEditor(QWidget *parent = 0, QString syntax = "clang");
    ~codeEditor(void);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
protected:
    void resizeEvent(QResizeEvent *event);
private:
    QWidget                             *lineNumberArea;
    // TODO: Interface fuer korrekte Syntaxfärbung!
    QSyntaxHighlighter                  *highlighter;
    QPair<int, int>                     *m_countCache;
private slots:
    /**
     * @brief Highlights the current line where the cursor resides in.
     * @details This gives just a little easier hint about the current selected line.
     * This feature is only available when the editor is not read-only!
     */
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
    void updateLineNumberAreaWidth(int newBlockCount);
};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(codeEditor *editor, bool enableNumbering) : QWidget(editor)
    {
        codeEditor = editor;
        m_enableNumbering = enableNumbering;
    }

    QSize sizeHint() const
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }
    bool        m_enableNumbering;
protected:
    void paintEvent(QPaintEvent *event)
    {
        if(m_enableNumbering)
            codeEditor->lineNumberAreaPaintEvent(event);
    }
private:
    codeEditor *codeEditor;
};
} // control

#endif // CODE_EDITOR_H
