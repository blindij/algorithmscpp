// File: list.hpp
//
#ifndef LIST_HPP
#define LIST_HPP
#include "list.h"

template<typename T>
int List<T>::Count(){
    return m_count;
}

template<typename T>
T const& List<T>::Get(int index){
    // Check if the index is out of bound
    if (index < 0 || index > m_count)
        throw  std::out_of_range("bad index, either negative or to large");
    return m_items[index];
}

template<typename T>
void List<T>::Insert(T const& val){
    // Copy the current array
    T * oldArray = m_items;

    // Initialize a new array    
    if (m_free == 0) { 
        m_free = 128;
        m_items = new T[m_count+m_free];
            // Copy items to new array
        for (auto i = 0; i < m_count; i++) m_items[i] = oldArray[i];

        // Add new item
        m_items[m_count] = val;

        // Increase the array length
        m_count++;
        m_free--;
        
        // delete the old array
        delete oldArray;


    } else {
        m_items[m_count] = val;
        m_count++;
        m_free--;
    }
}

template<typename T>
bool List<T>::Remove(T const& val){
    auto pos = Search(val);
    bool ret = false;
    if ( pos > 0 ){
        for ( auto i = pos; i < m_count; i++) {
            m_items[i] = m_items[i+1];
        }
        ret = true;
    }
    return ret;
}

template<typename T>
int List<T>::Search(T const& val){
    int position = -1;               // Return -1 if not found
    // Looping through the array elements
    // return the array index if value is found
    for (int i=0; i < m_count; ++i){
        if (m_items[i] == val){
            position = i;
        }
    }
    return position;
}

template<typename T>
void List<T>::Sort(){   // insertion sort
    for (int i=1; i < m_count; ++i){
        T  v = m_items[i];
        int j = i;
        while ((j > 0) && (Get(j-1) > v)){
            m_items[j] = m_items[j-1];
            j = j - 1;
        }
        m_items[j] = v;
    }
}
#endif // LIST_HPP