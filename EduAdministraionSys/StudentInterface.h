#pragma once
#include"Teacher.h"
#include"Student.h"
#include<memory>
//HRS:����ģʽ��ƣ�ѧ���ӿ�
class StudentInterface
{
	StudentInterface();//HRS:˽�л�Ĭ�Ϲ��캯��
	Student m_Student;//HRS:��ǰѧ����Ϣ
	static StudentInterface m_StudentInterface;//HRS:����ʵ��
public:
	static std::shared_ptr<StudentInterface> get();//HRS:��ȡʵ��

	std::shared_ptr<Student> getStudent();//HRS:��ȡ��ǰѧ����Ϣ
	void displayStudent();//HRS:�г�ѧ��������Ϣ
	void searchSemester();//HRS:��ѧ�ڲ�ѯ�γ̳ɼ�
	void searchCourseName();//HRS:���γ�����ѯ�γ̳ɼ�
};

