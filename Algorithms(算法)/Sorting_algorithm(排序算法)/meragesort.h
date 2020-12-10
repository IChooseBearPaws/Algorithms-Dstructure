#pragma once

/*
	Merge sort (Divide and conquer algorithm)
*/

// 归并排序 动画展示: https://www.bilibili.com/video/BV1AJ41167VK?from=search&seid=2883332805467242330

// 代码 :
template <class T>

void Meragesort(T * arr, int left, int right) {
	if (left == righ) return;

	int mid = (left + right) / 2;
	Meragesort(arr, left, mid);       // 左排序
	Meragesort(arr, mid + 1, right); //右排序

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

/*	原理 :  1.利用分治算法, 将数组 arr[] 形成两个序列 arr_1(n / 2) 和 arr_2(n / 2)一直递归分解, 直到每个序列只包含一个 / 两个元素
			2.形成两个数组a[], b[], 对两个数组的第一个元素进行比较, 较小的放到临时创建的数组 buff[] 中, 当其中一个数组 a[] / b[] 已经将所有元素放入了 buff[]中,
			  那么将剩下没有放完的数组 (b[] / a[]) 的剩余元素依次放进 buff[] 数组中去.
			3.重复第二步 直到排序完毕.

	举例:
		 arr[] = {8, 5, 1, 6, 2, 4, 9};
		 先将arr[] 分成 [8, 5, 1] 与 [6, 2, 4, 9]
		 然后将[8, 5, 1] 分成 [8] 与 [5, 1]
		 这时 [8] 中 left == right 无法在分割了 return
		 然后到了 [5, 1]
		 将[5. 1] 可以分成 a[] = [5] 与 b[] = [1], 显而易见, [5]和[1] 也没有办法分割
		 返回到了 [5, 1]中, [5 , 1]中的meragesort(left, mid) 以及 meragesort(mid + 1, right) 全部完成
		 将其归并排序,显然 1 < 5, 这样就变成了 [1, 5] return;
		 回到了[8, 5, 1], 此时已变成 [8, 1, 5], 并且 [8, 1, 5]中 meragesort(left, mid) 以及 meragesort(mid + 1, right) 全部完成
		 将其排序, a[] = {8} 与 b[] = {1, 5} 这两个数组首元素开始比较, 1 < 8 就将 1 放入 buff[] 中
		 然后 5 < 8, 再将 5放入 buff[]中, 这样b[] 数组全部遍历完成, 将a[] = {8} 依次放入 buff[] 中
		 这样 buff[] = {1, 5, 8}, arr[]的 meragesort(left, mid) 就已经排序完毕下来再按上述方法 对 meragesort(mid + 1, right)进行排列

		 最后得到一个 由小到大排列的数组 [1, 2, 4, 5, 6, 8, 9]


	算法分析:
		假设n > 1 : 时间是T(n) 那么两个就是 2T(2 / n) 合并算法时间是 O(n)
			n = 1 : O(1).
	
			根据主定理 : T(n) = kT(n / m) + f(n)中, f(n) = n ^ d, d >= 0
			则 时间复杂度是 O(nlogn).<出自借鉴百度>

			
	总结 :	归并排序是一种非就地排序，将需要与待排序序列一样多的辅助空间。在使用它对两个己有序的序列归并，将有无比的优势。
			其时间复杂度无论是在最好情况下还是在最坏情况下均是O(nlog2n)。
			对数据的有序性不敏感。若数据节点数据量大，那将不适合。
			但可改造成索引操作，效果将非常出色。<出自维基百科 https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F>
*/
