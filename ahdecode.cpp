#include <iostream>
#include "filter.h"
#include "ahdecode.h"
#include "adaptiveHuffman.h"

AHDecodeFilter::AHDecodeFilter() {
    split = false;
}

AHDecodeFilter::AHDecodeFilter(bool s) {
    split = s;
}

void AHDecodeFilter::filter(int argc, char** argv) {
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

// TODO obviously
void AHDecodeFilter::process(std::string line){
    AdaptiveHuffmanModel* model = new AdaptiveHuffmanModel(split);
    std::cout << model->decode(line) << std::endl;
}

// TODO Is -s allowed for decoder?
int main( int argc, char** argv ) {
    bool split = false;
    if (argc > 1){
        if (std::string(argv[1]) == "-s"){
            split = true;
        }
    }

    AHDecodeFilter* filter = new AHDecodeFilter(split);
    filter->filter(argc, argv);
	std::cout.flush();
    return 0;
}
