#include <iostream>
#include "filter.h"
#include "ahdecode.h"

void AHDecodeFilter::process(std::string line){
    std::cout << line << std::endl;
}

int main( int argc, char** argv ) {
    AHDecodeFilter* filter = new AHDecodeFilter;
    filter->filter(argc, argv);
	std::cout.flush();
    return 0;
}
