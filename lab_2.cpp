#include <cstdlib>
#include <iostream>
#include <chrono>

void quicksort(int* arr, int end, int begin) {
	int pivotElement;
	int start = begin;
	int finish = end;
	pivotElement = arr[(start + finish) / 2];
	while (start < finish) {
		while (arr[start] < pivotElement) start++;
		while (arr[finish] > pivotElement) finish--;
		if (start <= finish) {
			std::swap(arr[start], arr[finish]);
			start++;
			finish--;
		}
	}
	if (begin < finish) quicksort(arr, finish, begin);
	if (start < end) quicksort(arr, end, start);
}

int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}
		else {
			return binarySearch(arr, value, mid + 1, end);
		}
	}

	return -1;
}

int sorting(int arr[], int arrayLength, int value) {
	for (int i = 0; i < arrayLength; i++) {
		if (arr[i] == value) {
			return i;
		}
	}
}

void sortedArraySearch(int arr[], int arrayLength) {
	int maximum = arr[arrayLength-1];
	int minimum = arr[0];
}

void unsortedArraySearch(int arr[], int arrayLength) {
	int maximum = arr[0];
	int minimum = arr[0];

	for (int i = 1; i < arrayLength; i++) {
		if (arr[i] > maximum) {
			maximum = arr[i];
		}
		if (arr[i] < minimum) {
			minimum = arr[i];
		}
	}
}

int arithmeticMeanSearchSortedArray(int arr[], int arrayLength) {
	int maximum = arr[arrayLength - 1];
	int minimum = arr[0];
	int arithmeticMean = (maximum + minimum) / 2;
	return arithmeticMean;
}

int arithmeticMeanSearchUnsortedArray(int arr[], int arrayLength) {
	int maximum = 0;
	int minimum = 100;

	for (int i = 0; i < arrayLength; i++) {
		if (arr[i] > maximum) {
			maximum = arr[i];
		}
		if (arr[i] < minimum) {
			minimum = arr[i];
		}
	}
	int arithmeticMean = (maximum + minimum) / 2;
	return arithmeticMean;
}

void indexSearch(int arr[], int arrayLength, int arithmeticMean) {
	int countSortedArr = 0;
	for (int i = 0; i < arrayLength - 1; i++) {
		if (arr[i] == arithmeticMean) {
			countSortedArr += 1;
		}
	}
}

void changingElements(int arr[], int index1, int index2) {
	std::swap(arr[index1], arr[index2]);
}

