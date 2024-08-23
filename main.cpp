#include <iostream>
#include <fstream>
#include <string>

size_t countLines(std::istream &input) {
    std::string line;
    size_t lines = 0;

    // This incrementally gets lines
    while (std::getline(input, line)) {
        ++lines;
    }
    return lines;
}

size_t countWords(std::istream &input) {
    std::string line;
    size_t words = 0;

    while (std::getline(input, line)) {
        bool inWord = false;
        // Iterate through the line
        for (char ch : line) {
            // If it's a white space and we are in a word, we add to the word count (omits whitespace clusters)
            if (isspace(ch)) {
                if (inWord) {
                    ++words;
                    inWord = false;
                }
            } else {
                // We are in a new word
                inWord = true;
            }
        }
        if (inWord) ++words; // Count the last word if not followed by space
    }
    return words;
}

size_t countCharacters(std::istream &input) {
    char ch;
    size_t characters = 0;

    while (input.get(ch)) {
        ++characters;
    }
    return characters;
}

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <option> [filename]" << std::endl;
        std::cerr << "Options: -l (lines), -w (words), -m (characters)" << std::endl;
        return 1;
    }

    std::string option;
    std::string filename;
    bool useStdin = (argc == 2);

    if (argc == 3) {
        option = argv[1];
        filename = argv[2]; // Store the filename from the argument
    } else if (argc == 2) {
        option = argv[1]; // Here the option is the only argument, no filename provided
    }

    std::istream *input;
    std::ifstream file;

    if (useStdin) {
        input = &std::cin;  // Use standard input
    } else {
        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open the file " << filename << std::endl;
            return 1;
        }
        input = &file;
    }

    if (option == "-l") {
        size_t lines = countLines(*input);
        std::cout << lines << std::endl;
    } else if (option == "-w") {
        size_t words = countWords(*input);
        std::cout << words << std::endl;
    } else if (option == "-m") {
        size_t characters = countCharacters(*input);
        std::cout << characters << std::endl;
    } else {
        std::cerr << "Invalid option. Use -l for lines, -w for words, or -m for characters." << std::endl;
        return 1;
    }

    if (!useStdin) {
        file.close();
    }

    return 0;
}
