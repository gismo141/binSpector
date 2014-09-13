#ifndef GUI_FUNCTIONS_H
#define GUI_FUNCTIONS_H

#include <QPlainTextEdit>
#include <QFontMetrics>
#include <QString>
#include <QtCore/QDir.h>

namespace view
{
void setHeight(QPlainTextEdit *edit, int nRows);
QString exec(QString cmd);
bool copyRecursively(const QString &srcFilePath,
                     const QString &tgtFilePath);
} // view

#endif // GUI_FUNCTIONS_H
