#pragma once
#include "Stack(栈)\l_Stack.h"
/*
 *	Sequential String - 串的顺序存储结构
*/

class s_String
{
public:
	s_String();
	/*
	 *以下几个函数的功能，因采取C++实现，故用C++相关特性进行表述
	 *	1.void StrAssign(&T, chars);	//生成一个值等于字符串常量chars的串T
	 *	2.StrCopy(&T, S);	//由S复制得串T
	*/
	s_String(const char* chars);	//重载构造函数，功能同上1
	//s_String(const s_String & s);	//类的默认拷贝构造函数功能同上2，但是进行的是浅拷贝,析构对象时造成内存泄漏
	s_String(const s_String & s);	//重写拷贝构造函数为深拷贝
	void operator=(const s_String& s);	//功能同上，采用C++11特性进行扩展
	char operator[](int i);	//获取串的第i个元素
	bool StrEmpty();	//串是否为空串（空串 = ""），为空返回true，否则false
	int StrCompare(const s_String& S);	//当前串 >、=、< 串S，则返回子 >、=、< 0
	int StrLength();	//串的元素个数
	void ClearString();	//将当前串清空
	void Concat(s_String S1);	//将S1链接在当前串的后面并更新为当前串
	/*
	 * 功能:将两个字符串合并且返回，采用C++11特性。
	 * 注:函数返回值时调用一次拷贝构造函数，如果没有重写为深拷贝则会二次释放同一内存，造成内存泄漏。
	 *    这也是上面重写拷贝构造函数为深拷贝的另一个原因。
	 */
	s_String operator+(const s_String& S1);
	s_String SubString(int pos, int len);	//返回当前串第pos个字符起长度len的字串
	/*
	 * 功能:返回子串T在当前串第pos个字符之后第一次出现的位置.若不存在，则返回值为0
	 * 核心内容:串的模式匹配算法
	 *		1.BF匹配算法
	 *		2.KMP匹配算法
	*/
	int Index(s_String T, int pos);	//此处为KMP算法的实现
	l_Stack<int> Index(s_String T);	//重载为返回子串T在当前串中所有不重叠子串第一次出现的位置，为Replace函数的实现提供便利
	void Replace(s_String T, s_String V);	//用V替换当前串中所有与T相等的不重叠的子串
	void StrInsert(int pos, s_String T);	//当前串的第pos个字符之前插入串T
	void StrDelet(int pos, int len);	//删除当前串第pos个字符起长度为len的子串
	~s_String();	//销毁串
private:
	char* ch;
	int length = 0;
};

s_String::s_String()
{
	ch = NULL;
}

s_String::s_String(const s_String & s)
{
	length = s.length;
	ch = new char[s.length + 1];
	for (int i = 0; i <= s.length; i++)
	{
		ch[i] = s.ch[i];
	}
}

void s_String::operator=(const s_String & s)
{
	length = s.length;
	if (ch != NULL)
	{
		delete[] ch;
		ch = NULL;
	}
	ch = new char[s.length + 1];
	for (int i = 0; i <= s.length; i++)
	{
		ch[i] = s.ch[i];
	}
}

inline char s_String::operator[](const int i)
{
	if (i > length)
		return ch[i];
	else
		return ch[i - 1];
}

s_String::s_String(const char* chars)
{
	const char* ptr = chars;
	while (*ptr != '\0')
	{
		length++;
		ptr++;
	}
	ch = new char[length + 1];
	for (int i = 0; i <= length; i++, chars++)
	{
		ch[i] = *chars;
	}
}

inline bool s_String::StrEmpty()
{
	return !length && ch;
}

inline int s_String::StrCompare(const s_String & S)
{
	return length - S.length;
}

inline int s_String::StrLength()
{
	return length;
}

inline void s_String::ClearString()
{
	if (ch != NULL)
	{
		delete[] ch;
		ch = NULL;
	}
	ch = new char[1];
	ch[0] = '\0';
	length = 0;
}

