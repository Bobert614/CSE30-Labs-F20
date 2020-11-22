#include <iostream>
#include <Array.h>
#include <LinkedList.h>
#include <HashTable.h>
#include <fstream>
#include <TimeSupport.h>

using namespace std;

int main(){
    fstream fileStream;
    string file = "words.txt";

    timestamp start1 = current_time();

    // First read: cast each word to an array of characters, then determine
    // the sum of the ASCII values of those characters, and keep track of the
    // highest sum, this will determine the size of the array for the hash table
    int maxSum = 0;
    fileStream.open(file);
    while (!fileStream.eof()) {
        string str;
        fileStream >> str;
        int sum = 0;
        const char* arr = str.c_str();
        for (int i = 0; i < str.length(); i++) {
            sum += (int) arr[i];
        }
        if (sum > maxSum) maxSum = sum;
    }
    fileStream.close();

    timestamp end1 = current_time();

    cout << "First read complete in " << time_diff(start1, end1) << " ms" << endl;

    // Create a hash table whose size is defined by the operation above
    HashTable words (maxSum);
    // To record which words are reversible
    ResizableArray revWords;

    timestamp start2 = current_time();

    // Second read: populate the hash table with the words from the file
    fileStream.open(file);
    while (!fileStream.eof()) {
        string temp;
        fileStream >> temp;
        words.append(temp);
    }
    fileStream.close();

    timestamp end2 = current_time();

    cout << "Second read complete in " << time_diff(start2, end2) << " ms" << endl;

    timestamp start3 = current_time();

    // Third read: for each word, reverse it, then search for that reversed
    // word in the hash table
    fileStream.open(file);
    while (!fileStream.eof()) {
        string str;
        fileStream >> str;
        string rev = string(str.rbegin(),str.rend());
        if (words.search(rev)) {
            revWords.append(str);
        }
    }
    fileStream.close();

    timestamp end3 = current_time();

    cout << "Third read complete in " << time_diff(start3, end3) << " ms" << endl;

    cout << "The following words create words when reversed:" << endl << revWords << endl;

    cout << revWords.count << " reversible words found in " << time_diff(start1, end3) << " ms" << endl;
    
    return 0;
}
