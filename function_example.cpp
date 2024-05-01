/*关于成员函数的实现：这里把我的想法写了个小例子，可以参考*/
/*在成员函数内执行与用户的交互，让main.cpp中的代码更直观，
而且免去了很多不必要的成员变量存储*/
/*懒得运行可以直接链接，能看到运行示例（右侧可能看着输入输出不太对，其实是对的，线上编译器的问题
https://www.dotcpp.com/run/16638346  */

#include<iostream>
#include<cstring>
using std::cout;
using std::cin;
using std::string;
using std::endl;
class asking{
	public:
	asking(){}
	void askandadd(){
		int a,b;
		cout<<"please enter a number :";
		cin>>a;
		cout<<"please enter another number :";
		cin>>b;
		cout<<"a+b="<<a+b<<endl;
	}
    void askandsub(){
        int a,b;
        cout<<"please enter a number :";
        cin>>a;
        cout<<"please enter another number :";
        cin>>b;
        cout<<"a-b="<<a-b<<endl;
    }
};
int main(){
	string req;
	asking ask;
    cout<<"our calculator supports adding and substracting."<<endl;
	cout<<"what do you want?(eneter 'add' to add and 'sub' to substract)"<<endl;
    cout<<"Please enter your request: ";
	cin>>req;
	if(req=="add") 
        ask.askandadd();
    else if(req=="sub")
        ask.askandsub();
    else cout<<"no such option.";
	return 0;
}