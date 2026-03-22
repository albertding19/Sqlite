
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

typedef struct {
    // std::string is a char * that handles allocation/resizing/deallocation for you
    // and also tracks length which is accessible using std::string.size()
    // we always need a buffer to store the inputs given in an input file.
    std::string buffer;
} InputBuffer;

enum class MetaCommandResult
{
    SUCCESS,
    UNRECOGNIZED_COMMAND,
};

enum class StatementType {
    SELECT,
    INSERT,
};

enum class StatementPrepareResult {
    SUCCESS,
    UNRECONGNIZED_STATEMENT,
};

typedef struct {
    StatementType type;
} Statement;

static void print_prompt() {
    std::cout << "db > ";
}

static void read_input(InputBuffer &input) {

    // getline(buf, buflen, input) reads a line from input and updates buf with the read line
    // getline expands buf as needed as if with a realloc. buflen is extended by the number of characters read.
    // If buf is a null pointer, then mallocs.

    if (!std::getline(std::cin, input.buffer)) {
        std::cout << "Error reading input";
        exit(EXIT_FAILURE);
    }
}

static MetaCommandResult do_meta_command(const InputBuffer &input_buffer) {
    if (input_buffer.buffer == ".exit") {
        exit(EXIT_SUCCESS);
    } else {
        return MetaCommandResult::UNRECOGNIZED_COMMAND;
    }
}

static StatementPrepareResult prepare_statement(const InputBuffer &input_buffer, Statement &stmt) {
    if (input_buffer.buffer.starts_with("insert")) {
        stmt.type = StatementType::INSERT;
        return StatementPrepareResult::SUCCESS;
    } else if (input_buffer.buffer.starts_with("select")) {
        stmt.type = StatementType::SELECT;
        return StatementPrepareResult::SUCCESS;
    } else {
        return StatementPrepareResult::UNRECONGNIZED_STATEMENT;
    }
}

static void execute_statement(const Statement &stmt) {
    switch (stmt.type) {
        case (StatementType::INSERT):
            std::cout << "This is where we would do an insert";
        case (StatementType::SELECT):
            std::cout << "This is where we would do a select";
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    InputBuffer input_buffer;
    while (true) {
        print_prompt();
        read_input(input_buffer);

        // handle meta commands such as .exit
        if (input_buffer.buffer[0] == '.') {
            switch (do_meta_command(input_buffer)) {
                case (MetaCommandResult::SUCCESS):
                    continue;
                case (MetaCommandResult::UNRECOGNIZED_COMMAND):
                    std::cout << "Unrecognized command" << input_buffer.buffer << '\n';
                    continue;
            }
        }

        // handle keyword commands such as insert and select    
        Statement statement;
        switch (prepare_statement(input_buffer, statement)) {
            case (StatementPrepareResult::SUCCESS):
                // breaks out of the switch
                break;
            case (StatementPrepareResult::UNRECONGNIZED_STATEMENT):
                std:: cout << "Unrecognized keyword at start of " << input_buffer.buffer << '\n';
                continue;
        }

        execute_statement(statement);
        std::cout << "Executed" << std::endl;
    }
}
