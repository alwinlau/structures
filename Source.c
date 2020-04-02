#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// customer info
typedef struct customer {
    char firstName[30];
    char lastName[30];
    char street[35];
    char city[20];
    char state[3];
    int zip;
    char phone[15];
    int accountId;
} cust;
cust cus[10];

int main() {
    int x;
    int y = 0;
    int ask;
    char state[3];
    // enter 10 customers info
    for (x = 0; x < 10; x++) {
        printf("\nPlease enter customer %d info (first name last name phone number) ", x + 1);
        scanf_s("%s %s %s", &cus[x].firstName, 30, &cus[x].lastName, 30, &cus[x].phone, 15);
        printf("\nPlease enter the address for customer %d (street city state zip code) ", x + 1);
        scanf_s("%s %s %s %d", &cus[x].street, 35, &cus[x].city, 20, &cus[x].state, 3, &cus[x].zip);
        printf("\n Please enter the account ID for customer %d ", x + 1);
        scanf_s("%d", &cus[x].accountId);
    } // end for loop
    do {
        system("cls");
        // get the state for the customer info to display
        printf("\nPlease enter the state of the customers you want displayed ");
        scanf_s("%s", state, 3);
        printf("\n\nThe customers from %s are: ", state);
        // check to see if any customers are from the state specified
        for (x = 0; x < 10; x++) {
            if (strcmp(cus[x].state, state) == 0) {
                printf("\n\nData for customer %d", x + 1);
                printf("\nAccount # %d", cus[x].accountId);
                printf("\nName: %s %s", cus[x].firstName, cus[x].lastName);
                printf("\nAddress: %s \n\t%s, %s %d", cus[x].street, cus[x].city, cus[x].state, cus[x].zip);
                printf("\nPhone number: %s\n", cus[x].phone);
                y += 1;
            } // end if
        } // end for loop
        if (y == 0) {
            printf("\n\nNo customers found from the state of %s", state);
        } // end if
        printf("\n\nDo you want to check another state? Enter 1 for yes or 0 for no ");
        scanf_s("%d", &ask);
    } while (ask != 0); // end do while loop
    return 0;
} // end main