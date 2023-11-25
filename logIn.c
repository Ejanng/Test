#include <stdio.h>
#include <string.h>
#include <conio.h> // For getch()
#include <windows.h> // For Sleep() and  <stdlib>system("cls")
#include <time.h>

struct Record {
    char date[15];
    char name[30];
    char amount[25];
    char note[500];
};
void addrecord();
void viewrecords();
void editrecord();
void deleterecord();
void balancestatus();

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
            if (ch == 13)
                break;
            else
                printf("*");
            i++;
        }
        enteredPassword[i] = '\0';
        i = 0;

        if (strcmp(enteredUsername, correctUsername) == 0 && strcmp(enteredPassword, correctPassword) == 0) {
            printf("\n\n\n       WELCOME TO My System");
            printf("\n LOADING PLEASE WAIT... \n");
            for (i = 0; i < 3; i++) {
                printf(".");
                Sleep(500);
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


int main() {
    login();
    time_t currentTime;
    time(&currentTime);

    int choice;
    
    printf("\n\n\t:::::::::::::::::::::::::::::::::::\n");

    printf("\t:STUDENT SAVING  MANAGEMENT SYSTEM:\n");

    printf("\t:::::::::::::::::::::::::::::::::::");

     while (1) {
        printf("\n\n\t\t:MAIN MENU:");
        printf("\n\n\tPress <1> To ADD RECORD\t");
        printf("\n\tPress <2> To VIEW RECORDS\t");
        printf("\n\tPress <3> To EDIT RECORDS\t");
        printf("\n\tPress <4> To DELETE RECORD\t");
        printf("\n\tPress <5> To BALANCE STATUS\t");
        printf("\n\tPress <6> To EXIT\t\t");
        
        printf("\n\n\tCurrent date and time: %s", ctime(&currentTime));

        printf("\n\n\tENTER YOUR CHOICE:");
        scanf("%d", &choice);


        switch (choice)
        {
        case 1:
            addrecord();
            break;
        case 2: 
            viewrecords();
        case 3: 
            editrecord();
        case 4: 
            deleterecord();
        case 5: 
            balancestatus();
        
        case 6: 
            getch();
            break;
        }
                system("cls");
}
    return 0;
}

void addrecord(){
    system("cls");
    FILE *ar ;
    char filename[15] = "records.txt";
    int choice; 
    char another = 'Y';
     struct Record record;
    


    printf("\n\n\t\t:::::::::::::::::::::::::::\n");

    printf("\t\t: WELCOME TO THE ADD RECORDS :");

    printf("\n\t\t:::::::::::::::::::::::::::\n\n");

    printf("\n\n\tENTER DATE OF YOUR RECORD [yyyy-mm-dd]: ");
    fflush(stdin);
    gets(filename);

    ar = fopen(filename, "ab+");

    if (ar == NULL)
    {
    ar = fopen(filename, "wb+");
    if (ar == NULL)
    {
        printf("\n SYSTEM ERROR");
        getch();
    }
    
    }
    while (another == 'Y'|| another == 'y')
    {
        choice = 0;
        fflush(stdin);
        printf("\n\t Enter TIME [hh::mm]:  ");
        scanf("%s", record.date);
        gets(record.date);

        printf("\n\t Enter NAME: ");
        scanf("%s", record.name);
        gets(record.name);

        printf("\n\t Enter AMOUNT: ");
        scanf("%s", record.amount);
        gets(record.amount);

         printf("\n\t ADD NOTE: ");
        scanf("%s", record.note);
        gets(record.note);
        fwrite(&record, sizeof(record), 1, ar);
            printf("\nYOUR RECORD IS ADDED SUCCESSFULLY...\n");
             printf("\n\tDO YOU WANT TO ADD ANOTHER RECORD...(Y/N) ");
        fflush(stdin);
        another = getchar();
    }

    fclose(ar);
    printf("\n\nPRESS ANY KEY TO EXIT...");
    getch();
}



void viewrecords(){
system("cls");

    FILE *ar;
    char filename[] = "records.txt"; // Specify the filename containing the records
    struct Record record;

    ar = fopen(filename, "rb");

    if (ar == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\nRecords:\n\n");

    while (fread(&record, sizeof(struct Record), 1, ar) == 1) {
        printf("Date: %s\n", record.date);
        printf("Name: %s\n", record.name);
        printf("Amount: %s\n", record.amount);
        printf("Note: %s\n", record.note);
        printf("\n");
    }

    fclose(ar);
}
void editrecord(){
     
}

void deleterecord(){
 
}

void balancestatus(){
    
}

