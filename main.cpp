#include <iostream>
#include <vector>
#include <cstdlib>

template <class T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T>
void selection_sort(std::vector<T>& array) {

  for (int i = 0; i < array.size() - 1; i++) {

    int min_idx = i;
    for (int j = i + 1; j < array.size(); j++) {
      if (array[j] < array[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      swap(array[min_idx], array[i]);
    }

  }

}


template <class T>
void insertion_sort(std::vector<T>& array) {
  for (int i = 1; i < array.size(); i++) {
    int j = i;
    while (j > 0 && array[j-1] > array[j]) {
      swap(array[j], array[j-1]);
      j--;
    }
  }
}


template <class T>
void merge(std::vector<T>& src, std::vector<T>& dest,
    int left_start, int right_start, int end) {

  int i_left = left_start;
  int i_right = right_start;

  for (int i = left_start; i < end; i++) {

    if (i_left >= right_start) {
      dest[i] = src[i_right++];
    } else if (i_right >= end) {
      dest[i] = src[i_left++];
    } else if (src[i_left] <= src[i_right]) {
      dest[i] = src[i_left++];
    } else {
      dest[i] = src[i_right++];
    }

  }
}


template <class T>
void merge_sort(std::vector<T>& array) {

  std::vector<T> aux(array.size());

  for (int len = 1; len < array.size(); len *= 2) {

    for (int i = 0; i < array.size(); i += 2 * len) {
      merge(array, aux, i,
        std::min<int>(i + len, array.size()),
        std::min<int>(i + 2 * len, array.size()));
    }

    array = aux;

  }
}


template <class T>
int partition(std::vector<T>& array, int lo, int hi) {
  T pivot = array[lo];

  while (true) {
    while (array[lo] < pivot) {
      lo++;
    }

    while (array[hi] > pivot) {
      hi--;
    }

    if (lo >= hi) {
      return hi;
    }

    swap(array[hi], array[lo]);
  }
}


template <class T>
void quicksort_recursive(std::vector<T>& array, int lo, int hi) {

  if (lo < hi) {
    int p = partition(array, lo, hi);
    quicksort_recursive(array, lo, p);
    quicksort_recursive(array, p+1, hi);
  }

}


template <class T>
void quicksort(std::vector<T>& array) {
  quicksort_recursive(array, 0, array.size() - 1);
}


int main() {
  std::vector<int> vec;
  for (int i = 0; i < 16; i++) {
    vec.push_back(rand() % 100);
  }

  std::cout << "Before sorting:";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "  " << vec[i];
  }
  std::cout << std::endl;

  quicksort(vec);

  std::cout << "After sorting:";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "  " << vec[i];
  }
  std::cout << std::endl;
}
