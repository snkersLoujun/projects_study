//基类指针操作派生类对象，基类析构函数不是虚函数
#include<iostream>
using namespace std;
class ClxBase{
public:
	ClxBase() {};
	virtual ~ClxBase() { cout << "Output from the destructor of class ClxBase!" << endl; };
 
	virtual void DoSomething() { cout << "Do something in class ClxBase!" << endl; };
};
 
class ClxDerived : public ClxBase{
public:
	ClxDerived() {};
	~ClxDerived() { cout << "Output from the destructor of class ClxDerived!" << endl; };
 
	void DoSomething() { cout << "Do something in class ClxDerived!" << endl; };
};
int main(){
	ClxBase *p = new ClxDerived;		// 基类指针操作派生类对象
	p->DoSomething();
	delete p;
	system("pause");
	return 0;
}