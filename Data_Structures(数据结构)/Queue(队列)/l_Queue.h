#pragma once
/*
 *	Link Queue -- 栈的链式存储结构
*/

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <class T>
class l_Queue
{
public:
	l_Queue();		//构造函数初始化空队列
	bool QueueEmpty() const;		//队列是否为空
	bool EnQueue(const T& item);	//队尾插入新元素
	T GetHead();	//获取队首元素
	T DeQueue();	//删除队首元素
	int QueueLength();	//队列元素个数
	~l_Queue();		//析构函数销毁队列
private:
	Node<T>* front;	//队首指针
	Node<T>* rear;	//队尾指针
	int length;		//队列元素个数
};

template<class T>
l_Queue<T>::l_Queue()
{
	Node<T>* _node = new Node<T>;
	front = rear = _node;
	_node->data = NULL;
	front->next = NULL;
	length = 0;
}

template<class T>
inline bool l_Queue<T>::QueueEmpty() const
{
	return length==0;
}

template<class T>
bool l_Queue<T>::EnQueue(const T & item)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->next = NULL;
	rear->next = newNode;
	rear = newNode;
	length += 1;
	return true;
}

template<class T>
inline T l_Queue<T>::GetHead()
{
	if (length <= 0)
	{
		std::cout << "GetHead ERROR! Queue is empty,Fault Data -> ";
	}
	else
		return front->next->data;
}

template<class T>
T l_Queue<T>::DeQueue()
{
	if (length > 0)
	{
		Node<T>* _node;
		T _data;
		_node = front->next;
		_data = _node->data;
		front->next = _node->next;
		delete _node;
		_node = NULL;
		length -= 1;
		return _data;
	}
	else
	{
		std::cout << "DeQueue ERROR! Queue is empty,Fault Data -> ";
	}
}

template<class T>
inline int l_Queue<T>::QueueLength()
{
	return length;
}

template<class T>
l_Queue<T>::~l_Queue()
{
	Node<T>* _node;
	while (front->next != rear)
	{
		_node = front->next;
		front = _node->next;
		delete _node;
		_node = NULL;
	}
	delete rear, front;
	front = rear = NULL;
}

