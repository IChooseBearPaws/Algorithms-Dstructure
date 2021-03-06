#pragma once

/*
	//Quick_sort ¡ª¡ª ¿ìËÙÅÅÐò

*/


template<typename T>
void quick(T* arr, int low, int high)
{
	int p = high - 1;
	if (low > p)
		return;
	while (low != p)
	{ 
		if (arr[low] >= arr[high] && arr[p] <= arr[high])
			std::swap(arr[low], arr[p]);
		else if (arr[low] <= arr[high] && low != p)
			++low;
		else if (arr[p] >= arr[high] && low != p)
			--p;
	}

	if(arr[low] > arr[high])
		std::swap(arr[low], arr[high]);

	quick(arr, 0, low);

	quick(arr, low + 1, high);
}
