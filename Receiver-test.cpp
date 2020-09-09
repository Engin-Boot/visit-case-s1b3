#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "funR.h"

TEST_CASE("vjdbjdf"){
    int x = funR(2);
    REQUIRE(x==2);
}

TEST_CASE("vjdbjddvf"){
    int x = funR(0);
    REQUIRE(x==0);
}

TEST_CASE("vjdbj jkvfddf"){
    int x = funR(1);
    REQUIRE(x==1);
}