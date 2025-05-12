%{
#include "astnode.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <ftw.h>
#include <climits>    // For LONG_MAX
#include <ctime>      // For localtime and strftime
#include <map>        // For std::map
#include <string>     // For std::string

// Removed dependency on archive.h and archive_entry.h

#ifdef __cplusplus
extern "C" int yylex();
#endif

extern FILE* yyin;
void yyerror(const char *s);
void execute(ASTNode* node);
ASTNode* make_node(const char* cmd, const char* arg1, const char* arg2, const char* arg3, int num1, int num2);

// Command implementation functions
void cmd_make_folder(const char* path, const char* name);
void cmd_place_text(const char* text, const char* file);
void cmd_add_file(const char* content, const char* file);
void cmd_remove_file(const char* file);
void cmd_remove_folder(const char* folder);
void cmd_show_files(const char* folder);
void cmd_remove_all_containing(const char* ext, const char* pattern, const char* folder);
void cmd_delete_if_contains(const char* file, const char* check_file, const char* pattern);
void cmd_change_extension(const char* ext, const char* new_ext);
void cmd_repeat_make_file(const char* filename, int start, int end);
void cmd_compress_all(const char* ext, const char* folder);
void cmd_rename_with_prefix(const char* folder, const char* prefix);
void cmd_count_in(const char* ext, const char* folder);
void cmd_run_command(const char* command);
void cmd_search_for(const char* pattern, const char* folder);
void cmd_append_to(const char* content, const char* file);
void cmd_create_from_template(const char* template_file, const char* vars_file);
void cmd_batch_process(const char* cmd, const char* pattern, const char* dir);
void cmd_file_stats(const char* extension, const char* folder);
void cmd_move_large_files(const char* src_dir, const char* dest_dir, int size_thresh);
void cmd_transform_content(const char* filename, const char* regex, const char* replacement);
void cmd_remove_lines(const char* filename, int n);
void cmd_sort_by_size(const char* ext, const char* folder);
void cmd_sort_by_date(const char* ext, const char* folder);
void cmd_conditional_move(const char* file, const char* pattern, const char* dest);
void cmd_calculate_add(int num1, int num2, const char* result_var);
void cmd_calculate_subtract(int num1, int num2, const char* result_var);
void cmd_calculate_multiply(int num1, int num2, const char* result_var);
void cmd_calculate_divide(int num1, int num2, const char* result_var);
void cmd_calculate_modulo(int num1, int num2, const char* result_var);
void cmd_calculate_power(int num1, int num2, const char* result_var);
void cmd_print_value(const char* var_name);
void cmd_calculate_var_add(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_subtract(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_multiply(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_divide(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_modulo(const char* var1, const char* var2, const char* result_var);
void cmd_calculate_var_power(const char* var1, const char* var2, const char* result_var);
void cmd_store_number(int value, const char* var_name);
%}

%union {
    char *str;
    int num;
    ASTNode *node;
}

%token MAKE NEW FOLDER FILEKW INSIDE NAMED PLACE ADD AT END REMOVE SHOW IN ALL 
%token CONTAINING DELETE IF CONTAIN CONTENT OF CHANGE EXTENSION INTO REPEAT 
%token FROM UNTIL COMPRESS RENAME WITH PREFIX COUNT RUN WRITE TO APPEND SEARCH FOR
%token TEMPLATE VARIABLES BATCH PROCESS STATS LARGER THAN TRANSFORM USING REGEX 
%token REPLACE EVERY LINES SIZE WHEN MOVE SORT BY DATE
%token CREATE
%token SUBTRACT MULTIPLY DIVIDE CALCULATE STORE RESULT VALUE PRINT AND MOD POWER
%token EQUALS PLUS MINUS TIMES DIV MODULO POW
%token <str> STRING IDENTIFIER
%token <num> NUMBER

%type <node> command command_list

%%

input: command_list { execute($1); }
     ;

command_list: command { $$ = $1; }
            | command_list command { 
                ASTNode *ptr = $1; 
                while(ptr->next) ptr = ptr->next; 
                ptr->next = $2; 
                $$ = $1; 
            }
            ;

command:
      MAKE NEW FOLDER INSIDE STRING NAMED STRING
        { $$ = make_node("make_folder", $5, $7, NULL, 0, 0); }
    | PLACE STRING INSIDE STRING
        { $$ = make_node("place_text", $2, $4, NULL, 0, 0); }
    | ADD STRING AT END OF STRING
        { $$ = make_node("add_file", $2, $6, NULL, 0, 0); }
    | REMOVE FILEKW STRING
        { $$ = make_node("remove_file", $3, NULL, NULL, 0, 0); }
    | REMOVE FOLDER STRING
        { $$ = make_node("remove_folder", $3, NULL, NULL, 0, 0); }
    | SHOW FILEKW IN STRING
        { $$ = make_node("show_files", $4, NULL, NULL, 0, 0); }
    | REMOVE ALL STRING CONTAINING STRING IN STRING
        { $$ = make_node("remove_all_containing", $3, $5, $7, 0, 0); }
    | DELETE STRING IF STRING CONTAIN CONTENT OF STRING
        { $$ = make_node("delete_if_contains", $2, $4, $8, 0, 0); }
    | CHANGE EXTENSION OF ALL STRING INTO STRING
        { $$ = make_node("change_extension", $5, $7, NULL, 0, 0); }
    | REPEAT FROM NUMBER UNTIL NUMBER ':' MAKE FILEKW NAMED STRING
        { $$ = make_node("repeat_make_file", $10, NULL, NULL, $3, $5); }
    | COMPRESS ALL STRING IN STRING
        { $$ = make_node("compress_all", $3, $5, NULL, 0, 0); }
    | RENAME ALL IN STRING WITH PREFIX STRING
        { $$ = make_node("rename_with_prefix", $4, $7, NULL, 0, 0); }
    | COUNT STRING IN STRING
        { $$ = make_node("count_in", $2, $4, NULL, 0, 0); }
    | RUN STRING
        { $$ = make_node("run_command", $2, NULL, NULL, 0, 0); }
    | WRITE STRING TO STRING
        { $$ = make_node("place_text", $2, $4, NULL, 0, 0); }
    | APPEND STRING TO STRING
        { $$ = make_node("append_to", $2, $4, NULL, 0, 0); }
    | SEARCH FOR STRING IN STRING
        { $$ = make_node("search_for", $3, $5, NULL, 0, 0); }
     | CREATE FILEKW FROM TEMPLATE STRING WITH VARIABLES STRING
        { $$ = make_node("create_from_template", $5, $8, NULL, 0, 0); }
    | BATCH PROCESS STRING WITH STRING IN STRING
        { $$ = make_node("batch_process", $3, $5, $7, 0, 0); }
    | STATS OF STRING IN STRING
        { $$ = make_node("file_stats", $3, $5, NULL, 0, 0); }
    | MOVE ALL LARGER THAN NUMBER IN STRING TO STRING
        { $$ = make_node("move_large_files", $7, $9, NULL, $5, 0); }
    | TRANSFORM STRING USING REGEX STRING REPLACE STRING
        { $$ = make_node("transform_content", $2, $5, $7, 0, 0); }
    | REMOVE EVERY NUMBER LINES FROM STRING
        { $$ = make_node("remove_lines", $6, NULL, NULL, $3, 0); }
    | SORT STRING BY SIZE IN STRING
        { $$ = make_node("sort_by_size", $2, $6, NULL, 0, 0); }
    | SORT STRING BY DATE IN STRING
        { $$ = make_node("sort_by_date", $2, $6, NULL, 0, 0); }
    | WHEN STRING CONTAIN STRING ':' MOVE TO STRING
        { $$ = make_node("conditional_move", $2, $4, $8, 0, 0); }
    | CALCULATE NUMBER PLUS NUMBER STORE RESULT IN STRING
        { $$ = make_node("calculate_add", NULL, $8, NULL, $2, $4); }
    | CALCULATE NUMBER MINUS NUMBER STORE RESULT IN STRING
        { $$ = make_node("calculate_subtract", NULL, $8, NULL, $2, $4); }
    | CALCULATE NUMBER TIMES NUMBER STORE RESULT IN STRING
        { $$ = make_node("calculate_multiply", NULL, $8, NULL, $2, $4); }
    | CALCULATE NUMBER DIV NUMBER STORE RESULT IN STRING
        { $$ = make_node("calculate_divide", NULL, $8, NULL, $2, $4); }
    | CALCULATE NUMBER MODULO NUMBER STORE RESULT IN STRING
        { $$ = make_node("calculate_modulo", NULL, $8, NULL, $2, $4); }
    | CALCULATE NUMBER POW NUMBER STORE RESULT IN STRING
        { $$ = make_node("calculate_power", NULL, $8, NULL, $2, $4); }
    | PRINT VALUE OF STRING
        { $$ = make_node("print_value", $4, NULL, NULL, 0, 0); }
    | CALCULATE STRING PLUS STRING STORE RESULT IN STRING
        { $$ = make_node("calculate_var_add", $2, $4, $8, 0, 0); }
    | CALCULATE STRING MINUS STRING STORE RESULT IN STRING
        { $$ = make_node("calculate_var_subtract", $2, $4, $8, 0, 0); }
    | CALCULATE STRING TIMES STRING STORE RESULT IN STRING
        { $$ = make_node("calculate_var_multiply", $2, $4, $8, 0, 0); }
    | CALCULATE STRING DIV STRING STORE RESULT IN STRING
        { $$ = make_node("calculate_var_divide", $2, $4, $8, 0, 0); }
    | CALCULATE STRING MODULO STRING STORE RESULT IN STRING
        { $$ = make_node("calculate_var_modulo", $2, $4, $8, 0, 0); }
    | CALCULATE STRING POW STRING STORE RESULT IN STRING
        { $$ = make_node("calculate_var_power", $2, $4, $8, 0, 0); }
    | STORE NUMBER IN STRING
        { $$ = make_node("store_number", $4, NULL, NULL, $2, 0); }
    ;

%%

ASTNode *make_node(const char *cmd, const char *arg1, const char *arg2, const char *arg3, int num1, int num2) {
    ASTNode *n = (ASTNode*)calloc(1, sizeof(ASTNode));
    n->cmd = strdup(cmd);
    if(arg1) n->arg1 = strdup(arg1);
    if(arg2) n->arg2 = strdup(arg2);
    if(arg3) n->arg3 = strdup(arg3);
    n->num1 = num1;
    n->num2 = num2;
    n->next = NULL;
    return n;
}

// Helper function to ensure directory exists for a file
void ensure_directory(const char *path) {
    char *dir_path = strdup(path);
    char *dir = dirname(dir_path);
    
    // Check if directory exists
    struct stat st = {0};
    if (stat(dir, &st) == -1) {
        // Create directory recursively
        char cmd[1024];
        snprintf(cmd, sizeof(cmd), "mkdir -p %s", dir);
        system(cmd);
    }
    
    free(dir_path);
}

// Command implementations
void cmd_make_folder(const char* path, const char* name) {
    char full_path[1024];
    snprintf(full_path, sizeof(full_path), "%s/%s", path, name);
    
    printf("Creating folder: %s\n", full_path);
    
    // Create directory with rwx permissions for user
    if (mkdir(full_path, 0755) != 0) {
        if (errno != EEXIST) {
            perror("Error creating folder");
        } else {
            printf("Folder already exists\n");
        }
    } else {
        printf("Folder created successfully\n");
    }
}
void cmd_create_from_template(const char* template_file, const char* vars_file) {
    printf("Creating file from template '%s' with variables from '%s'\n", template_file, vars_file);
    
    // Read template file
    FILE* tf = fopen(template_file, "r");
    if (!tf) {
        perror("Cannot open template file");
        return;
    }
    
    // Read variables file
    FILE* vf = fopen(vars_file, "r");
    if (!vf) {
        perror("Cannot open variables file");
        fclose(tf);
        return;
    }
    
    // Get output filename from template (remove .template extension)
    char out_filename[256];
    strcpy(out_filename, template_file);
    char* dot = strrchr(out_filename, '.');
    if (dot && strcmp(dot, ".template") == 0) {
        *dot = '\0';
    } else {
        strcat(out_filename, ".output");
    }
    
    // Open output file
    FILE* of = fopen(out_filename, "w");
    if (!of) {
        perror("Cannot create output file");
        fclose(tf);
        fclose(vf);
        return;
    }
    
    // Read variables into memory
    char vars[50][256];
    char values[50][256];
    int var_count = 0;
    
    char line[512];
    while (fgets(line, sizeof(line), vf) && var_count < 50) {
        // Trim newline
        char* nl = strchr(line, '\n');
        if (nl) *nl = '\0';
        
        // Split by = sign
        char* eq = strchr(line, '=');
        if (eq) {
            *eq = '\0';
            strcpy(vars[var_count], line);
            strcpy(values[var_count], eq + 1);
            var_count++;
        }
    }
    
    // Process template file line by line
    while (fgets(line, sizeof(line), tf)) {
        // Process variables
        for (int i = 0; i < var_count; i++) {
            char var_token[300];
            sprintf(var_token, "{{%s}}", vars[i]);
            
            char* pos;
            while ((pos = strstr(line, var_token)) != NULL) {
                // Replace variable token with its value
                char before[512] = {0};
                strncpy(before, line, pos - line);
                
                char after[512] = {0};
                strcpy(after, pos + strlen(var_token));
                
                sprintf(line, "%s%s%s", before, values[i], after);
            }
        }
        
        // Write processed line to output
        fputs(line, of);
    }
    
    fclose(tf);
    fclose(vf);
    fclose(of);
    
    printf("Created file: %s\n", out_filename);
}

void cmd_batch_process(const char* cmd, const char* pattern, const char* dir) {
    printf("Batch processing files matching '%s' in '%s' with command '%s'\n", pattern, dir, cmd);
    
    DIR* d = opendir(dir);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    int files_processed = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            if (strstr(entry->d_name, pattern)) {
                char full_path[512];
                sprintf(full_path, "%s/%s", dir, entry->d_name);
                
                // Create and execute command
                char full_cmd[1024];
                sprintf(full_cmd, "%s \"%s\"", cmd, full_path);
                printf("Executing: %s\n", full_cmd);
                
                int result = system(full_cmd);
                if (result == 0) {
                    files_processed++;
                } else {
                    printf("Command failed with code %d\n", result);
                }
            }
        }
    }
    
    closedir(d);
    printf("Processed %d files\n", files_processed);
}

void cmd_file_stats(const char* extension, const char* folder) {
    printf("Gathering stats for files with extension '%s' in '%s'\n", extension, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    int file_count = 0;
    long total_size = 0;
    long smallest = LONG_MAX;
    long largest = 0;
    char smallest_file[256] = {0};
    char largest_file[256] = {0};
    
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            // Check if file has the right extension
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, extension) == 0) {
                char full_path[512];
                sprintf(full_path, "%s/%s", folder, entry->d_name);
                
                struct stat st;
                if (stat(full_path, &st) == 0) {
                    file_count++;
                    total_size += st.st_size;
                    
                    if (st.st_size < smallest) {
                        smallest = st.st_size;
                        strcpy(smallest_file, entry->d_name);
                    }
                    
                    if (st.st_size > largest) {
                        largest = st.st_size;
                        strcpy(largest_file, entry->d_name);
                    }
                }
            }
        }
    }
    
    closedir(d);
    
    printf("Statistics for '.%s' files in '%s':\n", extension, folder);
    printf("Total files: %d\n", file_count);
    printf("Total size: %ld bytes\n", total_size);
    if (file_count > 0) {
        printf("Average size: %ld bytes\n", total_size / file_count);
        printf("Smallest file: %s (%ld bytes)\n", smallest_file, smallest);
        printf("Largest file: %s (%ld bytes)\n", largest_file, largest);
    }
}

