#include <iostream>
#include <RandomSupport.h>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>

using namespace std;

long minPos(ResizableArray& arr, long start){
    long min = arr[start];
    long pos = start;
    for (long i = start+1; i < arr.count; i++){
        if (arr[i] < min){
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

void selectionSort(ResizableArray& arr){
    for (long i = 0; i < arr.count; i++){
        long j = minPos(arr, i);
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

int main(int argc, char* argv[]){

    // Set N, the size of the array we test with

	long N = 40000;

	ResizableArray array;
    ResizableArray another;
    

	randomizer device = new_randomizer();
	uniform_distribution dist = new_distribution(1, 10);

	for (long i = 0; i < N; i++){
		long r = sample(dist, device);
		array.append(N-i);
	}

    another = array;


    // Check selection sort =====================================


	timestamp start = current_time();

	selectionSort(array);

	timestamp end = current_time();

	long duration = time_diff(start, end);

	cout << "Selection sort took " << duration << " ms." << endl;

    
    
    // Check selection sort =====================================


	start = current_time();

	insertionSort(another);

	end = current_time();

    duration = time_diff(start, end);

	cout << "Insertion Sort took " << duration << " ms." << endl;

	return 0;
}
