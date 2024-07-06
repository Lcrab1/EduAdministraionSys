#include"pch.h"
#include"Database.h"
#include"StudentInterface.h"
#include"TeacherInterface.h"

/***
 *                                         ,s555SB@@&
 *                                      :9H####@@@@@Xi
 *                                     1@@@@@@@@@@@@@@8
 *                                   ,8@@@@@@@@@B@@@@@@8
 *                                  :B@@@@X3hi8Bs;B@@@@@Ah,
 *             ,8i                  r@@@B:     1S ,M@@@@@@#8;
 *            1AB35.i:               X@@8 .   SGhr ,A@@@@@@@@S
 *            1@h31MX8                18Hhh3i .i3r ,A@@@@@@@@@5
 *            ;@&i,58r5                 rGSS:     :B@@@@@@@@@@A
 *             1#i  . 9i                 hX.  .: .5@@@@@@@@@@@1
 *              sG1,  ,G53s.              9#Xi;hS5 3B@@@@@@@B1
 *               .h8h.,A@@@MXSs,           #@H1:    3ssSSX@1
 *               s ,@@@@@@@@@@@@Xhi,       r#@@X1s9M8    .GA981
 *               ,. rS8H#@@@@@@@@@@#HG51;.  .h31i;9@r    .8@@@@BS;i;
 *                .19AXXXAB@@@@@@@@@@@@@@#MHXG893hrX#XGGXM@@@@@@@@@@MS
 *                s@@MM@@@hsX#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&,
 *              :GB@#3G@@Brs ,1GM@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B,
 *            .hM@@@#@@#MX 51  r;iSGAM@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@8
 *          :3B@@@@@@@@@@@&9@h :Gs   .;sSXH@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:
 *      s&HA#@@@@@@@@@@@@@@M89A;.8S.       ,r3@@@@@@@@@@@@@@@@@@@@@@@@@@@r
 *   ,13B@@@@@@@@@@@@@@@@@@@5 5B3 ;.         ;@@@@@@@@@@@@@@@@@@@@@@@@@@@i
 *  5#@@#&@@@@@@@@@@@@@@@@@@9  .39:          ;@@@@@@@@@@@@@@@@@@@@@@@@@@@;
 *  9@@@X:MM@@@@@@@@@@@@@@@#;    ;31.         H@@@@@@@@@@@@@@@@@@@@@@@@@@:
 *   SH#@B9.rM@@@@@@@@@@@@@B       :.         3@@@@@@@@@@@@@@@@@@@@@@@@@@5
 *     ,:.   9@@@@@@@@@@@#HB5                 .M@@@@@@@@@@@@@@@@@@@@@@@@@B
 *           ,ssirhSM@&1;i19911i,.             s@@@@@@@@@@@@@@@@@@@@@@@@@@S
 *              ,,,rHAri1h1rh&@#353Sh:          8@@@@@@@@@@@@@@@@@@@@@@@@@#:
 *            .A3hH@#5S553&@@#h   i:i9S          #@@@@@@@@@@@@@@@@@@@@@@@@@A.
 *
 *
 *								谁让你看我代码的？
 */



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

	std::string SQLstr = "SELECT privilege FROM admin_info WHERE account='" + userIDStr + "' AND password='" + userPasswordStr+"'";
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

bool Database::searchStudent(IN const CString& studentID, OUT StudentInfo& studentInfo)
{
	std::string StudentIDStr = CW2A(studentID.GetString());

	std::string SQLstr = "SELECT *\
						  FROM studentInfo WHERE Sno='" + StudentIDStr +"';";
	if (mysql_query(&m_mysql, SQLstr.c_str()))
	{
		CString error(mysql_error(&m_mysql));
		MessageBox(NULL, error, L"查询失败", NULL);
		return false;
	}
	else
	{
		MYSQL_RES* result = mysql_store_result(&m_mysql);
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		studentInfo.ID = row[0];
		studentInfo.Name = row[1];
		studentInfo.EngName = row[2];
		studentInfo.Nation = row[3];
		studentInfo.Grade = row[4];
		studentInfo.Gender = row[5];
		studentInfo.Department = row[6];
		studentInfo.Major = row[7];
		studentInfo.Type = row[8];
		studentInfo.Class = row[9];
		studentInfo.Year = row[10];
		studentInfo.Graduate = row[11];
		studentInfo.Source = row[12];
		studentInfo.StudyForm = row[13];
		studentInfo.Email = row[14];
		studentInfo.Telephone = row[15];
	}
	return true;
}

bool Database::searchStudentAllCourse(IN const CString& studentID, IN const CString semester, OUT std::vector<CourseInfo>& course)
{
	return true;
}

bool Database::searchStudentCourseScore(IN const CString& studentID, IN const CString& courseID, OUT CString& score)
{
	return true;
}

