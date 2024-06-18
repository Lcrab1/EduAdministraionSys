#pragma once
#include<iostream>
//HRS:课程结构体
struct Course
{
	std::string m_CourseID;//HRS:课程编号
	std::string m_CourseName;//HRS:课程名称
	std::string m_CourseSemester;//HRS:开设学期
	std::string m_CourseTeacher;//HRS:课程教师
	int m_CoursePeople;//HRS:课程人数
	int m_CourseCredit;//HRS:课程学分
};