#ifndef FILTER_H
#define FITLER_H

void processStream(std::istream&);
void processFile(std::string const& filename);
int filter(int argc, char** argv, void (*process)(std::string));

#endif
