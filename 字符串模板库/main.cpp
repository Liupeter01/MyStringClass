#include"MyString.h"
#include"MyString.cpp"

int main()
{
		  MyString<wchar_t>my1(L"hello world");
		  MyString<wchar_t>my2(L" hello cpp");
		  MyString<wchar_t>my3;
		  my3= my1 + my2;
		  std::cout << my3 << std::endl;
		  return 0;
}