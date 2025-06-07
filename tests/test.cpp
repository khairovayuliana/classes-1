#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>

#include "point.h"

TEST_CASE("Point: Structure definition and initialization") {
    Point p;
    REQUIRE(sizeof(p.x) == sizeof(double));
    REQUIRE(sizeof(p.y) == sizeof(double));
}

TEST_CASE("Point: Initialization with zeros by default") {
    Point p;
    REQUIRE(std::abs(p.x) < 1e-9);  // Check if x is initialized to 0
    REQUIRE(std::abs(p.y) < 1e-9);  // Check if y is initialized to 0
}

TEST_CASE("Square area of rectangle defined by two points") {
    Point a{1.0, 2.0};
    Point b{4.0, 6.0};

    double area = rectangleSquare(a, b);
    REQUIRE(area == Approx(12.0).epsilon(1e-9));
}

TEST_CASE("Rectangle area: zero area when points are the same") {
    Point a{2.5, 3.5};
    Point b{2.5, 3.5};
    double area = rectangleSquare(a, b);
    REQUIRE(area == Approx(0.0).epsilon(1e-9));
}

TEST_CASE("Rectangle area: negative coordinates") {
    Point a{-2.0, -3.0};
    Point b{-5.0, -7.0};
    double area = rectangleSquare(a, b);
    REQUIRE(area == Approx(12.0).epsilon(1e-9));
}

TEST_CASE("Rectangle area: mixed positive and negative coordinates") {
    Point a{-1.0, 2.0};
    Point b{3.0, -2.0};
    double area = rectangleSquare(a, b);
    REQUIRE(area == Approx(16.0).epsilon(1e-9));
}

TEST_CASE("Rectangle area: one axis same") {
    Point a{0.0, 5.0};
    Point b{10.0, 5.0};
    double area = rectangleSquare(a, b);
    REQUIRE(area == Approx(0.0).epsilon(1e-9));
}

TEST_CASE("Rectangle area: large values") {
    Point a{1e6, 2e6};
    Point b{2e6, 4e6};
    double area = rectangleSquare(a, b);
    REQUIRE(area == Approx(2e12).epsilon(1e-3));
}
