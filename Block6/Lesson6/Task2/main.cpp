#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "List.h"

TEST_CASE("PushFront adds elements in correct order", "[List][pushfront]")
{
    List list;

    list.PushFront(10);
    list.PushFront(20);
    list.PushFront(30);

    REQUIRE(list.Size() == 3);

    REQUIRE(list.PopFront() == 30);
    REQUIRE(list.PopFront() == 20);
    REQUIRE(list.PopFront() == 10);

    REQUIRE(list.Empty() == true);
}

TEST_CASE("PushBack adds elements in correct order", "[List][pushback]")
{
    List list;

    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);

    REQUIRE(list.Size() == 3);

    REQUIRE(list.PopFront() == 1);
    REQUIRE(list.PopFront() == 2);
    REQUIRE(list.PopFront() == 3);

    REQUIRE(list.Empty() == true);
}

TEST_CASE("PopFront throws on empty list", "[List][popfront]")
{
    List list;

    REQUIRE(list.Empty() == true);
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);

    REQUIRE(list.Size() == 0);

    list.PushBack(42);
    REQUIRE(list.PopFront() == 42);
    REQUIRE(list.Empty() == true);
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}

TEST_CASE("PopBack throws on empty list", "[List][popback]")
{
    List list;

    REQUIRE(list.Empty() == true);
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);

    list.PushFront(100);
    REQUIRE(list.PopBack() == 100);
    REQUIRE(list.Empty() == true);
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
}

TEST_CASE("Mixed PushFront, PushBack, PopFront, PopBack operations", "[List][mixed]")
{
    List list;

    list.PushBack(1);
    list.PushBack(2);
    list.PushFront(0);
    list.PushBack(3);

    REQUIRE(list.Size() == 4);
    REQUIRE(list.PopFront() == 0);
    REQUIRE(list.PopBack() == 3);
    REQUIRE(list.Size() == 2);

    list.PushFront(-1);
    list.PushBack(4); 
    REQUIRE(list.Size() == 4);

    REQUIRE(list.PopFront() == -1);
    REQUIRE(list.PopFront() == 1);
    REQUIRE(list.PopBack() == 4);
    REQUIRE(list.PopFront() == 2);

    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);

    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
}