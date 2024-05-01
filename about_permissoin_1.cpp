/*https://www.dotcpp.com/run/16638691 懒得运行直接去链接看*/
/*关于如何实现几个派生类对象对同一个基类的受保护成员变量做出改变的思路
（Permission_Manage那边会用到，因为我们会希望Admin和Keeper的对象改变
的vector<Animal_Manage*> areas是同一个，不然就不能正常进行数据更新和使用了）*/
#include <iostream>
#include <vector>

class Base {
protected:
    static std::vector<int> sharedData; // 静态成员变量

public:
    static void displaySharedData() {
        for (int num : sharedData) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

std::vector<int> Base::sharedData = {1, 2, 3, 4, 5}; // 初始化静态成员变量

class Derived1 : public Base {
public:
    static void modifySharedData() {
        sharedData.push_back(6); // 修改静态成员变量
    }
};

class Derived2 : public Base {
public:
    static void modifySharedData() {
        sharedData.push_back(7); // 修改静态成员变量
    }
};

int main() {
    Base::displaySharedData(); // 显示共享数据

    Derived1 d1;
    d1.modifySharedData();
    Base::displaySharedData();

    Derived2 d2;
    d2.modifySharedData();
    Base::displaySharedData();

    Derived2 d3;
    d3.modifySharedData();
    Base::displaySharedData();

    return 0;
}
