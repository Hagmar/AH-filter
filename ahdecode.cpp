#include <iostream>
#include "filter.h"
#include "ahencode.h"

void AHEncodeFilter::process(std::string line){
    std::cout << line << std::endl;
}

int main( int argc, char** argv ) {
    AHEncodeFilter* filter = new AHEncodeFilter();
    filter->filter(argc, argv);
	std::cout.flush();
    return 0;
}