void cmd_move_large_files(const char* src_dir, const char* dest_dir, int size_thresh) {
    printf("Moving files larger than %d bytes from '%s' to '%s'\n", size_thresh, src_dir, dest_dir);
    
    // Make sure destination directory exists
    struct stat st = {0};
    if (stat(dest_dir, &st) == -1) {
        printf("Creating destination directory '%s'\n", dest_dir);
        if (mkdir(dest_dir, 0755) != 0) {
            perror("Failed to create destination directory");
            return;
        }
    }
    
    DIR* d = opendir(src_dir);
    if (!d) {
        perror("Cannot open source directory");
        return;
    }
    
    int files_moved = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            char src_path[512];
            sprintf(src_path, "%s/%s", src_dir, entry->d_name);
            
            struct stat file_stat;
            if (stat(src_path, &file_stat) == 0) {
                if (file_stat.st_size > size_thresh) {
                    char dest_path[512];
                    sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);
                    
                    printf("Moving %s (%ld bytes) to %s\n", src_path, file_stat.st_size, dest_path);
                    
                    if (rename(src_path, dest_path) == 0) {
                        files_moved++;
                    } else {
                        perror("Failed to move file");
                    }
                }
            }
        }
    }
    
    closedir(d);
    printf("Moved %d files\n", files_moved);
}

