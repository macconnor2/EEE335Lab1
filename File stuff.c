//
// Created by macco on 18/01/2022.
//

#include "File stuff.h"
#include "stdio.h"
//#include "stdlib.h"
#include "unistd.h"

#define  MAX_BUF 250

void createbook(char Source[], char Name[]){


    //todo error handling if the number of parameters are passed

    //Copy the working path at the start
    char Startpath[MAX_BUF];
    getcwd(Startpath, MAX_BUF);

    // Move the working path to where the files are
    chdir(Source);


    // Create the merged text file
    FILE *pasteme = fopen(Name, "w");

    //copy the title page
    char letter; // Variable used to copy characters
    FILE *copyme = fopen("cover.txt","r");
    // copy the characters from copy to paste
    while  ((letter = fgetc(copyme)) != EOF) { // tests to see if the new chapter exists
        fputc(letter, pasteme);
    }
    fclose(copyme);
    char ChapterFile[20];
    int i = 1;
    // open the file chapter one
    sprintf(ChapterFile, "%d.chapter", i);


    copyme = fopen( ChapterFile/* Need to use the i plus ".chapter" */, "r" );
    while (copyme != NULL){
        // copy the characters from copy to paste
        while  ((letter = fgetc(copyme)) != EOF) { // tests to see if the new chapter exists
            fputc(letter, pasteme);
        }
        //close the file for the old chapter
        fprintf(pasteme,"\n");
        fprintf(pasteme,"\n");
        fclose(copyme);

        // iterate the counter and generate the new filename
        i++;
        sprintf(ChapterFile, "%d.chapter", i);
        // open the new chapter

        copyme = fopen( ChapterFile, "r");
    }

    //reset the working directory
    chdir(Startpath);
}
int main() {
//    char filepath[MAX_BUF];
//    char bookname[20];
//    printf("Welcome to the book combiner\n");
//    printf("Please enter the filepath for the books you wish to combine\n\t");
//    fgets(filepath,MAX_BUF,stdin);
//    printf("The filepath is");
//    printf(filepath);
//    printf("\nPlease enter the file name you wish to use\n\t");
//    fgets(bookname,20,stdin);
//    printf("\nThank you\n\nPrinting book");

    createbook("C:\\Users\\macco\\OneDrive\\Documents\\School\\Year3\\03Winter\\EEE335\\Labs\\Lab1"
                       "\\Textforthechapter", "TestBook1.txt" );



    return 0;
}