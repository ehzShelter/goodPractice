#include <stdio.h>

void funcSscanf(char* str);
void funcSscanfString(char* str);
void funcSscanfStringNonChar(char* str);

int main(void)
{
    char buffer1[] = "f420Nayeem";
    funcSscanf(buffer1);

    char buffer2[] = "Chika420Nayeem";
    funcSscanf(buffer2);

    char buffer3[] = "hiphop";
    funcSscanf(buffer3);

    char buffer4[] = "7294";
    funcSscanf(buffer4);

    char buffer5[] = "757f";
    funcSscanf(buffer5);

    char buffer6[] = "-475";
    funcSscanf(buffer6);

    char buffer7[] = "content=0&website=Google";
    funcSscanfString(buffer7);

    char buffer8[] = "19 cool kid";
    funcSscanfStringNonChar(buffer8);
}

void funcSscanf(char* str)
{
    int digit;
    char character;

    printf("Parsing %d in buffer %s\n", sscanf(str, "%c%d%c", &character, &digit, &character), str);

    if (sscanf(str, "%c%d%c", &character, &digit, &character) == 3) {
        printf("buffer is OK\n\n");
    } else {
        printf("Buffer is undefined for parse\n\n");
    }
}

void funcSscanfString(char* str)
{
    char ch[100] = { 0 };
    char portion[100] = { 0 };

    printf("Parsing %d in buffer %s\n", sscanf(str, "%[^&]&%s", portion, ch), str);
}

void funcSscanfStringNonChar(char* str)
{
    char portion[100] = { 0 };
    int integer;
    printf("Parsing %d in buffer %s\n", sscanf(str, "%d %[^\t\n]", &integer, portion), str);
}
