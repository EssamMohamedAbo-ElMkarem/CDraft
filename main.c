#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265359

#ifndef PI
    #define PI 3.14159265359
#endif

extern errno; //variable declaration

void Math();
void NotePad();
void About();
void other();

struct Note
{
    char note_name[100];
    char *note_content;
};


int main()
{
    printf("**************************\n");
    printf("Welcome to our \"C\" program\n");
    printf("**************************\n");
    printf("1-Math    2-NotePad   3-About\n");

    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            Math();
            break;
        case 2:
            NotePad();
            break;
        case 3:
            About();
            break;
        default:
            printf("Please, Enter a valid choice.\n");
            main();
            break;
    }
    return 0;
}

void Math()
{
    int first, second;
    float result;
    printf("The first number is>>");
    scanf("%d", &first);
    printf("The second number is>>");
    scanf("%d", &second);
    puts("\n");
    printf("1-Add   2-Subtraction   3-Multiplication   4-Division   5-Other\n");
    printf("99-Back\n");
    short choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            result = first + second;
            break;
        case 2:
            result = first - second;
            break;
        case 3:
            result = first * second;
            break;
        case 4:
            if(second == 0){
                printf("Can't divide by zero x_x");
            }else{
                result = (float)first / (float)second;
            }
            break;
        case 5:
            other();
            break;
        case 99:
            main();
        default:
            puts("Enter a a valid value");
            Math();
    }
    printf("The result is %d\n", *(&result));
    Math();
}

 void other(){
    printf("Enter the value of X>>");
    float x, result;
    scanf("%f", &x);
    printf("1-sin(X)  2-cos(X)  3-tan(X)  4-Log(X)  5-PrimeTest\n");
    short choice;
    scanf("%d", choice);
    switch(choice)
    {
        case 1://need
            result = sin((x/180)*3.14);
            break;
        default:
            puts("Please, Enter a valid value");
            Math();
    }
    printf("%f", *(&result));
}

void NotePad()
{

    FILE *file;

    printf("1- Write a new note\n");
    printf("2- Read an existing note\n");
    puts("3-Back");

    int choice;
    scanf("%d", &choice);
    if(choice == 1){
        struct Note note;
        printf("File path/name is >>");
        scanf("%s", &note.note_name);
        note.note_content = malloc(200*sizeof(int));
        printf("Note>>");
        scanf("%s", note.note_content);
        file = fopen(note.note_name, "w+");
        fputs(note.note_content, file);
        fclose(file);
        NotePad();
    }
    else if(choice == 2){//neeeed
        char note_name[100];
        char *buffer;
        buffer = malloc(200*sizeof(int));
        printf("File path/name is >>");
        scanf("%s", &note_name);
        file = fopen(note_name, "r");
        rewind(file);
        fscanf(file, "%s", buffer);
        fclose(file);
        printf("The note is: %s\n", buffer);
        fclose(file);
    }
    else if(choice == 3){
        main();
    }
    else{
        puts("Please, Enter a valid value");
        main();
    }
    NotePad();
}

void About()
{
    printf("Powered by Essam Mohamed.\n\n");
    main();
}
