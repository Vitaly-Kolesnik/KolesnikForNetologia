#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "List.h"

TEST_CASE("New list is empty and has size 0", "[List][initial]")
{
    List list;
    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Empty and Size reflect the actual content after pushes", "[List][push]")
{
    List list;

    list.PushFront(10);
    REQUIRE(list.Empty() == false);
    REQUIRE(list.Size() == 1);

    list.PushBack(20);
    REQUIRE(list.Size() == 2);

    list.PushFront(5);
    REQUIRE(list.Size() == 3);

    REQUIRE(list.Empty() == false);
}

TEST_CASE("Clear removes all elements and resets size", "[List][clear]")
{
    List list;

    list.PushFront(1);
    list.PushFront(2);
    list.PushBack(3);
    REQUIRE(list.Size() == 3);

    list.Clear();

    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Clear on empty list is safe", "[List][clear]")
{
    List list;

    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);

    list.Clear();
    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);

    list.PushFront(42);
    REQUIRE(list.Size() == 1);

    list.Clear();
    REQUIRE(list.Size() == 0);
    REQUIRE(list.Empty() == true);
}

TEST_CASE("Empty and Size consistency after popping elements", "[List][pop]")
{
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);

    REQUIRE(list.Size() == 3);
    REQUIRE(list.Empty() == false);

    int val = list.PopFront();
    REQUIRE(val == 1);
    REQUIRE(list.Size() == 2);
    REQUIRE(list.Empty() == false);

    val = list.PopBack();
    REQUIRE(val == 3);
    REQUIRE(list.Size() == 1);

    val = list.PopFront();
    REQUIRE(val == 2);
    REQUIRE(list.Size() == 0);
    REQUIRE(list.Empty() == true);
}