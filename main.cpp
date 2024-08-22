#include <iostream>
#include <fstream>
#include <string>

void countLines(std::ifstream &file) {
    std::string line;
    size_t lines = 0;

    //This incrementally gets lines
    while (std::getline(file, line)) {
        ++lines;
    }

    std::cout << "Lines: " << lines << std::endl;
}

void countWords(std::ifstream &file) {
    std::string line;
    size_t words = 0;

    while (std::getline(file, line)) {
        bool inWord = false;
        //Iterate through the line
        for (char ch : line) {
            //If is a white space and it is not in a word, we add the word count (omits whitespace cluster)
            if (isspace(ch)) {
                if (inWord) {
                    ++words;
                    inWord = false;
                }
            } else {
                //We are in a new word
                inWord = true;
            }
        }
        if (inWord) ++words; //In the end we have an uncounted word
    }

    std::cout << "Words: " << words << std::endl;
}

void countCharacters(std::ifstream &file) {
    std::string line;
    size_t characters = 0;

    while (std::getline(file, line)) {
        characters += line.length() + 1; // +1 for the newline character
    }

    std::cout << "Characters: " << characters << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <option> <filename>" << std::endl;
        std::cerr << "Options: -l (lines), -w (words), -c (characters)" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::ifstream file(argv[2]);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << argv[2] << std::endl;
        return 1;
    }

    if (option == "-l") {
        countLines(file);
    } else if (option == "-w") {
        countWords(file);
    } else if (option == "-c") {
        countCharacters(file);
    } else {
        std::cerr << "Invalid option. Use -l for lines, -w for words, or -c for characters." << std::endl;
        return 1;
    }

    file.close();
    return 0;
}
