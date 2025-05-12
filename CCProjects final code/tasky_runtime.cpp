#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <climits>
#include <cctype>
#include <ctime>
#include <regex>

// Structure for storing file information
struct FileInfo {
    std::string name;
    size_t size;
    time_t mtime;
};

// Helper function to ensure directory exists
void ensure_directory(const std::string& path) {
    struct stat st = {0};
    if (stat(path.c_str(), &st) == -1) {
        mkdir(path.c_str(), 0755);
    }
}

// Helper function to check if a file contains a pattern
bool file_contains_pattern(const std::string& filename, const std::string& pattern) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(pattern) != std::string::npos) {
            return true;
        }
    }
    
    return false;
}

// Basic file operations
extern "C" void tasky_make_folder(const char* path, const char* name) {
    std::string folder_path = std::string(path) + "/" + std::string(name);
    printf("Creating folder: %s\n", folder_path.c_str());
    
    if (mkdir(folder_path.c_str(), 0755) == 0) {
        printf("Folder created successfully\n");
    } else {
        perror("Failed to create folder");
    }
}

extern "C" void tasky_place_text(const char* text, const char* file) {
    printf("Placing text in file: %s\n", file);
    
    std::ofstream out_file(file);
    if (out_file.is_open()) {
        out_file << text;
        out_file.close();
        printf("Text placed successfully\n");
    } else {
        perror("Failed to open file for writing");
    }
}

extern "C" void tasky_add_file(const char* content, const char* file) {
    printf("Adding content to file: %s\n", file);
    
    std::ofstream out_file(file, std::ios::app);
    if (out_file.is_open()) {
        out_file << content;
        out_file.close();
        printf("Content added successfully\n");
    } else {
        perror("Failed to open file for appending");
    }
}

extern "C" void tasky_remove_file(const char* file) {
    printf("Removing file: %s\n", file);
    
    if (remove(file) == 0) {
        printf("File removed successfully\n");
    } else {
        perror("Failed to remove file");
    }
}

extern "C" void tasky_remove_folder(const char* folder) {
    printf("Removing folder: %s\n", folder);
    
    // This is a simplified implementation that only removes empty directories
    if (rmdir(folder) == 0) {
        printf("Folder removed successfully\n");
    } else {
        perror("Failed to remove folder");
    }
}

extern "C" void tasky_show_files(const char* folder) {
    printf("Showing files in folder: %s\n", folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    struct dirent* entry;
    int file_count = 0;
    
    printf("Files in %s:\n", folder);
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            printf("  - %s\n", entry->d_name);
            file_count++;
        }
    }
    
    closedir(d);
    printf("Total files: %d\n", file_count);
}

// Template processing function
extern "C" void tasky_create_from_template(const char* template_file, const char* vars_file) {
    printf("Creating file from template '%s' with variables from '%s'\n", template_file, vars_file);
    
    std::ifstream tf(template_file);
    if (!tf.is_open()) {
        perror("Cannot open template file");
        return;
    }
    
    std::ifstream vf(vars_file);
    if (!vf.is_open()) {
        perror("Cannot open variables file");
        return;
    }
    
    // Get output filename from template (remove .template extension)
    std::string out_filename = template_file;
    size_t dot_pos = out_filename.rfind('.');
    if (dot_pos != std::string::npos && out_filename.substr(dot_pos) == ".template") {
        out_filename = out_filename.substr(0, dot_pos);
    } else {
        out_filename += ".output";
    }
    
    std::ofstream out_file(out_filename);
    if (!out_file.is_open()) {
        perror("Cannot create output file");
        return;
    }
    
    // Read variables into a map
    std::map<std::string, std::string> variables;
    std::string line;
    while (std::getline(vf, line)) {
        size_t eq_pos = line.find('=');
        if (eq_pos != std::string::npos) {
            std::string var_name = line.substr(0, eq_pos);
            std::string var_value = line.substr(eq_pos + 1);
            variables[var_name] = var_value;
        }
    }
    
    // Process template file line by line
    while (std::getline(tf, line)) {
        for (const auto& var : variables) {
            std::string token = "{{" + var.first + "}}";
            size_t pos = 0;
            while ((pos = line.find(token, pos)) != std::string::npos) {
                line.replace(pos, token.length(), var.second);
                pos += var.second.length();
            }
        }
        out_file << line << std::endl;
    }
    
    printf("Created file: %s\n", out_filename.c_str());
}

