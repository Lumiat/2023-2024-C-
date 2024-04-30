//实现对各个园区相对位置的初始设置，具体声明内容在"park_location.cpp"
#ifndef PARK_LOCATION_H
#define PARK_LOCATION_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef pair<int,string> PII;
//利用pair数组记录各个园区之间的距离
//格式：first记录距离，second记录目标位置，数组名是起点
//例：从东门到淡水鱼区是100m----->east_gate[0]：<100,"river_life_area">
/*说明：本动物园管理系统认为共有7个起点和7个终点（南门、东门、淡水鱼区、海洋鱼区、
极地动物、温带动物、热带动物*/

//东门为起点
extern vector<PII> east_gate;

//南门为起点
extern vector<PII> south_gate;

//河流区为起点
extern vector<PII> river_life_area;

//海洋区为起点
extern vector<PII> sea_life_area;

//极地荒漠区为起点
extern vector<PII> polar_area;

//温带森林区为起点
extern vector<PII> temperate_area;

//热带雨林区为起点
extern vector<PII> tropical_area;

#endif