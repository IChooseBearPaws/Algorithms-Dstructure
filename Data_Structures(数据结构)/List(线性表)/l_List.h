#pragma once
#include <iostream>
/*
 *	Link List - 线性表的链式存储结构
 *
*/

template<class T>
class Node 
{
public:
	T data;
	Node* next;
};

template<class T>
class l_list
{
public:
	l_list();								//构造函数初始化头节点
	bool ListInsert(const T& item);			//逻辑末尾处插入新元素item
	bool ListInsert(int i, const T& item);	//逻辑顺序i处插入新元素item
	int LocateElem(const T& item);			//返回第一个与item元素相等的序号，不存在返回0
	T GetElem(int i);				//获取i个元素个值,i=0则返回头结点数据域即元素个数
	T ListDelet(int i);				//删除第i个元素并返回其值
	~l_list();						//销毁线性表
private:
	Node<T>* head;					//头结点
	Node<T>* rNode;					//尾结点
};

template<class T>
l_list<T>::l_list()
{
	head = new Node<T>;				//初始化头结点
	head->data = 0;
	head->next = NULL;
	rNode = this->head;
}

template<class T>
bool l_list<T>::ListInsert(const T & item)
{
	Node<T> *newNode;				//声明新结点
	newNode = new Node<T>;			//初始化新节点
	newNode->data = item;			//赋值
	newNode->next = NULL;			//末尾指针置空
	this->head->data += 1;			//头结点数据与+1代表线性表元素个数
	rNode->next = newNode;			//当前尾结点指向新生成的结点
	rNode = newNode;				//将新生成结点置为尾结点
	return true;
}

template<class T>
bool l_list<T>::ListInsert(int i, const T & item)
{
	if (i > 0 && i <= this->head->data)
	{
		Node<T> *p, *s;
		s = new Node<T>;
		s->data = item;
		p = this->head;
		while (i - 1 >= 1)
		{
			p = p->next;
			i--;
		}
		s->next = p->next;
		p->next = s;
		this->head->data += 1;
		return true;
	}
	else
		return false;
}

template<class T>
int l_list<T>::LocateElem(const T & item)
{
	Node<T> *p;
	int i = 0;
	p = head;
	while (p->next)
	{
		p = p->next;
		i++;
		if (item == p->data)
			return i;
	}
	return 0;
}

template<class T>
T l_list<T>::GetElem(int i)
{
	try
	{
		if (i >= 0 && i <= this->head->data)
		{
			T _data;
			Node<T> *p;
			p = head;
			for (int n = 0; n < i; n++)
			{
				p = p->next;
			}
			_data = p->data;
			return _data;
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
T l_list<T>::ListDelet(int i)
{
	try
	{
		T _data;
		if (i > 1 && i <= this->head->data)
		{
			Node<T> *p, *q;
			p = this->head;
			while (i - 1 >= 1)
			{
				if (!(p->next))
				{
					throw i;
					break;
				}
				p = p->next;
				i--;
			}
			if (!(p->next->next))
				rNode = p;
			q = p->next;
			_data = q->data;
			p->next = q->next;
			delete q;
			q = NULL;
			this->head->data -= 1;
			return _data;
		}
		else
		{
			throw i;
		}
	}
	catch (int& value)
	{
		std::cout << "ListDelet ERROR! i -> ";
		return i;
	}
}

template<class T>
inline l_list<T>::~l_list()
{
	delete head;
	head = NULL;
}
