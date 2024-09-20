#include <stdio.h>

// Global arrays (stored in data or BSS segments)
int array1[10], array2[10], array3[10]; // BSS (uninitialized global arrays)
int array4[10] = {0};  // Data Segment (initialized to zero)

// Function prototypes
void func1(int arr[]);
void func2(int arr[]);
void func3(int arr[]);
void func4(int arr[]);
void func5(int arr[]);

int main() {
    int array5[10];  // Stack (local variable)

    // Pass the array to different functions
    func1(array1);
    func2(array2);
    func3(array3);
    func4(array4);
    func5(array5);

    return 0;
}

void func1(int arr[]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
}

void func2(int arr[]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }
}

void func3(int arr[]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 5;
    }
}

void func4(int arr[]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = i * i;
    }
}

void func5(int arr[]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = 10 - i;
    }
}
