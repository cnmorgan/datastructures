#pragma once

namespace dts
{

  /**
   * @brief A collection of type T that can have variable length
   * 
   * @tparam T 
   */
  template <typename T>
  class List
  {
  private:
    T* m_data;
    int m_capacity;
    int m_size;

    void increase_capacity();
  public:

    /**
     * @brief Construct a new List object of a given size
     * 
     * @param capacity The inital size of the list (optional)
     */
    List(int capacity);

    /**
     * @brief Construct a new List object
     * 
     */
    List();

    ~List();

    List(const List &other);

    List & operator=(const List &other);

    /**
     * @brief Append a value to the end of the list
     * 
     * @param val The value to append
     */
    void append(T val);

    /**
     * @brief Set the value at the given index to val
     * 
     * @param index Index at which to set
     * @param val The value to set to
     */
    void set(int index, T val);

    /**
     * @brief Gets the value from a given index
     * 
     * @param index 
     * @return T 
     */
    T get(int index);

    /**
     * @brief Removes and returns a value at the given index
     * 
     * @param index 
     * @return T 
     */
    T remove(int index);

    /**
     * @brief Gets the current length of the list
     * 
     * @return int 
     */
    int size();

    /**
     * @brief Get the capacity of the list
     * 
     * @return int 
     */
    int get_capacity();

    /**
     * @brief Returns true when the list has a size of 0
     * 
     * @return true 
     * @return false 
     */
    bool is_empty();
  };
}

#include "templates/list.tcc"