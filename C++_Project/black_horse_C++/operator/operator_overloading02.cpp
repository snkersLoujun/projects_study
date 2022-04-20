/**
 * @file operator_overloadingleft.cpp
 * @author your name (you@domain.com)
 * @brief 左移运算符重载
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& out, Person& p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

private:
	int m_A;
	int m_B;
};

//全局函数实现左移重载
//ostream对象只能有一个
ostream& operator<<(ostream& out, Person& p) {
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out;
}

void test() {
	Person p1(10, 20);
	cout << p1 << " hello world" << endl; //链式编程
}

int main() {

	test();
	return 0;
}