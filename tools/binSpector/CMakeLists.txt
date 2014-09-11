INCLUDE_DIRECTORIES("../../include")

SET( _MOC_HDRS
	../../include/control/codeEditor/codeEditor.h
	../../include/control/disassembler/Disassembler.h
	../../include/control/syntax/clang/clangHighlighter.h
	../../include/control/syntax/llvm_ir/llvmHighlighter.h
	../../include/control/syntax/markdown/MarkdownHighlighter.h
	../../include/view/binary/basicInfo.h
	../../include/view/guiFunctions.h
	../../include/view/mainWidget/code/code.h
	../../include/view/mainWidget/help/help.h
	../../include/view/visualizer/callGraph/callGraph.h
	../../include/view/visualizer/controlAndDataFlowGraph/controlAndDataFlowGraph.h
	../../include/view/visualizer/controlFlowGraph/controlFlowGraph.h
	../../include/view/visualizer/memoryAllocation/memoryAllocation.h
	./main.h)

QT5_WRAP_CPP( _MOC_SRCS ${_MOC_HDRS} )

INCLUDE_DIRECTORIES("../../lib")

SET( _SRCS
	../../lib/control/codeEditor/codeEditor.cpp
	../../lib/control/disassembler/Disassembler.cpp
	../../lib/control/syntax/clang/clangHighlighter.cpp
	../../lib/control/syntax/llvm_ir/llvmHighlighter.cpp
	../../lib/control/syntax/markdown/MarkdownHighlighter.cpp
	../../lib/view/binary/basicInfo.cpp
	../../lib/view/guiFunctions.cpp
	../../lib/view/mainWidget/code/code.cpp
	../../lib/view/mainWidget/help/help.cpp
	../../lib/view/visualizer/callGraph/callGraph.cpp
	../../lib/view/visualizer/controlAndDataFlowGraph/controlAndDataFlowGraph.cpp
	../../lib/view/visualizer/controlFlowGraph/controlFlowGraph.cpp
	../../lib/view/visualizer/memoryAllocation/memoryAllocation.cpp
	./main.cpp)

ADD_EXECUTABLE(binSpector ${_SRCS} ${_MOC_SRCS})

TARGET_LINK_LIBRARIES(binSpector ${QT_LIBRARIES})

QT5_USE_MODULES(binSpector Widgets)