// Batch processing function
extern "C" void tasky_batch_process(const char* cmd, const char* pattern, const char* dir) {
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
            std::string filename = entry->d_name;
            if (filename.find(pattern) != std::string::npos) {
                std::string full_path = std::string(dir) + "/" + filename;
                
                // Create and execute command
                std::string full_cmd = std::string(cmd) + " \"" + full_path + "\"";
                printf("Executing: %s\n", full_cmd.c_str());
                
                int result = system(full_cmd.c_str());
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

// File statistics function
extern "C" void tasky_file_stats(const char* extension, const char* folder) {
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
    std::string smallest_file;
    std::string largest_file;
    
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            // Check if file has the right extension
            std::string filename = entry->d_name;
            size_t dot_pos = filename.rfind('.');
            if (dot_pos != std::string::npos && filename.substr(dot_pos + 1) == extension) {
                std::string full_path = std::string(folder) + "/" + filename;
                
                struct stat st;
                if (stat(full_path.c_str(), &st) == 0) {
                    file_count++;
                    total_size += st.st_size;
                    
                    if (st.st_size < smallest) {
                        smallest = st.st_size;
                        smallest_file = filename;
                    }
                    
                    if (st.st_size > largest) {
                        largest = st.st_size;
                        largest_file = filename;
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
        printf("Smallest file: %s (%ld bytes)\n", smallest_file.c_str(), smallest);
        printf("Largest file: %s (%ld bytes)\n", largest_file.c_str(), largest);
    }
}

// Move large files function
extern "C" void tasky_move_large_files(const char* src_dir, const char* dest_dir, int size_thresh) {
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
            std::string src_path = std::string(src_dir) + "/" + entry->d_name;
            
            struct stat file_stat;
            if (stat(src_path.c_str(), &file_stat) == 0) {
                if (file_stat.st_size > size_thresh) {
                    std::string dest_path = std::string(dest_dir) + "/" + entry->d_name;
                    
                    printf("Moving %s (%ld bytes) to %s\n", src_path.c_str(), file_stat.st_size, dest_path.c_str());
                    
                    if (rename(src_path.c_str(), dest_path.c_str()) == 0) {
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

// Transform content function
extern "C" void tasky_transform_content(const char* filename, const char* search_pattern, const char* replacement) {
    printf("Transforming content in '%s' using pattern '%s' replacing with '%s'\n", 
           filename, search_pattern, replacement);
    
    // Read file content
    std::ifstream in_file(filename);
    if (!in_file.is_open()) {
        perror("Cannot open file");
        return;
    }
    
    std::stringstream buffer;
    buffer << in_file.rdbuf();
    std::string content = buffer.str();
    in_file.close();
    
    // Simple string replace (not a full regex implementation)
    int replacements = 0;
    size_t pos = 0;
    std::string search_str(search_pattern);
    std::string replace_str(replacement);
    
    while ((pos = content.find(search_str, pos)) != std::string::npos) {
        content.replace(pos, search_str.length(), replace_str);
        pos += replace_str.length();
        replacements++;
    }
    
    // Write back to file
    std::ofstream out_file(filename);
    if (!out_file.is_open()) {
        perror("Cannot open file for writing");
        return;
    }
    
    out_file << content;
    out_file.close();
    
    printf("Made %d replacements in the file\n", replacements);
}

// Remove lines function
extern "C" void tasky_remove_lines(const char* filename, int n) {
    printf("Removing every %d lines from file '%s'\n", n, filename);
    
    // Read file content
    std::ifstream in_file(filename);
    if (!in_file.is_open()) {
        perror("Cannot open file");
        return;
    }
    
    std::string temp_filename = std::string(filename) + ".tmp";
    std::ofstream out_file(temp_filename);
    if (!out_file.is_open()) {
        perror("Cannot create temporary file");
        in_file.close();
        return;
    }
    
    int line_count = 0;
    std::string line;
    while (std::getline(in_file, line)) {
        line_count++;
        if (line_count % n != 0) {
            out_file << line << std::endl;
        }
    }
    
    in_file.close();
    out_file.close();
    
    // Replace original with temp file
    if (rename(temp_filename.c_str(), filename) != 0) {
        perror("Failed to replace original file");
        return;
    }
    
    printf("Processed file, removed lines\n");
}

// Sort by size function
extern "C" void tasky_sort_by_size(const char* ext, const char* folder) {
    printf("Sorting files with extension '%s' in '%s' by size\n", ext, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    std::vector<FileInfo> files;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            std::string filename = entry->d_name;
            size_t dot_pos = filename.rfind('.');
            if (dot_pos != std::string::npos && filename.substr(dot_pos + 1) == ext) {
                std::string full_path = std::string(folder) + "/" + filename;
                
                struct stat st;
                if (stat(full_path.c_str(), &st) == 0) {
                    FileInfo info;
                    info.name = filename;
                    info.size = st.st_size;
                    info.mtime = st.st_mtime;
                    files.push_back(info);
                }
            }
        }
    }
    
    closedir(d);
    
    // Sort by size (largest first)
    std::sort(files.begin(), files.end(), 
        [](const FileInfo& a, const FileInfo& b) {
            return a.size > b.size;
        });
    
    // Display results
    printf("Files sorted by size (largest first):\n");
    for (size_t i = 0; i < files.size(); i++) {
        printf("%3zu. %s (%ld bytes)\n", i + 1, files[i].name.c_str(), files[i].size);
    }
}

// Sort by date function
extern "C" void tasky_sort_by_date(const char* ext, const char* folder) {
    printf("Sorting files with extension '%s' in '%s' by date\n", ext, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    std::vector<FileInfo> files;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            std::string filename = entry->d_name;
            size_t dot_pos = filename.rfind('.');
            if (dot_pos != std::string::npos && filename.substr(dot_pos + 1) == ext) {
                std::string full_path = std::string(folder) + "/" + filename;
                
                struct stat st;
                if (stat(full_path.c_str(), &st) == 0) {
                    FileInfo info;
                    info.name = filename;
                    info.size = st.st_size;
                    info.mtime = st.st_mtime;
                    files.push_back(info);
                }
            }
        }
    }
    
    closedir(d);
    
    // Sort by modification time (newest first)
    std::sort(files.begin(), files.end(), 
        [](const FileInfo& a, const FileInfo& b) {
            return a.mtime > b.mtime;  // Newest first
        });
    
    // Display results
    printf("Files sorted by date (newest first):\n");
    for (size_t i = 0; i < files.size(); i++) {
        char date[64];
        struct tm *tm_info = localtime(&files[i].mtime);
        strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%3zu. %s - %s (%ld bytes)\n", i + 1, files[i].name.c_str(), date, files[i].size);
    }
}

// Conditional move function
extern "C" void tasky_conditional_move(const char* file, const char* pattern, const char* dest) {
    printf("Checking if file '%s' contains '%s' for conditional move to '%s'\n", file, pattern, dest);
    
    // Check if file contains pattern
    if (file_contains_pattern(file, pattern)) {
        printf("Pattern found in file, moving to destination\n");
        
        // Make sure destination directory exists
        struct stat st = {0};
        std::string dest_dir = dest;
        size_t last_slash = dest_dir.rfind('/');
        if (last_slash != std::string::npos) {
            dest_dir = dest_dir.substr(0, last_slash);
            if (stat(dest_dir.c_str(), &st) == -1) {
                printf("Creating destination directory '%s'\n", dest_dir.c_str());
                if (mkdir(dest_dir.c_str(), 0755) != 0) {
                    perror("Failed to create destination directory");
                    return;
                }
            }
        }
        
        // Move the file
        if (rename(file, dest) == 0) {
            printf("File moved successfully\n");
        } else {
            perror("Failed to move file");
        }
    } else {
        printf("Pattern not found in file, no action taken\n");
    }
}

// Additional helper functions for other commands

// Remove all files containing pattern
extern "C" void tasky_remove_all_containing(const char* ext, const char* pattern, const char* folder) {
    printf("Removing all files with extension '%s' containing '%s' in '%s'\n", ext, pattern, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    int files_removed = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            std::string filename = entry->d_name;
            size_t dot_pos = filename.rfind('.');
            if (dot_pos != std::string::npos && filename.substr(dot_pos + 1) == ext) {
                std::string full_path = std::string(folder) + "/" + filename;
                
                if (file_contains_pattern(full_path, pattern)) {
                    printf("Removing file: %s\n", full_path.c_str());
                    if (remove(full_path.c_str()) == 0) {
                        files_removed++;
                    } else {
                        perror("Failed to remove file");
                    }
                }
            }
        }
    }
    
    closedir(d);
    printf("Removed %d files\n", files_removed);
}

// Change file extension
extern "C" void tasky_change_extension(const char* ext, const char* new_ext, const char* folder) {
    printf("Changing extension of all '.%s' files to '.%s' in '%s'\n", ext, new_ext, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    int files_changed = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            std::string filename = entry->d_name;
            size_t dot_pos = filename.rfind('.');
            if (dot_pos != std::string::npos && filename.substr(dot_pos + 1) == ext) {
                std::string old_path = std::string(folder) + "/" + filename;
                std::string new_filename = filename.substr(0, dot_pos + 1) + new_ext;
                std::string new_path = std::string(folder) + "/" + new_filename;
                
                printf("Renaming %s to %s\n", old_path.c_str(), new_path.c_str());
                if (rename(old_path.c_str(), new_path.c_str()) == 0) {
                    files_changed++;
                } else {
                    perror("Failed to rename file");
                }
            }
        }
    }
    
    closedir(d);
    printf("Changed extension of %d files\n", files_changed);
}

// Rename with prefix
extern "C" void tasky_rename_with_prefix(const char* folder, const char* prefix) {
    printf("Renaming all files in '%s' with prefix '%s'\n", folder, prefix);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    // First, collect all files to avoid issues with readdir
    std::vector<std::string> filenames;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            filenames.push_back(entry->d_name);
        }
    }
    
    closedir(d);
    
    int files_renamed = 0;
    for (const std::string& filename : filenames) {
        std::string old_path = std::string(folder) + "/" + filename;
        std::string new_path = std::string(folder) + "/" + prefix + filename;
        
        printf("Renaming %s to %s\n", old_path.c_str(), new_path.c_str());
        if (rename(old_path.c_str(), new_path.c_str()) == 0) {
            files_renamed++;
        } else {
            perror("Failed to rename file");
        }
    }
    
    printf("Renamed %d files\n", files_renamed);
}

// Count files
extern "C" void tasky_count_in(const char* ext, const char* folder) {
    printf("Counting files with extension '%s' in '%s'\n", ext, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    int count = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            std::string filename = entry->d_name;
            size_t dot_pos = filename.rfind('.');
            if (dot_pos != std::string::npos && filename.substr(dot_pos + 1) == ext) {
                count++;
            }
        }
    }
    
    closedir(d);
    printf("Found %d files with extension '.%s'\n", count, ext);
}

// Run a command
extern "C" void tasky_run_command(const char* command) {
    printf("Running command: %s\n", command);
    
    int result = system(command);
    if (result == 0) {
        printf("Command executed successfully\n");
    } else {
        printf("Command failed with code %d\n", result);
    }
}

// Search for a pattern in files
extern "C" void tasky_search_for(const char* pattern, const char* folder) {
    printf("Searching for '%s' in files under '%s'\n", pattern, folder);
    
    DIR* d = opendir(folder);
    if (!d) {
        perror("Cannot open directory");
        return;
    }
    
    int files_checked = 0;
    int files_matching = 0;
    struct dirent* entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            std::string full_path = std::string(folder) + "/" + entry->d_name;
            files_checked++;
            
            if (file_contains_pattern(full_path, pattern)) {
                printf("Found pattern in: %s\n", full_path.c_str());
                files_matching++;
            }
        }
    }
    
    closedir(d);
    printf("Checked %d files, found matches in %d files\n", files_checked, files_matching);
}

