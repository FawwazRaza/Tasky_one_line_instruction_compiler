#include "astnode.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#ifdef USE_LLVM
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/FileSystem.h>

// Forward declarations of helper functions
llvm::Function* createPrintf(llvm::Module* module);
llvm::Function* createMakeFolder(llvm::Module* module);
llvm::Function* createPlaceText(llvm::Module* module);
llvm::Function* createAddFile(llvm::Module* module);
llvm::Function* createRemoveFile(llvm::Module* module);
llvm::Function* createRemoveFolder(llvm::Module* module);
llvm::Function* createShowFiles(llvm::Module* module);
llvm::Function* createCreateFromTemplate(llvm::Module* module);
llvm::Function* createBatchProcess(llvm::Module* module);
llvm::Function* createFileStats(llvm::Module* module);
llvm::Function* createMoveLargeFiles(llvm::Module* module);
llvm::Function* createTransformContent(llvm::Module* module);
llvm::Function* createRemoveLines(llvm::Module* module);
llvm::Function* createSortBySize(llvm::Module* module);
llvm::Function* createSortByDate(llvm::Module* module);
llvm::Function* createConditionalMove(llvm::Module* module);
llvm::Function* createCalculateAdd(llvm::Module* module);
llvm::Function* createCalculateSubtract(llvm::Module* module);
llvm::Function* createCalculateMultiply(llvm::Module* module);
llvm::Function* createCalculateDivide(llvm::Module* module);
llvm::Function* createCalculateModulo(llvm::Module* module);
llvm::Function* createCalculatePower(llvm::Module* module);
llvm::Function* createPrintValue(llvm::Module* module);
llvm::Function* createStoreNumber(llvm::Module* module);
llvm::Function* createCalculateVarAdd(llvm::Module* module);
llvm::Function* createCalculateVarSubtract(llvm::Module* module);
llvm::Function* createCalculateVarMultiply(llvm::Module* module);
llvm::Function* createCalculateVarDivide(llvm::Module* module);
llvm::Function* createCalculateVarModulo(llvm::Module* module);
llvm::Function* createCalculateVarPower(llvm::Module* module);
// Helper function implementations
llvm::Function* createCreateFromTemplate(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void createFromTemplate(char* template_file, char* vars_file)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // template_file
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // vars_file
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_create_from_template",
        module
    );
}

llvm::Function* createBatchProcess(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void batchProcess(char* cmd, char* pattern, char* dir)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // cmd
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // pattern
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // dir
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_batch_process",
        module
    );
}
llvm::Function* createCalculateAdd(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_add",
        module);
}

llvm::Function* createCalculateSubtract(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_subtract",
        module);
}

llvm::Function* createCalculateMultiply(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_multiply",
        module);
}

llvm::Function* createCalculateDivide(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_divide",
        module);
}

llvm::Function* createCalculateModulo(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_modulo",
        module);
}

llvm::Function* createCalculatePower(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_power",
        module);
}

llvm::Function* createPrintValue(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_print_value",
        module);
}

llvm::Function* createStoreNumber(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::Type::getInt32Ty(context));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_store_number",
        module);
}

llvm::Function* createCalculateVarAdd(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_var_add",
        module);
}

llvm::Function* createCalculateVarSubtract(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_var_subtract",
        module);
}

llvm::Function* createCalculateVarMultiply(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_var_multiply",
        module);
}

llvm::Function* createCalculateVarDivide(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_var_divide",
        module);
}

llvm::Function* createCalculateVarModulo(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_var_modulo",
        module);
}

llvm::Function* createCalculateVarPower(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0));
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false);
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_calculate_var_power",
        module);
}
llvm::Function* createFileStats(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void fileStats(char* extension, char* folder)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // extension
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // folder
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_file_stats",
        module
    );
}

llvm::Function* createMoveLargeFiles(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void moveLargeFiles(char* src_dir, char* dest_dir, int size_thresh)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // src_dir
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // dest_dir
    paramTypes.push_back(llvm::Type::getInt32Ty(context)); // size_thresh
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_move_large_files",
        module
    );
}

llvm::Function* createTransformContent(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void transformContent(char* filename, char* regex, char* replacement)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // filename
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // regex
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // replacement
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_transform_content",
        module
    );
}

