#pragma once

/*
	//Selection sort ¡ª¡ª Ñ¡ÔñÅÅÐò

*/

template<class T>
void select(T* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
				std::swap(arr[j], arr[i]);
		}
	}
}

