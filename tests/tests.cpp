#include <gtest/gtest.h>

extern "C" {
#include "football.h"
}

TEST(Football, CorrectOutput) {
    ASSERT_EQ(count_combinations(5),    1);
    ASSERT_EQ(count_combinations(16),  14);
    ASSERT_EQ(count_combinations(62), 652);
}