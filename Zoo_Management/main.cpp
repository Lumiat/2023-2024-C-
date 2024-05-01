#include"zoo.h"
#include"park_location.h"
#include"animal_init.h"
#include"staff_init.h"
#include<iostream>
#include<cstring>
#include<vector>

int main(){
    //建立旅游业管理对象，设老年票10元，儿童票15元，成人票30元，家庭联票69元<75元（原价）
    Tourism_Manage tourism_manage(10,15,30,69);

    /*到时候写好了add_animal函数直接把相应的动物push_back到这几个对应类对象的vector容器里面
    例，向河流区添加泰国斗鱼：river.add_animal(),函数会询问得到需要的参数*/

    //交互界面在此
    int opt;
    do{
        cout<<"您好，欢迎来到假的动物园，请问您想..."<<endl;
        cout<<"1.使用动物园系统   2.退出程序"<<endl;
        cout<<"请选择（输入对应数字）：";
        cin>>opt;
        if(opt==1){
        //开始先要求身份认证
            int identity;
            cout<<"欢迎使用动物园系统！请问您是..."<<endl;
            cout<<"1.管理员   2.饲养员   3.游客"<<endl;
            cout<<"请选择您的身份（输入相应数字）：";
            cin>>identity;
            switch(identity){
            case 1:
                
            case 2:

            case 3:

            }
        }
    }while(opt!=2);
    
    
    
}