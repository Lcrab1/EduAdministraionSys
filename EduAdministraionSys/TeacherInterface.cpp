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
