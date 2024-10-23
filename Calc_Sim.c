#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int handle_bitwise_shift(int operand1, char operator[], int operand2)
{
    if (strcmp(operator, "<<") == 0)
    {
        return operand1 << operand2;
    }
    else if (strcmp(operator, ">>") == 0)
    {
        return operand1 >> operand2;
    }
    else
    {
        printf("Invalid bitwise operator!\n");
        return 0;
    }
}

int main()
{
    char operator[3];
    float operand1, operand2;
    int int_operand1, int_operand2;

    while (1)
    {
        printf("Enter operand operator operand (or type 'exit' to quit): ");

        if (scanf("%f %s %f", &operand1, operator, & operand2) != 3)
        {
            char exit_check[5];
            scanf("%s", exit_check);
            if (strcmp(exit_check, "exit") == 0)
            {
                break;
            }
            else
            {
                printf("Invalid input. Please try again.\n");
                continue;
            }
        }

        if (strcmp(operator, "+") == 0)
        {
            printf("Result: %.2f\n", operand1 + operand2);
        }
        else if (strcmp(operator, "-") == 0)
        {
            printf("Result: %.2f\n", operand1 - operand2);
        }
        else if (strcmp(operator, "*") == 0)
        {
            printf("Result: %.2f\n", operand1 * operand2);
        }
        else if (strcmp(operator, "/") == 0)
        {
            if (operand2 != 0)
            {
                printf("Result: %.2f\n", operand1 / operand2);
            }
            else
            {
                printf("Error: Division by zero!\n");
            }
        }
        else if (strcmp(operator, "%") == 0)
        {
            int_operand1 = (int)operand1;
            int_operand2 = (int)operand2;
            if (int_operand2 != 0)
            {
                printf("Result: %d\n", int_operand1 % int_operand2);
            }
            else
            {
                printf("Error: Division by zero!\n");
            }
        }
        else if (strcmp(operator, "<<") == 0 || strcmp(operator, ">>") == 0)
        {
            int_operand1 = (int)operand1;
            int_operand2 = (int)operand2;
            printf("Result: %d\n", handle_bitwise_shift(int_operand1, operator, int_operand2));
        }
        else
        {
            printf("Invalid operator. Please try again.\n");
        }
    }

    printf("Calculator exited.\n");
    return 0;
}
