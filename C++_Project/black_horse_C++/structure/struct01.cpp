#include<iostream>
using namespace std;

//结构体定义
struct student{
    //成员列表
    string name ; //姓名
    int age ; //年龄
    int score ; //分数
}stu3 ; 


int main()
{
    student s1;
    s1.age = 18;
    s1.name = "张三";
    s1.score = 100;
    cout << s1.age << s1.name << s1.score ;
        
}