bool Database::searchTeacherCourse(IN const CString& teacherID, OUT CourseInfo& courseInfo)
{
	return true;
}

bool Database::searchSemesterCourse(IN const CString& semester, OUT std::vector<CourseInfo>& course)
{
	return true;
}




void Database::SearchTeacher(IN const CString& teacherID,OUT TeacherInfo& teacherInfo)
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


void Database::GetClassOfTeacher(IN const CString& teacherID, OUT std::vector<ClassOfTeacher>& classOfTeacher)
{
	classOfTeacher.clear();
	//XK:(教学班)教学班的课程号+教师ID->(课程表)课程名
	std::string id = CW2A(teacherID.GetString());
	//在Teacher表中根据教师ID查找相关信息
	std::string SQLstr = "SELECT\
							CourseInfo.Cno,\
							CourseInfo.Cname,\
							COUNT(RecordCourseInfo.Cno) AS CourseCount,\
							CourseInfo.Ccredit,\
							ArrangementClassInfo.Aclassroom,\
							ArrangementClassInfo.Aweek,\
							ArrangementClassInfo.Ayear,\
							ArrangementClassInfo.Asemester\
							FROM CourseInfo\
							JOIN ArrangementClassInfo ON CourseInfo.Cno = ArrangementClassInfo.Cno\
							JOIN RecordCourseInfo ON CourseInfo.Cno = RecordCourseInfo.Cno\
							WHERE ArrangementClassInfo.Tno = '" + id + "'\
							GROUP BY CourseInfo.Cno, CourseInfo.Cname, CourseInfo.Ccredit, ArrangementClassInfo.Aclassroom, ArrangementClassInfo.Aweek;";
	const char* sss = SQLstr.c_str();
	if (mysql_query(&m_mysql, SQLstr.c_str()))
	{
		CString error(mysql_error(&m_mysql));
		MessageBox(NULL, error, L"查询失败", NULL);
	}
	else
	{
		MYSQL_RES* result = mysql_store_result(&m_mysql);
		if (result && result->row_count) {
			//int num_fields = mysql_num_fields(result);
			MYSQL_ROW row;
			while((row=mysql_fetch_row(result)))
			{
					int index = 0;
					CString id(row[index++]);
					CString name(row[index++]);
					CString studentCount(row[index++]);
					CString credit(row[index++]);
					CString classRoom(row[index++]);
					CString week(row[index++]);
					CString year(row[index++]);
					CString semester(row[index++]);
					classOfTeacher.emplace_back(id, name, studentCount, credit, classRoom, week, year, semester);
			}
		}
	}

}

void Database::GetGradeOfStudent(IN const CString& studentID, OUT std::vector<GradeOfStudent>& gradeOfStudent)
{
	gradeOfStudent.clear();
	//XK:(教学班)教学班的课程号+教师ID->(课程表)课程名
	std::string id = CW2A(studentID.GetString());
	//在Teacher表中根据教师ID查找相关信息
	std::string SQLstr = "SELECT ArrangementClassInfo.Ayear, ArrangementClassInfo.Asemester, CourseInfo.Cname, CourseInfo.Ccredit,\
						  RecordCourseInfo.RmidScore, RecordCourseInfo.RusualScore, RecordCourseInfo.RfinalScore, RecordCourseInfo.RtotalScore\
						  FROM RecordCourseInfo\
						  JOIN CourseInfo ON RecordCourseInfo.Cno = CourseInfo.Cno\
					      JOIN ArrangementClassInfo ON CourseInfo.Cno = ArrangementClassInfo.Cno\
						  WHERE RecordCourseInfo.Sno = '" + id +"';";
	const char* sss = SQLstr.c_str();
	if (mysql_query(&m_mysql, SQLstr.c_str()))
	{
		CString error(mysql_error(&m_mysql));
		MessageBox(NULL, error, L"查询失败", NULL);
	}
	else
	{
		MYSQL_RES* result = mysql_store_result(&m_mysql);
		if (result && result->row_count) {
			//int num_fields = mysql_num_fields(result);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(result)))
			{
					int index = 0;
					CString year(row[index++]);
					CString semester(row[index++]);
					CString course(row[index++]);
					CString credit(row[index++]);
					CString midScore(row[index++]);
					CString usualScore(row[index++]);
					CString finalScore(row[index++]);
					CString totalScore(row[index++]);
					gradeOfStudent.emplace_back(year, semester, course, credit, midScore, usualScore, finalScore, totalScore);
			}
		}
	}

}

