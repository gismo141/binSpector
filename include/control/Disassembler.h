#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <QString>

namespace control
{
class Disassembler
{
private:
	int infp, outfp;

	QString 					m_inputFileName;
	QString 					m_architecture;
	QString						m_outputFileName;
protected:
public:
    Disassembler(QString inputFileName, QString outputFileName, QString architecture);
    ~Disassembler(void);

    QString disassemble(QString parameters);
    QString showSections();
    //QString showSymbols();
};
} // control

#endif // DISASSEMBLER_H
