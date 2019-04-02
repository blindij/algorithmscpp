// File: list.hpp
//
#include "list.h"

template<typename T>
int List<T>::Count(){
    return m_count;
}

template<typename T>
T const& List<T>::Get(int index){
    // Check if the index is out of bound
    if (index < 0 || index > m_count)
        return -1;
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
    // Fill the new array with inserted data
    // if ( m_free == 127) {
    //         for(int i=0, j=0; i < m_count; ++i){
    //             if (index == i){
    //                 m_items[i] = val;
    //             } else {
    //                 m_items[i] = oldArray[j];
    //                 ++j;
    //             }
    //         }

    // // Remove copied array
    //     if ( oldArray != nullptr ) delete [] oldArray;
    // } else {
    //     for (int i=0, j=0; i < m_count; ++i){
    //         if ( index == i) {
    //             m_items[i] = val;
    //         } else {
    //             m_items[i] = o
    //         }
    //     }
    // }

}

// template<typename T>
// void List<T>::Remove(int index){
//     // Check if the index is out of bound
//     if (index < 0 || index > m_count)
//         return;
//     // Copy the current array
//     int * oldArray = m_items;

//     // Decrease the array length
//     m_count--;

//     // Initialize a new array
//     m_items = new int[m_count];

//     // Fill the new array
//     // and remove the selected index
//     for (int i = 0, j = 0; i < m_count; ++i, ++j){
//         if (index == j){
//             ++j;
//         }
//         m_items[i] = oldArray[j];
//     }

//     // Remove copied array
//     delete [] oldArray;
// }

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
    // Looping through the array elements
    // return the array index if value is found
    for (int i=0; i < m_count; ++i){
        if (m_items[i] == val){
            return i;
        }
    }
    return -1;
}