#pragma once
//XK：Database接口的设计采用单例模式
#include<iostream>
#include<mysql.h>

#include"Teacher.h"
#include<vector>
#pragma comment(lib,"libmysql.dll")
#define UNKNOW 0
#define STUDENT 1
#define TEACHER 2

struct TeacherInfo {
	CString no;				//XK:学号
	CString name;			//XK:姓名
	CString englishName;	//XK:英文名
	CString nation;			//XK:民族
	CString school;			//XK:行政管理学院
	CString gender;			//XK:性别
	CString hireDate;		//XK:入职年份
	CString jobTitle;		//XK:职称
	CString email;			//XK:电子邮箱
	CString telephone;		//XK:
};

struct ClassOfTeacher
{
	CString id;				//XK:课程代号
	CString name;			//XK:课程名称
	CString studentCount;	//XK:课程人数
	CString credit;			//XK:学分
	CString classRoom;		//XK:教室
	CString week;			//XK:教学周
	CString year;			//XK:学年学期

	ClassOfTeacher(const CString& id, const CString& name, const CString& studentCount,
		const CString& credit, const CString& classRoom, const CString& week,
		const CString& year)
		: id(id), name(name), studentCount(studentCount), credit(credit),
		classRoom(classRoom), week(week), year(year) {}
};



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


	void SearchTeacher(IN const CString& teacherID,OUT TeacherInfo& teacherInfo);	//XK：查询老师信息
	void GetClassOfTeacher(IN const CString& teacherID, OUT std::vector<ClassOfTeacher>& classOfTeacher);

};