llvm::Function* createRemoveLines(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void removeLines(char* filename, int n)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // filename
    paramTypes.push_back(llvm::Type::getInt32Ty(context)); // n
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_remove_lines",
        module
    );
}

llvm::Function* createSortBySize(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void sortBySize(char* ext, char* folder)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // ext
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // folder
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_sort_by_size",
        module
    );
}

llvm::Function* createSortByDate(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void sortByDate(char* ext, char* folder)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // ext
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // folder
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_sort_by_date",
        module
    );
}

llvm::Function* createConditionalMove(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    
    // Define function type: void conditionalMove(char* file, char* pattern, char* dest)
    std::vector<llvm::Type*> paramTypes;
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // file
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // pattern
    paramTypes.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // dest
    
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        paramTypes,
        false
    );
    
    return llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        "tasky_conditional_move",
        module
    );
}
llvm::Function* createPrintf(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    llvm::FunctionType* printf_type = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(context),
        llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0),
        true);
    
    return llvm::Function::Create(
        printf_type,
        llvm::Function::ExternalLinkage,
        "printf",
        module);
}

llvm::Function* createMakeFolder(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    std::vector<llvm::Type*> args;
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // path
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // name
    
    llvm::FunctionType* func_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context), 
        args, 
        false);
    
    return llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        "cmd_make_folder",
        module);
}

llvm::Function* createPlaceText(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    std::vector<llvm::Type*> args;
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // text
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // file
    
    llvm::FunctionType* func_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context), 
        args, 
        false);
    
    return llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        "cmd_place_text",
        module);
}

llvm::Function* createAddFile(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    std::vector<llvm::Type*> args;
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // content
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // file
    
    llvm::FunctionType* func_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context), 
        args, 
        false);
    
    return llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        "cmd_add_file",
        module);
}

llvm::Function* createRemoveFile(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    std::vector<llvm::Type*> args;
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // file
    
    llvm::FunctionType* func_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context), 
        args, 
        false);
    
    return llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        "cmd_remove_file",
        module);
}

llvm::Function* createRemoveFolder(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    std::vector<llvm::Type*> args;
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // folder
    
    llvm::FunctionType* func_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context), 
        args, 
        false);
    
    return llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        "cmd_remove_folder",
        module);
}

llvm::Function* createShowFiles(llvm::Module* module) {
    llvm::LLVMContext& context = module->getContext();
    std::vector<llvm::Type*> args;
    args.push_back(llvm::PointerType::get(llvm::Type::getInt8Ty(context), 0)); // folder
    
    llvm::FunctionType* func_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context), 
        args, 
        false);
    
    return llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        "cmd_show_files",
        module);
}


class TaskyCodeGen {
public:
    // Remove the extra qualification here
    TaskyCodeGen() : 
        context(std::make_unique<llvm::LLVMContext>()),
        module(std::make_unique<llvm::Module>("tasky", *context)),
        builder(std::make_unique<llvm::IRBuilder<>>(*context)) {


    // Initialize LLVM
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();

    // Create external function declarations
    printfFunc = createPrintf(module.get());
    makeFolderFunc = createMakeFolder(module.get());
    placeTextFunc = createPlaceText(module.get());
    addFileFunc = createAddFile(module.get());
    removeFileFunc = createRemoveFile(module.get());
    removeFolderFunc = createRemoveFolder(module.get());
    showFilesFunc = createShowFiles(module.get());

    // Create new function declarations
    createFromTemplateFunc = createCreateFromTemplate(module.get());
    batchProcessFunc = createBatchProcess(module.get());
    fileStatsFunc = createFileStats(module.get());
    moveLargeFilesFunc = createMoveLargeFiles(module.get());
    transformContentFunc = createTransformContent(module.get());
    removeLinesFunc = createRemoveLines(module.get());
    sortBySizeFunc = createSortBySize(module.get());
    sortByDateFunc = createSortByDate(module.get());
    conditionalMoveFunc = createConditionalMove(module.get());
    // Create arithmetic functions
    calculateAddFunc = createCalculateAdd(module.get());
    calculateSubtractFunc = createCalculateSubtract(module.get());
    calculateMultiplyFunc = createCalculateMultiply(module.get());
    calculateDivideFunc = createCalculateDivide(module.get());
    calculateModuloFunc = createCalculateModulo(module.get());
    
    }



    
    
