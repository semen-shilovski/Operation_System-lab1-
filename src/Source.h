#ifndef EMPLOYEE_REPORT_H
#define EMPLOYEE_REPORT_H

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <tchar.h>
#include <algorithm>
#include <string>

struct employee {
    int num;
    char name[10];
    double hours;
};


void createProcess(const char* commandLine) {
    STARTUPINFO si; // information about windows(console)
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    PROCESS_INFORMATION pi; // information about process, for controll it
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL, (TCHAR*)commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        std::cerr << "Error creating process" << std::endl;
        exit(1);
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
};

void readEmployeeData(const char* filename) {
    std::ifstream input(filename, std::ios::binary);
    if (!input) {
        std::cerr << "Error: Could not open file for reading" << std::endl;
        exit(1);
    }

    employee record;
    std::cout << std::endl;
    std::cout << "Records :" << std::endl;
    while (input.read(reinterpret_cast<char*>(&record), sizeof(record))) {
        std::cout << "ID: " << record.num << std::endl;
        std::cout << "Name: " << record.name << std::endl;
        std::cout << "Hours: " << record.hours << std::endl;
        std::cout << std::endl;
    }

    input.close();
};

void generateReport(const char* inputFilename) {
    std::string reportFile;
    double salary;
    std::cout << "Write name for Report file : " << std::endl;
    std::cin >> reportFile;
    std::cout << "Write salary : " << std::endl;
    std::cin >> salary;

    std::string command = "Reporter.exe " + std::string(inputFilename) + std::string(" ") + reportFile + std::string(" ") + std::to_string(salary);
    createProcess(command.c_str());

    std::ifstream input(reportFile);
    if (!input) {
        std::cerr << "Error: Could not open reporter file for reading" << std::endl;
        exit(1);
    }

    std::string line;
    std::cout << std::endl;
    while (std::getline(input, line))
    {
        std::cout << line << std::endl;
    }

    input.close();
};

#endif // EMPLOYEE_REPORT_H
