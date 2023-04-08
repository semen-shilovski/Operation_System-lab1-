#include "Source.h"
#pragma warning(disable: 2664)

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Error: Argument exception (must be equal 3)" << std::endl;
        return 1;
    }

    std::string command = "Creator.exe " + std::string(argv[1]) + std::string(" ") + std::string(argv[2]);
    createProcess(command.c_str());

    readEmployeeData(argv[1]);

    generateReport(argv[1]);

    return 0;
}