
#pragma once

#include <string>
#include <iostream>

typedef struct {
    // std::string is a char * that handles allocation/resizing/deallocation for you
    // and also tracks length which is accessible using std::string.size()
    // we always need a buffer to store the inputs given in an input file.
    std::string buffer;
} InputBuffer;

void print_prompt();

void read_input(InputBuffer &input);