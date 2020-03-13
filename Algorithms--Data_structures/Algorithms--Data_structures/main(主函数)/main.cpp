//算法头文件
#include "Search_algorithm(查找算法)/Order.h"
#include "Sorting_algorithm(排序算法)/Bubble.h"
#include "Sorting_algorithm(排序算法)\Insertion.h"
#include "Sorting_algorithm(排序算法)/Quick.h"
#include "Sorting_algorithm(排序算法)/Select.h"


//数据结构头文件
#include "Queue(队列)/Queue.h"

//标准库文件
#include <iostream>

using namespace std;

//顺序查找测试
void ordertest();
//冒泡排序测试
void bubbleTest();
//快速排序测试
void quickTest();
//选择排序测试
void selectTest();

//顺序队列测试
void queueTest();

int main(void)
{

	std::cout << "Welcome to algorithms and data structures." << std::endl;

	//顺序查找测试
	//ordertest();
	//冒泡排序测试
	bubbleTest();
	//快速排序测试
	//quickTest();
	//选择排序测试
	//selectTest();

	//顺序队列测试
	//queueTest();

	std::cin.get();
}
//顺序查找测试
void ordertest()
{
	int arr[5] = { 1, 3, 2, 4, 0 };
	
	cout << order(arr, 5, 0) << endl;
	cout << order(arr, 5, 4) << endl;
	cout << order(arr, 5, 9) << endl;
}
//冒泡排序测试
void bubbleTest()
{
	int Arr_i[] = { 3, 1, 4, 2 , 6, 9, 5, 7, 8, 0 };
	double Arr_d[] = { 13.1, 21.3, 31.4, 0.31, 1.43, 6.52, 12.6, 19.75, 50.01, 30.33 };
	//bubble(Arr_i, 10);
	//bubble(Arr_d, 10);
	insertion(Arr_i, 10);

	for (int i = 0; i < 10; i++)
		cout << Arr_i[i] << ", ";
	cout << endl;
}
//快速排序测试
void quickTest()
{
	int high;
	cin >> high;
	int *arr = new int[high];
	for (int i = 0; i < high; i++)
		cin >> arr[i];

	quick(arr, 0, high-1);

	for (int i = 0; i < high; i++)
		cout << arr[i] << ",";
}
//选择排序测试
void selectTest()
{
	int Arr[] = { 3, 1, 4, 2 , 6, 9, 5, 7, 8, 0 };
	select(Arr, 10);
	for (int i = 0; i < 10; i++)
		cout << Arr[i] << ", ";
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
