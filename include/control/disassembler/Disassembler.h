#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <QString>

namespace control
{
class Disassembler
{
private:
	int infp, outfp;
protected:
public:
    Disassembler(QString inputFileName, QString architecture);
    ~Disassembler(void);

    QString disassemble();
    QString showSections();
    //QString showSymbols();
};
} // control

#endif // DISASSEMBLER_H
