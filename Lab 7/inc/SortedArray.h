#ifndef SortedArray_h
#define SortedArray_h

#include <Array.h>

struct SortedArray {
    ResizableArray arr;

    SortedArray() {}

    SortedArray(const SortedArray& other) {
		arr.count = other.arr.count;
		arr.data = new long[other.arr.capacity];

		for (long i = 0; i < other.arr.count; i++){
			arr.data[i] = other.arr.data[i];
		}
    }

    // For each insertion, performs a binary search to find an element already in the array
    // that is the same as the value. If the search fails, 'mid' will be at the index where
    // the value belongs, then the value is simply inserted using the method from ResizableArray,
    // whose worst case is an insertion near the beginning of the array.
    // Worst case for this function is when we are inserting a value that belongs at the beginning
    // of the array that does not already exist in the array.
    // Because the slow part of this function is the actual insertion and not the search, the Best Case
    // is inserting to the end.
    void insert(long val) {
        long start = 0;
        long end = arr.count - 1;
        long mid = start + ((end - start)/2);

        while (start <= end) {
            if (arr[mid] == val) break;
            else if (arr[mid] > val) {
                end = mid - 1;
                mid = start + ((end - start)/2);
            }
            else if (arr[mid] < val) {
                start = mid + 1;
                mid = start + ((end - start)/2);
            }
        }
        arr.insert(mid, val);
    }

    ~SortedArray() {}
};

std::ostream& operator<<(std::ostream& os, const SortedArray& sArr) {
    for (long i = 0; i < sArr.arr.count; i++){
		os << sArr.arr.data[i] << " ";
	}

    return os;
}

#endif