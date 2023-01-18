#include "gtest/gtest.h"
#include "../includes/Functions.h"
TEST(GetDayOfYear, NormalInput) {
    int dayOfYear = 32;
    int year = 2020;
    Date2 expected = {1,2,2020};
    EXPECT_EQ(expected, get_day_of_year(dayOfYear, year));
}
TEST(GetDayOfYear, LeapYearInput) {
    int dayOfYear = 60;
    int year = 2020;
    Date2 expected = {29,2,2020};
    EXPECT_EQ(expected, get_day_of_year(dayOfYear, year));
}
