#pragma once
#include <initializer_list>	//用来实现可变参函数
/*
 *	Sequential Array - 数组的顺序存储结构
*/

template<class T>
class s_Array
{
public:
	s_Array(const int N, std::initializer_list<int> boundn);	//重载构造函数为可变参构造函数，初始化数组
	bool Value(T& elem, std::initializer_list<int> indexn);		//将数组中指定位置元素赋值给elem
	bool Assign(const T& elem, std::initializer_list<int> indexn);	//数组指定位置元素赋值为elem
	~s_Array();	//析构函数销毁数组
protected:
	/*
	 *	n维数组的映像函数为 LOC(J1, J2, ···, Jn) = LOC(0,0,···,0) + ΣCi*Ji(1 -> n)
	 *	Cn = L,Ci-1 = Bi*Ci, 1 < i <= n
	*/
	auto map_C(int i);	//求C的递归函数
private:
	T *base;		//数组首地址
	int n;			//维数
	int *bounds;	//各维长度	
};

template<class T>
s_Array<T>::s_Array(const int N, std::initializer_list<int> boundn) :n(N)
{
	auto ptr = boundn.begin();
	if ((int)boundn.size() == N)
	{
		bounds = new int[N];
		int capacity = 1;
		int i = 0;
		for (ptr; ptr != boundn.end(); ptr++, i++)
		{
			try
			{
				if (*ptr > 0)
				{
					bounds[i] = *ptr;
					capacity *= *ptr;
				}
				else
					throw *ptr;
			}
			catch (int& value)
			{
				std::cout << "第" << i + 1 << "维度长度必须大于0 ,当前为 -> " << *ptr << std::endl;
				exit(0);
			}
		}
		base = new T[capacity * sizeof(T)];
	}
}

template<class T>
bool s_Array<T>::Value(T & elem, std::initializer_list<int> indexn)
{
	auto ptr = indexn.begin();
	if ((int)indexn.size() == n)
	{
		int _sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (*ptr > bounds[i - 1] || *ptr < 0)
				return false;
			_sum += map_C(i) * (*ptr);
			ptr++;
		}
		auto loc = base + _sum;
		elem = *loc;
		return true;
	}
}

template<class T>
bool s_Array<T>::Assign(const T & elem, std::initializer_list<int> indexn)
{
	auto ptr = indexn.begin();
	if ((int)indexn.size() == n)
	{
		int _sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (*ptr >= bounds[i - 1] || *ptr < 0)
				return false;
			_sum += map_C(i) * (*ptr);
			ptr++;
		}
		auto loc = base + _sum;
		*loc = elem;
		return true;
	}
}

template<class T>
auto s_Array<T>::map_C(int i)
{
	if (i == 1)
	{
		return  bounds[i] * (int)sizeof(T);
	}
	else if (i == n)
	{
		return (int)sizeof(T);
	}
	else
	{
		return map_C(i - 1) / bounds[i];
	}
}

template<class T>
inline s_Array<T>::~s_Array()
{
	delete[] base;
	base = NULL;
	delete[] bounds;
	bounds = NULL;
}

