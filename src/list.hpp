// File: list.hpp
//
#include "list.h"

int List::Get(int index){
    // Check if the index is out of bound
    if (index < 0 || index > m_count)
        return -1;
    return m_items[index];
}
void List::Insert(int index, int val){
    // Check if the index is out of bound
    if (index < 0 || index > m_count) return;

    // Copy the current array
    int * oldArray = m_items;

    // Increase the array length
    m_count++;

    // Initialize a new array    
    m_items = new int[m_count];

    // Fill the new array with inserted data
    for(int i=0, j=0; i < m_count; ++i){
        if (index == i){
            m_items[i] = val;
        } else {
            m_items[i] = oldArray[j];
            ++j;
        }
    }

    // Remove copied array
    delete [] oldArray;
}