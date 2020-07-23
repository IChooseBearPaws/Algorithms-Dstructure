#pragma once
#include <iostream>
/*
 *	Sequential List - 线性表的顺序存储结构
 *	特性：逻辑相邻，物理也相邻
*/

template<class T>
class s_List
{
public:
	s_List(int listCapacity = 10);			//构造函数初始化线性表默认容量为10
	void ClearList();						//线性表置空
	bool ListEmpty() const;					//判断线性表是否为空
	bool ListInsert(int i, const T& item);	//第i个位置插入元素item
	int ListLength();						//获取线性表元素个数
	int LocateElem(const T& item);			//返回第一个与item相等的元素的序号，不存在则返回0
	T GetElem(int i);						//获取第i个元素的值
	T ListDelet(int i);						//删除第i个元素并返回其值
	T PriorElem(const T& item);				//返回第一个与item相等的元素的前驱
	T NextElem(const T& item);				//返回第一个与item相等的元素的后继
	~s_List();								//销毁线性表
private:
	T* s_list;								//线性表指针
	int capacity;							//线性表长度
	int length;								//线性表元素个数
};

template<class T>
s_List<T>::s_List(int listCapacity): capacity(listCapacity)
{
	try
	{
		if (capacity < 1)
			throw capacity;
		s_list = new T[capacity];
		length = 0;
	}
	catch (int& value)
	{
		std::cout << "List capacity must > 0" << std::endl;
	}
}

template<class T>
 inline void s_List<T>::ClearList()
{
	 length = 0;
}

 template<class T>
bool s_List<T>::ListEmpty() const
 {
	return length == 0 ? true : false;
 }

template<class T>
inline int s_List<T>::ListLength()
{
	return length;
}

template<class T>
inline T s_List<T>::GetElem(int i)
{
	return s_list[i-1];
}

template<class T>
int s_List<T>::LocateElem(const T & item)
{
	for (int num = 0; num < length; num++)
	{
		if (item == s_list[num])
		{
			return num + 1;
		}
	}
	return 0;
}

template<class T>
bool s_List<T>::ListInsert(int i, const T & item)
{
	if ((i > length ? 1 == i - length : i > 0) && i < capacity && length+1 <= capacity)
	{
		if (i > length)			//插入的元素为末尾元素
		{
			s_list[i - 1] = item;
		}
		else					//中间或首位插
		{
			for (int len = length; len >= i; len--)
			{
				s_list[len] = s_list[len - 1];
			}
			s_list[i - 1] = item;
		}
		length += 1;
		return true;
	}
	else
		return false;
}

template<class T>
T s_List<T>::ListDelet(int i)
{
	length -= 1;
	return s_list[i-1];
}

template<class T>
T s_List<T>::PriorElem(const T & item)
{
	try
	{
		int x = LocateElem(item);
		if (x < 1)
			throw item;
		return s_list[x-2];
	}
	catch (T& value)
	{
		std::cout << "PriorElem ERROR -> ";
		return item;
	}
}

template<class T>
T s_List<T>::NextElem(const T & item)
{
	try
	{
		int x = LocateElem(item);
		if (x >= length || x <= 0)
			throw item;
		return s_list[x];
	}
	catch (T& value)
	{
		std::cout << "NextElem ERROR -> ";
		return item;
	}
}

template<class T>
inline s_List<T>::~s_List()
{
	delete[] s_list;
	s_list = NULL;
}
