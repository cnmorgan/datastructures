#include <catch2/catch.hpp>
#include <datastructures/stack.hpp>

using namespace datastructures;

TEMPLATE_TEST_CASE("stack", "[stack][Template]", int){
  SECTION("can be created with an empty constructor"){
    Stack<int> stack = Stack<int>();

    REQUIRE(&stack != nullptr);
  }

  SECTION("can be created with an initial capacity"){
    Stack<int> stack = Stack<int>(5);

    REQUIRE(stack.get_capacity() == 5);
  }

  SECTION("pushes and pops values in the right order"){
    Stack<int> stack = Stack<int>();

    stack.push(3);
    stack.push(2);
    stack.push(5);

    REQUIRE(stack.pop == 5);

    stack.push(1);

    REQUIRE(stack.pop == 1);
    REQUIRE(stack.pop == 2);
    REQUIRE(stack.pop == 3);
  }

  SECTION("keeps track of size"){
    Stack<int> stack = Stack<int>();

    REQUIRE(stack.size() == 0);

    stack.push(3);
    stack.push(2);
    stack.push(5);

    REQUIRE(stack.size() == 3);

  }

  SECTION("can dynamically resize"){
    Stack<int> stack = Stack<int>(5);

    REQUIRE(stack.get_capacity() == 5);

    stack.push(6);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    REQUIRE(stack.get_capacity() == 10);
  }

  SECTION("can be created with a copy constructor"){
    Stack<int> stack = Stack<int>();

    stack.push(1);
    stack.push(2);
    stack.push(3);

    Stack<int> stack2 = stack;

    stack.pop()
    stack.pop()
    stack.push(11);

    REQUIRE(stack2.pop() == 3);
    REQUIRE(stack2.pop() == 2);
    REQUIRE(stack2.pop() == 1);

  }

  SECTION("can be reassigned with the = operator"){
    Stack<int> stack = Stack<int>();
    Stack<int> stack2 = Stack<int>();

    stack2.push(5);
    stack2.push(4);
    stack2.push(3);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack2 = stack;

    stack.pop()
    stack.pop()
    stack.push(11);

    REQUIRE(stack2.pop() == 3);
    REQUIRE(stack2.pop() == 2);
    REQUIRE(stack2.pop() == 1);
  }
}
