#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<functional>

/*
* ʹ��ģ�崦����ַ���խ�ַ�
* ��ģ������ͽ�����char��wchar_t
*/

template<typename T>
class MyString
{
public:
		  /*���캯������������*/
		  MyString():str(nullptr), length(0){}
		  MyString(const T* input);
		  MyString(const MyString& my);
		  ~MyString();

		  /*��ֵ���غ���*/
		  void operator=(const MyString& my);	  //��ֵ����
		  void operator+=(const MyString& my);
		  MyString& operator+(const MyString& my);
		  bool operator ==(const MyString& my);
		  bool operator !=(const MyString& my);
		  bool operator >=(const MyString& my);
		  bool operator <=(const MyString& my);
		  bool operator >(const MyString& my);
		  bool operator <(const MyString& my);
		  T operator[](const int id);			//����������

		  /*��������ӿ�*/
		  void display();
		  int getstringlength();

		  /*�ַ������ܺ���*/
		  void searchfirststring(const MyString& oldone, const MyString& newone);		  //����һ���ַ���
		  void searchallstring(const MyString& oldone, const MyString& newone);		  //�������е�ָ���ַ���

		  void replacefirststring(const MyString& oldone, const MyString& newone);		  //�滻һ���ַ���
		  void replaceallstring(const MyString& oldone, const MyString& newone);		  //�滻���е�ָ���ַ���

		  void insertfirststring(const MyString& oldone, const MyString& newone);		  //����һ���ַ���
		  void insertallstring(const MyString& oldone, const MyString& newone);		  //�������е�ָ���ַ���

		  void deletefirststring(const MyString& oldone, const MyString& newone);		  //ɾ��һ���ַ���
		  void deleteallstring(const MyString& oldone, const MyString& newone);		  //ɾ�����е�ָ���ַ���

		  /*��Ԫ����*/
		  template<typename T>
		  friend std::ostream& operator<<(std::ostream& os, const MyString<T>& my)
		  {
					return os << my.str << std::endl;
		  }

private:
		  T *str =nullptr;
		  int length = 0;
		  std::function<void(void)> ouput = [=]() {std::cout << this->str << std::endl; };
};

class InputOutOfRange					//�ڴ�Խ���׳��쳣
{

};