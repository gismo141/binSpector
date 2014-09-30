# binSpector - a graphical binary analyzer for LLVM-IR

**VERY EARLY STAGE OF DEVELOPMENT**

Die zum Projekt zugehörige Studienarbeit befindet sich [hier](https://github.com/gismo141/Studienarbeit).

## Overview

`binSpector` is a Qt5-driven open-source application that uses [dagger](http://dagger.repzret.org) and [fracture](https://github.com/draperlaboratory/fracture) for disassembling and decompiling *ARM*, *PPC* and *x86* (*i386* and *x86_64*)-binaries to [LLVM-IR](http://llvm.org/docs/LangRef.html).

After the decompilation to LLVM-IR the binary will be analysed to present the code-structure in different graphics:

- Call Graph
- Control-Flow Graph
- Control-Flow and Data-Flow Graph
- (Memory) Dependence (not implemented yet)

![faked disassembly](https://raw.github.com/gismo141/binSpector/master/docs/images/fakeDisassembly.png)

The UI consists of a 3-pane view.

The leftmost is a tabbed-dock that presents technical information about the binary actually analysed. The combo-boxes *Architecture* and *Compiler* are used to determine the project to use for the disassembly. Later these switches could be used for cross-compilation or other fun-stuff.

The main-area is meant to present everything that is code or the manual. It is possible to create an simple code-viewer which uses [pygments](http://pygments.org) to highlight its code or you can use the class `codeEditor()` and program your own syntax-parser. An example implementation for `C++`-parser is included under `./lib/control/syntax/clangHighlighter.cpp`.

The rightmost pane is also a tabbed-dock that presents all the visualized graphs. These graphs are created with the [graphviz-dot](http://www.graphviz.org)-utility upon the decompiled LLVM-IR. At the moment only image-files are supported. For better interaction it would be much better to implement postscript-support for zoom and graph-manipulation.

At the moment the program can open a binary-file and present its assembly-code. Everytime the user opens a binary, a structure of subfolders with the binary's name is created under `/tmp/binSpector/`:

```
/
`--tmp
   `-- binSpector
       |-- texts
       `-- graphs
```

This structure is used to save all the intermediate and visualized files until the user saves the project elsewhere. When the user saves the project to a specified location, the program copies every content from its `/tmp/binSpector/`-subfolder recursively to the new location and attaches an `.binsp`-extension.

## Prerequisits

`binSpector` is intended to run on nearly every available OS. At this stage of developement only the usage under Mac OSX 10.9.4 is guaranteed. It can be possible to run `binSpector` also on different operating systems but you may need to set some paths differently.

It is recommended to use the package-manager [Homebrew](http://brew.sh) for easy installation of the missing programs. **Homebrew** uses its own directory to compile its applications and links them to `/usr/local/bin` afterwards.

### XCode

You need to have XCode and its command-line-tools installed:

```Shell
xcode-select --install
```

Also accept the License Agreement which is presented when opening XCode.

### CMake

This project uses the CMake-build-system. The build-system can easily be maintained and altered.

```Shell
brew install cmake
```

### Qt5

Qt5 is needed for all the GUI-elements to provide an easy programming interface independent of the targeted operating system.

```Shell
brew install qt5
```

### Graphviz

This is used to create the graphs for analysation and the documentation.

```Shell
brew install graphviz
```

### Pandoc

This is used to convert `Markdown *.md`-files instantly into temporary `html`-code to present for example the manual in an appaeling way. 

```Shell
brew install pandoc
```

### Pygments

This Python-tool is used to highlight every file that will be shown in the central-area of `binSpector`. Every highlighted file will also be saved in the folder-structure under `/texts/{architecture}.{language}.html`. That saves some time on resize-events because the highlighted code can be reused.

```Shell
sudo easy_install Pygments
```

### Doxygen

This is used to compile the documentation with every build, this way the documentation is always up-to-date.

```Shell
brew install doxygen
```

## Installation

##### 1. Set your desired installation-path (everything after `=`):

```Shell
export DESTINATION=$HOME/Developer/binSpector
```

##### 2. Clone this repository:

```Shell
git clone git@github.com:gismo141/binSpector $DESTINATION
```

##### 3. Change to the cloned repository:

```Shell
cd $DESTINATION
```

##### 4. Create build-directory:

```Shell
mkdir build && cd build
```

##### 5. Compile the documentation and `binSpector`:

```Shell
cmake .. && make
```

## Usage

After the installation you will have a folder `$DESTINATION/build/tools/binSpector` which contains the newly compiled `binSpector.app`.

Under `$DESTINATION/build/docs/html` you'll find the documentation made wit *Doxygen*. Just open `index.html` in your browser.

##### Opening a project or creating a new analysis

When opening `binSpector.app` the user is presented with a file-dialog where he can select a binary-file or an existing `*.binsp`-project to analyse. The following images illustrate `binSpector`'s capabilities using it's own binary for analysis.

![open Binary/Project](https://raw.github.com/gismo141/binSpector/master/docs/images/openDialog.png)

##### Reading the manual

![rtf manual](https://raw.github.com/gismo141/binSpector/master/docs/images/manual.png)

##### Saving your analysation

![save Project](https://raw.github.com/gismo141/binSpector/master/docs/images/saveDialog.png)

##### Disassemble with standard options

![disassemble with tV](https://raw.github.com/gismo141/binSpector/master/docs/images/disassembled_x86_64_tV.png)

##### Disassemble with user-set options

![disassemble with t](https://raw.github.com/gismo141/binSpector/master/docs/images/disassembled_x86_64_t.png)

##### Decompile to LLVM-IR (at the moment this is not suppported)

When clicking the `decompile`-button `binSpector` will disassemble the binary with the standard `-tV`-options but the output will be highlighted using the LLVM-syntax. **There is no LLVM-IR code produced in this process!!!!**

![decompile to LLVM](https://raw.github.com/gismo141/binSpector/master/docs/images/llvm_ir_x86_64_na.png)

For every problem [send me an email](mailto:michael.r141@gmail.com) or create an issue.


## How could you contribute?

1. [Fork this project][fork] to your account.
2. [Create a new branch][branch] for the improvements, you intend to make.
3. **Make the changements in your fork.**
4. [Send a pull-request][pr] from your fork’s branch to my `master` branch.
 
You can always use the web-interface to make the changes you want. It helps you automizing the workflow from above.

[fork]: http://help.github.com/forking/
[branch]: https://help.github.com/articles/creating-and-deleting-branches-within-your-repository
[pr]: http://help.github.com/pull-requests/
