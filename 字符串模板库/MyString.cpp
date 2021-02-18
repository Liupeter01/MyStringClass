#include "MyString.h"

template<typename T>
MyString<T>::MyString(const T* input)
{
		  if (strcmp(typeid(T).name(), "char") == 0 || strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					this->length = (strcmp(typeid(T).name(), "char") == 0) ?  strlen(reinterpret_cast<const char*>(input)) : wcslen(reinterpret_cast<const wchar_t*>(input));
					this->str = new T[this->length + 1];
					memset(this->str, 0, this->length + 1);
					if (strcmp(typeid(T).name(), "char") == 0)
					{
							  strcpy(reinterpret_cast<char*>(this->str), reinterpret_cast<const char *>(input));
					}
					if (strcmp(typeid(T).name(), "wchar_t") == 0)
					{
							  wcscpy(reinterpret_cast<wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(input));
					}
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
		  }
}

template<typename T>
MyString<T>::MyString(const MyString& my)
{
		  if (this->str != nullptr)
		  {
					delete[] this->str;
		  }
		  this->length = 0;	  //清空类的原先的内存，将其归零
		  this->length = my.length;
		  this->str = new T[this->length + 1];
		  memset(this->str, 0, this->length + 1);
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					strcpy(reinterpret_cast<char*>(this->str), reinterpret_cast<const char*>(my.str));
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					wcscpy(reinterpret_cast<wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(my.str));
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
		  }
}

template<typename T>
void MyString<T>::operator=(const MyString& my)	  //赋值重载
{
		  if (this->str != nullptr)
		  {
					delete[] this->str;
		  }
		  this->length = 0;	  //清空类的原先的内存，将其归零
		  this->length = my.length;
		  this->str = new T[this->length + 1];
		  memset(this->str, 0, this->length + 1);
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					strcpy(reinterpret_cast<char*>(this->str), reinterpret_cast<const char*>(my.str));
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					wcscpy(reinterpret_cast<wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(my.str));
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
		  }
}

template<typename T>
void MyString<T>::operator+=(const MyString& my)
{
		  this->length += my.length;
		  T* mymem(new T[this->length + 1]);
		  memset(mymem, 0, sizeof(T) * (this->length + 1));

		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					strcpy(reinterpret_cast<char*>(mymem), reinterpret_cast<const char*>(this->str));
					strcat(reinterpret_cast<char*>(mymem), reinterpret_cast<const char*>(my.str));
					delete[] this->str;
					this->str = mymem;
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					wcscpy(reinterpret_cast<wchar_t*>(mymem), reinterpret_cast<const wchar_t*>(this->str));
					wcscat(reinterpret_cast<wchar_t*>(mymem), reinterpret_cast<const wchar_t*>(my.str));
					delete[] this->str;
					this->str = mymem;
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
					return;
		  }
}

template<typename T>
MyString<T> &MyString<T>::operator+(const MyString& my)
{
		  MyString<T>* ptemp(new MyString<T>);

		  ptemp->length = this->length + my.length;
		  ptemp->str = new T[ptemp->length + 1];
		  memset(ptemp->str, 0, sizeof(T) * (ptemp->length + 1));
		  
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					strcpy(reinterpret_cast<char*>(ptemp->str), reinterpret_cast<const char*>(this->str));
					strcat(reinterpret_cast<char*>(ptemp->str), reinterpret_cast<const char*>(my.str));
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					wcscpy(reinterpret_cast<wchar_t*>(ptemp->str), reinterpret_cast<const wchar_t*>(this->str));
					wcscat(reinterpret_cast<wchar_t*>(ptemp->str), reinterpret_cast<const wchar_t*>(my.str));
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
		  }
		  return *ptemp;
}

template<typename T>
bool MyString<T>::operator ==(const MyString& my)
{
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					return (strcmp(reinterpret_cast<const char*>(this->str), reinterpret_cast<const char*>(my.str)) == 0);
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					return (strcmp(reinterpret_cast<const wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(my.str)) == 0);
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
					return false;
		  }
}

template<typename T>
bool MyString<T>::operator !=(const MyString& my)
{
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					return (strcmp(reinterpret_cast<const char*>(this->str), reinterpret_cast<const char*>(my.str)) != 0);
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					return (strcmp(reinterpret_cast<const wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(my.str)) != 0);
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
					return false;
		  }
}

template<typename T>
bool MyString<T>::operator >=(const MyString& my)
{
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					return (strcmp(reinterpret_cast<const char*>(this->str), reinterpret_cast<const char*>(my.str)) >= 0);
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					return (strcmp(reinterpret_cast<const wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(my.str)) >= 0);
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
					return false;
		  }
}

template<typename T>
bool MyString<T>::operator <=(const MyString& my)
{
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					return (strcmp(reinterpret_cast<const char*>(this->str), reinterpret_cast<const char*>(my.str)) <= 0);
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					return (strcmp(reinterpret_cast<const wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(my.str)) <= 0);
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
					return false;
		  }
}

template<typename T>
bool MyString<T>::operator >(const MyString& my)
{
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					return (strcmp(reinterpret_cast<const char*>(this->str), reinterpret_cast<const char*>(my.str)) > 0);
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					return (strcmp(reinterpret_cast<const wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(my.str)) > 0);
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
					return false;
		  }
}

template<typename T>
bool MyString<T>::operator <(const MyString& my)
{
		  if (strcmp(typeid(T).name(), "char") == 0)
		  {
					return (strcmp(reinterpret_cast<const char*>(this->str), reinterpret_cast<const char*>(my.str)) < 0);
		  }
		  else if (strcmp(typeid(T).name(), "wchar_t") == 0)
		  {
					return (strcmp(reinterpret_cast<const wchar_t*>(this->str), reinterpret_cast<const wchar_t*>(my.str)) < 0);
		  }
		  else
		  {
					std::cout << "该数据类型不是字符串" << std::endl;
					return false;
		  }
}

template<typename T>
T MyString<T>::operator[](const int id)	//重载中括号
{
		  if (id < 0 || id> this->length)					//数据错误
		  {
					throw InputOutOfRange();	  //抛出异常
		  }
		  else
		  {
					return this->str[id];
		  }
}

template<typename T>
void MyString<T>::display()
{
		  std::cout << this->str << std::endl;
}
template<typename T>
int  MyString<T>::getstringlength()
{
		  return this->length;
}

template<typename T>
MyString<T>::~MyString()
{
		  delete[] this->str;
		  this->str = nullptr;
		  length = 0;
}

template<typename T>
void MyString<T>::searchfirststring(const MyString& oldone, const MyString& newone)	  //查找一个字符
{

}

template<typename T>
void MyString<T>::searchallstring(const MyString& oldone, const MyString& newone)	  //查找所有的字符串
{

}

template<typename T>
void MyString<T>::replacefirststring(const MyString& oldone, const MyString& newone)	  //替换一个字符
{

}

template<typename T>
void MyString<T>::replaceallstring(const MyString& oldone, const MyString& newone)		  //替换所有的字符串
{

}

template<typename T>
void MyString<T>::insertfirststring(const MyString& oldone, const MyString& newone)		  //插入一个字符串
{

}

template<typename T>
void MyString<T>::insertallstring(const MyString& oldone, const MyString& newone)		  //插入所有的指定字符串
{

}

template<typename T>
void MyString<T>::deletefirststring(const MyString& oldone, const MyString& newone)		  //删除一个字符串
{

}

template<typename T>
void MyString<T>::deleteallstring(const MyString& oldone, const MyString& newone)		  //删除所有的指定字符串
{

}
