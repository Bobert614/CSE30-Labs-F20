#ifndef HashTable_h
#define HashTable_h

#include <LinkedList.h>

struct HashTable {
    LinkedList* table;

    // Strings stored in this hash table are categorized by the
    // sum of the ASCII values that make up the string
    HashTable(long size) {
        table = new LinkedList[size];
    }

    // Returns the sum of the ASCII values that make up the string
    // Ex: "A" is 65, "APPLE" is 65 + 80 + 80 + 76 + 69 = 370
    int f(std::string str) {
        int sum = 0;
        const char* arr = str.c_str();
        for (int i = 0; i < str.length(); i++) {
            sum += (int) arr[i];
        }
        return sum;
    }

    // Group strings with other strings that have the same sum
    void append(std::string str) {   
        table[f(str)].append(str);
    }

    // To find a specific string, only look at the linked list of
    // strings whose sum is the same
    bool search(std::string str) {
        return table[f(str)].search(str);
    }

    ~HashTable() {
        delete[] table;
    }
};

#endif