    void generateIR(ASTNode* ast) {
        // Create the main function
        llvm::FunctionType* mainFuncType = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(*context), false);
        llvm::Function* mainFunc = llvm::Function::Create(
            mainFuncType, llvm::Function::ExternalLinkage, "main", module.get());
        
        // Create entry block
        llvm::BasicBlock* entryBlock = llvm::BasicBlock::Create(*context, "entry", mainFunc);
        builder->SetInsertPoint(entryBlock);
        
        // Create greeting message
        llvm::Value* greeting = builder->CreateGlobalStringPtr("TASKY Automation System Started\n");
        std::vector<llvm::Value*> args;
        args.push_back(greeting);
        builder->CreateCall(printfFunc, args);
        
        // Generate code for each AST node
        while (ast) {
            generateNodeIR(ast);
            ast = ast->next;
        }
        
        // Return 0 from main
        builder->CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*context), 0));
        
        // Verify the generated code
        llvm::verifyFunction(*mainFunc);
    }
    
    void dumpIR() {
        module->print(llvm::outs(), nullptr);
    }
    
    void saveIRToFile(const std::string& filename) {
        std::error_code EC;
        llvm::raw_fd_ostream dest(filename, EC, llvm::sys::fs::OF_None);
        if (EC) {
            std::cerr << "Could not open file: " << EC.message() << "\n";
            return;
        }
        module->print(dest, nullptr);
    }
    
