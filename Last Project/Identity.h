#pragma once //��ֹͷ�ļ��ظ�����
#include<string>
using namespace std;
//˼·����Ϊѧ������ʦ������Ա ���й�ͬ������ ���Կ���ͨ����������ʵ�����ǵĹ���
class Identity
{
public:
	//Identity�ǻ��࣬����Ҫ�������и��๲ͬӵ�е����ԣ������������� ѧ���ͽ�ʦ����ID�����ǹ���Աû��ID,����ID�ͷ��������Լ���������
	string m_Name ="";
	string m_Pwd ="";

	virtual void operMenu() = 0;//virtual��ʾ�麯�� =0��ʾ���麯��
};

