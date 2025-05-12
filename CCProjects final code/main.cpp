#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astnode.h"

extern FILE *yyin;
extern int yyparse();

void print_welcome() {
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                                                            ║\n");
    printf("║                     TASKY Language                         ║\n");
    printf("║          System Automation Made Simple                     ║\n");
    printf("║                                                            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    printf("Type your commands below or use 'exit' to quit:\n");
}

void print_help() {
    printf("\nTASKY Language Help:\n");
    printf("-------------------\n");
    printf("Basic Commands:\n");
    printf("  make new folder inside \"path\" named \"foldername\"\n");
    printf("  place \"text\" inside \"filename\"\n");
    printf("  add \"content\" at end of \"filename\"\n");
    printf("  remove file \"filename\"\n");
    printf("  remove folder \"foldername\"\n");
    printf("  show file in \"path\"\n\n");
    
    printf("Conditional Operations:\n");
    printf("  remove all .ext containing \"pattern\" in \"path\"\n");
    printf("  delete \"file\" if \"checkfile\" contain content of \"patternfile\"\n\n");
    
    printf("Batch Operations:\n");
    printf("  change extension of all .oldext into .newext\n");
    printf("  repeat from 1 until 10: make file named \"template_#\"\n");
    printf("  compress all .ext in \"path\"\n");
    printf("  rename all in \"path\" with prefix \"prefix_\"\n");
    printf("  count .ext in \"path\"\n\n");
    
    printf("Additional Commands:\n");
    printf("  write \"text\" to \"filename\"    - Same as place\n");
    printf("  append \"text\" to \"filename\"   - Same as add at end of\n");
    printf("  search for \"pattern\" in \"path\"\n");
    printf("  run \"command\"                  - Run system command\n\n");
    
    printf("Use 'help' to show this help text\n");
    printf("Use 'exit' to quit\n\n");
}

int main(int argc, char **argv) {
    print_welcome();
    print_help();
    
    // File mode
    if (argc > 1) {
        printf("Reading from file: %s\n", argv[1]);
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
        yyin = file;
        yyparse();
        fclose(file);
        return 0;
    }
    
    // Interactive mode
    char buffer[4096];
    FILE *temp_file = NULL;
    
    while (1) {
        printf("\nTASKY> ");
        
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            break;
        }
        
        // Remove trailing newline
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        
        // Check for exit command
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        
        // Check for help command
        if (strcmp(buffer, "help") == 0) {
            print_help();
            continue;
        }
        
        // Create temporary file for parsing
        temp_file = tmpfile();
        if (!temp_file) {
            perror("Error creating temporary file");
            return 1;
        }
        
        // Write command to temp file
        fputs(buffer, temp_file);
        rewind(temp_file);
        
        // Parse the command
        yyin = temp_file;
        yyparse();
        
        // Close temp file
        fclose(temp_file);
    }
    
    printf("\nThank you for using TASKY!\n");
    return 0;
}
