#pragma once
#include <iostream>
/*
 *	Link Stack -- 栈的链式存储结构
*	特性：逻辑相邻，物理不相邻
*/

template<class T>
class Node
{
public:
	T data;
	Node* next;
};

template<class T>
class l_Stack
{
public:
	l_Stack();		//构造函数初始化栈
	bool StackEmpty() const;	//判是否为空栈
	T GetTop();	//获取栈顶元素并返回其值
	bool Push(const T& item);	//插入新元素至栈顶
	T Pop();	//弹出栈顶元素并返回其值
	int StackLength();	//返回栈中元素个数
	~l_Stack();		//析构函数销毁栈
private:
	int length;
	Node<T>* head;
};

template<class T>
l_Stack<T>::l_Stack()
{
	head = new Node<T>;
	head = NULL;
	length = 0;
}

template<class T>
inline bool l_Stack<T>::StackEmpty() const
{
	return head == NULL;
}

template<class T>
inline T l_Stack<T>::GetTop()
{
	return head->data;
}

template<class T>
bool l_Stack<T>::Push(const T & item)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->next = head;
	head = newNode;
	length += 1;
	return true;
}

template<class T>
T l_Stack<T>::Pop()
{
	Node<T>* _node = new Node<T>;
	T data;
	_node = head;
	data = _node->data;
	head = _node->next;
	delete _node;
	_node = NULL;
	length -= 1;
	return data;
}

template<class T>
inline int l_Stack<T>::StackLength()
{
	return length;
}

template<class T>
l_Stack<T>::~l_Stack()
{
	Node<T>* _node;
	while (head != NULL)
	{
		_node = head;
		head = _node->next;
		delete _node;
		_node = NULL;
	}
	delete head;
	head = NULL;
}
