#pragma once

#include <datastructures/list.hpp>

namespace dts{
  template <typename T>
  class Stack{
    private:
      List<T> m_data;
    public:

      Stack();
      Stack(int capacity);

      void push(T val);
      T pop();
      int size();
      int get_capacity();
  };
}

#include "templates/stack.tcc"
