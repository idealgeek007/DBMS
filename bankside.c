#include <stdio.h>

struct BankAccount
{
    int accountNumber;
    int balance;
    int code;
};
int t, m, k, n;
void initialise()
{
    printf("Enter the value for total fund in ATM for today: ");
    scanf("%d", &t);

    printf("Enter the value for max withdrawal amount per day: ");
    scanf("%d", &k);

    printf("Enter the value for max withdrawal amount per transaction: ");
    scanf("%d", &m);

    printf("Enter the value for  minimum cash in ATM to permit transaction: ");
    scanf("%d", &n);

    // Open a file for writing
    FILE *file = fopen("initdata.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    // Write the values to the file
    fprintf(file, "%d %d %d %d", t, m, n, k);
    fclose(file);

    printf("Data saved to file successfully.\n");
}

int main()
{
    struct BankAccount accounts[5];

    initialise();                           // initialize the variables



    FILE *file = fopen("bank_data.csv", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read the data from the file in CSV format
    for (int i = 0; i < 5; i++)
    {
        if (fscanf(file, "%d,%d,%d\n", &accounts[i].accountNumber, &accounts[i].balance,&accounts[i].code) == 2)
        {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Balance: %d\n", accounts[i].balance);
        }
    }

    fclose(file);
    return 0;
}