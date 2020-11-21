#ifndef HashTable_h
#define HashTable_h

#include <LinkedList.h>

struct HashTable {
    LinkedList* table;

    HashTable() {
        table = new LinkedList[128];
    }

    void append(std::string str) {
        table[(int) str.at(0)].append(str);
    }

    bool search(std::string str) {
        return table[(int) str.at(0)].search(str);
    }
};

#endif