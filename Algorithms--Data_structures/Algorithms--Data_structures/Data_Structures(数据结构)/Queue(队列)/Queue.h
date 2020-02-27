#pragma once

/*
	sequential queue——循环队列
	特性:先进先出
*/

template<class T>
class Queue
{
public:
	Queue(int queueCapacity = 10);	//构造函数初始化队列默认容量为10
	bool isEmpty() const;			//功能函数判断当前队列是否为空
	void push_Q(const T& item);		//向队尾插入元素
	void pop_Q();					//删除队首元素
	void traversal();				//遍历队列
	int numel();					//当前队列中元素个数
	T& Front();						//获取当前队首元素值
	T& Rear();						//获取当前队尾元素值
	~Queue();						//销毁队列
private:
	T* queue;						//队列指针
	int capacity;					//队列长度
	int front;						//队列首元素下标
	int rear;						//队列尾元素下标
	int number;						//队列元素个数
};

template<class T>
Queue<T>::Queue(int queueCapacity) :capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = number = 0;
}

template<class T>
inline bool Queue<T>::isEmpty() const
{
	return !number;
}

template<class T>
void Queue<T>::push_Q(const T& item)
{
	if (number == capacity) throw "The queue is full";
	if (rear == capacity && front > 0)
		rear = 0;
	queue[rear++] = item;
	number++;
}

template<class T>
void Queue<T>::pop_Q()
{
	if (number == 0) throw "The queue is empty";
	if (front == capacity && rear > 0 && front >= rear)
		front = 0;
	queue[front++].~T();
	//front = (front + 1) % capacity;
	number--;
}

template<class T>
void Queue<T>::traversal()
{
	if (number == 0) throw "The queue is empty";
	int ff = front;
	int rr = rear;
	int xx = front>=rear ? capacity : rear;
	for(int i = ff; i < xx ; i++)
		std::cout << queue[i] << " ";
	if(rear <= front)
		for (int j = 0; j < rr; j++)
		{
			std::cout << queue[j] << " ";
		}
	std::cout << std::endl;
}

template<class T>
int Queue<T>::numel()
{
	//return front < rear ? rear - front : capacity - front + rear;
	return number;
}

template<class T>
inline T& Queue<T>::Front()
{
	if (number == 0) throw "The queue is empty";
	return queue[front];
}

template<class T>
inline T& Queue<T>::Rear()
{
	if (number == 0) throw "The queue is empty";
	return queue[rear-1];
}

template<class T>
Queue<T>::~Queue()
{
	delete[] queue;
	queue = 0;
}