// Append to file
extern "C" void tasky_append_to(const char* content, const char* file) {
    printf("Appending text to file: %s\n", file);
    
    std::ofstream out_file(file, std::ios::app);
    if (out_file.is_open()) {
        out_file << content;
        out_file.close();
        printf("Text appended successfully\n");
    } else {
        perror("Failed to open file for appending");
    }
}
// Global variable map for storing calculation results
std::map<std::string, int> variable_storage;

// Helper function to get variable value
int get_variable_value(const char* var_name) {
    std::string name(var_name);
    if (variable_storage.find(name) == variable_storage.end()) {
        std::cerr << "Error: Variable '" << name << "' not found." << std::endl;
        return 0;
    }
    return variable_storage[name];
}

// Basic arithmetic operations
extern "C" void tasky_calculate_add(int num1, int num2, const char* result_var) {
    int result = num1 + num2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %d + %d = %d (stored in '%s')\n", num1, num2, result, result_var);
}

extern "C" void tasky_calculate_subtract(int num1, int num2, const char* result_var) {
    int result = num1 - num2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %d - %d = %d (stored in '%s')\n", num1, num2, result, result_var);
}

extern "C" void tasky_calculate_multiply(int num1, int num2, const char* result_var) {
    int result = num1 * num2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %d * %d = %d (stored in '%s')\n", num1, num2, result, result_var);
}

