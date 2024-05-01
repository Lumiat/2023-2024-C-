#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#ifndef ZOO_H
#define ZOO_H
/*写在开头：感觉很多参数是需要但是没有必要记录的，因为可以看到我大量的函数都长xxxx();这样
我的想法是把输入输出交互的任务留在函数内实现，而那些完成功能所需要的参数放在函数里头来完成，
这样在主文件main.cpp中运用也更方便、直观*/
//Stuff结构体记录一名工作人员的信息
struct Staff{
    string staff_name;//员工姓名
    string who;//身份（管理员or饲养员）
    int id;//工号
    int passwd;//账户密码
};

//animal结构体记录某一动物种群相关信息
struct ANIMAL{
    string type_name;//种名
    string catagory;//所属分类（鱼类、哺乳类etc）
    int number;//种群数量
    string park;//园区名
    string food;//食物
    bool feed;//是否饲喂
    bool sick;//是否有生病个体
    string keeper;//饲养员
};



class Animal_Manage{
    protected:
    string parkname;

    public:
    Animal_Manage(const string&name);//实现的时候：parkname=name；
    //纯虚函数,type是种名，pname是园区名
    virtual void add_animal(string type)=0;//管理员权限：添加动物
    virtual void rmv_animal(string type)=0;//管理员权限：移除动物
    virtual void health_check(string type) const =0;//管理员+饲养员权限：健康检查
    virtual void feed_check(string type) const =0;//管理员+饲养员权限：饲喂
    virtual void show_park_species(string pname) const =0;//管理员+饲养员+游客：查看某园区有什么动物种群
    virtual void show_keeper(string type) const =0;//管理员权限：显示某个种群的饲养员
    virtual void show_animal_info(string type) const =0;//游客权限：显示某种动物的分类、种群数量、食物;对管理员+饲养员权限：显示种群数量
    virtual void show_environment(string pname) const =0;//管理员+饲养员+游客：显示某园区环境
};


//以下就是Aqua_Area类和Land_Area类，对于Aqua会有两个对象、Land有三个对象（详见main.cpp)
class Aqua_Area:public Animal_Manage{
    private:
    vector<ANIMAL> contain;//这一水族区有哪些种群（水族会分为淡水和海水两个Aqua_Area对象）
    string water;
    float water_temp;

    public:
    Aqua_Area(const string&name,const string& wt,float temp);
    void add_animal(string type);//管理员权限：添加动物
    void rmv_animal(string type);//管理员权限：移除动物
    void health_check(string type) const ;//管理员+饲养员权限：健康检查
    void feed_check(string type) const ;//管理员+饲养员权限：饲喂
    void show_park_species(string pname) const ;//管理员+饲养员+游客：查看某园区有什么动物种群
    void show_keeper(string type) const ;//管理员权限：显示某个种群的饲养员
    void show_animal_info(string type) const ;//游客权限：显示某种动物的分类、种群数量、食物;对管理员+饲养员：显示种群数量
    void show_environment(string pname) const ;//管理员+饲养员+游客：显示某园区环境

};

class Land_Area:public Animal_Manage{
    private:
    vector<ANIMAL> contain;//这一陆地动物区有哪些种群（会分为极地、温带和热带三个Land_Area对象）
    string plant;//植被类型
    string climate;//气候类型
    float temp;//温度
    float humidity;//湿度

    public:
    Land_Area(const string&name,const string&plt,const string&clmt,float temp,float humidity);
    void add_animal(string type);//管理员权限：添加动物
    void rmv_animal(string type);//管理员权限：移除动物
    void health_check(string type) const;//管理员+饲养员权限：健康检查
    void feed_check(string type) const ;//管理员+饲养员权限：饲喂
    void show_park_species(string pname) const;//管理员+饲养员+游客：查看某园区有什么动物种群
    void show_keeper(string type) const;//管理员权限：显示某个种群的饲养员
    void show_animal_info(string type) const;//游客权限：显示某种动物的分类、种群数量、食物;对管理员+饲养员：显示种群数量
    void show_environment(string pname) const;//管理员+饲养员+游客：显示某园区环境

};

/* Permission_Manage类用于对不同类型用户提供不同的权限
有三种（派生类）分别是Admin、Feeder和Tourist */
class Permission_Manage{
    protected:
    static vector<Animal_Manage*> areas;

    public:
    virtual bool login() = 0;//登陆提示
};

class Admin:public Permission_Manage{
    private:
    vector<Staff> admin_staff;//存储所有管理员的信息
    //引用一个对象tourism_manage,Admin可以使用tourism_manage的成员函数执行功能
    Tourism_Manage& tourism_manage;
    public:
    Admin(const Tourism_Manage& tourist);//这里不必要再用static，因为只有Admin一个类使用它
    bool login();//对于管理员，登陆提示输入id和passwd，进行验证

    //这里还有个问题，就是vector<Stafff> keeper是私有成员变量，不能直接访问
    void add_keeper(const vector<Staff>& keeper);//添加新的饲养员
    void rmv_keeper(const vector<Staff>& keeper);//移除某饲养员，使用id做辨识
    void add_admin();//添加新的管理员
    void rmv_admin();//删除某管理员，使用id做辨识
    void check_ticket();//查看售票情况，需要使用到tourism_manage，这个函数应该询问要干什么然后执行相应操作
    
