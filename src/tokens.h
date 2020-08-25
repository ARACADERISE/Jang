#ifndef TOKENS
#define TOKENS

typedef struct Tokens {
    enum {
        TOKEN_ID,
        TOKEN_LEFT_CURL,
        TOKEN_RIGHT_CURL,
        PKG_KEYWORD,
        TOKEN_EOF
    } token_id;
    char* token_value;
} Tokens_;

Tokens_* init_token(int token_id, char* value);

#define raise_error(errmsg, ...) \
fprintf(stderr,errmsg, ##__VA_ARGS__);\
fflush(stderr);\
exit(EXIT_FAILURE)\

#endif