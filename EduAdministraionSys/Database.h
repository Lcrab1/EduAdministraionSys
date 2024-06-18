#pragma once
//XK：Database接口的设计采用单例模式
#include<mysql.h>
#pragma comment(lib,"libmysql.dll")
class Database
{
private:
	Database();
private:
	//XK：此处写成员变量


public:
	static Database m_Database;	//XK:单例成员

public:
	//XK：此处写方法

};
