#include<iostream>
#include<thread>

void func(int a){
    
        //std::cout << "Cat" << std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(50));//延时50毫秒
        
}
int main(){

    int a = 0 ;
    std::thread thread1(func , a);
    std::cout<< "id 数目" << thread1.hardware_concurrency() << std::endl;
    thread1.join();
    // while(true){
    //     std::cout << "Hello World!" << std::endl;
    //     std::this_thread::sleep_for(std::chrono::microseconds(50));//延时50毫秒
    // }
    // while(true);

}

