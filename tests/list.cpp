#include <catch2/catch.hpp>
#include<datastructures/list.hpp>
using namespace datastructures;

TEMPLATE_TEST_CASE("Lists", "[list][template]", int){


  SECTION("can be constructed with a parameter"){
    List<int> list = List<int>(5);
    REQUIRE( list.size() == 0 );
    REQUIRE( list.get_capacity() == 5);
  }



  SECTION("can be constructed without a parameter"){
    List<int> list = List<int>(); 
    REQUIRE( list.size() == 0 );
    REQUIRE( list.get_capacity() == 10);
  }



  SECTION("accurately keeps track of size"){
    List<int> list = List<int>(); 
    REQUIRE( list.size() == 0 );
    for (int i = 0; i < 10; i++)
    {
      list.append(i);
      REQUIRE(list.size() == i + 1);
    }
  }



  SECTION("can be dynamically resized when needed"){
    List<int> list = List<int>(5);

    for (int i = 0; i < 5; i++)
    {
      list.append(i);
    }

    CHECK_NOTHROW(list.append(5));
    REQUIRE( list.size() == 6);
    REQUIRE( list.get_capacity() == 10);
  }


  SECTION("can get arbitrary index values"){
    List<int> list = List<int>();

    for (int i = 0; i < 10; i++)
    {
      list.append(i);
    }

    for (int i = 0; i < 10; i++)
    {
      REQUIRE(list.get(i) == i);
    }

  }



  SECTION("can set arbitrary index values"){
    List<int> list = List<int>();

    for (int i = 0; i < 10; i++)
    {
      list.append(i);
    }
    for (int i = 0; i < 10; i++)
    {
      list.set(i, 9 - i);
      REQUIRE(list.get(i) == 9 - i);
    }
  }



  SECTION("can tell when they are empty"){
    List<int> list = List<int>();

    REQUIRE(list.is_empty() == true);

    list.append(1);

    REQUIRE(list.is_empty() == false);
  }

  SECTION("can be copied over correctly"){
    List<int> list = List<int>();
    
    list.append(1);

    List<int> list2 = list;

    list.append(2);
    list.set(0, 5);

    REQUIRE(list2.size() == 1);
    REQUIRE(list2.get(0) == 1);

    list2 = list;

    REQUIRE(list2.size() == 2);

    list.append(9);

    REQUIRE(list2.size() == 2);

  }
}