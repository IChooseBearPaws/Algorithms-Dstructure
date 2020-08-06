#pragma once
/*
 *	sequential queue——循环队列顺序存储结构
*/

template<class T>
class s_Queue
{
public:
	s_Queue(int queueCapacity = 10);//构造函数初始化队列默认容量为10
	bool ClearQueue();				//清空队列
	bool QueueEmpty() const;		//功能函数判断当前队列是否为空
	bool EnQueue(const T& item);	//向队尾插入元素
	T GetHead();					//获取队首元素
	T DeQueue();					//删除队首元素
	int QueueLength();				//当前队列中元素个数
	~s_Queue();						//销毁队列
private:
	T* queue;						//队列指针
	int capacity;					//队列长度
	int front;						//队列首元素下标
	int rear;						//队列尾元素下标
};

template<class T>
s_Queue<T>::s_Queue(int queueCapacity):capacity(queueCapacity)
{
	try
	{
		if (capacity > 0)
		{
			queue = new T[capacity];
			front = 0;
			rear = 0;
		}
		else
			throw capacity;
	}
	catch (const std::exception&)
	{
		std::cout << "Queue capacity must > 0" << std::endl;
	}
}

template<class T>
inline bool s_Queue<T>::ClearQueue()
{
	rear = front;
	return true;
}

template<class T>
inline bool s_Queue<T>::QueueEmpty() const
{
	return front == rear;
}

template<class T>
bool s_Queue<T>::EnQueue(const T & item)
{
	if ((rear + 1) % capacity != front)
	{
		queue[rear] = item;
		rear = (rear + 1) % capacity;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline T s_Queue<T>::GetHead()
{
	if (front == rear)
	{
		std::cout << "GetHead ERROR! Queue is empty,Fault Data -> ";
		return queue[front];
	}
	else
		return queue[front];
}

template<class T>
T s_Queue<T>::DeQueue()
{
	T _data = queue[front];
	if ((front + 1) % capacity != rear)
	{
		front = (front + 1) % capacity;
		return _data;
	}
	else
	{
		front = rear;
		return _data;
	}
}

template<class T>
inline int s_Queue<T>::QueueLength()
{
	return (rear - front + capacity) % capacity;
}

template<class T>
s_Queue<T>::~s_Queue()
{
	delete queue;
	queue = NULL;
}