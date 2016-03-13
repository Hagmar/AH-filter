#ifndef AHENCODE_H
#define AHENCODE_H

#include "filter.h"

class AHEncodeFilter: public Filter {
    private:
        bool split;

        void process(std::string);

    public:
        AHEncodeFilter();
        AHEncodeFilter(bool);

        void filter(int, char**);
};

int main(int argc, char** argv);

#endif