    //以下都是静态成员函数，可以操纵static变量，到时候直接指针就行，比如找到目标后直接areas[i]->add_animal();
    //照这个逻辑，应该在这些静态成员函数中写交互信息，获取必要数据
    static void add_animal();//管理员权限：添加动物
    static void rmv_animal();//管理员权限：移除动物
    static void health_check();//管理员+饲养员权限：健康检查
    static void feed_check();//管理员+饲养员权限：饲喂检查
    static void show_park_species();//管理员+饲养员+游客：查看某园区有什么动物种群
    static void show_keeper();//管理员权限：显示某个种群的饲养员
    static void show_animal_info();//游客权限：显示某种动物的分类、种群数量、食物;对管理员+饲养员：显示种群数量
    static void show_environment();//管理员+饲养员+游客：显示某园区环境
};

class Keeper:public Permission_Manage{
    private:
    vector<Staff> keeper_staff;

    public:
    Keeper();
    bool login();//登陆提示输入id和passwd，进行验证，通过后显示该管理员负责的所有动物种群
    static void health_check();//管理员+饲养员权限：健康检查
    static void feed_check();//管理员+饲养员权限：饲喂检查
    static void show_park_species();//管理员+饲养员+游客：查看某园区有什么动物种群
    static void show_animal_info();//游客权限：显示某种动物的分类、种群数量、食物;对管理员+饲养员：显示种群数量
    static void health_repo();//更新自己管理动物的健康状况（以种群为单位）
    static void feed_repo();//更新自己管理动物的饲喂状况（以种群为单位）
};

/*Tourist类负责满足游客的各种需求，包括购票，搜索某种动物
所在园区、种群数量、食物、生活环境，某个园区信息：园区所含动物，
可以根据游客位置推荐最近的参观园区，并且能实现根据游客输入的参观人员
类型（老人小孩成年人）推荐参观的路线，比如有老人就选择从距离最近园区
开始，有小孩推荐从小孩子们比较喜欢的园区开始，成年人就无所谓了，当然，
要礼貌表述*/
class Tourist:public Permission_Manage{
    public:
    Tourist();
    void ticket_service(const Tourism_Manage& tourism);//售票服务，应该链接到serve_order，在这里应该询问有多少老人小孩成人，作为计算最省钱票价的依据
    void search_animal(const string&which_type);//查询某种动物的相关信息
    void search_park(const string&where);//查询某个园区相关信息
    void recommend_route();//进行路线推荐
    void show_nearest();//显示最近的园区
    void show_distance(const string &where);//显示去某地点的距离
    static void show_park_species();//管理员+饲养员+游客：查看某园区有什么动物种群
    static void show_animal_info();//游客权限：显示某种动物的分类、种群数量、食物;对管理员+饲养员：显示种群数量
    static void show_environment();//管理员+饲养员+游客：显示某园区环境
};

//旅游（主要是售票）相关管理，是管理员的权限范围内，即管理员有权使用所有成员函数
class Tourism_Manage{
    private:
    int old_ticket_sold=0;//老年票售出量/张
    int kid_ticket_sold=0;//儿童票售出量/张
    int adult_ticket_sold=0;//成人票售出量/张
    int family_ticket_sold=0;//家庭票售出量/张，包含2大人1小孩
    long long daily_income=0;//日收入/元
    long long total_sold=0;//当日总售出票量/张
    int old_price;//老年票价/元
    int kid_pirce;//儿童票价/元
    int adult_price;//成人票价/元
    int family_price;//家庭票价/元

    public:
    Tourism_Manage(int old,int kid,int adult,int family);//构造时传老年儿童成人的票价的参数
    void reset_price();//管理员可以更改票价
    void show_daily_income();//显示日收入/元
    void show_old_sold();//显示老年票售出量/张
    void show_kid_sold();//显示儿童票售出量/张
    void show_adult_sold();//显示成人票售出量/张
    void show_family_sold();//显示家庭联票售出量/张
    void show_total_sold();//显示当日总售出票量/张
    void serve_order();
    /*serve_order函数用来满足客户订单，根据用户输入的
    参观成员的身份和个数，推荐最省钱选项（贪心算法？），询问客户是否
    选择最优选择，完成订单交易后，更新游客统计数据并对
    游客显示订单具体内容*/
};

//完成园区部署
    Aqua_Area *river=new Aqua_Area("河流区","淡水",25.5);//淡水鱼区有泰国斗鱼、锦鲤、食人鱼
    Aqua_Area *sea=new Aqua_Area("海洋区","海水",21.0);//海水区有海龟、海豚、蝠鲼、白鲸、水母
    Land_Area *polar=new Land_Area("极地荒原区","苔原","极端寒冷干燥",-35.7,4.3);//极地区帝企鹅、北极熊
    Land_Area *temperate=new Land_Area("温带森林区","温带落叶阔叶林","气候适宜 四季分明",25.6,25.4);//老虎、棕熊、金丝猴、红腹锦鸡
    Land_Area *tropical=new Land_Area("热带雨林区","热带常绿阔叶林","气候炎热多雨",34.5,61.0);//金刚鹦鹉、变色龙、黑猩猩

//部署完成，初始化static
vector<Animal_Manage*> areas={river,sea,polar,temperate,tropical};

#endif