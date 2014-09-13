#ifndef CODE_VIEWER_H
#define CODE_VIEWER_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QLabel>

namespace view
{
namespace mainWidget
{
class codeViewer : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout 						*codeArea;
    QPlainTextEdit   					*editor;
    QTextEdit 							*viewer;

    bool								m_enableEditor;
    bool                                m_wrapLines;
    QString								m_language;

    void setupEditor(void);
protected:
public:
    codeViewer(bool enableEditor, bool wrapLines, QString language);
    ~codeViewer(void);
    void append(QString text);
    void setText(QString text);
    void highlightFile(QString inputFilePath, QString outPutFilePath);
    void showFile(QString filePath);
};
} // mainWidget
} // view

#endif // CODE_VIEWER_H
