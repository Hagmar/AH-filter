#include <iostream>
#include <fstream>
#include "filter.h"

int returnCode = 0;

void process(std::istream& stream){
	char line[50];
	std::string line2;
	while (getline(stream, line2)){
		//stream.get(line, 50);
		std::cout << line2 << std::endl;
	}
	//std::string a;
	//stream >> a;
	//std::cout << a << std::endl;
}

void processFile( std::string const& filename )
{
    if ( filename == "-" ) {
        process( std::cin );
    } else {
        std::ifstream in( filename.c_str() );
        if ( !in.is_open() ) {
            //std::cerr << argv[0] << ": cannot open " << filename << std::endl;
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
