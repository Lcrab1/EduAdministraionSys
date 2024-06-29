#pragma once
#include"Course.h"
//HRS:存储教师信息的类
class Teacher
{
	std::string m_TeacherID;//HRS:教师编号
	std::string m_TeacherName;//HRS:教师姓名
public:
	std::string getID();//HRS:获取编号
	std::string getName();//HRS:获取姓名
};

