#include <iostream>
#include <RandomSupport.h>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>
#include <SortedArray.h>
#include <HashTable.h>

#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    fstream fileStream;
    fileStream.open("words2.txt");

    HashTable test;

    while (!fileStream.eof()) {
        string temp;
        fileStream >> temp;
        test.append(temp);
    }

    fileStream.close();

    long num = 0;

    timestamp start = current_time();

    fileStream.open("words2.txt");
    while (!fileStream.eof()) {
        string str;
        fileStream >> str;
        string rev = string(str.rbegin(),str.rend());
        if (test.search(rev)) num++;
    }

    timestamp end = current_time();

    cout << num << " reverse words found in " << time_diff(start, end) << " ms" << endl;
}
