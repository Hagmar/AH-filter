#include <iostream>
#include <fstream>
#include "filter.h"

void Filter::processStream(std::istream& stream){
    std::string line;
    while (getline(stream, line)){
        process(line);
    }
}

void Filter::processFile(std::string const& filename) {
    if (filename == "-") {
        processStream(std::cin);
    } else {
        std::ifstream in(filename.c_str());
        if (!in.is_open()) {
            std::cerr << "Error: cannot open " << filename << std::endl;
        } else {
            processStream(in);
        }
    }
}

void Filter::filter(int argc, char** argv) {
    if (argc == 1) {
        processFile("-");
    } else {
        for (int i = 1; i != argc; i++) {
            processFile(argv[i]);
        }
    }
    std::cout.flush();
}
