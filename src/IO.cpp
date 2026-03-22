
#include "IO.h"

void print_prompt() {
    std::cout << "db > ";
}

void read_input(InputBuffer &input) {

    // getline(buf, buflen, input) reads a line from input and updates buf with the read line
    // getline expands buf as needed as if with a realloc. buflen is extended by the number of characters read.
    // If buf is a null pointer, then mallocs.

    if (!std::getline(std::cin, input.buffer)) {
        std::cout << "Error reading input";
        exit(EXIT_FAILURE);
    }
}