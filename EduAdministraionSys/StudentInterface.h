#pragma once
#include"Teacher.h"
#include"Student.h"
#include<memory>
//HRS:单例模式设计，学生接口
class StudentInterface
{
	StudentInterface();//HRS:私有化默认构造函数
	Student m_Student;//HRS:当前学生信息
	static StudentInterface m_StudentInterface;//HRS:单例实例
public:
	static std::shared_ptr<StudentInterface> get();//HRS:获取实例

	std::shared_ptr<Student> getStudent();//HRS:获取当前学生信息
	void displayStudent();//HRS:列出学生基本信息
	void searchSemester();//HRS:按学期查询课程成绩
	void searchCourseName();//HRS:按课程名查询课程成绩
};


