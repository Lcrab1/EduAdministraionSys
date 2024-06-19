#include"pch.h"
#include"Database.h"

Database Database::m_Database;

Database::Database()
{
}

void Database::login(IN const CString& userName, IN const CString& password, OUT int& privilege)
{
	std::string userIDStr = CW2A(userName.GetString());
	std::string userPasswordStr= CW2A(password.GetString());

	std::string SQLstr = "SELECT PRIVILEGE FROM LOGIN_TEST WHERE ID='" + userIDStr + "' AND PASSWD='" + userPasswordStr+"'";
	const char* sss = SQLstr.c_str();
	if (mysql_query(&m_mysql, SQLstr.c_str()))
	{
		privilege = UNKNOW;
	}
	else {
		MYSQL_RES* result = mysql_store_result(&m_mysql);
		if (result) {
			int num_fields = mysql_num_fields(result);
			MYSQL_ROW row;
			row = mysql_fetch_row(result);
			if(row==0)privilege = UNKNOW;
			else if (**row == '1')privilege = STUDENT;
			else if (**row == '2')privilege = TEACHER;
		}
	}
}

void Database::searchStudent(const CString& studentID)
{
}

void Database::searchStudentAllCourse(const CString& studentID)
{
}

void Database::searchStudentCourseName(const CString& studentID, const CString& courseID)
{
}

void Database::searchTeacherCourse(const CString& teacherID)
{
}

void Database::searchSemesterCourse(const CString& semester)
{
}

void Database::setGradeComposi(const CString& CourseID)
{
}

void Database::recordGrade(const CString& studentGrade, const CString& courseID)
{
}
