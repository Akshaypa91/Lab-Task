#include <stdio.h>

int main()
{
    int a, b, c, d;
    int temp;

    // Read four integers
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Sort the integers using a simple bubble sort approach
    // Store the integers in an array for easier manipulation
    int arr[4] = {a, b, c, d};

    // Bubble sort
    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = 0; j < 4 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted integers
    printf("The integers in increasing order are: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
