#include <iostream>
#include <fstream>
#include "filter.h"

int returnCode = 0;

void process(std::istream& stream){
	std::string line;
	while (getline(stream, line)){
		std::cout << line << std::endl;
	}
}

void processFile( std::string const& filename )
{
    if ( filename == "-" ) {
        process( std::cin );
    } else {
        std::ifstream in( filename.c_str() );
        if ( !in.is_open() ) {
            std::cerr << "Error: cannot open " << filename << std::endl;
            returnCode = 1;
        } else {
            process( in );
        }
    }
}

int main( int argc, char** argv )
{
    if ( argc == 1 ) {
        processFile( "-" );
    } else {
        for ( int i = 1; i != argc; ++ i ) {
            processFile( argv[i] );
        }
    }
    std::cout.flush();
    return std::cout ? returnCode : 2;
}
