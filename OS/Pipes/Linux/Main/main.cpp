#include <iostream>
#include <unistd.h>

int main() {
    std::string paths[] = {"/home/jan/CLionProjects/ProcessM/cmake-build-debug/ProcessM",
                           "/home/jan/CLionProjects/ProcessA/cmake-build-debug/ProcessA",
                           "/home/jan/CLionProjects/ProcessP/cmake-build-debug/ProcessP",
                           "/home/jan/CLionProjects/ProcessS/cmake-build-debug/ProcessS"};
    int p[3];
    std::cout << "enter numbers\n";
    for (int i = 0; i < 3; i++) {
        pipe(p);
        if (!fork()) {
            dup2(p[1], 1);
            system(paths[i].c_str());
            exit(0);
        }
        dup2(p[0], 0);
        close(p[1]);
    }
    system(paths[3].c_str());
    return 0;
}