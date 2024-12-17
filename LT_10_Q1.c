#include <stdio.h>
#include <string.h>

#define Saving 1
#define Check 2
#define Business 3

struct account {
    int accid;
    char name[32];
    double amount;
    int type;
};

void fsn(struct account accounts[], int n)
{
    int minInx = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(accounts[i].name, accounts[minInx].name) < 0) {
            minInx = i;
        }
    }
    printf("%d\n", accounts[minInx].accid);
    printf("%d\n", accounts[minInx].name);
    printf("%d\n", accounts[minInx].amount);
    if (accounts[minInx].type == Saving) {
        printf("Saving");
    }
    else if (accounts[minInx].type == Check) {
        printf("Check");
    }
    else if(accounts[minInx].type == Business) {
        printf("Business");
    }
    else {
        printf("Not Found");
    }
}

int main(void)
{
    struct account accounts[] = {
        {101, "Hello", 1400.3, Saving},
        {102, "Monster", 4322.67, Check},
        {103, "Coep", 3204.65, Business},
    };
    int numAcc = sizeof(accounts) / sizeof(accounts[0]);
    fsn(accounts, numAcc);
    return 0;
}