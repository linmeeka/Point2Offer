#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class CMystring
{
public:
	CMystring(char *pData=nullptr);
	CMystring(const CMystring &ptr);
	CMystring& operator=(const CMystring &str);
	CMystring::~CMystring();
private:
	char *m_pData;
};
CMystring::CMystring(char *pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMystring::CMystring(const CMystring &str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMystring::~CMystring()
{
	delete[] m_pData;
}
// ����Ҫ�����ã���֤����������ֵ(a=b=c)
//CMystring& CMystring::operator=(const CMystring &str)
//{
//	// this �����ʵ����[ָ��]�� &ȡ�βεĵ�ַ�� ��ַ�Ƚ����
//	// �жϣ������ظ��������Լ��ͷ�str�ڴ�
//	if (this == &str)
//		// ���ص���ʵ����*ȡthis��ֵ
//		return *this;
//
//	// �ͷ�ԭ���ڴ�
//	delete []m_pData;
//	m_pData = nullptr;
//	// ����ռ�
//	m_pData = new char[strlen(str.m_pData) + 1];
//	// copy
//	strcpy(m_pData, str.m_pData);
//	// ��������
//	return *this;
//}

CMystring& CMystring::operator=(const CMystring &str)
{
	if (this != &str)
	{
		// �ڹ��캯��������ڴ����롣 �������ʧ�ܣ���ǰʵ����Ȼ���������ڴ�
		CMystring tmp(str);
		char *pTmp = tmp.m_pData;
		// ��m_pData���ڴ����ʱ�ľֲ�����, �뿪������ʱ�Զ��������ͷ��ڴ�
		tmp.m_pData = m_pData;
		m_pData = pTmp;
	}
	return *this;
}

int main()
{
	char *t = "aa";
	CMystring a(t);
	CMystring b = a;
	CMystring c;
	c = b = a;
	b = b;
}