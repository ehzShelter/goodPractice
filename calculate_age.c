#include <stdio.h>
#include <stdbool.h>

#define DAYS_PER_MONTH 30
#define MONTHS_PER_YEAR 12

typedef struct
    {
    int day;
    int month;
    int year;
} date;

date today, birthday;

enum months {
    jan = 0,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

void calcAge(date* present, date* birth);
bool sanitizeDate(date* userDate);
void leapifyFeb(int* daysMonth, int year);
void printAge(int D, int M, int Y);
void throwException(void);

int main(void)
{
    printf("today's date (dd mm yyyy)>>>\n");

    printf("today's day: ");
    scanf("%d", &today.day);
    printf("today's month: ");
    scanf("%d", &today.month);
    printf("today's year: ");
    scanf("%d", &today.year);

    if (today.day <= 0 || today.month <= 0 || today.year <= 0) {
        throwException();
        return -1;
    }

    if (sanitizeDate(&today) == false) {
        throwException();
        return -1;
    }

    printf("birth date (dd mm yyyy)>>>\n");

    printf("bithday's day: ");
    scanf("%d", &birthday.day);
    printf("bithday's month: ");
    scanf("%d", &birthday.month);
    printf("bithday's year: ");
    scanf("%d", &birthday.year);

    if (birthday.day <= 0 || birthday.month <= 0 || birthday.year <= 0) {
        throwException();
        return -1;
    }

    if (sanitizeDate(&birthday) == false) {
        throwException();
        return -1;
    }

    calcAge(&today, &birthday);

    return 0;
}

void throwException(void)
{
    fprintf(stderr, "Some of your data is INVALID\n");
}

void leapifyFeb(int* daysMonth, int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysMonth[feb] = 29;
    }
}

bool sanitizeDate(date* userDate)
{
    int daysPerMonth[MONTHS_PER_YEAR] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    int Year = userDate->year;
    int Month = userDate->month;
    int Day = userDate->day;

    leapifyFeb(daysPerMonth, Year);

    if (Month > MONTHS_PER_YEAR || Day > daysPerMonth[Month - 1]) {
        return false;
    }
    return true;
}

void calcAge(date* present, date* birth)
{
    if (present->day < birth->day) {
        present->day += DAYS_PER_MONTH;
        birth->month += 1;
    }
    int calcDay = present->day - birth->day;

    if (present->month < birth->month) {
        present->month += MONTHS_PER_YEAR;
        birth->year += 1;
    }
    int calcMonth = present->month - birth->month;

    int calcYear = present->year - birth->year;

    if (calcDay < 0 || calcMonth < 0 || calcYear < 0) {
        throwException();
        return;
    }

    if (calcDay == 0 && calcMonth == 0 && calcYear == 0) {
        printf("You are born today\n");
        return;
    }

    puts("your age: ");

    printAge(calcDay, calcMonth, calcYear);

    printf("\n");
}

void printAge(int D, int M, int Y)
{
    if (Y != 0) {
        printf("%d years ", Y);
    }
    if (M != 0) {
        printf("%d months ", M);
    }
    if (D != 0) {
        printf("%d days ", D);
    }
}
