/*
 * differdate.c: The date difference calculator.
 *
 * Author: Rohan Bari
 * Date:   2021-09-16
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN_YEAR_RANGE  1800
#define MAX_YEAR_RANGE  9999

#define MIN_MONTH_RANGE 1
#define MAX_MONTH_RANGE 12

#define MIN_DAY_RANGE   1
#define MAX_DAY_RANGE   31

// Boolean definition.
typedef enum {
    false,
    true
} bool;

// Enumeration structure for months in a year.
typedef enum {
    JANUARY = 1,
    FEBRUARY,  MARCH,   APRIL,
    MAY,       JUNE,    JULY,
    SEPTEMBER, OCTOBER, NOVEMBER,
    DECEMBER
} Month;

// Data structure for an ideal date.
struct Date {
    int years;
    int months;
    int days;
};

/*
 * Verify if the inputted data is a valid date.
 */
bool is_valid_date(const struct Date dt) {
    bool is_leap = false;

    // Limiting the year range between the defined range.
    if (dt.years < MIN_YEAR_RANGE || dt.years > MAX_YEAR_RANGE)
        return false;

    // True if the year is a leap year.
    is_leap = (dt.years % 4 == 0 && dt.years % 100 != 0) || \
                (dt.years % 400 == 0);

    // Limiting the month range between the defined range.
    if (dt.months < MIN_MONTH_RANGE || dt.months > MAX_MONTH_RANGE)
        return false;

    // Validating the number of days of February month, that cannot exceed 29
    // (in leap years) and 28 in any ordinary year.
    if (dt.months == FEBRUARY) {
        if (is_leap && dt.days == 29)
            return true;
        else if (dt.days > 28)
            return false;
    }

    // Validating the number of days of April, June, September, and November
    // months, which cannot exceed 30.
    if (dt.months == APRIL || dt.months == JUNE || \
            dt.months == SEPTEMBER || dt.months == NOVEMBER) {
        if (dt.days > 30)
            return false;
    } else if (dt.days > 31)
        return false;

    // All the tests are passed, the date is vaild.
    return true;
}

/*
 * Obtain the user input safely. (Passed by reference)
 */
void assign_date(struct Date *dt) {
    if (fscanf(stdin, "%2d/%2d/%4d", \
            &dt->days, &dt->months, &dt->years) != 3) {
        fprintf(stderr, "error: Improper date format.\n");
        exit(EXIT_FAILURE);
    }

    if (!is_valid_date(*dt)) {
        fprintf(stderr, "error: This type of date does not exist.\n");
        exit(EXIT_FAILURE);
    }
}

/*
 * Calculate the difference between dates.
 */
struct Date difference(struct Date from, struct Date to) {
    struct Date diff_date;

    if (to.days < from.days) {
        // If the month is March, obtain days from February.
        if (to.months == MARCH) {
            // Taking leap year into consideration for accurate results.
            if ((to.years % 4 == 0 && to.years % 100 != 0) || \
                    (to.years % 400 == 0))
                to.days += MAX_DAY_RANGE - 2;
            else
                to.days += MAX_DAY_RANGE - 3;
        } else
            // Obtaining days from April, June, September, November months.
            to.days += MAX_DAY_RANGE;

        to.months -= MIN_MONTH_RANGE;
    }

    if (to.months < from.months) {
        to.months += MAX_MONTH_RANGE;
        to.years -= 1;
    }

    diff_date.days = to.days - from.days;
    diff_date.months = to.months - from.months;
    diff_date.years = to.years - from.years;

    if (diff_date.days < 0 || diff_date.months < 0 || diff_date.years < 0) {
        fprintf(stdout, "error: The destination date must be greater than " \
                        "the source date.\n");
        exit(EXIT_FAILURE);
    }

    return diff_date;
}

int main(void) {
    struct Date date_from; // Source date.
    struct Date date_to;   // Destination date.
    struct Date diff;      // Difference between source destination dates.

    fprintf(stdout, "Enter the source date in DD/MM/YYYY:      ");
    assign_date(&date_from);

    fprintf(stdout, "Enter the destination date in DD/MM/YYYY: ");
    assign_date(&date_to);

    diff = difference(date_from, date_to);

    fprintf(stdout, "The difference is: %2d year(s) %2d month(s) %2d day(s)\n",
                    diff.years, diff.months, diff.days);

    return EXIT_SUCCESS;
}
