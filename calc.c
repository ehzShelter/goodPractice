#include <stdio.h>
#include <limits.h>
#include <float.h>

void throwException(void);
void summation(void);
void substraction(void);
void multiplication(void);
void division(void);
void toThePower(void);

int main(void)
{
    char choice;
    printf("Please press desired key to continue ... \n\n ");

    do
    {
        printf("\nMENU\n\n"
                " + : addition\n"
                " - : substraction\n "
                " * : multiplication\n "
                " / : division\n"
                " ^ : power\n"
                " q : quit\n\n");

        printf("Command: ");
        scanf(" %c ", &choice);

        switch(choice)
        {
            case '+': summation(); break;
            case '-': substraction(); break;
            case '*': multiplication(); break;
            case '/': division(); break;
            case '^': toThePower(); break;
            case 'q': break;

            default:
            {
                fprintf(stderr, "you didn't press expected key :(\n");
            }
         }
    }
    while (choice != 'q');
}

void summation(void)
{
    size_t howMany;
    printf("How many numbers you want to add: ");
    scanf("%zd", &howMany);
    float arr[howMany];

    printf("enter the values: ");
    for (size_t i = 0; i < howMany; i++)
    {
         scanf("%f", &arr[i]);
    }

    float Sum = 0;
    for (size_t i = 0; i < howMany; i++)
    {
         Sum = Sum + arr[i];
    }

    if (Sum > FLT_MAX || Sum < FLT_MIN)
    {
       throwException();
       return;
    }
    printf("Summation is = %.2f\n", Sum);
}

void substraction(void)
{
    float num1, num2, Subtraction;
    printf("\n\nEnter two number: ");
    scanf("%f%f", &num1, &num2);
    Subtraction = num1 - num2;

    if (Subtraction > FLT_MAX)
    {
        throwException();
        return;
    }
    printf("\nSubtraction is : %.2f\n", Subtraction);
}

void multiplication(void)
{
    size_t howMany;
    printf("How many numbers you want to multiply: ");
    scanf("%zd", &howMany);
    float arr[howMany];
    printf("enter the values: ");
    for (size_t i = 0; i < howMany; i++)
    {
        scanf("%f", &arr[i]);
    }
    float multi = 1.00;

    for (size_t i = 0; i < howMany; i++)
    {
        multi = multi * arr[i];
    }

    if (multi > FLT_MAX)
    {
       throwException();
       return;
    }
    printf("multiplication is = %.2f\n", multi);
}

void division(void)
{
    float num1, num2, result;
    printf("\nEnter two number: ");
    scanf("%f%f", &num1, &num2);

    if (num2 == 0)
    {
        printf("cannot divided by zero\n");
        printf("Math error\n");
        return;
    }

    result = num1 / num2;
    if (result > FLT_MAX)
    {
        throwException();
        return;
    }
    printf("\nDivision  is : %.2f\n", result);
}

void toThePower(void)
{
    int x;
    int n;
    printf("enter base and power: ");
    scanf("%d%d", &x, &n);

    if (x == 0 || n < 0 || n > (INT_MAX / 2) || x > (INT_MAX / 2))
    {
        printf("base and power should be positive and in minimal range\n");
        return;
    }

    long long int multiply = 1;
    for (int i = 1; i <= n; i++)
    {
        multiply = multiply * x;
    }

    if (x > 0 && (multiply > LLONG_MAX  || multiply <= 0))
    {
        throwException();
        return;
    }
    else if (x < 0 && (multiply < LLONG_MIN || multiply >= 0))
    {
        throwException();
        return;
    }
    else
    {
        printf("%d to the power %u = %lld\n", x, n, multiply);
    }
}

void throwException(void)
{
    fprintf(stderr, "Overflow!!!!\n");
}
