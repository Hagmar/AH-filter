#ifndef AHDECODE_H
#define AHDECODE_H

#include "filter.h"

class AHDecodeFilter: public Filter {
    private:
        bool split;

        void process(std::string);
};

int main(int argc, char** argv);

#endif
