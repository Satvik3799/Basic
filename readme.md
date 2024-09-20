# How C Code Takes Memory Space

This section explains how memory is utilized when a C program has multiple arrays and functions. It details how memory is allocated for both code and arrays in RAM when compiled.

### Memory Layout Explanation

#### 1. **Code Segment (Text Segment)**:
   - The code segment contains the compiled machine instructions for the program. Functions like `main()`, `func1()`, `func2()`, and others are stored in this segment.
   - This segment is usually marked as **read-only** for protection and security purposes.

#### 2. **Data Segment**:
   - The data segment contains global variables and static variables that are initialized at the start of the program.
   - **Initialized Data**: Arrays or variables that are explicitly initialized are stored in this part of the data segment.
   - **Uninitialized Data (BSS Segment)**: Global arrays and variables that are declared but not initialized go into the BSS segment (Block Started by Symbol). This part of the memory is zeroed at runtime, and variables here persist for the duration of the program.

#### 3. **Stack**:
   - The stack is used to store local variables and parameters of functions. It also stores return addresses when functions call other functions.
   - Each time a function is called, memory is pushed onto the stack to hold its local variables and parameters. When the function returns, this memory is popped off the stack.
   - Arrays or variables declared inside functions are stored in this segment for the duration of the function execution.

#### 4. **Heap** (Not used in this example):
   - The heap is used for dynamic memory allocation. If the program uses functions like `malloc()` or `calloc()`, the memory will be allocated from the heap.
   - Unlike the stack, the heap requires explicit allocation and deallocation of memory, and the memory here persists until it is manually freed.

### Array Placement in RAM:

- **Global Arrays**: 
   - Global arrays are allocated in either the **BSS segment** (for uninitialized arrays) or the **Data segment** (for initialized arrays) at the start of the program. These arrays persist for the entire runtime of the program.
   
- **Local Arrays**:
   - Arrays declared inside functions are allocated memory in the **stack**. These arrays only exist while the function is executing. When the function ends, the memory used by these arrays is deallocated as the stack unwinds.

### Memory Distribution Summary:

- **Code Segment**: Stores machine-level instructions, i.e., compiled code for functions.
- **Data Segment**:
   - **Initialized Data**: Contains initialized global or static variables.
   - **Uninitialized Data (BSS)**: Contains uninitialized global or static variables, initialized to zero at runtime.
- **Stack**: Contains local variables, function parameters, and return addresses for active functions.
- **Heap**: Reserved for dynamically allocated memory, managed manually by the programmer.



# Compilation Process for `cc main.c -o main -lm`

When you compile a C program using `cc main.c -o main -lm`, the process involves several stages: preprocessing, compilation, assembly, and linking. Here’s an overview of each stage:

### Steps in the Compilation Process:

1. **Preprocessing**: 
   - Expands macros, includes header files, and processes directives like `#include`, `#define`.
   - Example command to see preprocessed output:  
     ```bash
     cc -E main.c > main.i
     ```
   - Output: Preprocessed C code without macros or includes.

2. **Compilation**: 
   - Converts the preprocessed code into assembly instructions for the target architecture.
   - Example command to see assembly output:  
     ```bash
     cc -S main.c -o main.s
     ```
   - Output: Assembly file `.s`.

3. **Assembly**: 
   - Converts the assembly code into machine code (object files).
   - Output: Object file `.o`.

4. **Linking**: 
   - Combines object files and external libraries into a single executable.
   - Resolves symbols (e.g., external function calls) and links with libraries like `libm` (math library for `sqrt()`, etc.).
   - Example command to link and generate a memory map:
     ```bash
     cc main.c -o main -lm -Wl,-Map=output.map
     ```
   - Output: Final executable `main` and optional map file `output.map`.

### Memory Layout and Sections:

1. **Code Segment (Text Segment)**:  
   Contains the machine instructions (compiled code). Typically, this is **read-only**.

2. **Data Segment**:  
   - **Initialized Data**: Stores global and static variables that are initialized.
   - **Uninitialized Data (BSS)**: Holds uninitialized global and static variables, initialized to zero at runtime.

3. **Heap**:  
   Holds dynamically allocated memory (e.g., using `malloc()`).

4. **Stack**:  
   Used for local variables and function calls. Grows/shrinks during execution.

### The `-lm` Option:

The `-lm` flag tells the linker to link the math library (`libm`) required for functions like `sqrt()`. If you don't include `-lm`, you will encounter "undefined reference" errors for math functions.
