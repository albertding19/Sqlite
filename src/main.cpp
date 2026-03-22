
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>

typedef struct {
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

static InputBuffer *new_input_buffer() {
    InputBuffer *input_buffer = new InputBuffer;
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    
    return input_buffer;
}

static void print_prompt() {
    std::cout << "db > ";
}

static void read_input(InputBuffer *input_buffer) {

    // getline(buf, buflen, input) reads a line from input and updates buf with the read line
    // getline expands buf as needed as if with a realloc. buflen is extended by the number of characters read.
    // If buf is a null pointer, then mallocs.
    ssize_t bytes_read = 
        getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (bytes_read <= 0) {
        std::cout << "Error reading input\n";
        exit(EXIT_FAILURE);
    }

    input_buffer->input_length = bytes_read -1;
    input_buffer->buffer[bytes_read - 1] = '\0';
}

static void close_input_buffer(InputBuffer *input_buffer) {
    free(input_buffer->buffer);
    delete input_buffer;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    InputBuffer *input_buffer = new_input_buffer();
    while (true) {
        print_prompt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command '%s' .\n", input_buffer->buffer);
        }
    }
}
