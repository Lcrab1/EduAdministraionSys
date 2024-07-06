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

//XK：教师信息表格
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

//XK:教师开售课程表格
struct ClassOfTeacher
{
	CString id;				//XK:课程代号
	CString name;			//XK:课程名称
	CString studentCount;	//XK:课程人数
	CString credit;			//XK:学分
	CString classRoom;		//XK:教室
	CString week;			//XK:教学周
	CString year;			//XK:学年
	CString semester;		//XK:学期

	//XK:使用vector中的emplace_back来存储结构体时，需要为结构体设置构造函数
	ClassOfTeacher(const CString& id, const CString& name, const CString& studentCount,
		const CString& credit, const CString& classRoom, const CString& week,
		const CString& year,const CString&semester)
		: id(id), name(name), studentCount(studentCount), credit(credit),
		classRoom(classRoom), week(week), year(year),semester(semester) {}
};

//YXY：录入成绩表格
struct ClassOfStudentScore
{
	CString CourseName;			//选中的课程名
	CString studentID;			// 学号
	CString studentName;		// 学生姓名
	CString dailyScore;        // 平时成绩
	CString midtermScore;      // 期中成绩
	CString finalScore;        // 期末成绩
	CString totalScore;        // 总评成绩
	CString year;			
	CString semester;		

	ClassOfStudentScore(const CString& courseName, const CString& id, const CString& name,
		const CString& daily, const CString& midterm, const CString & final,
		const CString& total, const CString& yr, const CString& sem)
		: CourseName(courseName), studentID(id), studentName(name),
		dailyScore(daily), midtermScore(midterm), finalScore(final),
		totalScore(total), year(yr), semester(sem) {}

};


struct StudentInfo
{
	CString ID;//HRS:学号
	CString Name;//HRS:学生姓名
	CString EngName;//HRS:学生英文名
	CString Nation;//HRS:学生民族
	CString Grade;//HRS:学生年级
	CString Gender;//HRS:学生性别
	CString Department;//HRS:学生所属学院
	CString Major;//HRS:学生专业
	CString Type;//HRS:学生类别(本科、研究生)
	CString Class;//HRS:学生行政班级
	CString Year;//HRS:学制(四年、五年)
	CString Graduate;//HRS:毕业时间
	CString Source;//HRS:生源地
	CString StudyForm;//HRS:学习形式(全日制、非全日制)
	CString Email;//HRS:学生邮箱
	CString Telephone;//HRS:学生电话
};

struct CourseInfo
{
	CString CourseID;
	CString CourseName;
	CString CourseCredit;
};

//XK:学期成绩
struct GradeOfStudent
{
	CString year;
	CString semester;
	CString course;
	CString credit;
	CString midScore;
	CString usualScore;
	CString finalScore;
	CString totalScore;

	GradeOfStudent(const CString& year, const CString& semester, const CString& course,const CString& credit,
		const CString& midScore, const CString& usualScore, const CString& finalScore, const CString& totalScore)
		:year(year),semester(semester),course(course),credit(credit),midScore(midScore),usualScore(usualScore),
		finalScore(finalScore),totalScore(totalScore){}
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
	bool searchStudent(IN const CString& studentID,OUT StudentInfo& studentInfo);//HRS:查询学生的个人信息
	bool searchStudentAllCourse(IN const CString& studentID,IN const CString semester,OUT std::vector<CourseInfo>& course);//HRS:查询学生某一学期所有的课程
	bool searchStudentCourseScore(IN const CString& studentID,IN const CString& courseID,OUT CString& score);//HRS:按课程名查询课程成绩
	bool searchTeacherCourse(IN const CString& teacherID,OUT CourseInfo& courseInfo);//HRS:查询老师所教授的课程
	bool searchSemesterCourse(IN const CString& semester,OUT std::vector<CourseInfo>& course);//HRS:查询某一学期的课程开设
	void recordGrade(IN const CString& studentID,IN const CString& courseID);//HRS:录入学生的成绩


	void SearchTeacher(IN const CString& teacherID,OUT TeacherInfo& teacherInfo);	//XK：查询老师信息
	void GetClassOfTeacher(IN const CString& teacherID, OUT std::vector<ClassOfTeacher>& classOfTeacher);	//XK：得到老师开课信息
	
	//XK:学生按获取课程成绩方法
	void GetGradeOfStudent(IN const CString& studentID, OUT std::vector<GradeOfStudent>& gradeOfStudent);

	//HRS:学生按学期获得课程成绩的方法
	bool searchStudentAllCourse(IN const CString& studentID, IN const CString& year, IN const CString& semester, OUT std::vector<GradeOfStudent>& courseGrade);
	//XK:学生修改个人信息方法
	void ChangePersonalInfo(IN const CString& studentID,IN const CString& englishName, IN const CString& telephone, IN const CString& email);

	void GetClassOfSC(IN const CString& CourseName, OUT std::vector<ClassOfStudentScore>& classOfStudentScore);//YXY：查询学生选课信息


};

