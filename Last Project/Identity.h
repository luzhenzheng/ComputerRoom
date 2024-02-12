#pragma once //防止头文件重复包含
#include<string>
using namespace std;
//思路：因为学生，老师，管理员 都有共同的属性 所以可以通过抽象类来实现他们的共性
class Identity
{
public:
	//Identity是基类，所以要包含所有父类共同拥有的特性，即姓名和密码 学生和教师还有ID，但是管理员没有ID,所以ID就放在他们自己的类里了
	string m_Name ="";
	string m_Pwd ="";

	virtual void operMenu() = 0;//virtual表示虚函数 =0表示纯虚函数
};

