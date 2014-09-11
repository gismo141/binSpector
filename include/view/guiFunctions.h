#ifndef GUI_FUNCTIONS_H
#define GUI_FUNCTIONS_H

#include <QPlainTextEdit>
#include <QFontMetrics>
#include <QtCore/QDir.h>

namespace view
{
void setHeight(QPlainTextEdit *edit, int nRows);
std::string exec(const char *cmd);
bool copyRecursively(const QString &srcFilePath,
                     const QString &tgtFilePath);
} // view

#endif // GUI_FUNCTIONS_H
