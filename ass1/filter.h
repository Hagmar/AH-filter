#ifndef FILTER_H
#define FITLER_H

void processStream(std::istream&);
int processFile(std::string const&);
int filter(int, char**, void (*)(std::string));

#endif
