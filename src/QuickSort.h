//
// Created by Zachary on 3/3/2022.
//

#ifndef INC_22S_PA02_QUICKSORT_H
#define INC_22S_PA02_QUICKSORT_H

#include "Sort.h"
#include "random"

template <class T>
class QuickSort : public Sort<T> {
public:
    /**
     * Default Constructor
     */
    QuickSort();
    /**
     * Copy Constructor
     */
    QuickSort(const Sort<T>&);
    /**
     * Overloaded Constructor
     * @param T* array of templated elements
     */
    QuickSort(const T*, int);
    /**
     * Destructor
     */
//    ~QuickSort();

    /**
     * Sorts the data array using QuickSort and returns the result
     * @return T* array of templated elements
     */
    T* sort() override;

    T* sortHelp(T*, int, int);

    int partition(T*, int, int);
};

template <class T>
QuickSort<T>::QuickSort() : Sort<T>(){

}

template <class T>
QuickSort<T>::QuickSort(const Sort<T>& other) : Sort<T>(other){

}

template <class T>
QuickSort<T>::QuickSort(const T* other, int size) : Sort<T>(other, size){

}

//template <class T>
//QuickSort<T>::~QuickSort() {
//    if (this->data != nullptr)
//        delete[] this->data;
//}

template <class T>
T* QuickSort<T>::sort() {
    static QuickSort<T> temp(this->data, this->size);
    sortHelp(temp.data, 0, temp.size-1);
    return temp.data;
}

template <class T>
T* QuickSort<T>::sortHelp(T* temp, int low, int high) {
    if (low < high) {
        int pivot = partition(temp, low, high);

        sortHelp(temp, low, pivot - 1);
        sortHelp(temp, pivot + 1, high);
    }
    else {
        return temp;
    }

}

template <class T>
int QuickSort<T>::partition(T* temp, int low, int high) {
    srand(time(nullptr));
    int pivot = low + rand() % (high - low);
    int i = (low - 1);

    std::swap(temp[pivot], temp[high]);
    pivot = high;

    for (int j = low; j <= high - 1; j++) {
        if (temp[j] <= temp[pivot]) {
            i++;
            T val = temp[i];
            temp[i] = temp[j];
            temp[j] = val;
        }
    }
    T val = temp[i + 1];
    temp[i + 1] = temp[high];
    temp[high] = val;
    return (i + 1);
}

#endif //INC_22S_PA02_QUICKSORT_H