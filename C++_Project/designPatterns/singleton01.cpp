/**
 * @file singleton.cpp
 * @author junluo
 * @brief 复现黑马C++设计模式(单例模式)
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

class A {
private:
    A(){
        a = new A;
    }
public:
    static A* getInstance(){
        return a ;
    }

private:
    static A* a ;
};

A* A::a = NULL;

//实现单例步骤
//1.构造函数私有化
//2.增加静态私有的当前类的指针变量
//3.提供静态对外接口，可以让用户获得单例对象

//单例 分为懒汉式 饿汉式

//1.懒汉式(需要的时候才会创建)
class Singleton_lazy {
private:
    Singleton_lazy(){
        cout << "我是懒汉构造" << endl;
    }

public:
    static Singleton_lazy* getInstance(){
        if(pSingleton == NULL){
            pSingleton = new Singleton_lazy;
        }
        return pSingleton;
    } 
private:
    static Singleton_lazy* pSingleton;
};

//类外初始化
Singleton_lazy* Singleton_lazy::pSingleton = NULL;

//2.饿汉式
class Singleton_hungry{
private:
    Singleton_hungry(){
        cout << "我是饿汉构造" << endl; 
    }

public:
    static Singleton_hungry* getIstance(){
        return pSingleton;
    } 

private:
    static Singleton_hungry* pSingleton;
};

//类外初始化
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;

void test01(){
    Singleton_lazy* p1 = Singleton_lazy::getInstance();
    Singleton_lazy* p2 = Singleton_lazy::getInstance();
    if(p1 == p2){
        cout << "两个指针指向同一块内存,是单例! " << endl;
    }
    else {
        cout << "不是单例！ " << endl;
    }

    Singleton_hungry* p3 = Singleton_hungry::getIstance();
    Singleton_hungry* p4 = Singleton_hungry::getIstance();
    if(p3 == p4){
        cout << "两个指针指向同一块内存,是单例! " << endl;
    }
    else{
        cout << "不是单例！ " << endl;
    }
}

int main()
{
    test01();
    cout << "main函数开始执行" << endl;
    return 0 ;
}

    