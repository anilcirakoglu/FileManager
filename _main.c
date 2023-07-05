#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Creates a new file with the given name.
void createFile(const char* fileName) {
    FILE* file;
    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("Failed to create the file.\n");
    }
    fclose(file);
    printf("The file has been created successfully. %s\n", fileName);
    return;
}

//Deletes an existing file with the given name.
void deleteFile(const char* fileName) {
    if (remove(fileName) == 0)
        printf("File removed: %s\n", fileName);
    else
        printf("File could not be deleted: %s\n", fileName);
}

//Renames an existing file with the given old and new names.
void renameFile(const char* oldName, const char* newName) {
    if (rename(oldName, newName) == 0)
        printf("File renamed: %s -> %s\n", oldName, newName);
    else
        printf("File could not be renamed: %s\n", oldName);
}

//Copies a file from the source location to the destination location.
void copyFile(const char* sourceFile, const char* destFile) {
    FILE* source = fopen(sourceFile, "rb");
    FILE* dest = fopen(destFile, "wb");
    if (source == NULL || dest == NULL) {
        printf("File could not be copied\n");
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(source);
    fclose(dest);
    printf("File copied: %s ----> %s\n", sourceFile, destFile);
}

//Moves a file from the source location to the destination folder.
void moveFile(const char* sourceFile, const char* destFolder) {
    char destPath[256];
    snprintf(destPath, sizeof(destPath), "%s/%s", destFolder, sourceFile);
    if (rename(sourceFile, destPath) == 0)
        printf("Folder moved: %s ----> %s\n", sourceFile, destPath);
    else
        printf("Folder could not moved: %s\n", sourceFile);
}

//Appends text to the end of an existing file
void appendToFile(const char* fileName, const char* text) {
    FILE* file = fopen(fileName, "a");
    if (file == NULL) {
        printf("File could not open.\n");
        return;
    }
    fprintf(file, "%s", text);
    fclose(file);
    printf("Text added to file: %s\n", fileName);
}

//Inserts text at a specific position within an existing file.
void insertInFile(const char* fileName, const char* text, int position) {
    FILE* file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("File could not open.\n"); 
        return;
    }

    fseek(file, position, SEEK_SET);
    char buffer[1024];
    size_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
    fseek(file, position, SEEK_SET);
    fwrite(text, 1, strlen(text), file);
    fwrite(buffer, 1, bytesRead, file);

    fclose(file);
    printf("text added to file: %s\n", fileName);
}

//Removes all text from an existing file
void removeAllText(const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("File could not open\n");
        return;
    }
    fclose(file);
    printf("All text removedd from file: %s\n", fileName);
}

//Displays the content of a text file, allowing pagination.
void showTextFile(const char* fileName, int linesPerPage) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File could not open.\n");
        return;
    }

    char buffer[1024];
    int lineNumber = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
        lineNumber++;
        if (lineNumber % linesPerPage == 0) {
            printf("Continue , write any word.--\n");
            getchar();
        }
    }

    fclose(file);
    printf(" //File ended.\n");
}


// It displays a menu of options for file manipulation.
// Based on the user's choice, it calls the corresponding function to perform the desired operation.
int main() {

    printf("Welcome isik_filemanager File Program !\n");
    printf("----------------------------------\n\n");

    int choice;
    char yesOrNo;
    char input;
    char fileName[256];
    char text[2048];
    int position;
    int linesPerPage;

    while (1) {
        printf("1. Create a new file\n");
        printf("2. Delete an existing file\n");
        printf("3. Rename an existing file\n");
        printf("4. Copy a file\n");
        printf("5. Move a file from one folder to another\n");
        printf("6. Append text to the end of a file\n");
        printf("7. Insert text in a specific position within the file\n");
        printf("8. Remove all text present in a file\n");
        printf("9. Show the content of a text data store\n");
        printf("10. exit\n");
        printf("<-------Select One------->\n");
        
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("File name: ");
                scanf("%s", fileName);
                createFile(fileName);   
                printf("Do you want to turn. Write 'y' or 'Y' \n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }
                
            case 2:
                printf("File name: ");
                scanf("%s", fileName);
                deleteFile(fileName);
                printf("Do you want to turn. Write 'y' or 'Y'\n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }
            case 3:
                printf("Old file name: ");
                scanf("%s", fileName);
                printf("New file re-name");
                scanf("%s", text);
                renameFile(fileName, text);
                printf("Do you want to turn. Write 'y' or 'Y' \n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }
            case 4:
                printf("Source file name: ");
                scanf("%s", fileName);
                printf("Destination file name: ");
                scanf("%s", text);
                copyFile(fileName, text);
                printf("Do you want to turn. Write 'y' or 'Y' \n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }
            case 5:
                printf("Source file name: ");
                scanf("%s", fileName);
                printf("Destination file name: ");
                scanf("%s", text);
                moveFile(fileName, text);
                printf("Do you want to turn. Write 'y' or 'Y' \n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }
            case 6:
                printf("File name: ");
                scanf("%s", fileName);
                printf("The text you want to add: ");
                getchar();
                fgets(text, sizeof(text), stdin);
                appendToFile(fileName, text);
                printf("Do you want to turn. Write 'y' or 'Y' \n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }
            case 7:
                printf("File name: ");
                scanf("%s", fileName);
                printf("The text you want to add: ");
                getchar();
                fgets(text, sizeof(text), stdin);
                printf("Enter location (only char): ");
                scanf("%d", &position);
                insertInFile(fileName, text, position);
                printf("Do you want to turn. Write 'y' or 'Y' \n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }
            case 8:
                printf("File name: ");
                scanf("%s", fileName);
                removeAllText(fileName);
                printf("Do you want to turn. Write 'y' or 'Y' \n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }
            case 9:
                printf("File name. ");
                scanf("%s", fileName);
                printf("how many rows to show on each page");
                scanf("%d", &linesPerPage);
                showTextFile(fileName, linesPerPage);
                printf("Do you want to turn. Write 'y' or 'Y' \n");
                scanf("%s" , &yesOrNo);
                if(yesOrNo == 'y' || yesOrNo == 'Y'){
                    break;
                }else{ 
                    printf("exiting the program....\n"); 
                    printf("See you next time.\n ");
                    exit(0); }  
            case 10:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Error! Try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}
