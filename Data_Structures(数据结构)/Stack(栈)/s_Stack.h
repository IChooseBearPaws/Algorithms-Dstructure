#pragma once
#include <iostream>
/*
	Sequential stack -- 栈的顺序存储结构
	特性：逻辑相邻，物理也相邻
*/

template<class T>
class s_Stack
{
public:
	s_Stack(int stackCapacity = 10);	//构造函数初始化栈默认容量为10
	void ClearStack();	//将栈清空
	bool StackEmpty() const;	//判是否为空栈
	T GetTop();	//获取栈顶元素并返回其值
	bool Push(const T& item);	//插入新元素至栈顶
	T Pop();	//弹出栈顶元素并返回其值
	int StackLength();	//返回栈中元素个数
	~s_Stack();			//析构函数销毁栈
private:
	T* s_stack;
	int top;		//栈顶指针
	int capacity;	//栈的存储容量
};

template<class T>
s_Stack<T>::s_Stack(int stackCapacity): capacity(stackCapacity)
{
	try
	{
		if (capacity < 1)
			throw capacity;
		s_stack = new T[capacity];
		top = -1;
	}
	catch (int& value)
	{
		std::cout << "Stack capacity must > 0" << std::endl;
	}
}

template<class T>
inline void s_Stack<T>::ClearStack()
{
	top = -1;
}

template<class T>
inline bool s_Stack<T>::StackEmpty() const
{
	return top > -1 ? false : true;
}

template<class T>
T s_Stack<T>::GetTop()
{
	try
	{
		if (top > -1)
			return s_stack[top]; \
		else
			throw -1;
	}
	catch (int& value)
	{
		std::cout << "GetTop ERROR!";
		return NULL;
	}
}

template<class T>
bool s_Stack<T>::Push(const T & item)
{
	if (top < capacity - 1)
	{
		top++;
		s_stack[top] = item;
		return true;
	}
	else
		return false;
}

template<class T>
T s_Stack<T>::Pop()
{
	T data;
	data = s_stack[top];
	top--;
	return data;
}

template<class T>
inline int s_Stack<T>::StackLength()
{
	return top + 1;
}

template<class T>
inline s_Stack<T>::~s_Stack()
{
	delete[] s_stack;
	s_stack = NULL;
}
