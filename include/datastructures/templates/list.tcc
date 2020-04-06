#include <datastructures/list.hpp>

using namespace datastructures;

template <typename T>
List<T>::List(int capacity){
  m_capacity = capacity;
  m_data = new T[m_capacity];
  m_size = 0;
}

template <typename T>
List<T>::List(){
  m_capacity = 10;
  m_data = new T[m_capacity];
  m_size = 0;
}

template <typename T>
List<T>::List(const List<T> &other): m_capacity(other.m_capacity), m_size(other.m_size), m_data(new T[m_capacity]){
  for (int i = 0; i < other.m_size; i++)
  {
    m_data[i] = other.m_data[i];
  }
  
}

template<typename T>
List<T> & List<T>::operator=(const List<T> &other){

  if(&other != this){
    m_capacity = other.m_capacity;
    m_size = other.m_size;

    //free any memory we are currently using
    if(m_data != NULL){
      delete [] m_data;
    }

    m_data = new T[m_capacity];

    for (int i = 0; i < other.m_size; i++)
    {
      m_data[i] = other.m_data[i];
    }
  }

  return *this;
}

template <typename T>
List<T>::~List(){
  delete [] m_data;
}

template <typename T>
void List<T>::increase_capacity(){
  //double the lists capacity
  m_capacity = m_capacity * 2;
  //create a temporary pointer to the new internal
  //array
  int* tmp_ptr = new T[m_capacity];

  //copy over the old data to the new array
  for (int i = 0; i < m_capacity/2; i++)
  {
    tmp_ptr[i] = m_data[i];
  }

  //release memory and clear the member pointer
  delete [] m_data;
  m_data = nullptr;

  //set the member pointer to the new data
  m_data = tmp_ptr;
}

template <typename T>
void List<T>::append(T val){
  //Make sure we still have room
  if(m_size == m_capacity){
    increase_capacity();
  }

  //add the data to the end of the list
  m_data[m_size] = val;

  m_size++;
}

template <typename T>
void List<T>::set(int index, T val){
  if(index < 0 || index > m_capacity - 1 || index > m_size - 1){
    throw "Index out of bounds";
  }

  m_data[index] = val;
}

template <typename T>
T List<T>::get(int index){
  if(index < 0 || index > m_capacity - 1 || index > m_size - 1){
    throw "Index out of bounds";
  }

  return m_data[index];
}

template <typename T>
int List<T>::size(){
  return m_size;
}

template <typename T>
int List<T>::get_capacity(){
  return m_capacity;
}

template<typename T>
bool List<T>::is_empty(){
  return m_size == 0;
}

