#ifndef AHDECODE_H
#define AHDECODE_H

#include "filter.h"

class AHDecodeFilter: public Filter {
    private:
        bool split;

        void process(std::string);

    public:
        AHDecodeFilter();
        AHDecodeFilter(bool);

        void filter(int, char**);
};

int main(int argc, char** argv);

#endif
