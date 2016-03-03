#include <iostream>
#include "filter.h"

int returnCode = 0;

void process(std::string line){
    std::cout << line << std::endl;
}

int main( int argc, char** argv ) {
	filter(argc, argv, &process);
	std::cout.flush();
	return std::cout ? returnCode : 2;
}
