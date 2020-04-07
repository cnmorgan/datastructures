#include <datastructures/stack.hpp>

using namespace dts;

template <typename T>
Stack<T>::Stack() : m_data(10){
// do nothing
}

template <typename T>
Stack<T>::Stack(int capacity) : m_data(capacity){
// do nothing
}

template <typename T>
void Stack<T>::push(T val){
  m_data.append(val);
}

template <typename T>
T Stack<T>::pop(){

  if (m_data.size() == 0)
  {
    throw "Stack is empty";
  }

  return m_data.remove(m_data.size() - 1);
}

template <typename T>
int Stack<T>::size(){
  return m_data.size();
}

template <typename T>
int Stack<T>::get_capacity(){
  return m_data.get_capacity();
}