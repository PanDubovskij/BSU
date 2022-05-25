#include <iostream>
#include <string>

std::string directory = "/home/jan/CLionProjects/Killer/cmake-build-debug/Killer";

void showActiveProcesses() {
    system("ps -e");
}

void killProcesses(const std::string &toKill) {
    system((directory + " " + toKill).c_str());
}

int main() {
    showActiveProcesses();
    setenv("PROC_TO_KILL", "gnome-calculato,firefox", 0);
    killProcesses("");
    unsetenv("PROC_TO_KILL");
    showActiveProcesses();

    int option;
    std::cout << "1 id, 2 name\n";
    std::cin >> option;
    switch (option) {
        case 1: {
            int id;
            std::cin >> id;
            std::string process = "--id ";
            process += std::to_string(id);
            killProcesses((process));
            break;
        }
        case 2: {
            std::string name;
            std::cin >> name;
            std::string process = "--name " + name;
            killProcesses(process);
            break;
        }
        default:
            break;
    }

    return 0;
}