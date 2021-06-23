#pragma once
//Ï£¶ûÅÅĞò

template<class T>

void hill_sort(T* arr) {
	int n = arr.size();
	int gap = n / 2;
	while (gap > 0) {
		for (int i = gap; i < n; ++i) {
			int tmp = arr[i];
			int j = i - gap;
			while (j >= 0 && tmp < arr[j]) {
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = tmp;
		}
		gap = gap / 2;
	}
}