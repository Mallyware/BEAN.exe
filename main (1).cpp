#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

void displayWarning() {
    std::cout << "WARNING!!! This is considered malware. If you proceed, your system may be permanently affected. If you are unsure, it's best to terminate this program now. Proceed at your own risk.\n";
}

void invertColors() {
    std::srand(std::time(0));
    while (true) {
        std::cout << "\033[7m"; // Enable color inversion
        usleep(100000); // Sleep for 100 milliseconds
        std::cout << "\033[0m"; // Disable color inversion
        usleep(100000); // Sleep for 100 milliseconds
    }
}

void spawnMessageBox() {
    while (true) {
        std::cout << "FUCKED BY BEAN.exe\n";
        usleep(200000); // Sleep for 200 milliseconds
    }
}

void tunnelEffect() {
    int screenWidth = 80; // Adjust the screen width as needed
    int screenHeight = 24; // Adjust the screen height as needed
    int tunnelDepth = 15; // Adjust the tunnel depth as needed

    std::srand(std::time(0));

    while (true) {
        for (int z = 0; z < tunnelDepth; z++) {
            for (int y = 0; y < screenHeight; y++) {
                for (int x = 0; x < screenWidth; x++) {
                    if (x == screenWidth / 2 && y == screenHeight / 2) {
                        std::cout << "\033[1;32m"; // Set color to green
                        std::cout << "O";
                    } else {
                        std::cout << "\033[1;30m"; // Set color to gray
                        std::cout << ".";
                    }
                }
                std::cout << "\n";
            }
            usleep(100000); // Sleep for 100 milliseconds
            std::cout << "\033[2J\033[1;1H"; // Clear the screen
        }
    }
}

int main() {
    displayWarning();

    pid_t pid = fork();
    if (pid == 0) {
        invertColors();
    } else if (pid > 0) {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            spawnMessageBox();
        } else if (pid2 > 0) {
            tunnelEffect();
        } else {
            std::cerr << "Failed to create child process.\n";
            return 1;
        }
    } else {
        std::cerr << "Failed to create child process.\n";
        return 1;
    }

    return 0;
}