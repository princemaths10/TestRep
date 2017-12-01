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


    #include<windows.h>  
    #include<iostream>  
    using namespace std;  
    int main()  
    {  
            double time=0;  
            double counts=0;  
            LARGE_INTEGER nFreq;  
        LARGE_INTEGER nBeginTime;  
        LARGE_INTEGER nEndTime;  
        QueryPerformanceFrequency(&nFreq);  
            QueryPerformanceCounter(&nBeginTime);//开始计时  
            for(int i=0;i<99999;i++)  
            {  
                counts++;  
            }  
            QueryPerformanceCounter(&nEndTime);//停止计时  
            time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s  
            cout<<"程序执行时间："<<time*1000<<"ms"<<endl;  
    }  