void cmd_transform_content(const char* filename, const char* regex_str, const char* replacement) {
    printf("Transforming content in '%s' using regex '%s' replacing with '%s'\n", 
           filename, regex_str, replacement);
    
    // Read file content
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("Cannot open file");
        return;
    }
    
    // Read entire file into memory
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    char* buffer = (char*)malloc(file_size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(f);
        return;
    }
    
    size_t bytes_read = fread(buffer, 1, file_size, f);
    buffer[bytes_read] = '\0';
    fclose(f);
    
    // Simple string replace (not a full regex implementation)
    int replacements = 0;
    char* result = (char*)malloc(file_size * 2); // Allow for growth
    char* result_ptr = result;
    char* current = buffer;
    
    while (*current) {
        char* found = strstr(current, regex_str);
        if (found) {
            // Copy up to the match
            size_t len = found - current;
            strncpy(result_ptr, current, len);
            result_ptr += len;
            
            // Add replacement
            strcpy(result_ptr, replacement);
            result_ptr += strlen(replacement);
            
            // Move past the match
            current = found + strlen(regex_str);
            replacements++;
        } else {
            // Copy the rest
            strcpy(result_ptr, current);
            result_ptr += strlen(current);
            break;
        }
    }
    
    // Write back to file
    f = fopen(filename, "w");
    if (!f) {
        perror("Cannot open file for writing");
        free(buffer);
        free(result);
        return;
    }
    
    fputs(result, f);
    fclose(f);
    
    printf("Made %d replacements in the file\n", replacements);
    
    free(buffer);
    free(result);
}

