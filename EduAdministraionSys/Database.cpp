#include"pch.h"
#include"Database.h"

Database Database::m_Database;

Database::Database()
{
	
}

Database& Database::getDatabase()
{
	return m_Database;
}

int Database::login(IN const CString& userName, IN const CString& password)
{
	int privilege=0;
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
	return privilege;
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

void Database::searchTeacher(IN const CString& teacherID,OUT TeacherInfo& teacherInfo)
{
	//获取教师ID
	std::string id = CW2A(teacherID.GetString());
	//在Teacher表中根据教师ID查找相关信息
	std::string SQLstr = "SELECT Tno,Tname,TEnglishName,Tnation,Tschool,Tgender,Thiredate,TjobTitle,Temail,Ttelephone\
						FROM TeacherInfo\
						WHERE Tno = '" + id+"';";
	const char* sss = SQLstr.c_str();
	if (mysql_query(&m_mysql, SQLstr.c_str()))
	{
		CString error(mysql_error(&m_mysql));
		MessageBox(NULL, error, L"查询失败", NULL);
	}
	else
	{
		MYSQL_RES* result = mysql_store_result(&m_mysql);
		if (result&&result->row_count) {
			int num_fields = mysql_num_fields(result);
			MYSQL_ROW row;
			row = mysql_fetch_row(result);
			int index = 0;
			teacherInfo.no = row[index++];
			teacherInfo.name = row[index++];
			teacherInfo.englishName = row[index++];
			teacherInfo.nation = row[index++];
			teacherInfo.school = row[index++];
			teacherInfo.gender = row[index++];
			teacherInfo.hireDate = row[index++];
			teacherInfo.jobTitle = row[index++];
			teacherInfo.email = row[index++];
			teacherInfo.telephone = row[index++];
		}
	}
}
