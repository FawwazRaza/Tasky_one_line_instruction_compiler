#ifndef ASTNODE_H
#define ASTNODE_H

#include <stddef.h>

// Abstract Syntax Tree Node
typedef struct ASTNode {
    char *cmd;           // Command name
    char *arg1;          // First argument
    char *arg2;          // Second argument
    char *arg3;          // Third argument
    int num1;            // First numeric argument
    int num2;            // Second numeric argument
    struct ASTNode *next; // Next node in sequence
} ASTNode;

#endif // ASTNODE_H