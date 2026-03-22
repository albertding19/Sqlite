
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include "commands.h"
#include "IO.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    InputBuffer input_buffer{};
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
        Statement statement{};
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
