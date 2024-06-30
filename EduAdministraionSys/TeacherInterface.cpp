#include "pch.h"
#include "TeacherInterface.h"

TeacherInterface TeacherInterface::m_TeacherInterface;

TeacherInterface::TeacherInterface()
{
	
}

TeacherInterface& TeacherInterface::get()
{
	return m_TeacherInterface;
}

std::vector<ClassOfTeacher>& TeacherInterface::getClassOfTeacher()
{
	return m_ClassOfTeacher;
	// TODO: 在此处插入 return 语句
}

Teacher& TeacherInterface::getTeacher()
{
	return m_Teacher;
}

void TeacherInterface::displayAllCources()
{
}

void TeacherInterface::selectCourse()
{
}

void TeacherInterface::setCoursePoint()
{
}

void TeacherInterface::submitGrade()
{
}
