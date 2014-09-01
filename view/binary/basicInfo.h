#ifndef BASIC_INFO_H
#define BASIC_INFO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QPushButton>

namespace view
{
namespace binary
{
class basicInfo : public QWidget
{
    Q_OBJECT
private:
	QVBoxLayout 	*basicInfoLayout;

    QLabel      	*filenameLabel;
    QPlainTextEdit  *filename;

    QLabel      	*architectureLabel;
    QComboBox  		*architecture;

    QLabel      	*compilerLabel;
    QComboBox  		*compiler;

    QPushButton		*disassembleButton;
    QPushButton		*decompileIRButton;
protected:
	QMainWindow *thisParent;
public:
    basicInfo(QMainWindow *parent = 0);
    void setFilename(const QString & name);
};
} // binary
} // view

#endif // BASIC_INFO_H