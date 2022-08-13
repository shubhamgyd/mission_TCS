#include<stdio.h>
#include<string.h>
#include <stdlib.h>

// Helper Function which read the first line from C File
void readFirstLine(char *fileName)
{
    // Get the size of filename
    int sz=sizeof(fileName)/sizeof(fileName[0]);
    // Make a string array
    char string[sz];
    // Copy the char array to string array
    strcpy(string, fileName);
    
    // Step 1: Open the file using fileStream.
    FILE *fptr;
    fptr= fopen(string,"r");

    // Step 2: Read First Line using fgets() 
    char fileFirstTextLine[100];
    fgets(fileFirstTextLine, 100, fptr);


    // Step 3: Close File
    fclose(fptr);

    // Print First Line
    printf("%s",fileFirstTextLine);

}

int main()
{
    char fileName[100];
    scanf("%s",fileName);
    readFirstLine(fileName);
    return 0;
}