extern "C" void tasky_calculate_divide(int num1, int num2, const char* result_var) {
    if (num2 == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return;
    }
    int result = num1 / num2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %d / %d = %d (stored in '%s')\n", num1, num2, result, result_var);
}

extern "C" void tasky_calculate_modulo(int num1, int num2, const char* result_var) {
    if (num2 == 0) {
        std::cerr << "Error: Modulo by zero!" << std::endl;
        return;
    }
    int result = num1 % num2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %d %% %d = %d (stored in '%s')\n", num1, num2, result, result_var);
}

extern "C" void tasky_calculate_power(int num1, int num2, const char* result_var) {
    int result = 1;
    for (int i = 0; i < num2; i++) {
        result *= num1;
    }
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %d ^ %d = %d (stored in '%s')\n", num1, num2, result, result_var);
}

// Variable-based arithmetic operations
extern "C" void tasky_calculate_var_add(const char* var1, const char* var2, const char* result_var) {
    int value1 = get_variable_value(var1);
    int value2 = get_variable_value(var2);
    int result = value1 + value2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %s(%d) + %s(%d) = %d (stored in '%s')\n", 
           var1, value1, var2, value2, result, result_var);
}

extern "C" void tasky_calculate_var_subtract(const char* var1, const char* var2, const char* result_var) {
    int value1 = get_variable_value(var1);
    int value2 = get_variable_value(var2);
    int result = value1 - value2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %s(%d) - %s(%d) = %d (stored in '%s')\n", 
           var1, value1, var2, value2, result, result_var);
}

