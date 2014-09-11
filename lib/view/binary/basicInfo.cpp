#include <QHBoxLayout>

#include "iostream"

#include "view/binary/basicInfo.h"
#include "view/binspector.h"
#include "view/guiFunctions.h"

view::binary::basicInfo::basicInfo(QMainWindow *parent)
{
    m_parent = parent;
    m_codeWidget = new view::mainWidget::code();

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

    QObject::connect(disassembleButton, SIGNAL(clicked()), this, SLOT(disassemble()));

    basicInfoLayout = new QVBoxLayout();
    basicInfoLayout->addLayout(filenameLayout);
    basicInfoLayout->addLayout(architectureLayout);
    basicInfoLayout->addLayout(compilerLayout);
    basicInfoLayout->addWidget(disassembleButton);
    basicInfoLayout->addWidget(decompileIRButton);

    this->setLayout(basicInfoLayout);
}

view::binary::basicInfo::~basicInfo(void) {}

void view::binary::basicInfo::setFilename(const QString &name)
{
    filename->setPlainText(name.toUtf8().constData());
}

QString view::binary::basicInfo::getArchitecture(void)
{
    return (architecture->itemData(architecture->currentIndex())).toString();
}

void view::binary::basicInfo::disassemble()
{
    if (filename->toPlainText().isEmpty())
        return;
    if (getArchitecture() != "ARM")
        return;
    ((view::binspector *) m_parent)->showCentralWidget(m_codeWidget);

    m_disassembler = new control::Disassembler(((view::binspector *) m_parent)->getActiveBinaryPath(), getArchitecture());

    m_codeWidget->setText(m_disassembler->disassemble());
}