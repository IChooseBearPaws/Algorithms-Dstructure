//算法头文件
#include "Sorting_algorithm(排序算法)/Bubble.h"

//数据结构头文件
#include "Queue(队列)/Queue.h"

//标准库头文件
#include <iostream>

using namespace std;

//冒泡排序测试
void bubbleTest();
//顺序队列测试
void queueTest();

int main(void)
{

	std::cout << "Welcome to algorithms and data structures." << std::endl;

	//冒泡排序测试
	bubbleTest();

	//顺序队列测试
	queueTest();









	std::cin.get();
}

//冒泡排序测试
void bubbleTest()
{
	int Arr_i[] = { 3, 1, 4, 2 , 6, 9, 5, 7, 8, 0 };
	double Arr_d[] = { 13.1, 21.3, 31.4, 0.31, 1.43, 6.52, 12.6, 19.75, 50.01, 30.33 };
	bubble(Arr_i, 10);
	bubble(Arr_d, 10);
	for (int i = 0; i < 10; i++)
		cout << Arr_d[i] << ", ";
	cout << endl;
}

//队列测试
void queueTest()
{
	Queue<int> queue_i;
	Queue<double> queue_d(8);
	cout << queue_i.isEmpty() << endl;
	queue_i.push_Q(0);
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.traversal();
	queue_i.push_Q(1);
	cout << queue_i.Front() << endl;
	cout << queue_i.Rear() << endl;
	queue_i.push_Q(2);
	queue_i.push_Q(3);
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.push_Q(4);
	queue_i.push_Q(5);
	queue_i.push_Q(6);
	queue_i.push_Q(7);
	queue_i.traversal();
	cout << "numel:" << queue_i.numel() << endl;
	cout << queue_i.Rear() << endl;
	queue_i.push_Q(8);
	queue_i.push_Q(9);
	cout << queue_i.Rear() << endl;
	cout << queue_i.Front() << endl;
	queue_i.traversal();
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.pop_Q();
	queue_i.push_Q(10);
	cout << queue_i.Rear() << endl;
	cout << queue_i.Front() << endl;
	queue_i.pop_Q();
	queue_i.push_Q(11);
	cout << queue_i.Front() << endl;
	cout << queue_i.Rear() << endl;
	queue_i.traversal();
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.push_Q(31);
	queue_i.push_Q(41);
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	queue_i.pop_Q();
	cout << queue_i.Rear() << endl;
	cout << queue_i.Front() << endl;
	cout << "numel:" << queue_i.numel() << endl;
	queue_i.traversal();
	queue_i.pop_Q();
	cout << "numel:" << queue_i.numel() << endl;
	cout << queue_i.isEmpty() << endl;
}
