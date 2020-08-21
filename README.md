# Algorithms-and-Data-structures(C++语言描述，具备C++特性)

以下列举一些常见实用特性，更多完整特性请参阅官方文档[MSDN](https://msdn.microsoft.com/en-us/library/hh567368.aspx)
---
## Initialize List（初始化列表）
* STL容器的初始化列表:
```C++
//所有STL容器都支持，限于篇幅举例说明
std::vector<double> i_v = {1.1, 2.2, 3.3};
std::map<int, std::string> m = {{1, "a"}, {2, "b"}};
```
* 自定义类的初始化列表:
```C++
class A
{
public:
    A(const int item, const string nameItem):length(item), name(nameItem)
private:
    int length;
    string name;
};
//实例化对象
A a1(3, "Hamlet");
```