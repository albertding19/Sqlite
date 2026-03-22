
#pragma once
#include "IO.h"
#include <string>
#include <cstdlib>

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

MetaCommandResult do_meta_command(const InputBuffer &input_buffer);

StatementPrepareResult prepare_statement(const InputBuffer &input_buffer, Statement &stmt);

StatementPrepareResult prepare_statement(const InputBuffer &input_buffer, Statement &stmt);

void execute_statement(const Statement &stmt);


