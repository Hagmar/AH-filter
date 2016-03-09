#include <iostream>
#include "filter.h"
#include "ahencode.h"

void AHEncodeFilter::process(std::string line){
    std::cout << line << std::endl;
}

int main( int argc, char** argv ) {
	std::cout.flush();
    return 0;
}
