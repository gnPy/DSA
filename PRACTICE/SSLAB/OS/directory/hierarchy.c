#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SUB 1000

// Structure representing a file or directory
struct file {
    char name[25];
    bool isFile; // true for file, false for directory
    struct file* sub[MAX_SUB];
    int subCount; // Track the number of subdirectories/files
};

// Function to create a new directory or file
struct file* createFile(char* name, bool isFile) {
    struct file* newFile = (struct file*)malloc(sizeof(struct file));
    strcpy(newFile->name, name);
    newFile->isFile = isFile;
    newFile->subCount = 0;
    return newFile;
}

// Function to add a subdirectory or file to a directory
void addSubFile(struct file* parent, struct file* child) {
    if (parent->subCount < MAX_SUB) {
        parent->sub[parent->subCount++] = child;
    } else {
        printf("Cannot add more subdirectories/files\n");
    }
}

// Function to display the structure
void displayStructure(struct file* root, int level) {
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s\n", root->name);

    for (int i = 0; i < root->subCount; i++) {
        displayStructure(root->sub[i], level + 1);
    }
}

int main() {
    struct file* root = createFile("root", false); // Root directory

    // Creating some directories and files
    struct file* folder1 = createFile("folder1", false);
    struct file* folder2 = createFile("folder2", false);
    struct file* file1 = createFile("file1.txt", true);
    struct file* file2 = createFile("file2.txt", true);

    // Adding directories and files to root
    addSubFile(root, folder1);
    addSubFile(root, file1);

    // Adding subdirectories/files to folder1
    addSubFile(folder1, folder2);
    addSubFile(folder1, file2);

    // Display the structure
    printf("Directory Structure:\n");
    displayStructure(root, 0);

    return 0;
}
