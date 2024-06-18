#include "pch.h"
#include "TeacherInterface.h"

TeacherInterface TeacherInterface::m_TeacherInterface;

TeacherInterface::TeacherInterface()
{
}

std::shared_ptr<TeacherInterface> TeacherInterface::get()
{
	return std::make_shared<TeacherInterface>(m_TeacherInterface);
}

std::shared_ptr<Teacher> TeacherInterface::getTeacher()
{
	return std::make_shared<Teacher>(m_Teacher);
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
