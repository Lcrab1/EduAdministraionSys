#pragma once
#include"Course.h"
//HRS:存储学生信息的类
class Student
{
	std::string m_StudentID;//HRS:学号
	std::string m_StudentName;//HRS:学生姓名
	std::string m_StudentGrade;//HRS:学生年级
	std::string m_StudentDepartment;//HRS:学生所属学院
	std::string m_StudentMajor;//HRS:学生专业
	std::string m_StudentType;//HRS:学生类别(本科、研究生)
	std::string m_StudentClass;//HRS:学生行政班级
	std::string m_StudentYear;//HRS:学制(四年、五年)
	std::string m_StudentGraduate;//HRS:毕业时间
	std::string m_StudentSource;//HRS:生源地
	std::string m_StudyForm;//HRS:学习形式(全日制、非全日制)
public:
	std::string getID();//HRS:获取学号
	std::string getName();//HRS:获取姓名
	std::string getGrade();//HRS:获取年级
	std::string getDepartment();//HRS:获取学院
	std::string getMajor();//HRS:获取专业
	std::string getType();//HRS:获取学生类别(本科、研究生)
	std::string getClass();//HRS:获取班级
	std::string getStudyYear();//HRS:获取学制(四年、五年)
	std::string getGraduate();//HRS:获取毕业时间
	std::string getSource();//HRS:获取生源地
	std::string getStudyForm();//HRS:获取学习形式
};