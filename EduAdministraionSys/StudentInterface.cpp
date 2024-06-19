#include "pch.h"
#include "StudentInterface.h"

StudentInterface StudentInterface::m_StudentInterface;

StudentInterface::StudentInterface()
{
}

std::shared_ptr<StudentInterface> StudentInterface::get()
{
	return std::make_shared<StudentInterface>(m_StudentInterface);
}

std::shared_ptr<Student> StudentInterface::getStudent()
{
	return std::make_shared<Student>(m_Student);
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