private:
    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder;
    
    llvm::Function* printfFunc;
    llvm::Function* makeFolderFunc;
    llvm::Function* placeTextFunc;
    llvm::Function* addFileFunc;
    llvm::Function* removeFileFunc;
    llvm::Function* removeFolderFunc;
    llvm::Function* showFilesFunc;
    llvm::Function* createFromTemplateFunc;
    llvm::Function* batchProcessFunc;
    llvm::Function* fileStatsFunc;
    llvm::Function* moveLargeFilesFunc;
    llvm::Function* transformContentFunc;
    llvm::Function* removeLinesFunc;
    llvm::Function* sortBySizeFunc;
    llvm::Function* sortByDateFunc;
    llvm::Function* conditionalMoveFunc;
    llvm::Function* calculateAddFunc;
    llvm::Function* calculateSubtractFunc;
    llvm::Function* calculateMultiplyFunc;
    llvm::Function* calculateDivideFunc;
    llvm::Function* calculateModuloFunc;
   
  
    
       
    // Code generation helper
     void generateNodeIR(ASTNode* node) {
        if (!node) return;
        
        std::string cmdName = node->cmd;
        std::vector<llvm::Value*> args;
        
        // Create command execution message
        std::string execMsg = "Executing: " + cmdName + "\n";
        llvm::Value* execMsgVal = builder->CreateGlobalStringPtr(execMsg);
        args.push_back(execMsgVal);
        builder->CreateCall(printfFunc, args);
        args.clear();
        
        if (cmdName == "make_folder") {
            if (node->arg1 && node->arg2) {
                llvm::Value* path = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* name = builder->CreateGlobalStringPtr(node->arg2);
                args.push_back(path);
                args.push_back(name);
                builder->CreateCall(makeFolderFunc, args);
            }
        } else if (cmdName == "create_from_template") {
            if (node->arg1 && node->arg2) {
                llvm::Value* templateFile = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* varsFile = builder->CreateGlobalStringPtr(node->arg2);
                args.push_back(templateFile);
                args.push_back(varsFile);
                builder->CreateCall(createFromTemplateFunc, args);
            }
        } else if (cmdName == "batch_process") {
            if (node->arg1 && node->arg2 && node->arg3) {
                llvm::Value* cmd = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* pattern = builder->CreateGlobalStringPtr(node->arg2);
                llvm::Value* dir = builder->CreateGlobalStringPtr(node->arg3);
                args.push_back(cmd);
                args.push_back(pattern);
                args.push_back(dir);
                builder->CreateCall(batchProcessFunc, args);
            }
        } else if (cmdName == "file_stats") {
            if (node->arg1 && node->arg2) {
                llvm::Value* extension = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* folder = builder->CreateGlobalStringPtr(node->arg2);
                args.push_back(extension);
                args.push_back(folder);
                builder->CreateCall(fileStatsFunc, args);
            }
        } else if (cmdName == "move_large_files") {
            if (node->arg1 && node->arg2) {
                llvm::Value* srcDir = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* destDir = builder->CreateGlobalStringPtr(node->arg2);
                llvm::Value* sizeThreshold = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*context), node->num1);
                args.push_back(srcDir);
                args.push_back(destDir);
                args.push_back(sizeThreshold);
                builder->CreateCall(moveLargeFilesFunc, args);
            }
        } else if (cmdName == "transform_content") {
            if (node->arg1 && node->arg2 && node->arg3) {
                llvm::Value* filename = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* regex = builder->CreateGlobalStringPtr(node->arg2);
                llvm::Value* replacement = builder->CreateGlobalStringPtr(node->arg3);
                args.push_back(filename);
                args.push_back(regex);
                args.push_back(replacement);
                builder->CreateCall(transformContentFunc, args);
            }
        } else if (cmdName == "remove_lines") {
            if (node->arg1) {
                llvm::Value* filename = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* n = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*context), node->num1);
                args.push_back(filename);
                args.push_back(n);
                builder->CreateCall(removeLinesFunc, args);
            }
        } else if (cmdName == "sort_by_size") {
            if (node->arg1 && node->arg2) {
                llvm::Value* extension = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* folder = builder->CreateGlobalStringPtr(node->arg2);
                args.push_back(extension);
                args.push_back(folder);
                builder->CreateCall(sortBySizeFunc, args);
            }
        } else if (cmdName == "sort_by_date") {
            if (node->arg1 && node->arg2) {
                llvm::Value* extension = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* folder = builder->CreateGlobalStringPtr(node->arg2);
                args.push_back(extension);
                args.push_back(folder);
                builder->CreateCall(sortByDateFunc, args);
            }
        } else if (cmdName == "conditional_move") {
            if (node->arg1 && node->arg2 && node->arg3) {
                llvm::Value* file = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* pattern = builder->CreateGlobalStringPtr(node->arg2);
                llvm::Value* dest = builder->CreateGlobalStringPtr(node->arg3);
                args.push_back(file);
                args.push_back(pattern);
                args.push_back(dest);
                builder->CreateCall(conditionalMoveFunc, args);
            }
        }else if (cmdName == "place_text") {
            if (node->arg1 && node->arg2) {
                llvm::Value* text = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* file = builder->CreateGlobalStringPtr(node->arg2);
                args.push_back(text);
                args.push_back(file);
                builder->CreateCall(placeTextFunc, args);
            }
        } else if (cmdName == "add_file") {
            if (node->arg1 && node->arg2) {
                llvm::Value* content = builder->CreateGlobalStringPtr(node->arg1);
                llvm::Value* file = builder->CreateGlobalStringPtr(node->arg2);
                args.push_back(content);
                args.push_back(file);
                builder->CreateCall(addFileFunc, args);
            }
        } else if (cmdName == "remove_file") {
            if (node->arg1) {
                llvm::Value* file = builder->CreateGlobalStringPtr(node->arg1);
                args.push_back(file);
                builder->CreateCall(removeFileFunc, args);
            }
        } else if (cmdName == "remove_folder") {
            if (node->arg1) {
                llvm::Value* folder = builder->CreateGlobalStringPtr(node->arg1);
                args.push_back(folder);
                builder->CreateCall(removeFolderFunc, args);
            }
        } else if (cmdName == "show_files") {
            if (node->arg1) {
                llvm::Value* folder = builder->CreateGlobalStringPtr(node->arg1);
                args.push_back(folder);
                builder->CreateCall(showFilesFunc, args);
            }
        }
        // Note: You can add more command implementations as needed
    }
};


// Function to generate LLVM IR from AST
extern "C" void generate_llvm_ir(ASTNode* ast, const char* output_file) {
    TaskyCodeGen codegen;
    codegen.generateIR(ast);
    if (output_file) {
        codegen.saveIRToFile(output_file);
    } else {
        codegen.dumpIR();
    }
    // No exception handling
}


#else
// Stub function when LLVM is not available
extern "C" void generate_llvm_ir(ASTNode* ast, const char* output_file) {
    std::cerr << "LLVM backend not enabled. Compile with -DUSE_LLVM to enable." << std::endl;
}
#endif // USE_LLVM