int main() {
		const int arrayLength = 100;
		int unsortedArr[arrayLength];
		int sortedArr[arrayLength];
		int userAnswer;

		srand(time(0));
		std::cout << "The unsorted array is " << std::endl;
		for (int i = 0; i < arrayLength; i++) {
			unsortedArr[i] = rand() % 199 - 99;
			sortedArr[i] = rand() % 199 - 99;
			std::cout << unsortedArr[i] << " ";
		}
		for (int i = 0; i < arrayLength; i++) {
			sortedArr[i] = unsortedArr[i];
		}
		std::cout << std::endl;

		int end = arrayLength - 1, begin = 0;
		auto start = std::chrono::steady_clock::now();
		quicksort(sortedArr, end, begin);
		auto stop = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		std::cout << "The sorted array is " << std::endl;
		for (int i = 0; i < arrayLength; i++) {
			std::cout << sortedArr[i] << " ";
		}
		std::cout << std::endl << "The time spent to sort the array is " << duration.count() << " ns\n";
		std::cout << std::endl;

		std::cout << "What do you want to do? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes) ";
		std::cin >> userAnswer;

		if (userAnswer == 1) {
			std::cout << "The maximum and minimum elements in the array are ";
			std::cout << sortedArr[arrayLength - 1] << ", " << sortedArr[0] << std::endl;

			auto startSortedSearch = std::chrono::steady_clock::now();
			sortedArraySearch(sortedArr, arrayLength);
			auto stopSortedSearch = std::chrono::steady_clock::now();
			auto durationSortedSearch = std::chrono::duration_cast<std::chrono::nanoseconds>(stopSortedSearch - startSortedSearch);
			std::cout << "The time spent to find the maximum and minimum element in the sorted array is " << durationSortedSearch.count() << " ns\n";

			auto startUnsortedSearch = std::chrono::steady_clock::now();
			unsortedArraySearch(unsortedArr, arrayLength);
			auto stopUnsortedSearch = std::chrono::steady_clock::now();
			auto durationUnsortedSearch = std::chrono::duration_cast<std::chrono::nanoseconds>(stopUnsortedSearch - startUnsortedSearch);
			std::cout << "The time spent to find the maximum and minimum element in the unsorted array is " << durationUnsortedSearch.count() << " ns\n";
			std::cout << std::endl;

			std::cout << "What do you want to do next? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes) ";
			std::cin >> userAnswer;
		}

		if (userAnswer == 2) {
			int arithmeticMean = arithmeticMeanSearchSortedArray(sortedArr, arrayLength);
			std::cout << "The arithmetic mean in an array is: " << arithmeticMean << std::endl;
			auto startArithmeticMeanSearchSorted = std::chrono::steady_clock::now();
			arithmeticMeanSearchSortedArray(sortedArr, arrayLength);
			auto stopArithmeticMeanSearchSorted = std::chrono::steady_clock::now();
			auto durationArithmeticMeanSearchSorted = std::chrono::duration_cast<std::chrono::nanoseconds>(stopArithmeticMeanSearchSorted - startArithmeticMeanSearchSorted);
			std::cout << "The time spent to find arithemtic mean in a sorted array is " << durationArithmeticMeanSearchSorted.count() << " ns\n";

			auto startArithmeticMeanSearchUnsorted = std::chrono::steady_clock::now();
			arithmeticMeanSearchUnsortedArray(sortedArr, arrayLength);
			auto stopArithmeticMeanSearchUnsorted = std::chrono::steady_clock::now();
			auto durationArithmeticMeanSearchUnsorted = std::chrono::duration_cast<std::chrono::nanoseconds>(stopArithmeticMeanSearchUnsorted - startArithmeticMeanSearchUnsorted);
			std::cout << "The time spent find arithemtic mean in an unsorted array is " << durationArithmeticMeanSearchUnsorted.count() << " ns\n";
			std::cout << std::endl;

			int countSortedArr = 0;
			std::cout << "The indexes of the elements that have the same value as arithemtic mean in the sorted array are ";
			for (int i = 0; i < arrayLength - 1; i++) {
				if (sortedArr[i] == arithmeticMean) {
					countSortedArr += 1;
					std::cout << i << " ";
				}
			}
			if (countSortedArr == 0) {
				std::cout << std::endl << "There are no elements that have the same value as the arithmetic mean.";
			}
			std::cout << std::endl;

			int countUnsortedArr = 0;
			std::cout << "The indexes of the elements that have the same value as arithemtic mean in the unsorted array are ";
			for (int i = 0; i < arrayLength - 1; i++) {
				if (unsortedArr[i] == arithmeticMean) {
					countUnsortedArr += 1;
					std::cout << i << " ";
				}
			}
			if (countUnsortedArr == 0) {
				std::cout << std::endl << "There are no elements that have the same value as the arithmetic mean.";
			}
			std::cout << std::endl;

			auto startIndexSearchSorted = std::chrono::steady_clock::now();
			indexSearch(sortedArr, arrayLength, arithmeticMean);
			auto stopIndexSearchSorted = std::chrono::steady_clock::now();
			auto durationIndexSearchSorted = std::chrono::duration_cast<std::chrono::nanoseconds>(stopIndexSearchSorted - startIndexSearchSorted);
			std::cout << "The overall time spent to find elements that have the same value as arithmetic mean and their amount in the sorted array is " << durationIndexSearchSorted.count() + durationArithmeticMeanSearchSorted.count() << " ns\n";

			auto startIndexSearchUnsorted = std::chrono::steady_clock::now();
			indexSearch(unsortedArr, arrayLength, arithmeticMean);
			auto stopIndexSearchUnsorted = std::chrono::steady_clock::now();
			auto durationIndexSearchUnsorted = std::chrono::duration_cast<std::chrono::nanoseconds>(stopIndexSearchUnsorted - startIndexSearchUnsorted);
			std::cout << "The overall time spent to find elements that have the same value as arithmetic mean and their amount in the sorted array is " << durationIndexSearchUnsorted.count() + durationArithmeticMeanSearchUnsorted.count() << " ns\n";
			std::cout << std::endl;

			std::cout << "What do you want to do next? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes) ";
			std::cin >> userAnswer;
		}

		if (userAnswer == 3) {
			std::cout << "Enter any number from -99 to 99: ";
			int lowerNumber;
			std::cin >> lowerNumber;
			int countLowerNumbers = 0;
			int indexLowerNumbers = 0;
			while (sortedArr[indexLowerNumbers] < lowerNumber) {
				countLowerNumbers++;
				indexLowerNumbers++;
			}
			std::cout << "The amount of elements that are lower than your number is " << countLowerNumbers << std::endl;

			std::cout << "Enter any number from -99 to 99: ";
			int higherNumber;
			std::cin >> higherNumber;
			int countHigherNumbers = 0;
			int indexHigherNumbers = 99;
			while (sortedArr[indexHigherNumbers] > higherNumber) {
				countHigherNumbers++;
				indexHigherNumbers--;
			}
			std::cout << "The amount of elements that are higher than your number is " << countHigherNumbers << std::endl;

			std::cout << "What do you want to do next? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes) ";
			std::cin >> userAnswer;
		}

		if (userAnswer == 4) {
			int size = sizeof(sortedArr) / sizeof(sortedArr[0]);
			int value;
			std::cout << "Please, enter any number: ";
			std::cin >> value;

			int answer = binarySearch(sortedArr, value, 0, size - 1);

			if (answer == -1) {
				std::cout << "There's no such number in the array." << std::endl;
			}
			else {
				std::cout << "Your number's index in the array is " << answer << std::endl;
			}

			auto startComparisonBinarySearch = std::chrono::steady_clock::now();
			binarySearch(sortedArr, value, 0, size - 1);
			auto stopComparisonBinarySearch = std::chrono::steady_clock::now();
			auto durationComparisonBinarySearch = std::chrono::duration_cast<std::chrono::nanoseconds>(stopComparisonBinarySearch - startComparisonBinarySearch);
			std::cout << "The time spent to find the index of your number using binary search is " << durationComparisonBinarySearch.count() << std::endl;

			auto startComparisonLinearSearch = std::chrono::steady_clock::now();
			sorting(sortedArr, arrayLength, value);
			auto stopComparisonLinearSearch = std::chrono::steady_clock::now();
			auto durationComparisonLinearSearch = std::chrono::duration_cast<std::chrono::nanoseconds>(stopComparisonLinearSearch - startComparisonLinearSearch);
			std::cout << "The time spent to find the index of your number using linear search is " << durationComparisonLinearSearch.count() << std::endl;

			int durationDifference = durationComparisonBinarySearch.count() - durationComparisonLinearSearch.count();
			if (durationDifference < 0) {
				durationDifference *= -1;
			}
			std::cout << "The difference between binary search and linear search is " << durationDifference << std::endl;

			std::cout << "Enter two indexes from 0 to 99 " << std::endl;
			int index1, index2;
			std::cin >> index1 >> index2;

			auto startChangingElements = std::chrono::steady_clock::now();
			changingElements(sortedArr, index1, index2);
			auto stopChangingElements = std::chrono::steady_clock::now();
			auto durationChangingElements = std::chrono::duration_cast<std::chrono::nanoseconds>(stopChangingElements - startChangingElements);
			std::cout << "The time spent to swap the elements with the indexes you've entered is " << durationChangingElements.count() << " ns" << std::endl;

			std::cout << "The changed array is " << std::endl;
			for (int i = 0; i < arrayLength; i++) {
				std::cout << sortedArr[i] << " ";
			}

			std::cout << std::endl << "What do you want to do? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes) ";
			std::cin >> userAnswer;
		}
}

