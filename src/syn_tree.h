#ifndef SYNT_TREE
#define SYNT_TREE
//#include "parser.h"
#include "easy_access.h"

typedef struct SYN_TREE {
    enum {
        TREE_DEF,
        TREE_PKG,
        TREE_IMPORTS,
        TREE_EXPORTS,
        TREE_EOF
    } TREE_TOKEN_TYPE;

    /* SECONDARY TREE FOR IMPORTED FILES */
    struct SYN_TREE** secondary_tree;
    size_t amount_of_secondary_trees;

    /* For TREE_DEF */
    struct SYN_TREE* current_state;
    struct SYN_TREE** syntax_tree_values;
    size_t amount_of_statements;

    /* PKG INFORMATION */
    /* IMPORTED PKG NAME INFORMATION. THIS HAS NOTHING TO DO WITH IMPORTED FILE NAMES */
    size_t amount_of_imported_pkg_names;
    char** imported_pkg_names;
    void** parser_pkg_information; 
    /*
        This parser struct array will be used to check each pkg name
    */

    /* MAIN PKG NAME. THIS HAS NOTHING TO DO WITH ANYTHING RELATED TO IMPORTS */
    char* main_pkg_name;

    /* MAIN PKG IMPORTS */
    size_t amount_of_imports;
    char** import_names;
    //char* current_import_name;
    void** parser_import_information; /*
        This parser struct array will be used to check each import name
        against each ideal in the import_names array
    */

    /* IMPORTED PKG IMPORTS. THIS IS ALL IMPORT INFORMATION TAKEN PLACE IN IMPORTED FILES */
    size_t amount_of_secondary_imports;
    char** secondary_imports;
    void** parser_2_imports; /*
        This parser struct array will be used to check each import name within the parser struct array
        and the secondary_imports array
    */
} SYN_TREE_;

SYN_TREE_* init_syntax_tree(int SYNTAX_TREE_TOKEN_ID);

#endif