void cmd_remove_lines(const char* filename, int n) {
    printf("Removing every %d lines from file '%s'\n", n, filename);
    
    // Read file content
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("Cannot open file");
        return;
    }
    
    char temp_filename[256];
    sprintf(temp_filename, "%s.tmp", filename);
    FILE* out = fopen(temp_filename, "w");
    if (!out) {
        perror("Cannot create temporary file");
        fclose(f);
        return;
    }
    
    int line_count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        line_count++;
        if (line_count % n != 0) {
            fputs(line, out);
        }
    }
    
    fclose(f);
    fclose(out);
    
    // Replace original with temp file
    if (rename(temp_filename, filename) != 0) {
        perror("Failed to replace original file");
        return;
    }
    
    printf("Processed file, removed lines\n");
}

typedef struct {
    char name[256];
    long size;
    time_t mtime;
} FileInfo;

int compare_by_size(const void* a, const void* b) {
    const FileInfo* fa = (const FileInfo*)a;
    const FileInfo* fb = (const FileInfo*)b;
    return fb->size - fa->size; // Descending order
}

int compare_by_date(const void* a, const void* b) {
    const FileInfo* fa = (const FileInfo*)a;
    const FileInfo* fb = (const FileInfo*)b;
    return fb->mtime - fa->mtime; // Descending order
}

