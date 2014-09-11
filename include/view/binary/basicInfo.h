#ifndef BASIC_INFO_H
#define BASIC_INFO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QPushButton>

#include "view/mainWidget/code/code.h"
#include "control/disassembler/Disassembler.h"

namespace view
{
namespace binary
{
class basicInfo : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout             *basicInfoLayout;

    QLabel                  *filenameLabel;
    QPlainTextEdit          *filename;

    QLabel                  *architectureLabel;
    QComboBox               *architecture;

    QLabel                  *compilerLabel;
    QComboBox               *compiler;

    QPushButton             *disassembleButton;
    QPushButton             *decompileIRButton;

    view::mainWidget::code  *m_codeWidget;
    control::Disassembler   *m_disassembler;
protected:
    QMainWindow             *m_parent;
public:
    basicInfo(QMainWindow *parent = 0);
    ~basicInfo(void);
    void setFilename(const QString &name);

    QString getArchitecture(void);
public slots:
    void disassemble(void);
};
} // binary
} // view

#endif // BASIC_INFO_H