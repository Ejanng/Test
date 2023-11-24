#include <stdio.h>
#include <string.h>
#include <conio.h>
//#include <windows.h> //Hindi gumagana sa android
#include <stdlib.h>
#include <time.h>
void login() {
    int loginAttempts = 0;
    int i = 0;
    char enteredUsername[10], enteredPassword[10], ch;
    char correctUsername[10] = "user";
    char correctPassword[10] = "pass";

    do {
        printf("\n  ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ");
        printf("\n                       ENTER USERNAME: ");
        scanf("%s", enteredUsername);
        printf("\n                       ENTER PASSWORD: ");

        i = 0;
        while (i < 10) {
            enteredPassword[i] = getch();
            ch = enteredPassword[i];
            if (strcmp(ch, "correctPassword") == 0){
                break;
            }
            else {
                printf("%c",ch);
            }
            i++;
        }
        enteredPassword[i] = '\0';
        i = 0;

        if (strcmp(enteredUsername, correctUsername) == 0 && strcmp(enteredPassword, correctPassword) == 0) {
            printf("\n\n\n       WELCOME TO My System");
            printf("\n LOADING PLEASE WAIT... \n");
            for (i = 0; i < 3; i++) {
                printf(".");
                sleep(500);
            }
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch(); // Holds the screen
            break;
        } else {
            printf("\n        SORRY! LOGIN IS UNSUCCESSFUL");
            loginAttempts++;
            getch(); // Holds the screen
        }
    } while (loginAttempts <= 2);

    if (loginAttempts > 2) {
        printf("\nSorry, you have entered the wrong username and password four times!!!\n");
        getch();
    }

    system("cls");
}