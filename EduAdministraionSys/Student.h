#pragma once
#include"Course.h"
//HRS:�洢ѧ����Ϣ����
class Student
{
	std::string m_StudentID;//HRS:ѧ��
	std::string m_StudentName;//HRS:ѧ������
	std::string m_StudentGrade;//HRS:ѧ���꼶
	std::string m_StudentDepartment;//HRS:ѧ������ѧԺ
	std::string m_StudentMajor;//HRS:ѧ��רҵ
	std::string m_StudentType;//HRS:ѧ�����(���ơ��о���)
	std::string m_StudentClass;//HRS:ѧ�������༶
	std::string m_StudentYear;//HRS:ѧ��(���ꡢ����)
	std::string m_StudentGraduate;//HRS:��ҵʱ��
	std::string m_StudentSource;//HRS:��Դ��
	std::string m_StudyForm;//HRS:ѧϰ��ʽ(ȫ���ơ���ȫ����)
public:
	std::string getID();//HRS:��ȡѧ��
	std::string getName();//HRS:��ȡ����
	std::string getGrade();//HRS:��ȡ�꼶
	std::string getDepartment();//HRS:��ȡѧԺ
	std::string getMajor();//HRS:��ȡרҵ
	std::string getType();//HRS:��ȡѧ�����(���ơ��о���)
	std::string getClass();//HRS:��ȡ�༶
	std::string getStudyYear();//HRS:��ȡѧ��(���ꡢ����)
	std::string getGraduate();//HRS:��ȡ��ҵʱ��
	std::string getSource();//HRS:��ȡ��Դ��
	std::string getStudyForm();//HRS:��ȡѧϰ��ʽ
};