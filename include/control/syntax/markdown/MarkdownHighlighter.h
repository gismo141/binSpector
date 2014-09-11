#ifndef MARKDOWN_HIGHLIGHTER_H
#define MARKDOWN_HIGHLIGHTER_H

/*
 *
 * largely copied from: http://doc.qt.digia.com/qq/qq21-syntaxhighlighter.html
 *
 */

#include <QSyntaxHighlighter>

namespace control
{
namespace syntax
{
class MarkdownHighlighter: public QSyntaxHighlighter
{
    Q_OBJECT
public:
    MarkdownHighlighter(QTextDocument *parent = 0);
    ~MarkdownHighlighter(void);
protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};
} // syntax_highlighter
} // control

#endif // MARKDOWN_HIGHLIGHTER_H
