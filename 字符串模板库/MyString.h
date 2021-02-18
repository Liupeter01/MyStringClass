#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<functional>

/*
* 使用模板处理宽字符和窄字符
* 类模板的类型仅限于char和wchar_t
*/

template<typename T>
class MyString
{
public:
		  /*构造函数与析构函数*/
		  MyString():str(nullptr), length(0){}
		  MyString(const T* input);
		  MyString(const MyString& my);
		  ~MyString();

		  /*赋值重载函数*/
		  void operator=(const MyString& my);	  //赋值重载
		  void operator+=(const MyString& my);
		  MyString& operator+(const MyString& my);
		  bool operator ==(const MyString& my);
		  bool operator !=(const MyString& my);
		  bool operator >=(const MyString& my);
		  bool operator <=(const MyString& my);
		  bool operator >(const MyString& my);
		  bool operator <(const MyString& my);
		  T operator[](const int id);			//重载中括号

		  /*数据输出接口*/
		  void display();
		  int getstringlength();

		  /*字符串功能函数*/
		  void searchfirststring(const MyString& oldone, const MyString& newone);		  //查找一个字符串
		  void searchallstring(const MyString& oldone, const MyString& newone);		  //查找所有的指定字符串

		  void replacefirststring(const MyString& oldone, const MyString& newone);		  //替换一个字符串
		  void replaceallstring(const MyString& oldone, const MyString& newone);		  //替换所有的指定字符串

		  void insertfirststring(const MyString& oldone, const MyString& newone);		  //插入一个字符串
		  void insertallstring(const MyString& oldone, const MyString& newone);		  //插入所有的指定字符串

		  void deletefirststring(const MyString& oldone, const MyString& newone);		  //删除一个字符串
		  void deleteallstring(const MyString& oldone, const MyString& newone);		  //删除所有的指定字符串

		  /*友元函数*/
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

class InputOutOfRange					//内存越界抛出异常
{

};