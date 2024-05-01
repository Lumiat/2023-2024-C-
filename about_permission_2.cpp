/* 写了个更像我们代码结构的东西，可以参考这个
还是一样，懒得运行直接打开链接看结果
https://www.dotcpp.com/run/16639497 
这种的bug在于...我们的几个派生类对象会有全局性，可能数据保护就。。。*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class manage{
    protected:
    string parkname;

    public:
    manage(const string& name):parkname(name){}
    virtual void reset(const string& what)=0;
    virtual void show()=0;
};

class aqua:public manage{
    private:
    string water;
    
    public:
    aqua(const string& name,const string& wt):manage(name){
        water=wt;
    }
    void reset(const string& what){
        water=what;
    }
    void show(){
        cout<<"water_area water:"<<water<<endl;
    }
};

class land:public manage{
    private:
    string temperature;
    
    public:
    land(const string& name,const string& tmp):manage(name){
        temperature=tmp;
    }
    void reset(const string& what){
        temperature=what;
    }
    void show(){
        cout<<"land_area temperature:"<<temperature<<endl;
    }
};

class permission{
    public:
    static vector<manage*> rec;
    
    public:
    /*static void init(const vector<manage*>& areas) {
        rec = areas;
    }*/
    static void showpark(){
        for(int i=0;i<rec.size();i++){
            rec[i]->show();
        }
    }
};

class admin:public permission{
    public:
    admin() {
        cout<<"create an admin..."<<endl;  
    }
    static void reset_thing(int i,const string& m){
        rec[i]->reset(m);
        cout<<"I changed sth"<<endl;
    }
};

aqua *sealife=new aqua("sealife","sea");
aqua *riverlife=new aqua("riverlife","fresh");
land *forest=new land("forest","25摄氏度");
    
vector<manage*> permission::rec={sealife,riverlife,forest};
 
int main(){
    /*areas.push_back(&sealife);
    areas.push_back(&riverlife);
    areas.push_back(&forest);*/
    cout<<"Before change"<<endl;
    permission::showpark();
    cout<<"build 2 admins"<<endl;
    admin person1;
    admin person2;
    person1.reset_thing(1,"not-sea-anymore,what a shame");
    person2.reset_thing(2,"24摄氏度");
    permission::showpark();
    return 0;
}