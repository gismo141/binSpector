# binSpector - a graphical binary analyzer for LLVM-IR

**VERY EARLY STAGE OF DEVELOPMENT**

`binSpector` is a Qt-driven open-source application that uses [dagger](http://dagger.repzret.org) and [fracture](https://github.com/draperlaboratory/fracture) for disassembling ARM and x86-binaries to LLVM-IR.

After the disassembly the LLVM-code will be analysed to present the code-structure in different graphics:

- Call Graph
- Control-Flow Graph
- Control-Flow and Data-Flow Graph
- Memory Allocation (not implemented yet)

The UI consists of a 3-pane view. The leftmost is a tabbed-dock that presents technical information about the binary actually analysed. The combo-boxes *Architecture* and *Compiler* are used to determine the project to use for the disassembly. Later these switches could be used for cross-compilation or other fun-stuff.

<p >
  <img src="https://raw.github.com/gismo141/binSpector/master/docs/images/fakeDisassembly.png" alt="faked disassembly" width="1024px"/>
</p>

The main-area is meant to present everything that is code. This could be the direct assembly, LLVM-IR (llvm's intermediate representation) or later C-code.

The rightmost pane is also a tabbed-dock that presents all the visualized graphs. At the moment only image-files are supported. For better interaction it would be much better to implement postscript-support for zoom and graph-manipulation.

At the moment the program can open a binary-file and present its assembly-code. Everytime the user opens a binary, a structure of subfolders with the binary's name is created under `/tmp/binSpector/`. This structure is used to save all the intermediate and visualized files until the user saves the project. When the user saves the project to a specified location, the program copies every content from its `/tmp/binSpector/`-subfolder recursively to the new location and attaches an `.binsp`-extension.