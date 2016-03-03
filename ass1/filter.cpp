#include <iostream>
#include <fstream>
#include "filter.h"

int returnCode = 0;

void processStream(std::istream& stream, void (*process)(std::string)){
	std::string line;
	while (getline(stream, line)){
		std::cout << line << std::endl;
	}
}

void processFile( std::string const& filename, void (*process)(std::string) ) {
    if ( filename == "-" ) {
        processStream( std::cin, process );
    } else {
        std::ifstream in( filename.c_str() );
        if ( !in.is_open() ) {
            std::cerr << "Error: cannot open " << filename << std::endl;
            returnCode = 1;
        } else {
            processStream( in, process );
        }
    }
}

int filter( int argc, char** argv, void (*process)(std::string) ) {
    if ( argc == 1 ) {
        processFile( "-", process );
    } else {
        for ( int i = 1; i != argc; i++ ) {
            processFile( argv[i], process );
        }
    }
    std::cout.flush();
    return std::cout ? returnCode : 2;
}
