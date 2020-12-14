#ifndef HashTable_h
#define HashTable_h

#include <LinkedList.h>

struct HashTable {
    LinkedList* table;
    int size = 0;

    HashTable(int num) {
        size = num;
        table = new LinkedList[size];
    }

    long f(std::string str) {
        int seed = 5051;
        unsigned long hash = 0;
        while (str.length() < 4) str += "_";
        for (int i=0; i < 4; i++) {
            hash = (hash * seed) + str[i];
        }
        return hash % size;
    }

    void append(std::string str) {   
        table[f(str)].append(str);
    }

    bool search(std::string str) {
        return table[f(str)].search(str);
    }

    ~HashTable() {
        delete[] table;
    }
};

#endif