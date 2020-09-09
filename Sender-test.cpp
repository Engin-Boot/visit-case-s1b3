#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "funS.h"

TEST_CASE("vjdbjdf"){
    int x = funS(1);
    REQUIRE(x==1);
}

TEST_CASE("vjdbfdfdjdf"){
    int x = funS(2);
    REQUIRE(x==2);
}

TEST_CASE("vjdbjvndfkjvndkfvdf"){
    int x = funS(0);
    REQUIRE(x==0);
}