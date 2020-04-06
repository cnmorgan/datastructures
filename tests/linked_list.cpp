#include <catch2/catch.hpp>
#include <datastructures/linked_list.hpp>

#include <iostream>

using namespace datastructures;

TEMPLATE_TEST_CASE("linked_list", "[linked_list][Template]", int){
  SECTION("can be constructed without issue"){
    LinkedList<int> list = LinkedList<int>();

    REQUIRE(list.size() == 0);
  }

  SECTION("Can append values"){
    LinkedList<int> list = LinkedList<int>();

    list.append(1);
    
    REQUIRE(list.size() == 1);
    REQUIRE(list.get(0) == 1);
    
    list.append(2);

    REQUIRE(list.size() == 2);
    REQUIRE(list.get(1) == 2);
  }


  SECTION("Can remove values"){
    LinkedList<int> list = LinkedList<int>();
    
    for (int i = 0; i < 5; i++)
    {
      list.append(i);
    }

    REQUIRE(list.size() == 5);
    REQUIRE(list.get(4) == 4);

    list.remove(4);

    REQUIRE(list.size() == 4);

    list.remove(0);

    REQUIRE(list.size() == 3);
    REQUIRE(list.get(0) == 1);

  }


  SECTION("Can set arbitrary values"){
    LinkedList<int> list = LinkedList<int>();
    
    for (int i = 0; i < 5; i++)
    {
      list.append(i);
    }
    
    REQUIRE(list.size() == 5);
    REQUIRE(list.get(4) == 4);

    list.set(0, 9);

    REQUIRE(list.size() == 5);
    REQUIRE(list.get(0) == 9);

    list.set(4, 22);

    REQUIRE(list.size() == 5);
    REQUIRE(list.get(4) == 22);
  }

  SECTION("Can get arbitrary values"){
    LinkedList<int> list = LinkedList<int>();

    for (int i = 0; i < 5; i++)
    {
      list.append(i);
    }

    REQUIRE(list.get(0) == 0);
    REQUIRE(list.get(1) == 1);
    REQUIRE(list.get(2) == 2);
    REQUIRE(list.get(3) == 3);
    REQUIRE(list.get(4) == 4);
  }

  SECTION("Can insert values at arbitrary indices"){
    LinkedList<int> list = LinkedList<int>();

    for (int i = 0; i < 5; i++)
    {
      list.append(i);
    }

    REQUIRE(list.size() == 5);
    REQUIRE(list.get(4) == 4);

    list.insert(3, 99);

    REQUIRE(list.size() == 6);
    REQUIRE(list.get(3) == 99);;
    REQUIRE(list.get(4) == 3);

  }

  SECTION("Accurately tracks the list's size"){
    LinkedList<int> list = LinkedList<int>();

    for (int i = 0; i < 5; i++)
    {
      REQUIRE(list.size() == i);
      list.append(i);
    }

  }

  SECTION("Can tell when the list is empty"){
    LinkedList<int> list = LinkedList<int>();

    REQUIRE(list.is_empty());

    list.append(0);

    REQUIRE_FALSE(list.is_empty());
  }
}
