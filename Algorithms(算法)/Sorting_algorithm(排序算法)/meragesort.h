#pragma once

/*
	Merge sort (Divide and conquer algorithm)
*/

// �鲢���� ����չʾ: https://www.bilibili.com/video/BV1AJ41167VK?from=search&seid=2883332805467242330

// ���� :
template <class T>

void Meragesort(T * arr, int left, int right) {
	if (left == righ) return;

	int mid = (left + right) / 2;
	Meragesort(arr, left, mid);       // ������
	Meragesort(arr, mid + 1, right); //������

	int ret[right - left + 1];
	int begin = left, end = mid + 1;
	int index = 0;
	while (begin <= left || end <= right) {
		if (begin > left) ret[index++] = arr[right++];
		else if (end > right) ret[index++] = arr[left++];
		else if (arr[begin] < arr[left]) ret[index++] = arr[begin++];
		else ret[index++] = arr[end++];
	}

	int index_ = 0;
	for (int i = left, i <= right; ++i) arr[i] = ret[index_++];
}

/*	ԭ�� :  1.���÷����㷨, ������ arr[] �γ��������� arr_1(n / 2) �� arr_2(n / 2)һֱ�ݹ�ֽ�, ֱ��ÿ������ֻ����һ�� / ����Ԫ��
			2.�γ���������a[], b[], ����������ĵ�һ��Ԫ�ؽ��бȽ�, ��С�ķŵ���ʱ���������� buff[] ��, ������һ������ a[] / b[] �Ѿ�������Ԫ�ط����� buff[]��,
			  ��ô��ʣ��û�з�������� (b[] / a[]) ��ʣ��Ԫ�����ηŽ� buff[] ������ȥ.
			3.�ظ��ڶ��� ֱ���������.

	����:
		 arr[] = {8, 5, 1, 6, 2, 4, 9};
		 �Ƚ�arr[] �ֳ� [8, 5, 1] �� [6, 2, 4, 9]
		 Ȼ��[8, 5, 1] �ֳ� [8] �� [5, 1]
		 ��ʱ [8] �� left == right �޷��ڷָ��� return
		 Ȼ���� [5, 1]
		 ��[5. 1] ���Էֳ� a[] = [5] �� b[] = [1], �Զ��׼�, [5]��[1] Ҳû�а취�ָ�
		 ���ص��� [5, 1]��, [5 , 1]�е�meragesort(left, mid) �Լ� meragesort(mid + 1, right) ȫ�����
		 ����鲢����,��Ȼ 1 < 5, �����ͱ���� [1, 5] return;
		 �ص���[8, 5, 1], ��ʱ�ѱ�� [8, 1, 5], ���� [8, 1, 5]�� meragesort(left, mid) �Լ� meragesort(mid + 1, right) ȫ�����
		 ��������, a[] = {8} �� b[] = {1, 5} ������������Ԫ�ؿ�ʼ�Ƚ�, 1 < 8 �ͽ� 1 ���� buff[] ��
		 Ȼ�� 5 < 8, �ٽ� 5���� buff[]��, ����b[] ����ȫ���������, ��a[] = {8} ���η��� buff[] ��
		 ���� buff[] = {1, 5, 8}, arr[]�� meragesort(left, mid) ���Ѿ�������������ٰ��������� �� meragesort(mid + 1, right)��������

		 ���õ�һ�� ��С�������е����� [1, 2, 4, 5, 6, 8, 9]


	�㷨����:
		����n > 1 : ʱ����T(n) ��ô�������� 2T(2 / n) �ϲ��㷨ʱ���� O(n)
			n = 1 : O(1).
	
			���������� : T(n) = kT(n / m) + f(n)��, f(n) = n ^ d, d >= 0
			�� ʱ�临�Ӷ��� O(nlogn).<���Խ���ٶ�>

			
	�ܽ� :	�鲢������һ�ַǾ͵����򣬽���Ҫ�����������һ����ĸ����ռ䡣��ʹ��������������������й鲢�������ޱȵ����ơ�
			��ʱ�临�Ӷ����������������»����������¾���O(nlog2n)��
			�����ݵ������Բ����С������ݽڵ����������ǽ����ʺϡ�
			���ɸ��������������Ч�����ǳ���ɫ��<����ά���ٿ� https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F>
*/
