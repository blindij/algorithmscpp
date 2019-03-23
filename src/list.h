// File : list.h
#ifndef LIST_H
#define LIST_H

#include <iostream>

class List {
    private:
        int m_count = 0;
        int *m_items = nullptr;

    public:
        // List();
        // ~List();
        int Get(int index);
        void Insert(int index, int val);
        int Search(int val);
        void Remove(int index);
        int Count();
};
#endif // LIST_H