#include<iostream>
#include<string>
#include<sstream>
#include<windows.h>
#include<winbase.h>
#include<TlHelp32.h>

void killByName(const char *szExeName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(PROCESSENTRY32);

    std::string sName(szExeName);
    if (Process32First(hSnapshot, &pEntry)) {
        while (Process32Next(hSnapshot, &pEntry)) {
            std::wstring wst = std::wstring(sName.begin(), sName.end());
            const wchar_t *wstr = wst.c_str();
            if (!std::wcscmp(reinterpret_cast<const wchar_t *>(pEntry.szExeFile), wstr)) {
                HANDLE terminate = OpenProcess(PROCESS_TERMINATE, FALSE, pEntry.th32ProcessID);
                if (terminate != nullptr) {
                    TerminateProcess(terminate, 0);
                    CloseHandle(terminate);
                }
            }
        }
    }
    CloseHandle(hSnapshot);
}

void killByID(int procID) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pEntry)) {
        while (Process32Next(hSnapshot, &pEntry)) {
            if (pEntry.th32ProcessID == procID) {
                HANDLE terminate = OpenProcess(PROCESS_TERMINATE, 0, pEntry.th32ProcessID);
                if (terminate != nullptr) {
                    TerminateProcess(terminate, 0);
                    CloseHandle(terminate);
                }
            }
        }
    }
    CloseHandle(hSnapshot);
}


int main(int argc, char *argv[]) {
    const CHAR *proc = "PROC_TO_KILL";
    const DWORD buffSize = 100000;
    char buff[buffSize];

    GetEnvironmentVariableA(proc, buff, buffSize);
    std::stringstream stream(buff);
    while (stream.getline(buff, buffSize, ',')) {
        std::string str(buff);
        str += ".exe";
        const char *ch = str.c_str();
        killByName(ch);
    }

    std::string flag;
    if (argc > 1) {
        flag = argv[0];
    } else flag = "";

    if (flag == "--name") {
        std::cout << flag << std::endl;
        std::string name(argv[1]);
        name += ".exe";
        const char *filename = name.c_str();
        killByName(filename);
    } else if (flag == "--id") {
        std::cout << flag << std::endl;
        killByID(std::stoi(argv[1]));
    }

    return 0;
}