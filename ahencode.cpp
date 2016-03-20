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
