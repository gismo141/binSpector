INCLUDE_DIRECTORIES("control")
INCLUDE_DIRECTORIES("view")
ADD_LIBRARY(binSpectorLib
	./control/codeEditor.cpp
	./control/Disassembler.cpp
	./control/syntax/clangHighlighter.cpp
	./view/binary/basicInfo.cpp
	./view/guiFunctions.cpp
	./view/mainWidget/codeViewer.cpp
	./view/mainWidget/help.cpp
	./view/visualizer/callGraph.cpp
	./view/visualizer/controlAndDataFlowGraph.cpp
	./view/visualizer/controlFlowGraph.cpp
	./view/visualizer/memoryDependence.cpp
	./view/binspector.cpp
)

QT5_USE_MODULES(binSpectorLib Widgets)