void cmd_sort_by_size(const char* ext, const char* folder) {
    printf("Sorting files with extension '%s' in '%s' by size\n", ext, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    // Count matching files first
    int file_count = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, ext) == 0) {
                file_count++;
            }
        }
    }
    
    rewinddir(d);
    
    // Allocate array for file info
    FileInfo* files = (FileInfo*)malloc(file_count * sizeof(FileInfo));
    if (!files) {
        perror("Memory allocation failed");
        closedir(d);
        return;
    }
    
    // Fill array with file info
    int idx = 0;
    while ((entry = readdir(d)) != NULL && idx < file_count) {
        if (entry->d_type == DT_REG) {
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, ext) == 0) {
                char full_path[512];
                sprintf(full_path, "%s/%s", folder, entry->d_name);
                
                struct stat st;
                if (stat(full_path, &st) == 0) {
                    strcpy(files[idx].name, entry->d_name);
                    files[idx].size = st.st_size;
                    files[idx].mtime = st.st_mtime;
                    idx++;
                }
            }
        }
    }
    
    closedir(d);
    
    // Sort by size
    qsort(files, idx, sizeof(FileInfo), compare_by_size);
    
    // Display results
    printf("Files sorted by size (largest first):\n");
    for (int i = 0; i < idx; i++) {
        printf("%d. %s - %ld bytes\n", i+1, files[i].name, files[i].size);
    }
    
    free(files);
}

void cmd_sort_by_date(const char* ext, const char* folder) {
    printf("Sorting files with extension '%s' in '%s' by date\n", ext, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    // Count matching files first
    int file_count = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, ext) == 0) {
                file_count++;
            }
        }
    }
    
    rewinddir(d);
    
    // Allocate array for file info
    FileInfo* files = (FileInfo*)malloc(file_count * sizeof(FileInfo));
    if (!files) {
        perror("Memory allocation failed");
        closedir(d);
        return;
    }
    
    // Fill array with file info
    int idx = 0;
    while ((entry = readdir(d)) != NULL && idx < file_count) {
        if (entry->d_type == DT_REG) {
            char* dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot + 1, ext) == 0) {
                char full_path[512];
                sprintf(full_path, "%s/%s", folder, entry->d_name);
                
                struct stat st;
                if (stat(full_path, &st) == 0) {
                    strcpy(files[idx].name, entry->d_name);
                    files[idx].size = st.st_size;
                    files[idx].mtime = st.st_mtime;
                    idx++;
                }
            }
        }
    }
    
    closedir(d);
    
    // Sort by date
    qsort(files, idx, sizeof(FileInfo), compare_by_date);
    
    // Display results
    printf("Files sorted by date (newest first):\n");
    for (int i = 0; i < idx; i++) {
        char date_str[64];
        struct tm* timeinfo = localtime(&files[i].mtime);
        strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", timeinfo);
        printf("%d. %s - %s\n", i+1, files[i].name, date_str);
    }
    
    free(files);
}

void cmd_conditional_move(const char* file, const char* pattern, const char* dest) {
    printf("Checking if '%s' contains '%s', if yes, moving to '%s'\n", file, pattern, dest);
    
    // Check if file exists
    FILE* f = fopen(file, "r");
    if (!f) {
        perror("Cannot open file");
        return;
    }
    
    // Read file content
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    char* buffer = (char*)malloc(file_size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(f);
        return;
    }
    
    size_t bytes_read = fread(buffer, 1, file_size, f);
    buffer[bytes_read] = '\0';
    fclose(f);
    
    // Check if pattern is in file
    if (strstr(buffer, pattern)) {
        printf("Pattern found in file, moving...\n");
        
        // Make sure destination directory exists
        struct stat st = {0};
        if (stat(dest, &st) == -1) {
            printf("Creating destination directory '%s'\n", dest);
            if (mkdir(dest, 0755) != 0) {
                perror("Failed to create destination directory");
                free(buffer);
                return;
            }
        }
        
        // Get filename part
const char* filename_const = strrchr(file, '/');
char* filename = filename_const ? const_cast<char*>(filename_const) : const_cast<char*>(file);

        if (filename) {
            filename++; // Skip the '/'
        } else {
            filename = (char*)file; // No path separator, use the whole string
        }
        
        char dest_path[512];
        sprintf(dest_path, "%s/%s", dest, filename);
        
        if (rename(file, dest_path) == 0) {
            printf("Moved '%s' to '%s'\n", file, dest_path);
        } else {
            perror("Failed to move file");
        }
    } else {
        printf("Pattern not found in file, no action taken\n");
    }
    
    free(buffer);
}

