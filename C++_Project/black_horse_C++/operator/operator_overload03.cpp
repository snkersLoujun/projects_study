/**
 * @file operator_overload03.cpp
 * @author junluo
 * @brief 递增运算符重载
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

class MyInteger{
    friend ostream& operator<<(ostream& out , MyInteger myInt);
public:
    MyInteger(){
        m_Num = 0 ;
    }

    //前置++
    MyInteger& operator++(){
        m_Num ++;
        return *this;
    }

    //后置++
    MyInteger operator++(int){
        MyInteger temp = *this;
        m_Num++;
        return temp;
    }

private:
    int m_Num;

};

ostream& operator<<(ostream& out , MyInteger myInt){
    cout << myInt.m_Num ;
    return out ;
}

void test01(){
    MyInteger myInt;
    cout << myInt << endl;
}

void test02(){
    MyInteger myInt;
    cout << myInt ++ << endl;
    cout << ++ myInt << endl;
}

int main(){

    // test01();
    test02();

    return 0 ;
}