void s_String::Concat(s_String S1)
{
	char* _ch = new char[length];
	for (int i = 0; i < length; i++)
	{
		_ch[i] = ch[i];
	}
	delete[] ch;
	ch = NULL;
	ch = new char[length + S1.length + 1];
	for (int i = 0; i < length + S1.length + 1; i++)
	{
		if (i < length)
			ch[i] = _ch[i];
		else
			ch[i] = S1.ch[i - length];
	}
	length += S1.length;
	delete[] _ch;
	_ch = NULL;
}

s_String s_String::operator+(const s_String & S1)
{
	s_String _str;
	_str.length = length + S1.length;
	_str.ch = new char[_str.length + 1];
	for (int i = 0; i < _str.length + 1; i++)
	{
		if (i < length)
			_str.ch[i] = ch[i];
		else
			_str.ch[i] = S1.ch[i - length];
	}
	return _str;
}

s_String s_String::SubString(int pos, int len)
{
	if (pos > length || pos < 1 || len > length - pos)
		return "";
	s_String _str;
	_str.ch = new char[len + 1];
	_str.length = len;
	int i;
	for (i = 0; i < len; i++)
	{
		_str.ch[i] = ch[pos + i - 1];
	}
	_str.ch[i] = '\0';
	return _str;
}

int s_String::Index(s_String T, int pos)
{
	//求模式串T的next函数修正值并存入数组nextval
	int i = 0, j = -1;
	int* nextval = new int[T.length];
	nextval[0] = -1;
	while (i < T.length - 1)
	{
		if (j == -1 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
	//利用模式串T的nextval数组求T在当前串中第pos个字符之后的位置
	//其中T非空，1 <= pos <= this.length
	if (T.length == 0 || pos < 1 || pos > this->length)
		return 0;
	int s, t;
	s = pos;
	t = 0;
	while (s < length && t < T.length)
	{
		if (t == -1 || ch[s] == T.ch[t])		//对应相等继续比较后续字符
		{
			++s;
			++t;
		}
		else
			t = nextval[t];		//模式串右移
	}
	delete[] nextval;
	nextval = NULL;
	if (t == T.length)		//匹配成功
	{
		return s - T.length + 1;
	}
	else
		return 0;
}

l_Stack<int> s_String::Index(s_String T)
{
	//存取下标的数组动态扩大，调用之前实现的链式存储结构的栈
	l_Stack<int> _arr;
	int pos = 1;
	while (pos < this->length)
	{
		_arr.Push(Index(T, pos));
		if (_arr.GetTop() == 0)
			break;
		pos = _arr.GetTop() + T.length - 1;
	}
	return _arr;
}

void s_String::Replace(s_String T, s_String V)
{
	l_Stack<int> _arr(Index(T));
	while (_arr.StackLength())
	{
		int pos = _arr.Pop();
		StrDelet(pos, T.length);
		StrInsert(pos, V);
	}
}

void s_String::StrInsert(int pos, s_String T)
{
	if (pos > 0 && pos <= length)
	{
		s_String _str;
		_str.length = length + T.length;
		_str.ch = new char[_str.length + 1];
		int i = -1;
		while (++i < _str.length)
		{
			if (pos == 1)
			{
				if (i < T.length)
					_str.ch[i] = T.ch[i];
				else
					_str.ch[i] = ch[i - T.length];
			}
			else
			{
				if (i < pos - 1 || i > pos + T.length - 2)
					_str.ch[i] = ch[i > (pos + T.length - 2) ? i - T.length : i % (pos - 1)];
				else
					_str.ch[i] = T.ch[i - pos + 1];
			}
		}
		_str.ch[i] = '\0';
		*this = _str;
	}
}

void s_String::StrDelet(int pos, int len)
{
	if (pos >= 1 && pos < length && len <= length - pos)
	{
		s_String _str;
		_str.length = length - len;
		_str.ch = new char[length - len + 1];
		int i = -1;
		while (++i < length)
		{
			if (i < pos)
				_str.ch[i] = ch[i];
			else if (i > pos + len - 2)
				_str.ch[i - len] = ch[i];
		}
		_str.ch[i - len] = '\0';
		*this = _str;
	}
}

s_String::~s_String()
{
	delete[] ch;
	ch = NULL;
}