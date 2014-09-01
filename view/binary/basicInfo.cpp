#include <QHBoxLayout>

#include "iostream"

#include "basicInfo.h"
#include "../guiFunctions.cpp"

view::binary::basicInfo::basicInfo(QMainWindow *parent) {
	thisParent = parent;

	int fixedWidth = 100;

	// filename
    filenameLabel = new QLabel("Filename:", this);
    filenameLabel->setAlignment(Qt::AlignCenter);
    filenameLabel->setFixedWidth(fixedWidth);
    filename = new QPlainTextEdit(this);
    filename->setReadOnly(true);
    filename->setTextInteractionFlags(filename->textInteractionFlags() | Qt::TextSelectableByKeyboard);
    view::setHeight(filename, 2);

    QHBoxLayout *filenameLayout = new QHBoxLayout();
    filenameLayout->addWidget(filenameLabel);
    filenameLayout->addWidget(filename);

    // architecture
    architectureLabel = new QLabel("Architecture:", this);
    architectureLabel->setAlignment(Qt::AlignCenter);
    architectureLabel->setFixedWidth(fixedWidth);
    architecture = new QComboBox(this);
    architecture->setEditable(false);
    architecture->addItem("ARM", "ARM");
    architecture->addItem("x86", "x86");

    QHBoxLayout *architectureLayout = new QHBoxLayout();
    architectureLayout->addWidget(architectureLabel);
    architectureLayout->addWidget(architecture);

    // compiler
    compilerLabel = new QLabel("Compiler:", this);
    compilerLabel->setAlignment(Qt::AlignCenter);
    compilerLabel->setFixedWidth(fixedWidth);
    compiler = new QComboBox(this);
    compiler->setEditable(false);
    compiler->addItem("GCC", "GCC");
    compiler->addItem("CLANG", "CLANG");

    QHBoxLayout *compilerLayout = new QHBoxLayout();
    compilerLayout->addWidget(compilerLabel);
    compilerLayout->addWidget(compiler);

    // disassemble
    disassembleButton = new QPushButton("Show Assembly", this);
    decompileIRButton = new QPushButton("Decompile to LLVM-IR", this);

    basicInfoLayout = new QVBoxLayout();
	basicInfoLayout->addLayout(filenameLayout);
	basicInfoLayout->addLayout(architectureLayout);
	basicInfoLayout->addLayout(compilerLayout);
	basicInfoLayout->addWidget(disassembleButton);
	basicInfoLayout->addWidget(decompileIRButton);
   
    this->setLayout(basicInfoLayout);
}

void view::binary::basicInfo::setFilename(const QString & name)
{
    //std::cout << name.toUtf8().constData() << std::endl;
    filename->setPlainText(name.toUtf8().constData());
}