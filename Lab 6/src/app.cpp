#include <iostream>
#include <Array.h>
#include <LinkedList.h>

using namespace std;


long minPos(const ResizableArray& arr, long start, long end){
    long value = arr[start];
    long pos = start;

    for (long i = start; i < end; i++){
        if (arr[i] < value){
            value = arr[i];
            pos = i;
        }
    }

    return pos;
}

void selectionSort(ResizableArray& arr){
    for (long i = 0; i < arr.count; i++){
        long j = minPos(arr, i, arr.count);
        long temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


void insertionSort(ResizableArray& arr){
    for (long i = 1; i < arr.count; i++){
        long j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            long temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j = j - 1;
        }
    }
}

int main(){

    ResizableArray nums;
    nums.append(5);
    nums.append(7);
    nums.append(3);
    nums.append(1);

    cout << nums << endl;  

    insertionSort(nums);

    cout << nums << endl;

    
    return 0;
}
