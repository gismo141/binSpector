INCLUDE_DIRECTORIES("control")
INCLUDE_DIRECTORIES("view")

ADD_LIBRARY(binSpectorLib
	./control/codeEditor/codeEditor.cpp
	./control/disassembler/Disassembler.cpp
	./control/syntax/clang/clangHighlighter.cpp
	./control/syntax/llvm_ir/llvmHighlighter.cpp
	./control/syntax/markdown/MarkdownHighlighter.cpp
	./view/binary/basicInfo.cpp
	./view/guiFunctions.cpp
	./view/mainWidget/code/code.cpp
	./view/mainWidget/help/help.cpp
	./view/visualizer/callGraph/callGraph.cpp
	./view/visualizer/controlAndDataFlowGraph/controlAndDataFlowGraph.cpp
	./view/visualizer/controlFlowGraph/controlFlowGraph.cpp
	./view/visualizer/memoryAllocation/memoryAllocation.cpp
)

QT5_USE_MODULES(binSpectorLib Widgets)