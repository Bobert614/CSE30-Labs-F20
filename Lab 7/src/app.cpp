#include <iostream>
#include <Array.h>
#include <LinkedList.h>
#include <HashTable.h>
#include <fstream>
#include <TimeSupport.h>

using namespace std;

string reverse(string str) {
    return string(str.rbegin(),str.rend());
}

int main(){
    fstream fileStream;
    string file = "words.txt";

    cout << "Enter file name (words.txt, words2.txt, or words3.txt): ";
    cin >> file;

    // To record which words are reversible
    ResizableArray revWords;
    // Store the words in a way that's good for iterating but bad for searching
    ResizableArray list;

    timestamp start1 = current_time();

    // Read from the file once and store the words in the resizable array
    fileStream.open(file, ios::in);
    if (!fileStream.is_open()) {
        cout << "Couldn't open file" << endl;
        return 1;
    }
    string temp;
    while (getline(fileStream, temp)) {
        list.append(temp);
    }
    fileStream.close();

    timestamp end1 = current_time();

    // cout << "Read \"" << file << "\" in " << time_diff(start1, end1) << " ms" << endl;

    timestamp start2 = current_time();

    // Create a hash table whose size is defined by the number of words to be stored
    HashTable words (list.count/2);

    // Populate the hash table
    for (int i=0; i < list.count; i++) {
        words.append(list[i]);
    }

    timestamp end2 = current_time();

    // cout << "Populated hash table in " << time_diff(start2, end2) << " ms" << endl;

    timestamp start3 = current_time();

    // For each word, reverse it, then search for that reversed
    // word in the hash table, keeping track of ones that are found
    for (int i=0; i < list.count; i++) {
        if (words.search(reverse(list[i])))
            revWords.append(list[i]);
    }

    timestamp end3 = current_time();

    // cout << "The following words create words when reversed:" << endl << revWords << endl;

    cout << "Found " << revWords.count << " reversible words in " << time_diff(start3, end3) << " ms" << endl;
    
    return 0;
}
