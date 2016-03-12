#ifndef AHENCODE_H
#define AHENCODE_H

#include "filter.h"

class AHEncodeFilter: public Filter {
    private:
        bool split;

        void process(std::string);
};

int main(int argc, char** argv);

#endif
