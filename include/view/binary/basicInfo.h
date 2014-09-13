#ifndef BASIC_INFO_H
#define BASIC_INFO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QPushButton>

#include "view/mainWidget/codeViewer.h"
#include "control/Disassembler.h"

namespace view
{
namespace binary
{
class basicInfo : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout                     *m_basicInfoLayout;

    QLabel                          *m_filenameLabel;
    QPlainTextEdit                  *m_filename;

    QLabel                          *m_architectureLabel;
    QComboBox                       *m_architecture;

    QLabel                          *m_disassembleOptionsLabel;
    QPlainTextEdit                  *m_disassembleOptions;
    QPushButton                     *m_disassembleButton;

    QLabel                          *m_decompileOptionsLabel;
    QPlainTextEdit                  *m_decompileOptions;
    QPushButton                     *m_decompileIRButton;

    view::mainWidget::codeViewer    *m_codeWidget;
    control::Disassembler           *m_disassembler;
    //control::Decompiler           *m_decompiler;
    control::Disassembler           *m_decompiler;
protected:
    QMainWindow                     *m_parent;
public:
    basicInfo(QMainWindow *parent = 0);
    ~basicInfo(void);

    void setFilename(const QString &name);
    void setArchitecture(QString architecture);

    QString getArchitecture(void);
public slots:
    void disassemble(void);
    void decompileIR(void);
};
} // binary
} // view

#endif // BASIC_INFO_H