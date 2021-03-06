#pragma once

namespace dts{
  template <typename T>
  class LinkedList{
    private:
      class Node
      {
        private:
          T m_data;
          Node *m_next;
        public:
          Node(T data);

          ~Node();

          Node* get_next();

          void set_next(T data);

          void set_next(Node* next);

          T get_data();

          void set_data(T data);
      };

      Node *m_head;
      int m_size;
      
    public:

      /**
       * @brief Construct a new Linked List object
       * 
       */
      LinkedList();

      LinkedList(const LinkedList &other);

      LinkedList & operator=(const LinkedList &other);

      /**
       * @brief Destroy the Linked List object
       * 
       */
      ~LinkedList();

      /**
       * @brief get the size of the list
       * 
       * @return int 
       */
      int size();

      /**
       * @brief Returns true if the list is empty
       * 
       * @return true 
       * @return false 
       */
      bool is_empty();

      /**
       * @brief Get the first value in the list
       * 
       * @return T 
       */
      T first();

      /**
       * @brief get the value from the given index in the list
       * 
       * @param index 
       * @return T 
       */
      T get(int index) const;

      /**
       * @brief remove the value from the given index from the list
       * 
       * @param index 
       * @return T the removed value
       */
      T remove(int index);

      /**
       * @brief Sets the value at the given index to the given value
       * 
       * @param index 
       * @param val
       */
      void set(int index, T val);

      /**
       * @brief Inserts the given value at the given index in the list
       * 
       * @param index 
       * @param val 
       */
      void insert(int index, T val);

      /**
       * @brief Appends the given value to the end of the list
       * 
       * @param val 
       */
      void append(T val);
  };
}

#include "templates/linked_list.tcc"
