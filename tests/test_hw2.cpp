#include <gtest/gtest.h>
#include "duration.h"

TEST(DurationTest, TotalSeconds) {
    Duration time(3, 5);
    EXPECT_EQ(time.total_seconds(), 185);
}

TEST(DurationTest, NegativeTotal) {
    Duration time(0, -5);
    EXPECT_EQ(time.total_seconds(), 0);
}

TEST(DurationTest, SecondsCarry) {
    Duration time(0, 75);
    EXPECT_EQ(time.total_seconds(), 75);
}
