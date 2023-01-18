#include "gtest/gtest.h"
#include "../includes/Functions.h"
TEST(MondayTest, FirstMonday)
{
    EXPECT_EQ(firstMonday(2022), 3);
    EXPECT_EQ(firstMonday(2023), 2);
    EXPECT_EQ(firstMonday(2024), 1);
}
TEST(MondayTest, LastMonday)
{
    EXPECT_EQ(lastMonday(2022), 360);
    EXPECT_EQ(lastMonday(2023), 359);
    EXPECT_EQ(lastMonday(2024), 364);
}
