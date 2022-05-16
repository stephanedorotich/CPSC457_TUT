// Author: Stéphane Dorotich
// CPSC457 - Spring 2022
// Use freely

#include <iostream>
#include <fstream>

std::string stream_reader(std::istream& stream) {
    std::string line;
    getline(stream, line);
    std::cout << line << std::endl;
    return line;
}

// void file_reader() {
//     std::string line;
//     std::ifstream myFile;
//     myFile.open("file.txt");
//     if (myFile.is_open()) {
//         while (myFile.good()) {
//             stream_reader(myFile);
//         }
//         myFile.close();
//     }
// }

int main() {
    std::string line;
    // file_reader();
    do {
        line = stream_reader(std::cin);
    } while (!line.empty());
    return 0;
}