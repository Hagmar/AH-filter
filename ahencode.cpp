#include <iostream>
#include "filter.h"
#include "ahencode.h"
#include "adaptiveHuffman.h"

void AHEncodeFilter::process(std::string line){
    AdaptiveHuffmanModel* model = new AdaptiveHuffmanModel;

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
