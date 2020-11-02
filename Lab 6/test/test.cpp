#include <igloo/igloo.h>
#include <SortedArray.h>
#include <Array.h>
#include <TimeSupport.h>
#include <RandomSupport.h>

using namespace igloo;

Context(SortedInsertionTests) {
	Spec(ValExists_Beginning) {
		ResizableArray expected;
		expected.append(1);
		expected.append(1);
		expected.append(2);
		expected.append(3);

		SortedArray actual;
		actual.arr.append(1);
		actual.arr.append(2);
		actual.arr.append(3);
		actual.insert(1);

		Assert::That(actual.arr == expected);
	}
	Spec(ValExists_End) {
		ResizableArray expected;
		expected.append(1);
		expected.append(2);
		expected.append(3);
		expected.append(3);

		SortedArray actual;
		actual.arr.append(1);
		actual.arr.append(2);
		actual.arr.append(3);
		actual.insert(3);

		Assert::That(actual.arr == expected);
	}
	Spec(ValExists_Mid) {
		ResizableArray expected;
		expected.append(1);
		expected.append(2);
		expected.append(2);
		expected.append(3);

		SortedArray actual;
		actual.arr.append(1);
		actual.arr.append(2);
		actual.arr.append(3);
		actual.insert(2);

		Assert::That(actual.arr == expected);
	}

	Spec(ValNotExists_Beginning) {
		ResizableArray expected;
		expected.append(1);
		expected.append(2);
		expected.append(3);

		SortedArray actual;
		actual.arr.append(2);
		actual.arr.append(3);
		actual.insert(1);

		Assert::That(actual.arr == expected);
	}
	Spec(ValNotExists_End) {
		ResizableArray expected;
		expected.append(1);
		expected.append(2);
		expected.append(3);

		SortedArray actual;
		actual.arr.append(1);
		actual.arr.append(2);
		actual.insert(3);

		Assert::That(actual.arr == expected);
	}
	Spec(ValNotExists_Mid) {
		ResizableArray expected;
		expected.append(1);
		expected.append(2);
		expected.append(3);

		SortedArray actual;
		actual.arr.append(1);
		actual.arr.append(3);
		actual.insert(2);

		Assert::That(actual.arr == expected);
	}

	Spec(LotsOfInserts) {
		long N = 100000;

		ResizableArray expected;

		SortedArray actual;

		// resizable array inserted in order from 0 to N
		for (long i = 0; i < N; i++)
			expected.append(i);

		// sorted array inserted from N to 0
		for (long i = N-1; i >= 0; i--)
			actual.insert(i);

		Assert::That(actual.arr == expected);
	}
};

Context(ComplexityProofs) {
	long N = 10000000;
	Spec(Best) {
		SortedArray sArr;

		for (int i=0; i < N; i++)
			sArr.arr.append(i);

		timestamp start = current_time();
		sArr.insert(N+1);
		timestamp end = current_time();

		std::cout << std::endl << "Best case - optimize insert (N+1), N=" << N << " elements: " << time_diff(start, end) << "ms" << std::endl;
	}
	Spec(Worst) {
		SortedArray sArr;

		for (int i=0; i < N; i++)
			sArr.arr.append(i);

		timestamp start = current_time();
		sArr.insert(-1);
		timestamp end = current_time();

		std::cout << std::endl << "Worst case - beginning of list (-1), N=" << N << " elements: " << time_diff(start, end) << "ms" << std::endl;
	}
	Spec(FakeBest) {
		SortedArray sArr;

		for (int i=0; i < N; i++)
			sArr.arr.append(i);

		timestamp start = current_time();
		sArr.insert((N-1)/2);
		timestamp end = current_time();

		std::cout << std::endl << "Fake Best case - optimize search ((N+1)/2)), N=" << N << " elements: " << time_diff(start, end) << "ms" << std::endl;
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
