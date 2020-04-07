#pragma once

namespace datastructures{
  template <typename T>
  class Stack{
    private:
      T* m_data;
      int m_size;
      int m_capacity;

      void increase_capacity();
    public:
      Stack();
      Stack(int capacity);
      Stack(const Stack &other);
      Stack & operator=(const Stack &other);
      void push(T val);
      T pop();
      int size();
      int get_capacity();
  };
}

#include "templates/stack.tcc"
