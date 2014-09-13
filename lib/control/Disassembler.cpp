// #include <sys/types.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

#include "control/Disassembler.h"
#include "view/guiFunctions.h"

//#include "CodeInv/MCDirector.h"
//#include "CodeInv/Disassembler.h"

// #define READ 0
// #define WRITE 1

// pid_t popen2(const char *command, int *infp, int *outfp)
// {
//     int p_stdin[2], p_stdout[2];
//     pid_t pid;

//     if (pipe(p_stdin) != 0 || pipe(p_stdout) != 0)
//         return -1;

//     pid = fork();
//     if (pid < 0)
//         return pid;
//     else if (pid == 0)
//     {
//         close(p_stdin[WRITE]);
//         dup2(p_stdin[READ], READ);
//         close(p_stdout[READ]);
//         dup2(p_stdout[WRITE], WRITE);
//         execl("/bin/sh", "sh", "-c", command, NULL);
//         perror("execl");
//         exit(1);
//     }

//     if (infp == NULL)
//         close(p_stdin[WRITE]);
//     else
//         *infp = p_stdin[WRITE];
//     if (outfp == NULL)
//         close(p_stdout[READ]);
//     else
//         *outfp = p_stdout[READ];
//     return pid;
// }

control::Disassembler::Disassembler(QString inputFileName, QString outputFileName, QString architecture) : m_inputFileName(inputFileName), m_outputFileName(outputFileName), m_architecture(architecture)
{
    // if (popen2("$HOME/Developer/binSpector/control/fracture-cl -mattr=v6 $HOME/Developer/fracture/samples/arm/fib_armel", &infp, &outfp) <= 0)
    // {
    //     printf("Unable to exec fracture-cl\n");
    //     exit(1);
    // }

    //fracture::MCDirector MCD = new fracture::MCDirector();
    //fracture::Disassembler DAS = new fracture::Disassembler();
}

control::Disassembler::~Disassembler(void) {}

QString control::Disassembler::disassemble(QString parameters)
{
    QString disassemble = "otool -arch " + m_architecture + " -" + parameters + " " + m_inputFileName;
    QString demangle = "c++filt";

    if (m_architecture == "library")
        disassemble = "otool -" + parameters + " " + m_inputFileName;

    QString cmd = disassemble + " | " + demangle + " > " + m_outputFileName;
    return view::exec(cmd);
}

QString control::Disassembler::showSections()
{
    // char buf[32];
    // memset (buf, 0x0, sizeof(buf));

    // /*
    // * writing to stdin here
    // */
    // if (write(infp, "sect\n", 5) != 5)
    // {
    //     write(2, "There was an error writing to standard out\n", 44);
    //     return "Error";
    // }
    // close(infp);

    // /*
    //  * reading stdout here
    //  */
    // while ((read(outfp, buf, 32)) > 0)
    // {
    //     result.append(buf);
    // }
    // close(outfp);

    QString cmd = "";
    return view::exec(cmd);
}