void cmd_place_text(const char* text, const char* file) {
    printf("Writing text to file: %s\n", file);
    
    ensure_directory(file);
    
    FILE *fp = fopen(file, "w");
    if (!fp) {
        perror("Error opening file for writing");
        return;
    }
    
    fprintf(fp, "%s", text);
    fclose(fp);
    printf("Text written successfully\n");
}

void cmd_add_file(const char* content, const char* file) {
    printf("Appending text to file: %s\n", file);
    
    ensure_directory(file);
    
    FILE *fp = fopen(file, "a");
    if (!fp) {
        perror("Error opening file for appending");
        return;
    }
    
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("Text appended successfully\n");
}

void cmd_remove_file(const char* file) {
    printf("Removing file: %s\n", file);
    
    if (unlink(file) != 0) {
        perror("Error removing file");
    } else {
        printf("File removed successfully\n");
    }
}

void cmd_remove_folder(const char* folder) {
    printf("Removing folder: %s\n", folder);
    
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "rm -rf %s", folder);
    if (system(cmd) != 0) {
        perror("Error removing folder");
    } else {
        printf("Folder removed successfully\n");
    }
}

void cmd_show_files(const char* folder) {
    printf("Listing files in: %s\n", folder);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    } else {
        perror("Error opening directory");
    }
}

void cmd_remove_all_containing(const char* ext, const char* pattern, const char* folder) {
    printf("Removing all %s files containing '%s' in %s\n", ext, pattern, folder);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, ext) != NULL) {
                char file_path[1024];
                snprintf(file_path, sizeof(file_path), "%s/%s", folder, dir->d_name);
                
                // Check if file contains pattern
                FILE *fp = fopen(file_path, "r");
                if (fp) {
                    char buffer[4096];
                    size_t bytes_read = fread(buffer, 1, sizeof(buffer)-1, fp);
                    buffer[bytes_read] = '\0';
                    fclose(fp);
                    
                    if (strstr(buffer, pattern) != NULL) {
                        printf("Removing file: %s\n", file_path);
                        unlink(file_path);
                    }
                }
            }
        }
        closedir(d);
    } else {
        perror("Error opening directory");
    }
}

void cmd_delete_if_contains(const char* file, const char* check_file, const char* pattern_file) {
    printf("Checking if %s contains content of %s to delete %s\n", check_file, pattern_file, file);
    
    // Read pattern file
    FILE *pattern_fp = fopen(pattern_file, "r");
    if (!pattern_fp) {
        perror("Error opening pattern file");
        return;
    }
    
    char pattern[4096];
    size_t pattern_len = fread(pattern, 1, sizeof(pattern)-1, pattern_fp);
    pattern[pattern_len] = '\0';
    fclose(pattern_fp);
    
    // Read check file
    FILE *check_fp = fopen(check_file, "r");
    if (!check_fp) {
        perror("Error opening check file");
        return;
    }
    
    char check_content[4096];
    size_t check_len = fread(check_content, 1, sizeof(check_content)-1, check_fp);
    check_content[check_len] = '\0';
    fclose(check_fp);
    
    // Check if content matches
    if (strstr(check_content, pattern) != NULL) {
        printf("Match found, deleting %s\n", file);
        unlink(file);
    } else {
        printf("No match found, keeping %s\n", file);
    }
}

void cmd_change_extension(const char* ext, const char* new_ext) {
    printf("Changing extension from %s to %s in current directory\n", ext, new_ext);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char *file_ext = strrchr(dir->d_name, '.');
            if (file_ext && strcmp(file_ext, ext) == 0) {
                char new_name[1024];
                int name_len = file_ext - dir->d_name;
                strncpy(new_name, dir->d_name, name_len);
                new_name[name_len] = '\0';
                strcat(new_name, new_ext);
                
                printf("Renaming %s to %s\n", dir->d_name, new_name);
                rename(dir->d_name, new_name);
            }
        }
        closedir(d);
    } else {
        perror("Error opening directory");
    }
}

void cmd_repeat_make_file(const char* filename_template, int start, int end) {
    printf("Creating files from %d to %d with template %s\n", start, end, filename_template);
    
    for (int i = start; i <= end; i++) {
        char filename[1024];
        const char *hash_pos = strchr(filename_template, '#');
        
        if (hash_pos) {
            // Replace # with the current number
            int prefix_len = hash_pos - filename_template;
            strncpy(filename, filename_template, prefix_len);
            filename[prefix_len] = '\0';
            sprintf(filename + prefix_len, "%d%s", i, hash_pos + 1);
        } else {
            // Just append number to the filename
            sprintf(filename, "%s%d", filename_template, i);
        }
        
        printf("Creating file: %s\n", filename);
        
        // Make sure the directory exists
        ensure_directory(filename);
        
        // Create the file
        FILE *fp = fopen(filename, "w");
        if (!fp) {
            perror("Error creating file");
            continue;
        }
        
        fprintf(fp, "File %d in sequence\n", i);
        fclose(fp);
    }
}


