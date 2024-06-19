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

Student& StudentInterface::getStudent()
{
	return m_Student;
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

