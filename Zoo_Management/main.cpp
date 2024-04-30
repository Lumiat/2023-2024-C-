#include"zoo.h"
#include"park_location.h"
#include"animal_init.h"
#include"staff_init.h"
#include<iostream>
#include<cstring>
#include<vector>

int main(){
    Aqua_Area river("河流区","淡水",21.5);//淡水鱼区有泰国斗鱼、锦鲤、食人鱼
    Aqua_Area sea("海洋区","海水",25.0);//海水区有海龟、海豚、蝠鲼、白鲸、水母
    Land_Area polar("极地荒原区","苔原","极端寒冷干燥",-35.7,4.3);//极地区帝企鹅、北极熊
    Land_Area temperate("温带森林区","温带落叶阔叶林","气候适宜 四季分明",25.6,25.4);//老虎、棕熊、金丝猴、红腹锦鸡
    Land_Area tropical("热带雨林区","热带常绿阔叶林","气候炎热多雨",34.5,61.0);//金刚鹦鹉、变色龙、黑猩猩

    //到时候写好了add函数直接把相应的动物push_back到这几个对应类对象的vector容器里面
    //开始先要求身份认证

}