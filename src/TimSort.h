//
// Created by Daniel Ryan on 3/8/22.
//

#ifndef INC_22S_PA02_TIMSORT_H
#define INC_22S_PA02_TIMSORT_H

#include "Sort.h"

template <class T>
class TimSort : public Sort<T> {
public:
    /**
     * Default Constructor
     */
    TimSort();
    /**
     * Copy Constructor
     */
    TimSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    TimSort(const T* s, int c);

    /**
     * Sorts the data array using SelectionSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;

    void insertionSort(T*, int, int);

    void mergeSort(T*, int, int, int);
};

template <class T>
TimSort<T>::TimSort() : Sort<T>() {

}

template <class T>
TimSort<T>::TimSort(const Sort<T>& s) : Sort<T>(s) {

}

template <class T>
TimSort<T>::TimSort(const T* s, int c) : Sort<T>(s, c) {

}

template <class T>
T* TimSort<T>::sort() {
    static TimSort<T> temp(this->data, this->size);

    for(int i = 0; i < temp.size; i+=32) {
        if(i+31 < temp.size-1)
            insertionSort(temp.data, i, (i+31));
        else
            insertionSort(temp.data, i, temp.size-1);
    }

    for(int s = 32; s < temp.size; s*=2) {

        for(int low = 0; low < temp.size; low += 2*s) {
            int mid = low + temp.size - 1;
            int high = ((low + 2*temp.size - 1) < temp.size-1) ? (low + 2*temp.size - 1) : temp.size-1;

            if(mid < high)
                mergeSort(temp.data, low, mid, high);
        }
    }

    return temp.data;
}

template<class T>
void TimSort<T>::insertionSort(T* arr, int low, int high) {

    for (int i = low+1; i <= high; i++) {
        int j = i;
        while (j > low && arr[j] < arr[j-1]) {
            T val = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = val;
            j--;
        }
    }

}

template<class T>
void TimSort<T>::mergeSort(T* arr, int low, int mid, int high) {

    int leftArrSize = mid - low + 1;
    int rightArrSize = high - mid;

    T* leftArr = new T[leftArrSize];
    T* rightArr = new T[rightArrSize];

    for(int i = 0; i < leftArrSize; i++)
        leftArr[i] = arr[low + i];
    for(int i = 0; i < rightArrSize; i++)
        rightArr[i] = arr[mid + 1 + i];


    int leftIndex = 0, rightIndex = 0, arrIndex = low;
    while(leftIndex < leftArrSize || rightIndex < rightArrSize) {
        if(rightIndex == rightArrSize || leftArr[leftIndex] <= rightArr[rightIndex]) {
            arr[arrIndex] = leftArr[leftIndex];
            leftIndex++;
        } else {
            arr[arrIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        arrIndex++;
    }

    if(leftArrSize != 0)
        delete[] leftArr;
    if(rightArrSize != 0)
        delete[] rightArr;
}

#endif //INC_22S_PA02_TIMSORT_H