#include "func.h"

void cur(std::string &bebr) {
    int iter{ 0 };

    std::reverse(bebr.begin(), bebr.end());
    for (const auto &i : bebr) {
        iter++;
        if (i == '/') {
            break;
        }
    }

    bebr.erase(bebr.begin(), bebr.begin() + iter);
    std::reverse(bebr.begin(), bebr.end());
}

void switch_command() {
    std::string dir;
    char command;

    fs::current_path("C:\\");

    do {
        std::cout << ">> ";
        std::cin >> command;
        if (command == 'c' or command == 'm' or command == 'r') {
            std::cin >> dir;
            try {
                if (dir == " " or dir == "")
                    throw - 1;

            }
            catch (int err) {
                std::cerr << err << std::endl;
                return;
            }
        }

        switch (command) {
        case 'c':
            if (dir == "..") {
                auto st = fs::current_path().generic_string();
                cur(st);
                fs::current_path(st);
            }
            fs::current_path(dir);
            break;
        case 'l':
            system("dir");
            break;
        case 'm':
            if (!fs::exists(dir)) {
                fs::create_directories(dir);
            }
            else {
                std::cout << "Directory exist" << std::endl;
            }
            break;
        case 'r':
            if (fs::exists(dir)) {
                fs::remove(dir);
            }
            else {
                std::cout << "Directory not exist" << std::endl;
            }
        }
    } while (command != 'e');
}
