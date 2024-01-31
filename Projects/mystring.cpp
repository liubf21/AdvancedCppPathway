#include <cstring>
#include <iostream>

class CMyString {
public:
  CMyString(char *pData = nullptr);
  CMyString(const CMyString &str);
  ~CMyString(void);

  CMyString &operator=(const CMyString &str);
  std::ostream &operator<<(std::ostream &stream);
  void Print();

private:
  char *m_pData;
};

CMyString::CMyString(char *pData) {
  if (pData == nullptr) {
    m_pData = new char[1];
    m_pData[0] = '\0';
  } else {
    m_pData = new char[strlen(pData) + 1];
    strcpy(m_pData, pData);
  }
}

CMyString::CMyString(const CMyString &str) {
  m_pData = new char[strlen(str.m_pData) + 1];
  strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void) { delete[] m_pData; }

std::ostream &CMyString::operator<<(std::ostream &stream) {
  stream << m_pData;
  return stream;
}

void CMyString::Print() { printf("%s", m_pData); }

// 1. 传统写法:
// 返回值是引用，可以连续赋值
// 传入参数是常量引用，避免拷贝
// 释放自身已有的内存，避免内存泄漏
// 判断传入的参数和当前的实例是不是同一个实例
/*
CMyString& CMyString::operator=(const CMyString &str)
{
    if(this == &str)
        return *this;

    delete []m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData)+1]; //
如果内存不够，会抛出异常，则m_pData指向nullptr strcpy(m_pData, str.m_pData);

    return *this;
}
*/

// 2. 优化写法:
// 先用new分配新的内存，再释放旧的内存，避免异常安全问题；分配失败时，不会改变原来的实例
// 更好的方法：先创建一个临时实例，再交换指针
CMyString &CMyString::operator=(const CMyString &str) {
  if (this != &str) {
    CMyString strTemp(
        str); // 临时实例，出作用域时会自动调用析构函数；如果在此过程中抛出异常，则还未交换指针，不会影响原来的实例
    char *pTemp = strTemp.m_pData;
    strTemp.m_pData = m_pData;
    m_pData = pTemp;
  }
  return *this;
}

void Test1() {
  printf("Test1 begins:\n");

  char *text = "Hello world";

  CMyString str1(text);
  CMyString str2;
  str2 = str1;

  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str2.Print();
  printf(".\n");
}

// 赋值给自己
void Test2() {
  printf("Test2 begins:\n");

  char *text = "Hello world";

  CMyString str1(text);
  str1 = str1;

  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str1.Print();
  printf(".\n");
}

// 连续赋值
void Test3() {
  printf("Test3 begins:\n");

  char *text = "Hello world";

  CMyString str1(text);
  CMyString str2, str3;
  str3 = str2 = str1;

  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str2.Print();
  printf(".\n");

  printf("The expected result is: %s.\n", text);

  printf("The actual result is: ");
  str3.Print();
  printf(".\n");
}

int main() {
  Test1();
  Test2();
  Test3();

  return 0;
}
