#pragma once
#include"Teacher.h"
#include"Student.h"
#include<memory>
//HRS:����ģʽ��ƣ���ʦ�ӿ�
class TeacherInterface
{
	TeacherInterface();//˽�л�Ĭ�Ϲ��캯��
	Teacher m_Teacher;//��ǰ��ʦ��Ϣ
	static TeacherInterface m_TeacherInterface;//����ʵ��
public:
	static std::shared_ptr<TeacherInterface> get();//��ȡʵ��

	std::shared_ptr<Teacher> getTeacher();
	void displayAllCources();//HRS:��ʾ���н��ڵĿγ�
	void selectCourse();//HRS:ѡ��γ�
	void setCoursePoint();//HRS:���óɼ�ռ��
	void submitGrade();//HRS:�ύѧ���ɼ�
};