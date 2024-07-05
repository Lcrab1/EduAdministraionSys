#include "pch.h"
#include "StudentInterface.h"

StudentInterface StudentInterface::m_StudentInterface;

StudentInterface::StudentInterface()
{
}

StudentInterface& StudentInterface::get()
{
	return m_StudentInterface;
}

void StudentInterface::getStudent()
{
	
}

void StudentInterface::displayStudent()
{

}

void StudentInterface::searchSemester()
{
}

void StudentInterface::searchCourseName()
{
}

std::vector<GradeOfStudent>& StudentInterface::GetGradeOfStudent()
{
	// TODO: 在此处插入 return 语句
	return m_GradeOfStudent;
}

