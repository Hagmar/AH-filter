#ifndef FILTER_H
#define FILTER_H

class Filter {
    protected:
        void processFile(std::string const&);
        void processStream(std::istream&);

        virtual void process(std::string) = 0;

    public:
        void filter(int, char**);
};

#endif
