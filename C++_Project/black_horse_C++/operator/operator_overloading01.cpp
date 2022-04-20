/**
 * @file operator_overloading.cpp
 * @author junluo
 * @brief 加号运算符重载
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
    Persion(){};
    Persion(int a , int b){
        this->m_A = a ;
        this->m_B = b ;
    }
    //成员函数+号运算符重载
    Persion operator+(const Persion& p){
        Persion temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_A + p.m_B;
        return temp;
    }

public:
    int m_A;
    int m_B;
};

//全局函数实现运算符重载
// Persion operator+(const Persion& p1 , const Persion& p2){
//     Persion temp ;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_A + p2.m_B;
//     return temp;

// }

Persion operator+(const Persion& p2 , int val){
    Persion temp ;
    temp.m_A = p2.m_A + val ;
    temp.m_B = p2.m_B + val ;
    return temp;
}

void test(){
    Persion p1(10 , 10);
    Persion p2(20 , 20);

    //成员函数方式
    Persion p3 = p2 + p1;
    // Persion p4 = p2.operator+(p1);
    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;

    Persion p4 = p3 + 10;
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

}

int main(){
    
    test();

    return 0 ;
}
