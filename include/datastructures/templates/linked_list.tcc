#include <datastructures/linked_list.hpp>

using namespace datastructures;

#pragma region Node Implementation

template <typename T>
LinkedList<T>::Node::Node(T data){
  m_data = data;
  m_next = nullptr;
}

template <typename T>
LinkedList<T>::Node::~Node(){
  //Do nothing. Deletion of member m_next is out of this classes scope.
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Node::get_next(){
  return m_next;
}

template <typename T>
void LinkedList<T>::Node::set_next(T data){
  LinkedList<T>::Node* tmp = new LinkedList<T>::Node(data);

  //Don't delete previous next object. That is handled by the linked list class

  m_next = tmp;
}

template <typename T>
void LinkedList<T>::Node::set_next(LinkedList<T>::Node* next){

  //Don't delete previous next object. That is handled by the linked list class

  m_next = next;
}

template <typename T>
T LinkedList<T>::Node::get_data(){
  return m_data;
}

template <typename T>
void LinkedList<T>::Node::set_data(T data){
  m_data = data;
}

#pragma endregion

#pragma region Linked List Implementation

template <typename T>
LinkedList<T>::LinkedList(){
  m_size = 0;
  m_head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) : m_size(other.m_size){
  
  if(other.m_head != nullptr){
    m_head = new LinkedList<T>::Node(other.m_head->get_data());
  }
  else{
    m_head = nullptr;
  }
}

template<typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> &other){
  if(&other != this){
    m_size = other.m_size;

    //If this list has any values free up all that memory
    if(m_head != nullptr){
      typename LinkedList<T>::Node* currentNode = m_head;

      while (currentNode != nullptr)
      {
        typename LinkedList<T>::Node* tmp = currentNode->get_next();

        delete currentNode;

        currentNode = tmp;
      }
    }

    m_head = nullptr;

    //copy over all the values from the other list
    if(other.m_head != nullptr){
      m_head = new LinkedList<T>::Node(other.m_head->get_data());
      LinkedList<T>::Node* currentNode = m_head;

      for (int i = 1; i < other.m_size; i++)
      {
        LinkedList<T>::Node *newNode = new LinkedList<T>::Node(other.get(i));
        currentNode->set_next(newNode);
        currentNode = currentNode->get_next();
      }
      
    }
  }

  return *this;
}

template <typename T>
LinkedList<T>::~LinkedList(){
  typename LinkedList<T>::Node* currentNode = m_head;

  while (currentNode != nullptr)
  {
    typename LinkedList<T>::Node* tmp = currentNode->get_next();

    delete currentNode;

    currentNode = tmp;
  }
  
}

template <typename T>
int LinkedList<T>::size(){
  return m_size;
}

template <typename T>
bool LinkedList<T>::is_empty(){
  return m_size == 0;
}

template <typename T>
T LinkedList<T>::first(){
  if (m_head == nullptr)
  {
    throw "List is empty";
  }

  return m_head->get_data();
  
}

template <typename T>
T LinkedList<T>::get(int index) const {
  if (index >= m_size || index < 0)
  {
      throw "Index out of bounds";
  }

  typename LinkedList<T>::Node* currentNode = m_head;
  int currentIndex = 0;

  while (currentIndex < index)
  {
    currentNode = currentNode->get_next();
    currentIndex++;
  }

  return currentNode->get_data();
}


template <typename T>
T LinkedList<T>::remove(int index){
  if (index >= m_size || index < 0)
  {
      throw "Index out of bounds";
  }


  typename LinkedList<T>::Node *prevNode = nullptr;
  typename LinkedList<T>::Node *currentNode = m_head;
  int currentIndex = 0;

  while (currentIndex < index)
  {

    prevNode = currentNode;
    currentNode = currentNode->get_next();
    currentIndex++;
  }

  T removed_val;

  // Special case if deleting the first element
  if (prevNode == nullptr){
    m_head = currentNode->get_next();
    removed_val = currentNode->get_data();
    delete currentNode;
  }
  else{
    prevNode->set_next(currentNode->get_next());
    removed_val = currentNode->get_data();
    delete currentNode;
  }

  m_size--;

  return removed_val;
}


template <typename T>
void LinkedList<T>::set(int index, T val){
  if (index >= m_size || index < 0)
  {
      throw "Index out of bounds";
  }

  typename LinkedList<T>::Node* currentNode = m_head;
  int currentIndex = 0;

  while (currentIndex < index)
  {
    currentNode = currentNode->get_next();
    currentIndex++;
  }

  currentNode->set_data(val);
}


template <typename T>
void LinkedList<T>::insert(int index, T val){

  if (index >= m_size || index < 0)
  {
      throw "Index out of bounds";
  }

  typename LinkedList<T>::Node* prevNode = nullptr;
  typename LinkedList<T>::Node* currentNode = m_head;
  typename LinkedList<T>::Node* newNode = new LinkedList<T>::Node(val);
  int currentIndex = 0;

  while (currentIndex < index)
  {
    prevNode = currentNode;
    currentNode = currentNode->get_next();
    currentIndex++;
  }

  // Special case if inserting the first element
  if (prevNode == nullptr){
    m_head = newNode;
    newNode->set_next(currentNode);
  }
  // All other cases should be covered by this
  else{
    prevNode->set_next(newNode);
    newNode->set_next(currentNode);
  }

  m_size++;
}

template <typename T>
void LinkedList<T>::append(T val){
  if(m_size == 0 && m_head == nullptr)
  {
    m_head = new LinkedList<T>::Node(val);
    m_size++;  // increment size
    return;    // and return right away
  }

  typename LinkedList<T>::Node* prevNode = nullptr;
  typename LinkedList<T>::Node* currentNode = m_head;
  typename LinkedList<T>::Node* newNode = new LinkedList<T>::Node(val);
  int currentIndex = 0;

  while (currentIndex < m_size)
  {
    prevNode = currentNode;
    currentNode = currentNode->get_next();
    currentIndex++;
  }

  prevNode->set_next(newNode);

  m_size++;
}

#pragma endregion
