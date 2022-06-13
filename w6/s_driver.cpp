// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022

#include "sort.cpp"

#include <fstream>
#include <iostream>
#include <vector>

// COPIED FROM ASSIGNMENT 4 COMMON.CPP
// AUTHOR: Dr. Pavol Federl
// modified to take reference to a vector of strings.
void split(const std::string& p_line, std::vector<std::string> & words)
{
    auto line = p_line + " ";
    bool in_str = false;
    std::string curr_word = "";
    for (auto c : line) {
        if (isspace(c)) {
            if (in_str)
                words.push_back(curr_word);
            in_str = false;
            curr_word = "";
        } else {
            curr_word.push_back(c);
            in_str = true;
        }
    }
    return;
}

void usage_error(const char * prog) {
    std::cout << "Usage:\n\t" << prog << " filename" << std::endl;
    exit(-1);
}

int main (int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);

    std::ifstream fs; // declare file stream object
    fs.open(argv[1]); // open file
    std::string str; // declare string to store lines
    std::vector<std::string> words;

    if (!fs.is_open()) usage_error(argv[0]); // check if file successfully opened
    
    // read file contents and add words to words vector
    while (std::getline(fs, str)) {
        split(str, words);
    }
    fs.close();

    // custom sort words
    custom_sort(words);

    for (auto w : words) {
        std::cout << w << ", ";
    }
    return 0;
}

