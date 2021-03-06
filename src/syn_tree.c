#include "syn_tree.h"

SYN_TREE_* init_syntax_tree(int SYNTAX_TREE_TOKEN_ID) {
    SYN_TREE_* syntax_tree = calloc(1,sizeof(*syntax_tree));

    switch(SYNTAX_TREE_TOKEN_ID) {
        /* This switch statement is used to make sure the SYNTAX_TREE_TOKEN_ID is an actual Token Id or not */
        case TREE_PKG:
        case TREE_EXPORTS:
        case TREE_IMPORTS:
        case TREE_EOF:
        case TREE_DEF: {
            goto continue_;
            break;
        }
        default: {
            raise_error("\nAST Tokens do not match");
        }
    }
    continue_:
    syntax_tree->secondary_tree = calloc(1,sizeof(*syntax_tree->secondary_tree));
    syntax_tree->amount_of_secondary_trees = 0;

    syntax_tree->TREE_TOKEN_TYPE = SYNTAX_TREE_TOKEN_ID;
    syntax_tree->amount_of_statements = 0;
    syntax_tree->current_state = (void*)0;
    syntax_tree->syntax_tree_values = (void*)0;

    /* IMPORTED PKG NAME INFORMATION. THIS HAS NOTHING TO DO WITH IMPORTED FILE NAMES */
    //syntax_tree->amount_of_imported_pkg_names = 0;
    //syntax_tree->imported_pkg_names = calloc(1,sizeof(*syntax_tree->import_names));
    //syntax_tree->parser_pkg_information = calloc(1,sizeof(*syntax_tree->parser_pkg_information));
    
    /* MAIN PKG NAME. THIS HAS NOTHING TO DO WITH ANYTHING RELATED TO IMPORTS */
    syntax_tree->main_pkg_name = (void*)0;

    /* MAIN PKG IMPORTS */
    syntax_tree->amount_of_imports = 0;
    syntax_tree->import_names = calloc(1,sizeof(*syntax_tree->import_names));
    syntax_tree->parser_import_information = calloc(1,sizeof(*syntax_tree->parser_import_information));

    /* IMPORTED PKG IMPORTS. THIS IS ALL IMPORT INFORMATION TAKEN PLACE IN IMPORTED FILES */
    syntax_tree->amount_of_secondary_imports = 0;
    syntax_tree->secondary_imports = calloc(1,sizeof(*syntax_tree->secondary_imports));
    syntax_tree->parser_2_imports = calloc(1,sizeof(*syntax_tree->parser_2_imports));

    return syntax_tree;
}

/* Set the currently active file(or the file that is running) based off of the package name. */
SYN_TREE_* set_active_package(SYN_TREE_* syntax_tree) {
    return syntax_tree;
}