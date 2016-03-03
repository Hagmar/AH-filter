#include <iostream>
#include <fstream>
#include "filter.h"

void processStream(std::istream& stream, void (*process)(std::string)){
    std::string line;
    while (getline(stream, line)){
        process(line);
    }
}

int processFile( std::string const& filename, void (*process)(std::string) ) {
    if ( filename == "-" ) {
        processStream( std::cin, process );
    } else {
        std::ifstream in( filename.c_str() );
        if ( !in.is_open() ) {
            std::cerr << "Error: cannot open " << filename << std::endl;
            return 1;
        } else {
            processStream( in, process );
        }
    }
    return 0;
}

int filter( int argc, char** argv, void (*process)(std::string) ) {
    int returnValue;
    if ( argc == 1 ) {
        returnValue = processFile( "-", process );
    } else {
        for ( int i = 1; i != argc; i++ ) {
            returnValue = processFile( argv[i], process );
        }
    }
    std::cout.flush();
    return returnValue;
}
