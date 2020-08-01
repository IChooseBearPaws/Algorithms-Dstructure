#pragma once 
#include <iostream>

/*
 * double Link List - 线性表的双向循环链表
 * 
*/

template<class T>
class Node
{
public:
	T data;
	Node* prior;
	Node* next;
};

template<class T>
class dl_List
{
public:
	dl_List();								//构造函数初始化头结点
	int ListLength() const;					//获取线性表元素个数
	bool ListEmpty() const;					//判断线性表是否为空
	bool ListInsert(const T& item);			//顺序插入元素item
	bool ListInsert(int i, const T& item);	//第i个位置插入元素item
	int LocateElem(const T& item);			//返回第一个与item相等元素的序号，不存在则返回0
	T GetElem(int i);						//获取第i个元素值
	T ListDelet(int i);						//删除第i个元素并返回其值
	T PriorElem(const T& item);				//返回第一个与item相等元素的前驱
	T NextElem(const T& item);				//返回第一个与item相等元素的后继
	~dl_List();				//析构函数销毁线性表
private:
	int length;
	Node<T>* head;			//头结点
	Node<T>* rNode;			//尾元素指针
};

template<class T>
dl_List<T>::dl_List()
{
	head = new Node<T>;
	length = 0;			
	head->data = NULL;
	head->prior = head;
	head->next = head;
	rNode = head;
}

template<class T>
inline int dl_List<T>::ListLength() const
{
	return length;
}

template<class T>
inline bool dl_List<T>::ListEmpty() const
{
	return length == 0 ? true : false;
}

template<class T>
bool dl_List<T>::ListInsert(const T & item)
{
	Node<T> *newNode;				//声明新结点
	newNode = new Node<T>;			//初始化新结点
	newNode->data = item;			//赋值
	newNode->prior = rNode;			//新结点头指针指向当前尾结点
	newNode->next = rNode->next;	//新结点尾指针指向当前尾结点的后继即环首
	head->prior = newNode;			//头结点前驱指向新结点即环尾
	rNode->next = newNode;			//当前尾结点后继指向新结点
	rNode = newNode;				//尾结点为新结点
	length += 1;
	return true;
}

template<class T>
bool dl_List<T>::ListInsert(int i, const T & item)
{
	try
	{
		if (i > 0 && i <= length)
		{
			Node<T>* _node;
			Node<T>* newNode = new Node<T>;
			newNode->data = item;
			_node = head;
			while (i)
			{
				_node = _node->next;
				i--;
			}
			newNode->prior = _node->prior;
			_node->prior->next = newNode;
			_node->prior = newNode;
			newNode->next = _node;
			length += 1;
			return true;
		}
		else
			throw i;
	}
	catch (int& value)
	{
		return false;
	}
}

template<class T>
inline int dl_List<T>::LocateElem(const T & item)
{
	int _length = length;
	Node<T> *_node = this->rNode;
	while (_length && _node != head)
	{
		if (_node->data == item)
		{
			return _length;
		}
		_node = _node->prior;
		_length--;
	}
	return 0;
}

template<class T>
T dl_List<T>::GetElem(int i)
{
	try
	{
		if (i > 0 && i <= length)
		{
			Node<T>* _node = this->head;
			while (i > 0)
			{
				_node = _node->next;
				i--;
			}
			return _node->data;
		}
		else
			throw i;
	}
	catch (int& value)
	{
		std::cout << "GetElem ERROR! i -> ";
		return i;
	}
}

template<class T>
T dl_List<T>::ListDelet(int i)
{
	try
	{
		if (i > 0 && i <= length)
		{
			Node<T>* _node = this->head;
			T _data;
			while (i > 0)
			{
				_node = _node->next;
				i--;
			}
			_data = _node->data;
			_node->prior->next = _node->next;
			_node->next->prior = _node->prior;
			rNode = _node->next;
			delete _node;
			_node = NULL;
			length -= 1;
			return _data;
		}
		else
			throw i;
	}
	catch (int& value)
	{
		std::cout << "ListDelet ERROR! i -> ";
		return i;
	}
}

template<class T>
T dl_List<T>::PriorElem(const T & item)
{
	Node<T>* _node;
	_node = this->rNode;
	while (_node->prior != head)
	{
		if (_node->data == item)
			return _node->prior->data;
		_node = _node->prior;
	}
	return head->data;
}

template<class T>
T dl_List<T>::NextElem(const T & item)
{
	Node<T>* _node;
	_node = this->head->next;
	while (_node->next != head)
	{
		if (_node->data == item)
			return _node->next->data;
		_node = _node->next;
	}
	return head->data;
}

template<class T>
dl_List<T>::~dl_List()
{
	Node<T>* _node;
	while (rNode != head)
	{
		_node = rNode;
		rNode = _node->prior;
		delete _node;
		_node = NULL;
	}
	delete head;
	head = NULL;
}
