#include <QHBoxLayout>
#include <QDebug>

#include "view/binary/basicInfo.h"
#include "view/binspector.h"
#include "view/guiFunctions.h"

view::binary::basicInfo::basicInfo(QMainWindow *parent)
{
    m_parent = parent;
    m_codeWidget = new view::mainWidget::codeViewer(false, true, "nasm");

    int fixedWidth = 100;

    // filename
    m_filenameLabel = new QLabel("Filename:", this);
    m_filenameLabel->setAlignment(Qt::AlignCenter);
    m_filenameLabel->setFixedWidth(fixedWidth);
    m_filename = new QPlainTextEdit(this);
    m_filename->setReadOnly(true);
    m_filename->setTextInteractionFlags(m_filename->textInteractionFlags() | Qt::TextSelectableByKeyboard);
    view::setHeight(m_filename, 2);

    QHBoxLayout *m_filenameLayout = new QHBoxLayout();
    m_filenameLayout->addWidget(m_filenameLabel);
    m_filenameLayout->addWidget(m_filename);

    // architecture
    m_architectureLabel = new QLabel("Architecture:", this);
    m_architectureLabel->setAlignment(Qt::AlignCenter);
    m_architectureLabel->setFixedWidth(fixedWidth);
    m_architecture = new QComboBox(this);
    m_architecture->setEditable(false);
    m_architecture->addItem("ARM", "ARM");
    m_architecture->addItem("i386", "i386");
    m_architecture->addItem("x86_64", "x86_64");
    m_architecture->addItem("ppc", "ppc");
    m_architecture->addItem("library", "library");

    QHBoxLayout *m_architectureLayout = new QHBoxLayout();
    m_architectureLayout->addWidget(m_architectureLabel);
    m_architectureLayout->addWidget(m_architecture);

    // disassemble
    m_disassembleOptionsLabel = new QLabel("Dis-Options:", this);
    m_disassembleOptionsLabel->setAlignment(Qt::AlignCenter);
    m_disassembleOptionsLabel->setFixedWidth(fixedWidth);
    m_disassembleOptions = new QPlainTextEdit(this);
    m_disassembleOptions->setReadOnly(false);
    m_disassembleOptions->setPlainText("tV");
    view::setHeight(m_disassembleOptions, 2);
    QHBoxLayout *m_disassembleOptionsLayout = new QHBoxLayout();
    m_disassembleOptionsLayout->addWidget(m_disassembleOptionsLabel);
    m_disassembleOptionsLayout->addWidget(m_disassembleOptions);
    m_disassembleButton = new QPushButton("Disassemble", this);

    // decompile
    m_decompileOptionsLabel = new QLabel("Dec-Options:", this);
    m_decompileOptionsLabel->setAlignment(Qt::AlignCenter);
    m_decompileOptionsLabel->setFixedWidth(fixedWidth);
    m_decompileOptions = new QPlainTextEdit(this);
    m_decompileOptions->setReadOnly(false);
    m_decompileOptions->setPlainText("NOT IMPLEMENTED");
    view::setHeight(m_decompileOptions, 2);
    QHBoxLayout *m_decompileOptionsLayout = new QHBoxLayout();
    m_decompileOptionsLayout->addWidget(m_decompileOptionsLabel);
    m_decompileOptionsLayout->addWidget(m_decompileOptions);
    m_decompileIRButton = new QPushButton("Decompile to LLVM-IR", this);

    QObject::connect(m_disassembleButton, SIGNAL(clicked()), this, SLOT(disassemble()));
    QObject::connect(m_decompileIRButton, SIGNAL(clicked()), this, SLOT(decompileIR()));

    m_basicInfoLayout = new QVBoxLayout();
    m_basicInfoLayout->addLayout(m_filenameLayout);
    m_basicInfoLayout->addLayout(m_architectureLayout);
    m_basicInfoLayout->addLayout(m_disassembleOptionsLayout);
    m_basicInfoLayout->addLayout(m_decompileOptionsLayout);
    m_basicInfoLayout->addWidget(m_disassembleButton);
    m_basicInfoLayout->addWidget(m_decompileIRButton);

    this->setLayout(m_basicInfoLayout);
}

view::binary::basicInfo::~basicInfo(void) {}

void view::binary::basicInfo::setFilename(const QString &name)
{
    m_filename->setPlainText(name.toUtf8().constData());
}

QString view::binary::basicInfo::getArchitecture(void)
{
    return (m_architecture->itemData(m_architecture->currentIndex())).toString();
}

void view::binary::basicInfo::setArchitecture(QString architecture)
{
    m_architecture->setCurrentIndex(m_architecture->findData(architecture));
}

void view::binary::basicInfo::disassemble(void)
{
    if (m_filename->toPlainText().isEmpty())
        return;

    m_codeWidget = new view::mainWidget::codeViewer(false, true, "nasm");
    ((view::binspector *) m_parent)->showCentralWidget(m_codeWidget, "DIS(" + getArchitecture() + ", -" + m_disassembleOptions->toPlainText() + ")");

    QString disassembledFilePath = ((view::binspector *) m_parent)->getActiveAnalysisPath() + "/texts/" + getArchitecture() + "." + m_disassembleOptions->toPlainText() + ".asm";
    QString highlightedFilePath = disassembledFilePath + ".html";

    m_disassembler = new control::Disassembler(((view::binspector *) m_parent)->getActiveBinaryPath(),
            disassembledFilePath,
            getArchitecture());

    m_disassembler->disassemble(m_disassembleOptions->toPlainText());
    m_codeWidget->highlightFile(disassembledFilePath, highlightedFilePath);
}

void view::binary::basicInfo::decompileIR(void)
{
    if (m_filename->toPlainText().isEmpty())
        return;

    m_codeWidget = new view::mainWidget::codeViewer(false, true, "llvm");
    ((view::binspector *) m_parent)->showCentralWidget(m_codeWidget, "LLVM-IR" + getArchitecture() + ", -" + m_decompileOptions->toPlainText() + ")");

    //QString decompiledFilePath = ((view::binspector *) m_parent)->getActiveAnalysisPath() + "/texts/" + getArchitecture() + "." + m_decompileOptions->toPlainText() + ".ll";
    QString decompiledFilePath = ((view::binspector *) m_parent)->getActiveAnalysisPath() + "/texts/" + getArchitecture() + ".tV.ll";
    QString highlightedFilePath = decompiledFilePath + ".html";

    m_decompiler = new control::Disassembler(((view::binspector *) m_parent)->getActiveBinaryPath(),
            decompiledFilePath,
            getArchitecture());
    //m_decompiler->disassemble(m_decompileOptions->toPlainText());
    m_decompiler->disassemble("tV");

    // NOT IMPLEMENTED YET !!!
    // m_decompiler = new control::Decompiler(((view::binspector *) m_parent)->getActiveBinaryPath(),
    //         decompiledFilePath,
    //         getArchitecture());
    // m_decompiler->decompile(m_decompileOptions->toPlainText());

    m_codeWidget->highlightFile(decompiledFilePath, highlightedFilePath);
}