#pragma once
//  Union Find
//并查集动画 : https://www.bilibili.com/video/BV1yE411u7FD?p=21
//并查集讲解: https://www.bilibili.com/video/BV1qK411J7J6?from=search&seid=14834253158345534002
// 并查集是 用于关于图的两个结点连通性问题 一个很经典的一个解法
// 代码可读性高, 时间复杂度只有 O(1), 空间复杂度 O(n);
class UF {
private:
	vector <int>par;
public:
	UF(int n) : par(n) {
		for (int i = 0; i < n; ++i) {
			par[i] = i;
		}
	}

	int find(int x) {
		return par[x] = x == par[x] ? x : find(par[x]);
	}

	// 对于 union find的 find函数 最初的写法 有 return x == par[x] ? x : find(par[x]); 如果是这样查询 那么最坏的结果是查询一个链表 
	// 他的时间复杂度将会是 O(n), 而 如果写成 return par[x] = x == par[x] ? x : find(par[x]); 那么 他将变成 一棵深度为二的一棵树, 
	// 那么 当第二次查询的时候 他的时间复杂度 可以降到 O(1) 这个是非常好的 

	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (find(x) != find(y)) {
			par[find(y)] = find(x);
		}
	}
};

//以上就是 关于并查集 Union Find 的基本模板

//关于 Union Find 例题 (来自于 Leetcode 684 冗余连接(mid))
	//输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。
	//结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。
	//返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边[u, v] 应满足相同的格式 u < v。
//示例一 : 
	//输入: [[1,2], [1,3], [2,3]]
	//输出: [2, 3]
	//解释 : 给定的无向图为 :
	//	 1
	//	/ \
	// 2 - 3
//思路解答: 对于这种无向图问题, 我们可以抽象成, 图的两个结点连通问题, 那么我们的思路就是: 去遍历整个图, 如果一个点的 x与y, 他们的find(x) != find(y) 那么将他们merge在一起,
//此时 他们将会拥有共同的祖先, 如果 一个点 他们的 x与y 的祖先相同(find(x) == find(y)) 那么把他们记录在 ans 中.

//代码: 

/*class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int size = 0;
		for (auto v :edges) {
			for (auto val :v) size = max(size, val);
		}
		UF uf_(size + 1);

        vector <int > ans;
        for (auto& ve : edges) {
            if (uf_.find(ve[0]) != uf_.find(ve[1])) {
                uf_.merge(ve[0], ve[1]);
                continue;
            }
            ans.emplace_back(ve[0]);
            ans.emplace_back(ve[1]);
            break;
        }
        return ans;
    }
private: 
	class UF {
	private:
		vector <int>par;
	public:
		UF(int n) : par(n) {
			for (int i = 0; i < n; ++i) {
				par[i] = i;
			}
		}

		int find(int x) {
			return par[x] = x == par[x] ? x : find(par[x]);
		}

		void merge(int x, int y) {
			int fx = find(x), fy = find(y);
			if (find(x) != find(y)) {
				par[find(y)] = find(x);
			}
		}
	};
};*/   //时间复杂度O(n),空间复杂度 O(n);
