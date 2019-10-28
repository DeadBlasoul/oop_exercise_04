#include <gtest/gtest.h>

#include <polygon.hpp>
#include <algorithm.hpp>

#define TEST_SUIT_NAME Rhombus
auto constexpr precision = 0.000000001L;

TEST(TEST_SUIT_NAME, Area) {
    auto result = area2d(std::tuple{
        point2d{-1, 0},
        point2d{0, 2},
        point2d{1, 0},
        point2d{0, -2}});
    ASSERT_TRUE(std::abs(result - 4) < precision);
}

TEST(TEST_SUIT_NAME, Center) {
    auto center = center2d(std::tuple{
        point2d{-1, 0},
        point2d{0, 2},
        point2d{1, 0},
        point2d{0, -2}});
    //auto [x, y] = center;
    //ASSERT_TRUE(std::abs(x) < precision && std::abs(y) < precision);
}
