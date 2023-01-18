#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include "../includes/Functions.h"
TEST(GetNiceLookingHHMMFormat, EmptyInput) {
    std::string input = "";
    EXPECT_EQ("HH.MM", get_nice_looking_HHMM_format(input));
}
TEST(GetNiceLookingHHMMFormat, OneDigitInput) {
    std::string input = "1";
    EXPECT_EQ("1H.MM", get_nice_looking_HHMM_format(input));
}
TEST(GetNiceLookingHHMMFormat, TwoDigitInput) {
    std::string input = "11";
    EXPECT_EQ("11.MM", get_nice_looking_HHMM_format(input));
}
TEST(GetNiceLookingHHMMFormat, ThreeDigitInput) {
    std::string input = "111";
    EXPECT_EQ("11.1M", get_nice_looking_HHMM_format(input));
}
TEST(GetNiceLookingHHMMFormat, FourDigitInput) {
    std::string input = "1111";
    EXPECT_EQ("11.11", get_nice_looking_HHMM_format(input));
}


