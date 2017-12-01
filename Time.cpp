    #include<boost/timer.hpp>  
    #include<iostream>  
    using namespace std;  
    using namespace boost;  
    int main()  
    {  
        timer t;//声明计时器对象并开始计时  

[cpp] view plain copy

         Sleep(500);//需要测试的运行代码  
        cout<<"now:"<<t.elapsed() <<"s"<<endl;//输出已流失的时间  
    }  
