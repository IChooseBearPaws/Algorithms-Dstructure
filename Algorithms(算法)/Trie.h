//�ֵ�����ѧ:https://www.bilibili.com/video/BV1Az4y1S7c7?from=search&seid=7439230436454907529
//�ֵ���ģ��
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() : root_(new TrieNode()) {}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root_.get();
		for (char c : word) {
			if (!p->child[c - 'a'])
				p->child[c - 'a'] = new TrieNode();
			p = p->child[c - 'a'];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = find(word);
		return p && p->is_word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return find(prefix) != nullptr;
	}
private:
	class TrieNode {
	public:
		TrieNode() : is_word(false), child(26, nullptr) {}
		~TrieNode() {
			for (TrieNode* p : child) {
				if (p) delete p;
			}
		}
		vector <TrieNode*> child;
		bool is_word;   // ��������һ�������ĵ���(true) ����Ȼ
	};

	TrieNode* find(const string& prefix) {
		TrieNode* p = root_.get();
		for (auto charr : prefix) {
			p = p->child[charr - 'a'];
			if (nullptr == p) break;
		}
		return p;
	}
	std::unique_ptr<TrieNode> root_;  //����ָ�� �����Զ�����
};