void Database::ChangePersonalInfo(IN const CString& studentID, IN const CString& englishName, IN const CString& telephone, IN const CString& email)
{
	std::string idStr = CW2A(studentID.GetString());
	std::string englishNameStr = CW2A(englishName.GetString());
	std::string telephoneStr = CW2A(telephone.GetString());
	std::string emailStr = CW2A(email.GetString());
	
	std::string SQLstr = "UPDATE StudentInfo\
						  SET SEnglishName = '" + englishNameStr + "',\
						  Stelephone = '" + telephoneStr + "',\
						  Semail = '" + emailStr + "'\
						WHERE Sno = '" + idStr + "';";
	const char* sss = SQLstr.c_str();
	if (mysql_query(&m_mysql, SQLstr.c_str()))
	{
		CString error(mysql_error(&m_mysql));
		MessageBox(NULL, error, L"查询失败", NULL);
	}



}

void Database::GetClassOfSC(IN const CString& TeacherID, OUT std::vector<ClassOfStudentScore>& classOfStudentScore)
{
	classOfStudentScore.clear();
	//XK:(教学班)教学班的课程号+教师ID->(课程表)课程名
	std::string Teacherid = CW2A(TeacherID.GetString());
	//根据课程名查找相关信息
	std::string SQLstr = "SELECT\
		ArrangementClassInfo.Ayear,\
		ArrangementClassInfo.Asemester,\
		CourseInfo.Cname,\
		RecordCourseInfo.Sno,\
		StudentInfo.Sname\
		FROM\
		TeacherInfo\
		JOIN\
		ArrangementClassInfo ON TeacherInfo.Tno = ArrangementClassInfo.Tno\
		JOIN\
		CourseInfo ON ArrangementClassInfo.Cno = CourseInfo.Cno\
		JOIN\
		RecordCourseInfo ON CourseInfo.Cno = RecordCourseInfo.Cno\
		JOIN\
		StudentInfo ON RecordCourseInfo.Sno = StudentInfo.Sno\
		WHERE\
		TeacherInfo.Tno = '" + Teacherid + "'";



	const char* sss = SQLstr.c_str();
	if (mysql_query(&m_mysql, SQLstr.c_str()))
	{
		CString error(mysql_error(&m_mysql));
		MessageBox(NULL, error, L"查询失败", NULL);
	}
	else
	{
		MYSQL_RES* result = mysql_store_result(&m_mysql);
		if (result && result->row_count) {
			//int num_fields = mysql_num_fields(result);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(result)))
			{
				for (int i = 0; i < result->row_count; i++)
				{
					int index = 0;
					CString year(row[index++]);
					CString semester(row[index++]);
					CString CourseName(row[index++]);
					CString studentID(row[index++]);
					CString studentName(row[index++]);

					classOfStudentScore.emplace_back(CourseName, studentID, studentName,
												_T("0"), _T("0"), _T("0"), _T("0"),year, semester);
				}
			}
		}
	}
}

bool Database::searchStudentAllCourse(IN const CString& studentID, IN const CString& year, IN const CString& semester, OUT std::vector<GradeOfStudent>& courseGrade)
{
	std::string IDstr = CW2A(studentID.GetString());
	std::string yearStr = CW2A(year.GetString());
	std::string semesterStr = CW2A(semester.GetString());
	std::string SQLstr = "\
		SELECT courseInfo.Cname,\
		courseInfo.Ccredit,\
		RecordCourseInfo.RmidScore, \
		RecordCourseInfo.RusualScore, \
		RecordCourseInfo.RfinalScore, \
		RecordCourseInfo.RtotalScore, \
		FROM courseInfo,RecordCourseInfo\
		WHERE RecordCourseInfo.Sno='" + IDstr + "' " +
		"AND RecordCourseInfo.Cno IN\
		(SELECT Cno\
		FROM ArrangementClassInfo\
		WHERE Ayear='" + yearStr + "' AND Asemester='" + semesterStr + "') \
		AND courseInfo.Cno=RecordCourseInfo.Cno";


	if (mysql_query(&m_mysql, SQLstr.c_str()))
	{
		CString error(mysql_error(&m_mysql));
		MessageBox(NULL, error, L"查询失败", NULL);
		return false;
	}
	else
	{
		MYSQL_RES* result = mysql_store_result(&m_mysql);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(result))
		{
			CString Cname(row[0]);
			CString Ccredit(row[1]);
			CString mid(row[2]);
			CString usual(row[3]);
			CString final(row[4]);
			CString total(row[5]);
			courseGrade.emplace_back(year, semester, Cname, Ccredit, mid, usual, final, total);
		}
	}
	return true;
}
/*
	CString studentID;       // 学号
	CString studentName;     // 学生姓名
	CString dailyScore;        // 平时成绩
	CString midtermScore;      // 期中成绩
	CString finalScore;        // 期末成绩
	CString totalScore;        // 总评成绩
	CString year;
	CString semester;
*/


