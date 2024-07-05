#pragma once
#include"Course.h"
//HRS:存储学生信息的类
class Student
{
	std::string m_StuID;//HRS:学号
	std::string m_StuName;//HRS:学生姓名
	std::string m_StuEngName;//HRS:学生英文名
	std::string m_StuNation;//HRS:学生民族
	std::string m_StuGrade;//HRS:学生年级
	std::string m_StuGender;//HRS:学生性别
	std::string m_StuDepartment;//HRS:学生所属学院
	std::string m_StuMajor;//HRS:学生专业
	std::string m_StuType;//HRS:学生类别(本科、研究生)
	std::string m_StuClass;//HRS:学生行政班级
	std::string m_StuYear;//HRS:学制(四年、五年)
	std::string m_StuGraduate;//HRS:毕业时间
	std::string m_StuSource;//HRS:生源地
	std::string m_StuStudyForm;//HRS:学习形式(全日制、非全日制)
	std::string m_StuEmail;//HRS:学生邮箱
	std::string m_StuTelephone;//HRS:学生电话
public:
	std::string getID();//HRS:获取学号
	std::string getName();//HRS:获取姓名
	std::string getEnglishName();//HRS:获取英文名
	std::string getGrade();//HRS:获取年级
	std::string getDepartment();//HRS:获取学院
	std::string getMajor();//HRS:获取专业
	std::string getType();//HRS:获取学生类别(本科、研究生)
	std::string getClass();//HRS:获取班级
	std::string getStudyYear();//HRS:获取学制(四年、五年)
	std::string getGraduate();//HRS:获取毕业时间
	std::string getSource();//HRS:获取生源地
	std::string getStudyForm();//HRS:获取学习形式
	std::string getEmail();//HRS:获取学生邮箱
	std::string getTelephone();//HRS:获取学生电话
};