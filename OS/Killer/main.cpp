#include <iostream>
#include <string>
#include <sstream>

void killByName(const char *filename) {
    std::string toKill(filename);
    std::system(("killall " + toKill).c_str());
}

void killByID(int id) {
    system(("kill " + std::to_string(id)).c_str());
}

int main(int argc, char *argv[]) {
    char *toKill = getenv("PROC_TO_KILL");

    if (toKill != nullptr) {
        std::string buff(toKill);
        std::stringstream streamProc(toKill);
        while (streamProc.getline(toKill, (int) buff.size(), ',')) {
            std::string str(toKill);
            const char *ch = str.c_str();
            killByName(ch);
        }
        std::cout << "danone" << std::endl;
    }

    std::string option, flag;
    if (argc == 3) {
        std::cout << argv[1] << std::endl;
        option = argv[1];

        if (option == "--name") {
            std::string name(argv[2]);
            const char *filename = name.c_str();
            killByName(filename);
        } else if (option == "--id") {
            killByID(std::stoi(argv[2]));
        }
    }
    return 0;
}
