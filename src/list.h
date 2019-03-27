// File : list.h
#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T>
class List {
    private:
        int m_count = 0;
        T *m_items = nullptr;

    public:
        // List(T const& t_) : {
        //    mcount = mcount+1;
        //    m_items = new T[mcount];
        //    m[mcount-1] = t_;
        //};
        // ~List();
        T const& Get(int index);
        void Insert(int index, T const& t);
        int Search(T const& t);
        void Remove(int index);
        int Count();
};
#endif // LIST_H