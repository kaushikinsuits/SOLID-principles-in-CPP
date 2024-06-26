#include <iostream>
#include <fstream>
#include <string>

class FileManager {
public:
    void readFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::cout << "Read line: " << line << std::endl;
        }
    }

    void writeFile(const std::string& filename, const std::string& data) {
        std::ofstream file(filename);
        file << data;
        std::cout << "Data written to file: " << filename << std::endl;
    }
};

int main() {
    FileManager fileManager;
    fileManager.readFile("input.txt");
    fileManager.writeFile("output.txt", "Hello, World!");
    return 0;
}

/*
In this code, the FileManager class handles both reading from and writing to a
file. However, this violates SRP because the class is responsible for two different
things: file I/O operations and managing file contents.
*/