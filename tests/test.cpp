#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "magicbook.h"
#include <string>

SECTION("Field types") {
        static_assert(std::is_same_v<decltype(MagicBook::title), std::string>, 
            "title must be of type std::string");
        static_assert(std::is_same_v<decltype(MagicBook::year), int>, 
            "year must be of type int");
        static_assert(std::is_same_v<decltype(MagicBook::pages), int>, 
            "pages must be of type int");
    }

TEST_CASE("Class definition and initialization") {
    SECTION("Default initialization") {
        MagicBook book;
        REQUIRE(book.title == ""); // Check if title is initialized to ""
        REQUIRE(book.year == 0); // Check if year is initialized to 0
        REQUIRE(book.pages == 0); // Check if pages is initialized to 0
    }

    SECTION("Field assignment and access") {
        MagicBook book;
        book.title = "Advanced Spellcasting";
        book.year = 1492;
        book.pages = 742;
        
        REQUIRE(book.title == "Advanced Spellcasting");
        REQUIRE(book.year == 1492);
        REQUIRE(book.pages == 742);
    }

TEST_CASE("Book size evaluation") {
    MagicBook book;
    
    SECTION("Class 1 books") {
        book.pages = 1000;
        REQUIRE(evaluateBookSize(book) == 1);
        book.pages = 1500;
        REQUIRE(evaluateBookSize(book) == 1);
        book.pages = 2000;
        REQUIRE(evaluateBookSize(book) == 1);
    }
    
    SECTION("Class 2 books") {
        book.pages = 500;
        REQUIRE(evaluateBookSize(book) == 2);
        book.pages = 750;
        REQUIRE(evaluateBookSize(book) == 2);
        book.pages = 999;
        REQUIRE(evaluateBookSize(book) == 2);
    }
    
    SECTION("Class 3 books") {
        book.pages = 1;
        REQUIRE(evaluateBookSize(book) == 3);
        book.pages = 499;
        REQUIRE(evaluateBookSize(book) == 3);
        book.pages = 250;
        REQUIRE(evaluateBookSize(book) == 3);
    }
}

TEST_CASE("Arcane year detection") {
    MagicBook book;
    
    SECTION("Arcane years") {
        book.year = 100;
        REQUIRE(isFromArcaneYear(book));
        book.year = 200;
        REQUIRE(isFromArcaneYear(book));
        book.year = 1800;
        REQUIRE(isFromArcaneYear(book));
        book.year = 2000;
        REQUIRE(isFromArcaneYear(book));
    }
    
    SECTION("Non-arcane years") {
        book.year = 0;
        REQUIRE_FALSE(isFromArcaneYear(book));
        book.year = 99;
        REQUIRE_FALSE(isFromArcaneYear(book));
        book.year = 101;
        REQUIRE_FALSE(isFromArcaneYear(book));
        book.year = 2025;
        REQUIRE_FALSE(isFromArcaneYear(book));
    }
    
