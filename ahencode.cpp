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
    if (argc <= 1) {
        processFile("-");
    } else {
        int i;
        if (argv[1] == "-s"){
            i = 2;
        } else {
            i=1;
        }
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
        std::cout << model->encode(*it) << std::endl;
        model->updateModel(*it);
    }
}

int main( int argc, char** argv ) {
    AHEncodeFilter* filter = new AHEncodeFilter();
    filter->filter(argc, argv);
	std::cout.flush();
    return 0;
}
