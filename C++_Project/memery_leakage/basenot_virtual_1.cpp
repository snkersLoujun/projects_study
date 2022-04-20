/*
 * @file basenot_virtual.cpp
 * @author junluo
 * @brief 派生类指针操作派生类对象，基类析构函数不是虚函数
 * @version 0.1
 * @date 2022-04-08
 */

#include<iostream>
using namespace std;
class ClxBase{
public:
	ClxBase() {};
	~ClxBase() { cout << "Output from the destructor of class ClxBase!" << endl; };
 
	void DoSomething() { cout << "Do something in class ClxBase!" << endl; };
};
 
class ClxDerived : public ClxBase{
public:
	ClxDerived() {};
	~ClxDerived() { cout << "Output from the destructor of class ClxDerived!" << endl; };
 
	void DoSomething() { cout << "Do something in class ClxDerived!" << endl; };
};
int main(){
    ClxDerived *p = new ClxDerived;		// 派生类指针操作派生类对象
	p->DoSomething();
	delete p;
	system("pause");
	return 0;
}
