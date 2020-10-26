#ifndef SortedArray_h
#define SortedArray_h

#include <Array.h>

struct SortedArray {
    ResizableArray arr;

    SortedArray() {
    }

    SortedArray(const SortedArray& other) {
        std::cout << "HELLO" << std::endl;
		arr.count = other.arr.count;
		arr.data = new long[other.arr.capacity];

		for (long i = 0; i < other.arr.count; i++){
			arr.data[i] = other.arr.data[i];
		}
    }

    void insert(long val) {
        arr.append(val);
        insertionSort(arr);
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

    ~SortedArray() {
    }
};

std::ostream& operator<<(std::ostream& os, const SortedArray& sArr) {
    for (long i = 0; i < sArr.arr.count; i++){
		os << sArr.arr.data[i] << " ";
	}

    return os;
}

#endif