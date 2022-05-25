#include<iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <iomanip>
#include <string>
#include<winbase.h>

LPCSTR directory = R"(D:\programs\JetBrains\Toolbox\projects_clion\Killer\cmake-build-debug\Killer.exe)";

void showActiveProcesses() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(snapshot, &pEntry)) {
        std::cout << std::setw(10) << std::left << "PROC_NAME" << std::setw(10) << "ID" << "\n";
        while (Process32Next(snapshot, &pEntry)) {
            std::wcout <<
                       std::setw(10) << std::left << pEntry.szExeFile <<
                       std::setw(5) << std::right << pEntry.th32ProcessID << "\n";
        }
    }
    CloseHandle(snapshot);
    std::cout << "\n\n\n\n";
}

void killProcesses(const std::string &pToKill) {
    char *toKill = (char *) pToKill.c_str();
    STARTUPINFOA sInfo = {0};
    PROCESS_INFORMATION pInfo = {nullptr};
    if (CreateProcessA(directory, toKill, nullptr, nullptr, FALSE, 0, nullptr, nullptr, &sInfo, &pInfo)) {
        WaitForSingleObject(pInfo.hProcess, INFINITE);
    }
}

int main() {
    SetEnvironmentVariableA("PROC_TO_KILL", "Telegram,Discord");
    showActiveProcesses();
    killProcesses("");
    _putenv("PROC_TO_KILL");
    //std::cout << "All is okey\n";

    int option;
    std::cout << "1 - id, 2 - name\n";
    std::cin >> option;
    switch (option) {
        case 1: {
            int id;
            std::cin >> id;
            std::string process = "--id ";
            process += std::to_string(id);
            std::cout << process << "\n";
            killProcesses(process);
            break;
        }
        case 2: {
            std::string name;
            std::cin >> name;
            std::string process = "--name " + name;
            std::cout << process << "\n";
            killProcesses(process);
            break;
        }
        default:
            break;
    }

    _putenv("");
    return 0;
}