void cmd_compress_all(const char* ext, const char* folder) {
    printf("Compressing all %s files in %s\n", ext, folder);
    
    // Modified to use tar directly instead of libarchive
    char cmd[1024];
    char archive_name[1024];
    snprintf(archive_name, sizeof(archive_name), "%s_archive.tar.gz", ext+1);
    snprintf(cmd, sizeof(cmd), "find %s -name \"*%s\" -print0 | tar -czvf %s --null -T -", 
             folder, ext, archive_name);
    
    if (system(cmd) != 0) {
        perror("Error compressing files");
    } else {
        printf("Files compressed to %s\n", archive_name);
    }
}

void cmd_rename_with_prefix(const char* folder, const char* prefix) {
    printf("Renaming files in %s with prefix %s\n", folder, prefix);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {
                char old_path[1024];
                char new_path[1024];
                snprintf(old_path, sizeof(old_path), "%s/%s", folder, dir->d_name);
                snprintf(new_path, sizeof(new_path), "%s/%s%s", folder, prefix, dir->d_name);
                
                printf("Renaming %s to %s\n", old_path, new_path);
                rename(old_path, new_path);
            }
        }
        closedir(d);
    } else {
        perror("Error opening directory");
    }
}

void cmd_count_in(const char* ext, const char* folder) {
    printf("Counting %s files in %s\n", ext, folder);
    
    DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    int count = 0;
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char *file_ext = strrchr(dir->d_name, '.');
            if (file_ext && strcmp(file_ext, ext) == 0) {
                count++;
            }
        }
        closedir(d);
        printf("Found %d files with extension %s\n", count, ext);
    } else {
        perror("Error opening directory");
    }
}

void cmd_run_command(const char* command) {
    printf("Executing command: %s\n", command);
    
    int result = system(command);
    if (result != 0) {
        printf("Command returned non-zero exit code: %d\n", result);
    } else {
        printf("Command executed successfully\n");
    }
}

void cmd_search_for(const char* pattern, const char* folder) {
    printf("Searching for '%s' in %s\n", pattern, folder);
    
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "grep -r \"%s\" %s", pattern, folder);
    system(cmd);
}

void cmd_append_to(const char* content, const char* file) {
    printf("Appending to file: %s\n", file);
    
    ensure_directory(file);
    
    FILE *fp = fopen(file, "a");
    if (!fp) {
        perror("Error opening file for appending");
        return;
    }
    
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("Content appended successfully\n");
}
// Global map for variable storage
std::map<std::string, int> variables;

void cmd_store_number(int value, const char* var_name) {
    if (!var_name) return;
    std::string name(var_name);
    variables[name] = value;
    printf("Stored value %d in variable '%s'\n", value, var_name);
}

int get_value(const char* var_name) {
    if (!var_name) return 0;
    std::string name(var_name);
    auto it = variables.find(name);
    if (it != variables.end()) {
        return it->second;
    }
    printf("Warning: Variable '%s' not found, using 0\n", var_name);
    return 0;
}

void cmd_print_value(const char* var_name) {
    if (!var_name) return;
    std::string name(var_name);
    auto it = variables.find(name);
    if (it != variables.end()) {
        printf("Value of variable '%s' is: %d\n", var_name, it->second);
    } else {
        printf("Variable '%s' not found\n", var_name);
    }
}