extern "C" void tasky_calculate_var_multiply(const char* var1, const char* var2, const char* result_var) {
    int value1 = get_variable_value(var1);
    int value2 = get_variable_value(var2);
    int result = value1 * value2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %s(%d) * %s(%d) = %d (stored in '%s')\n", 
           var1, value1, var2, value2, result, result_var);
}

extern "C" void tasky_calculate_var_divide(const char* var1, const char* var2, const char* result_var) {
    int value1 = get_variable_value(var1);
    int value2 = get_variable_value(var2);
    if (value2 == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return;
    }
    int result = value1 / value2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %s(%d) / %s(%d) = %d (stored in '%s')\n", 
           var1, value1, var2, value2, result, result_var);
}

extern "C" void tasky_calculate_var_modulo(const char* var1, const char* var2, const char* result_var) {
    int value1 = get_variable_value(var1);
    int value2 = get_variable_value(var2);
    if (value2 == 0) {
        std::cerr << "Error: Modulo by zero!" << std::endl;
        return;
    }
    int result = value1 % value2;
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %s(%d) %% %s(%d) = %d (stored in '%s')\n", 
           var1, value1, var2, value2, result, result_var);
}

extern "C" void tasky_calculate_var_power(const char* var1, const char* var2, const char* result_var) {
    int value1 = get_variable_value(var1);
    int value2 = get_variable_value(var2);
    int result = 1;
    for (int i = 0; i < value2; i++) {
        result *= value1;
    }
    std::string var_name(result_var);
    variable_storage[var_name] = result;
    printf("Calculated: %s(%d) ^ %s(%d) = %d (stored in '%s')\n", 
           var1, value1, var2, value2, result, result_var);
}

// Variable management functions
extern "C" void tasky_store_number(int value, const char* var_name) {
    std::string name(var_name);
    variable_storage[name] = value;
    printf("Stored value %d in variable '%s'\n", value, var_name);
}

extern "C" void tasky_print_value(const char* var_name) {
    std::string name(var_name);
    if (variable_storage.find(name) == variable_storage.end()) {
        std::cerr << "Error: Variable '" << name << "' not found." << std::endl;
        return;
    }
    printf("Value of '%s' is %d\n", var_name, variable_storage[name]);
}