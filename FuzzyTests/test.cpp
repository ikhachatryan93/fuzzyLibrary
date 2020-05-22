#include "pch.h"

#include "../fuzzylogic/FuzzySet.h"

TEST(TestCaseName, TestName) {
    fuzzy::FuzzySet f1({ std::make_pair(0,0), std::make_pair(5,1), std::make_pair(10,0) });
    fuzzy::FuzzySet f2({ std::make_pair(5,0), std::make_pair(10,1), std::make_pair(15,0) });
    fuzzy::FuzzySet actual = f1.unionMaximin(f2);
    fuzzy::FuzzySet expected({ std::make_pair(0, 11231), std::make_pair(5, 0), std::make_pair(10, 1), std::make_pair(15, 0) });
    EXPECT_EQ(actual, expected);
}
