#pragma once
//  Union Find
// ���鼯�� ���ڹ���ͼ�����������ͨ������ һ���ܾ����һ���ⷨ
// ����ɶ��Ը�, ʱ�临�Ӷ�ֻ�� O(1), �ռ临�Ӷ� O(n);
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

	// ���� union find�� find���� �����д�� �� return x == par[x] ? x : find(par[x]); �����������ѯ ��ô��Ľ���ǲ�ѯһ������ 
	// ����ʱ�临�ӶȽ����� O(n), �� ���д�� return par[x] = x == par[x] ? x : find(par[x]); ��ô ������� һ�����Ϊ����һ����, 
	// ��ô ���ڶ��β�ѯ��ʱ�� ����ʱ�临�Ӷ� ���Խ��� O(1) ����Ƿǳ��õ� 

	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (find(x) != find(y)) {
			par[find(y)] = find(x);
		}
	}
};

//���Ͼ��� ���ڲ��鼯 Union Find �Ļ���ģ��

//���� Union Find ���� (������ Leetcode 684 ��������(mid))
	//����һ��ͼ����ͼ��һ������N���ڵ� (�ڵ�ֵ���ظ�1, 2, ..., N) ������һ�����ӵı߹��ɡ����ӵıߵ��������������1��N�м䣬�������ӵı߲����������Ѵ��ڵıߡ�
	//���ͼ��һ���Ա���ɵĶ�ά���顣ÿһ���ߵ�Ԫ����һ��[u, v] ������ u < v����ʾ���Ӷ���u ��v������ͼ�ıߡ�
	//����һ������ɾȥ�ıߣ�ʹ�ý��ͼ��һ������N���ڵ����������ж���𰸣��򷵻ض�ά�����������ֵıߡ��𰸱�[u, v] Ӧ������ͬ�ĸ�ʽ u < v��
//ʾ��һ : 
	//����: [[1,2], [1,3], [2,3]]
	//���: [2, 3]
	//���� : ����������ͼΪ :
	//	 1
	//	/ \
	// 2 - 3
//˼·���: ������������ͼ����, ���ǿ��Գ����, ͼ�����������ͨ����, ��ô���ǵ�˼·����: ȥ��������ͼ, ���һ����� x��y, ���ǵ�find(x) != find(y) ��ô������merge��һ��,
//��ʱ ���ǽ���ӵ�й�ͬ������, ��� һ���� ���ǵ� x��y ��������ͬ(find(x) == find(y)) ��ô�����Ǽ�¼�� ans ��.

//����: 

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
};*/   //ʱ�临�Ӷ�O(n),�ռ临�Ӷ� O(n);