



//




//realloc 为什么要用临时指针接收返回值？写出正确写法。
//answer: 因为realloc失败之后会返回NULL，直接用原指针接受会导致内存泄漏
//解释：new int; 与 new int(); 的区别。 
//answer: new int 只分配内存，不初始化；new int() 分配内存并初始化为0
//解释：为什么 cout << d << endl; 依赖 operator<< 返回 ostream&（
//answer: 因为 operator<< 返回 ostream& 可以实现链式调用，如 cout << a << b; 实际上是 (cout << a) << b;
//placement new 的“构造”和“释放”分别由谁负责？
//answer: placement new 的构造由程序员负责，释放也由程序员负责，需要手动调用析构函数
//举一个必须考虑大小端/字节序的场景（你自己的话）。
//answer: 网络通信中，数据需要按照特定的字节序进行传输，否则接收方可能无法正确解析数据
//简述：new/delete 与 operator new/operator delete 的分工差异。
//answer: new/delete 是 C++ 的运算符，负责对象的构造和析构；operator new/operator delete 是函数，负责内存的分配和释放。new/delete 会调用 operator new/operator delete 来完成内存管理，同时还会调用构造函数和析构函数来管理对象的生命周期。

/*以下是第一题
int all_v = 0;
int main()
{
	int static a = 0;
	int b = 0;
	int* p = new int(10);
	int* q = (int*)malloc(sizeof(int) * 10);

	//但是我不会插入hello
	char b[5] = "hello"
	cout << "全局变量地址" << &all_v << endl;
	cout << "静态局部变量地址" << &a << endl;
	cout << "普通局部变量地址" << &b << endl;
	cout << "new 得到的堆指针地址" << p << endl;
	cout << "nmalloc 得到的堆指针地址" << q << endl;
	return 0;
}*/


/*以下是第二题
int main()
{
	int a[4] = (int*)malloc(sizeof(int) * 4);
	for (int i = 0; i < 4; i++)
	{
		a[i] = ++i;
	}
	int* p = &a;
	//后面的不会了
	return 0;
}*/

/*3) new[] / delete[] 析构次数验证（建议做）

写类 A，构造 / 析构都打印 this。

A * p = new A[3]; delete[] p; 观察析构打印次数。
（注意：这题是安全的）*/

/*以下是第三题 结果是调用了3次构造和析构
class A
{
public:
	A() :_a(0)
	{
		cout << "A()" << this << endl;
	}
	~A()
	{
		cout << "~A()" << this << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = new A[3];
	delete[] p;
	return 0;
}*/* /


以下是第四题
//class A
//{
//public:
//	A() :_a(0)
//	{
//		cout << "A()" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//
//
//	A* p = new A[3]; delete p; // 这是未定义行为，因为 delete p 只会调用一个对象的析构函数，而不是整个数组的析构函数。由于 new[] 在分配内存时会在前面存储一个 cookie 来记录数组的大小，delete p 无法正确识别这个 cookie，因此无法正确调用所有对象的析构函数，可能导致资源泄漏或其他不可预期的行为。
//	return 0;
//}

下面是第五题
//5) placement new + 手动析构（必做）
//
//在一块 buffer 上构造一个对象并手动析构。要求：
//
//用 alignas(T) 保证对齐
//
//T 用你自己写的类（构造 / 析构打印）
//
//调用：new(buf) T(args...) 构造；p->~T() 析构
class T
{
public:
	T() :_a(0)
	{
		cout << "T 构造函数被调用" << endl;
	}
	~T()
	{
		cout << "T 析构函数被调用" << endl;
	}
private:
	int _a;
};
int main()
{
	char buffer[1024];
	T* p = new(buffer) T(); // 在 buffer 上构造一个 T 对象
	//但是你说的alignas(T)我不会用
	return 0;
}





下面是第六题
#include <iostream>
#include <cstdlib> // malloc/free
using namespace std;

// 全局重载 operator new/delete 统计（加分）
//
// operator new(size_t)：累加统计“总分配次数 / 总字节数”
// operator delete(void*)：累加释放次数

void* operator new(size_t size)
{
	static size_t total_allocations = 0;
	static size_t total_bytes = 0;
	total_allocations++;
	total_bytes += size;
	return malloc(size);
}

void operator delete(void* ptr) noexcept
{
	static size_t total_deletes = 0;
	total_deletes++;
	free(ptr);
}
//但是我有疑问 正常的new不是会根据传递进来的类型来调用对应的构造函数吗？如果全局重载了 operator new/delete，是否会影响到类的构造和析构函数的调用？而且返回的指针类型是 void*，不是应该根据传递进来的类型来返回对应类型的指针吗？
int main()
{
	yes
	return 0;
}