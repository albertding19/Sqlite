
#include "commands.h"

MetaCommandResult do_meta_command(const InputBuffer &input_buffer) {
    if (input_buffer.buffer == ".exit") {
        exit(EXIT_SUCCESS);
    } else {
        return MetaCommandResult::UNRECOGNIZED_COMMAND;
    }
}

StatementPrepareResult prepare_statement(const InputBuffer &input_buffer, Statement &stmt) {
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

void execute_statement(const Statement &stmt) {
    switch (stmt.type) {
        case (StatementType::INSERT):
            std::cout << "This is where we would do an insert" << "\n";
            break;
        case (StatementType::SELECT):
            std::cout << "This is where we would do a select" << "\n";
            break;
    }
}