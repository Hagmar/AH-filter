#include <iostream>
#include "filter.h"
#include "ahencode.h"
#include "adaptiveHuffman.h"

AHEncodeFilter::AHEncodeFilter() {
    split = false;
}

AHEncodeFilter::AHEncodeFilter(bool s) {
    split = s;
}

// Overrides the filter function to add support for the "-s" option
void AHEncodeFilter::filter(int argc, char** argv) {
    if (argc <= 1 || (split && argc == 2)) {
        processFile("-");
    } else {
        int i = split ? 2 : 1;

        for (; i != argc; i++) {
            processFile(argv[i]);
        }
    }
    std::cout.flush();
}

// The encoding filter's way of processing lines of input
// Iterate through all characters in the line, encoding them with the current
// Huffman tree and printing to stdout before updating the model with the new
// character. Inserts spaces between encoded characters if "-s" is provided
void AHEncodeFilter::process(std::string line){
    AdaptiveHuffmanModel* model = new AdaptiveHuffmanModel(split);

    std::string::iterator it = line.begin();
    for (; it != line.end(); ++it){
        std::cout << model->encode(*it);
        model->updateModel(*it);

        if (split && it+1 != line.end()){
            std::cout << " ";
        }
    }
    delete model;
    std::cout << std::endl;
}

// Determine whether to split encoded characters with a space, and then
// process all input
int main( int argc, char** argv ) {
    bool split = false;
    if (argc > 1){
        if (std::string(argv[1]) == "-s"){
            split = true;
        }
    }

    AHEncodeFilter* filter = new AHEncodeFilter(split);
    filter->filter(argc, argv);
	std::cout.flush();
    return 0;
}
