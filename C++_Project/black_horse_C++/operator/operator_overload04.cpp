/**
 * @file operator_overload04.cpp
 * @author junluo
 * @brief  赋值运算符重载
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;


class Persion{

public:
    Persion(int age){
        //将年龄数据开辟到堆区
        m_Age = new int(age); 
    }

    //重载赋值运算符
    Persion& operator=(Persion &p){
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
        //编译器提供的代码是浅拷贝
        //m_Age = p.m_Age;

        //提供深拷贝 解决浅拷贝的问题
        m_Age = new int(*p.m_Age);

        return *this;
    }

    ~Persion(){
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }


    int *m_Age; //年龄的指针
};


void test01(){
    Persion p1(18);

    Persion p2(20);

    Persion p3(30);
    p3 = p2 = p1; //赋值操作

	cout << "p1的年龄为:" << *p1.m_Age << endl;

	cout << "p2的年龄为:" << *p2.m_Age << endl;

	cout << "p3的年龄为:" << *p3.m_Age << endl;
}

int main(){

    test01();
    return 0 ;
}
