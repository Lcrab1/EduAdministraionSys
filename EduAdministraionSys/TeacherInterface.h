#pragma once
#include"Teacher.h"
#include"Student.h"
#include"Database.h"
//HRS:单例模式设计，教师接口
class TeacherInterface
{
	TeacherInterface();//私有化默认构造函数
	Teacher m_Teacher;//当前教师信息
	static TeacherInterface m_TeacherInterface;//单例实例
	std::vector<ClassOfTeacher> m_ClassOfTeacher;
public:
	static TeacherInterface& get();//获取实例
	Teacher& getTeacher();
	std::vector<ClassOfTeacher>& getClassOfTeacher();
	void displayAllCources();//HRS:显示所有教授的课程
	void selectCourse();//HRS:选择课程
	void setCoursePoint();//HRS:设置成绩占比
	void submitGrade();//HRS:提交学生成绩
};

