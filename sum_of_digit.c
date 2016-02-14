#include <stdio.h>
#include <string.h>

#define THROW_EXCEPTION -1

int sumHold;
// function prototype
int seperateDigit(int val);
void sanitizeUserValue(const char* str);

int main(int argc, const char* argv[])
{
    if ((argc != 2) || (argv[1] == NULL))
    {
        fprintf(stderr, "Expected two command line arguments\n");
        fprintf(stderr, "USAGE: %s [positive integer value]\n", argv[0]);
        return THROW_EXCEPTION;
    }
    else
    {
        const char* argVector = argv[1];

        sanitizeUserValue(argVector);
    }

    return 0;
}

void sanitizeUserValue(const char* str)
{
    if (strchr(str, '-') != NULL)
    {
        fprintf(stderr, "input must be non-negative!\n");
        return;
    }

    int value;
    char ch;
    if (sscanf(str, "%d %c", &value, &ch) == 1)
    {
        // calling seperateDigit function
        fprintf(stdout, "the sum of %d spltting = %d\n", value, seperateDigit(value));
    }
    else
    {
        fprintf(stderr, "%s is not an integer value\n", str);
        return;
    }
}

// implementing seperateDigit recursive function
int seperateDigit(int val)
{
    // base case
    if (val == 0)
    {
        return 0;
    }
    else
    {
        int digit = val % 10;
        val /= 10;
        // calling seperateDigit function
        seperateDigit(val);

        return sumHold = digit + sumHold;
    }
}
