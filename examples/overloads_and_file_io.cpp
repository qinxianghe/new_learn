//17 写一个 print 的重载：支持 int 和 std::string，要求输出格式：int: <value> / str: <value>。
#include <iostream>
#include <fstream>
#include <string>
namespace new_print {
	void print(int i = 0)
	{
		std::cout << "i = " << i << std::endl;
	}
	void print(std::string s)
	{
		std::cout << "s = " << s << std::endl;
	}
	//18 写一个 readFileFirstLine(const std::string& path)：用 ifstream 读取文件第一行（失败返回空字符串
	std::string readFileFirstLine(const std::string& path)
	{
		std::ifstream fin(path);
		if (!fin.is_open()) {
			return "";
		}
		std::string line;
		if (!std::getline(fin, line)) {
			return "";
		}
		return line;
	}
}

int main()
{
	new_print::print(5);
	new_print::print("Hello, World!");
	return 0;
}


