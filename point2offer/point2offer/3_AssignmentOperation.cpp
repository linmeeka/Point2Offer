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
// 返回要是引用，保证可以连续赋值(a=b=c)
//CMystring& CMystring::operator=(const CMystring &str)
//{
//	// this 是这个实例的[指针]， &取形参的地址， 地址比较相等
//	// 判断，避免重复操作，以及释放str内存
//	if (this == &str)
//		// 返回的是实例，*取this的值
//		return *this;
//
//	// 释放原有内存
//	delete []m_pData;
//	m_pData = nullptr;
//	// 申请空间
//	m_pData = new char[strlen(str.m_pData) + 1];
//	// copy
//	strcpy(m_pData, str.m_pData);
//	// 返回引用
//	return *this;
//}

CMystring& CMystring::operator=(const CMystring &str)
{
	if (this != &str)
	{
		// 在构造函数里进行内存申请。 如果分配失败，当前实例仍然保留它的内存
		CMystring tmp(str);
		char *pTmp = tmp.m_pData;
		// 把m_pData的内存给临时的局部变量, 离开作用域时自动析构，释放内存
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