//以下是new02.h的内容
#pragma once
/*namespace new02
{
	class Counter
	{
	public:
		Counter(int v = 0) : value(v) {}
		
		void inc() {
			++value;
		}
		int get() const {
			return value;
		}
	private:
		int value;
	};
}*/

namespace MyNamespace
{
	class Counter
	{
	public:
		Counter(int v = 0);
		void inc();
		int get() const;
	private:
		int value;
	};
	
}