void cmd_calculate_add(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    int result = num1 + num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d + %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_subtract(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    int result = num1 - num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d - %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_multiply(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    int result = num1 * num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d * %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_divide(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    if (num2 == 0) {
        printf("Error: Division by zero!\n");
        return;
    }
    int result = num1 / num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d / %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_modulo(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    if (num2 == 0) {
        printf("Error: Modulo by zero!\n");
        return;
    }
    int result = num1 % num2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d %% %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_power(int num1, int num2, const char* result_var) {
    if (!result_var) return;
    int result = 1;
    for (int i = 0; i < num2; i++) {
        result *= num1;
    }
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %d ^ %d = %d and stored in '%s'\n", num1, num2, result, result_var);
}

void cmd_calculate_var_add(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    int result = val1 + val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) + %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_subtract(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    int result = val1 - val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) - %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_multiply(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    int result = val1 * val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) * %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_divide(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    if (val2 == 0) {
        printf("Error: Division by zero!\n");
        return;
    }
    int result = val1 / val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) / %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_modulo(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    if (val2 == 0) {
        printf("Error: Modulo by zero!\n");
        return;
    }
    int result = val1 % val2;
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) %% %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}

void cmd_calculate_var_power(const char* var1, const char* var2, const char* result_var) {
    if (!var1 || !var2 || !result_var) return;
    int val1 = get_value(var1);
    int val2 = get_value(var2);
    int result = 1;
    for (int i = 0; i < val2; i++) {
        result *= val1;
    }
    std::string name(result_var);
    variables[name] = result;
    printf("Calculated %s(%d) ^ %s(%d) = %d and stored in '%s'\n", 
           var1, val1, var2, val2, result, result_var);
}
void execute(ASTNode *node) {
    while(node) {
        printf("\n-----------------------------------------------------\n");
        printf("Executing: %s\n", node->cmd);
        
        if (strcmp(node->cmd, "make_folder") == 0) {
            cmd_make_folder(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "place_text") == 0) {
            cmd_place_text(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "add_file") == 0) {
            cmd_add_file(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "remove_file") == 0) {
            cmd_remove_file(node->arg1);
        } else if (strcmp(node->cmd, "remove_folder") == 0) {
            cmd_remove_folder(node->arg1);
        } else if (strcmp(node->cmd, "show_files") == 0) {
            cmd_show_files(node->arg1);
        } else if (strcmp(node->cmd, "remove_all_containing") == 0) {
            cmd_remove_all_containing(node->arg1, node->arg2, node->arg3);
        } else if (strcmp(node->cmd, "delete_if_contains") == 0) {
            cmd_delete_if_contains(node->arg1, node->arg2, node->arg3);
        } else if (strcmp(node->cmd, "change_extension") == 0) {
            cmd_change_extension(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "repeat_make_file") == 0) {
            cmd_repeat_make_file(node->arg1, node->num1, node->num2);
        } else if (strcmp(node->cmd, "compress_all") == 0) {
            cmd_compress_all(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "rename_with_prefix") == 0) {
            cmd_rename_with_prefix(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "count_in") == 0) {
            cmd_count_in(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "run_command") == 0) {
            cmd_run_command(node->arg1);
        } else if (strcmp(node->cmd, "search_for") == 0) {
            cmd_search_for(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "append_to") == 0) {
            cmd_append_to(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "create_from_template") == 0) {
            cmd_create_from_template(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "batch_process") == 0) {
            cmd_batch_process(node->arg1, node->arg2, node->arg3);
        } else if (strcmp(node->cmd, "file_stats") == 0) {
            cmd_file_stats(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "move_large_files") == 0) {
            cmd_move_large_files(node->arg1, node->arg2, node->num1);
        } else if (strcmp(node->cmd, "transform_content") == 0) {
            cmd_transform_content(node->arg1, node->arg2, node->arg3);
        } else if (strcmp(node->cmd, "remove_lines") == 0) {
            cmd_remove_lines(node->arg1, node->num1);
        } else if (strcmp(node->cmd, "sort_by_size") == 0) {
            cmd_sort_by_size(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "sort_by_date") == 0) {
            cmd_sort_by_date(node->arg1, node->arg2);
        } else if (strcmp(node->cmd, "conditional_move") == 0) {
            cmd_conditional_move(node->arg1, node->arg2, node->arg3);
        }else if (strcmp(node->cmd, "calculate_add") == 0) {
            cmd_calculate_add(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_subtract") == 0) {
            cmd_calculate_subtract(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_multiply") == 0) {
            cmd_calculate_multiply(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_divide") == 0) {
            cmd_calculate_divide(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_modulo") == 0) {
            cmd_calculate_modulo(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_power") == 0) {
            cmd_calculate_power(node->num1, node->num2, node->arg1);
        }
        else if (strcmp(node->cmd, "print_value") == 0) {
            cmd_print_value(node->arg1);
        }
        else if (strcmp(node->cmd, "calculate_var_add") == 0) {
            cmd_calculate_var_add(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_subtract") == 0) {
            cmd_calculate_var_subtract(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_multiply") == 0) {
            cmd_calculate_var_multiply(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_divide") == 0) {
            cmd_calculate_var_divide(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_modulo") == 0) {
            cmd_calculate_var_modulo(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "calculate_var_power") == 0) {
            cmd_calculate_var_power(node->arg1, node->arg2, node->arg3);
        }
        else if (strcmp(node->cmd, "store_number") == 0) {
            cmd_store_number(node->num1, node->arg1);
        }else {
            printf("Unknown command: %s\n", node->cmd);
        }
        
        printf("-----------------------------------------------------\n");
        node = node->next;
    }
}
// Add these to the yyerror function in tasky.y
void yyerror(const char *s) {
    extern char *yytext;
    fprintf(stderr, "Parse error: %s near token '%s'\n", s, yytext);
}

// Enhanced parsing diagnostic helper
void debug_token(const char* token_text, int token_type) {
    printf("TOKEN: '%s', TYPE: %d\n", token_text, token_type);
}
