/**
 * @file operator_overload05.cpp
 * @author junluo
 * @brief 关系运算符重载
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    Person(string name , int age){
        m_Name = name;
        m_Age = age;
    }

    bool operator==(Person & p){
        if(this->m_Age == p.m_Age && this->m_Name == p.m_Name){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator!=(Person &p){
        if(this->m_Age == p.m_Age && this->m_Name == p.m_Name){
            return false;
        }
        else{
            return true;
        }
    }

    string m_Name;
    int m_Age;

};

void test01()
{
	//int a = 0;
	//int b = 0;

	Person a("孙悟空", 18);
	Person b("孙悟空", 18);

	if (a == b)
	{
		cout << "a和b相等" << endl;
	}
	else
	{
		cout << "a和b不相等" << endl;
	}

	if (a != b)
	{
		cout << "a和b不相等" << endl;
	}
	else
	{
		cout << "a和b相等" << endl;
	}
}
int main(){
    test01();
    return 0 ;
}