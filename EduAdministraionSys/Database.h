#pragma once
//XK：Database接口的设计采用单例模式
#include<mysql.h>
#include"StudentInterface.h"
#include"TeacherInterface.h"
#pragma comment(lib,"libmysql.dll")

#define UNKNOW 0
#define STUDENT 1
#define TEACHER 2

class Database
{
private:
	Database();
	Database(const Database& database)=delete;
private:
	//XK：此处写成员变量
	static Database m_Database;	//XK:单例成员
	

public:
	MYSQL m_mysql;//HRS:数据库接口

public:
	//XK：此处写方法
	static Database& getDatabase();//HRS:获取实例

	int login(IN const CString& userName,IN const CString& password);//HRS:登录用户账号
	void searchStudent(const CString& studentID);//HRS:查询学生的个人信息
	void searchStudentAllCourse(const CString& studentID);//HRS:查询学生某一学期所有的课程
	void searchStudentCourseName(const CString& studentID,const CString& courseID);//HRS:按课程名查询课程成绩
	void searchTeacherCourse(const CString& teacherID);//HRS:查询老师所教授的课程
	void searchSemesterCourse(const CString& semester);//HRS:查询某一学期的课程开设
	void setGradeComposi(const CString& CourseID);//HRS:设置成绩的分数组成
	void recordGrade(const CString& studentGrade,const CString& courseID);//HRS:录入学生的成绩
};
