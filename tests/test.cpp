#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "magicbook.h"
#include <string>

static_assert(std::is_same_v<decltype(MagicBook::title), std::string>, 
        "title must be of type std::string");
static_assert(std::is_same_v<decltype(MagicBook::year), int>, 
        "year must be of type int");
static_assert(std::is_same_v<decltype(MagicBook::pages), int>, 
        "pages must be of type int");
    
   
TEST_CASE("Class initialization and assignment") {
    MagicBook book;
    
    SECTION("Default values") { // check your initialization!
        REQUIRE(book.title == ""); 
        REQUIRE(book.year == 0);
        REQUIRE(book.pages == 0);
    }

    SECTION("Field assignment") {
        book.title = "Ancient Spells Compendium";
        book.year = 1500;
        book.pages = 1200;
        
        REQUIRE(book.title == "Ancient Spells Compendium");
        REQUIRE(book.year == 1500);
        REQUIRE(book.pages == 1200);
    }
}

TEST_CASE("Book size evaluation") {
    MagicBook book;
    
    SECTION("LARGE books") {
        book.pages = 1000;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::LARGE);
        book.pages = 1500;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::LARGE);
        book.pages = 2000;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::LARGE);
    }
    
    SECTION("MEDIUM books") {
        book.pages = 500;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::MEDIUM);
        book.pages = 750;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::MEDIUM);
        book.pages = 999;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::MEDIUM);
    }
    
    SECTION("SMALL books") {
        book.pages = 1;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::SMALL);
        book.pages = 499;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::SMALL);
        book.pages = 250;
        REQUIRE(evaluateBookSize(book) == MagicBook::BookClass::SMALL);
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
}
