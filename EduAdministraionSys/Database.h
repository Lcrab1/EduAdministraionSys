#pragma once
//XK：Database接口的设计采用单例模式
#include<mysql.h>
#include"StudentInterface.h"
#include"TeacherInterface.h"
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
	void login(CString& userName,CString& password);//HRS:登录用户账号
	void searchStudent(CString& studentID);//HRS:查询学生的个人信息
	void searchStudentAllCourse(CString& studentID);//HRS:查询学生某一学期所有的课程
	void searchStudentCourseName(CString& studentID, CString& courseID);//HRS:按课程名查询课程成绩
	void searchTeacherCourse(CString& teacherID);//HRS:查询老师所教授的课程
	void searchSemesterCourse(CString& semester);//HRS:查询某一学期的课程开设
	void setGradeComposi(CString& CourseID);//HRS:设置成绩的分数组成
	void recordGrade(CString& studentGrade,CString& courseID);//HRS:录入学生的成绩
};

