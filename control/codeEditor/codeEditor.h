#ifndef CODE_EDITOR_H
#define CODE_EDITOR_H

/*
 *
 * Code borrowed from: http://qt-project.org/doc/qt-4.8/widgets-codeeditor.html
 *
 */

#include <QWidget>
#include <QPlainTextEdit>

// HIER MUSS EIN INTERFACE HER UM DIE SYNTAXE ZU WECHSELN !!!
#include "../syntax/clang/clangHighlighter.h"

namespace control
{
class codeEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    codeEditor(QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
protected:
    void resizeEvent(QResizeEvent *event);
private:
    QWidget                             *lineNumberArea;
    control::syntax::clangHighlighter   *highlighter;
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
    LineNumberArea(codeEditor *editor) : QWidget(editor)
    {
        codeEditor = editor;
    }

    QSize sizeHint() const
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }
protected:
    void paintEvent(QPaintEvent *event)
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }
private:
    codeEditor *codeEditor;
};
} // control

#endif // CODE_EDITOR_H
