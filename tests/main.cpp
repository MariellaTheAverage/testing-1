#include <gtest/gtest.h>

extern "C" {
    #include "../app/main.h"
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(quadraticTest, TwoRealRoots) {
    double a = 1.0;
    double b = -3.0;
    double c = 2.0;

    std::array<double, 2> roots;

    quadratic(a, b, c, roots.data()); 

    ASSERT_FALSE(roots.empty());
    ASSERT_DOUBLE_EQ(roots[0], 2.0);
    ASSERT_DOUBLE_EQ(roots[1], 1.0);
}

TEST(quadraticTest, OneRealRoot) {
    double a = 1.0;
    double b = 2.0;
    double c = 1.0;

    std::array<double, 2> roots;

    quadratic(a, b, c, roots.data()); 

    ASSERT_FALSE(roots.empty());
    ASSERT_DOUBLE_EQ(roots[0], -1.0);
    ASSERT_DOUBLE_EQ(roots[1], -1.0);
}

TEST(quadraticTest, NoRealRoots) {
    double a = 1.0;
    double b = 2.0;
    double c = 3.0;

    std::array<double, 2> roots;
    quadratic(a, b, c, roots.data()); 
    ASSERT_FALSE(roots.empty());
    ASSERT_DOUBLE_EQ(roots[0], 0.0);
    ASSERT_DOUBLE_EQ(roots[1], 0.0);
}

TEST(quadraticTest, NoARoots) {
    double a = 0.0;
    double b = 2.0;
    double c = 3.0;

    std::array<double, 2> roots;
    quadratic(a, b, c, roots.data()); 
    ASSERT_FALSE(roots.empty());
    ASSERT_TRUE(std::isnan(roots[0]));
    ASSERT_TRUE(std::isinf(roots[1]) && roots[1] < 0);
}

TEST(quadraticTest, NoABRoots) {
    double a = 0.0;
    double b = 0.0;
    double c = 3.0;

    std::array<double, 2> roots;
    quadratic(a, b, c, roots.data()); 
    ASSERT_FALSE(roots.empty());
    ASSERT_TRUE(std::isnan(roots[0]));
    ASSERT_TRUE(std::isnan(roots[1]));
}