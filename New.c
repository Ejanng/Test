#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct Record {
    char date[15];
    char description[500];
    float amount;
    float spentAmount;
};

struct BankSystem {
    float balance;
    struct Record transaction[100];
    int transactionCount;
};

void addrecord(struct BankSystem *bank);
void viewrecords(struct BankSystem *bank);
void spend(struct BankSystem *bank);
void balancestatus(struct BankSystem *bank);
void login();

int main() {
    login();
    system("cls");

    int choice;
    struct BankSystem bank = {0, 0};

    while (1) {
        printf("\n\n\t\t:MAIN MENU:");
        printf("\n\n\tPress <1> To ADD RECORD\t");
        printf("\n\tPress <2> To VIEW RECORDS\t");
        printf("\n\tPress <3> To SPEND\t");
        printf("\n\tPress <4> To BALANCE STATUS\t");
        printf("\n\tPress <5> To EXIT\t\t");

        printf("\n\n\tENTER YOUR CHOICE:");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addrecord(&bank);
            break;
        case 2:
            viewrecords(&bank);
            break;
        case 3:
            spend(&bank);
            break;
        case 4:
            balancestatus(&bank);
            getch();
            break;
        case 5:
            printf("\nExiting program...\n");
            exit(0);
        default:
            printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
        }

        system("cls");
    }

    return 0;
}

void addrecord(struct BankSystem *bank) {
    char another = 'Y';
    system("cls");

    printf("\n\n\t\t:::::::::::::::::::::::::::\n");
    printf("\t\t: WELCOME TO ADD RECORDS :");
    printf("\n\t\t:::::::::::::::::::::::::::\n\n");

    while(another == 'Y'|| another == 'y'){
    if (bank->transactionCount < 100) {
        printf("Enter date (e.g., DD/MM/YYYY): ");
        scanf("%s", (*bank).transaction[bank->transactionCount].date);

        printf("Enter description: ");
        scanf("%s", bank->transaction[bank->transactionCount].description);

        printf("Enter amount: ");
        scanf("%f", &bank->transaction[bank->transactionCount].amount);

        bank->balance += bank->transaction[bank->transactionCount].amount;
        bank->transactionCount++;

    } else {
        printf("Transaction limit reached. Cannot add more records.\n");
        break;
    }
        printf("\n\tDO YOU WANT TO ADD ANOTHER RECORD...(Y/N) ");
        fflush(stdin);  
        scanf(" %c", &another);
    }
		printf("Press the Enter Key....");

    getch();
}

void viewrecords(struct BankSystem *bank) {
    system("cls");

    printf("\n\n\t\t:::::::::::::::::::::::::::\n");
    printf("\t\t:   VIEW TRANSACTION RECORDS   :");
    printf("\n\t\t:::::::::::::::::::::::::::\n\n");

    if (bank->transactionCount == 0) {
        printf("No records available.\n");
    } else {
        printf("%-15s%-25s%-10s\n", "Date", "Description", "Amount");

        for (int i = 0; i < bank->transactionCount; i++) {
            printf("%-15s%-25s$%-10.2f\n",
                   bank->transaction[i].date,
                   bank->transaction[i].description,
                   bank->transaction[i].amount);
        }
    }

    getch();
}

void spend(struct BankSystem *bank) {
    system("cls");

    printf("\n\n\t\t:::::::::::::::::::::::::::\n");
    printf("\t\t:        SPEND MONEY         :");
    printf("\n\t\t:::::::::::::::::::::::::::\n\n");

    float spentAmount;
    int s; 
    printf("Enter amount to spend: ");
    scanf("%f", &spentAmount);

    if (spentAmount > bank->balance) {
        printf("Insufficient funds. Cannot spend more than the available balance.\n");
    } else {
        printf("Enter description for spending: ");
        scanf("%s", bank->transaction[bank->transactionCount].description);
        printf("\n Transaction successful.\n You spent %.2f for %s. \n %s New balance: %.2f\n", spentAmount, bank->transaction[bank->transactionCount].description,bank->transaction, bank->balance - spentAmount);

        bank->balance -= spentAmount;
        bank->transaction[bank->transactionCount].amount = -spentAmount;
        strcpy(bank->transaction[bank->transactionCount].date, "SPEND");
        bank->transactionCount++;




        printf("Money spent successfully.\n");

 //       for ( s = 0; s < bank->transactionCount;s++)
 //       {
 //            printf("%-15s%-25s$%-10.2f\n",
 //                  bank->transaction[s].amount,
 //                  bank->transaction[s].description,
 //                  bank->transaction[s].spentAmount);
 //       }

    }

    getch();
}

void balancestatus(struct BankSystem *bank) {

    system("cls");
    printf("\n\n\t\t:::::::::::::::::::::::::::\n");
    printf("\t\t:      BALANCE STATUS        :");
    printf("\n\t\t:::::::::::::::::::::::::::\n\n");

    printf("Current Balance: $%.2f\n", bank->balance);

    getch();
}

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
