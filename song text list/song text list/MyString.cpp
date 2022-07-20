#include "Class_MyString.h"
#pragma warning(disable: 4996)
using namespace std;
MyString::MyString()
{
    len = 0;
    s = new char; *s = '\0';
}
MyString::MyString(const char* S1)
{
    s = new char[(len = strlen(S1)) + 1];
    strcpy(s, S1);
}
MyString::MyString(const MyString& MS1)
{
    len = MS1.len;
    s = new char[len + 1];
    strcpy(s, MS1.s);
}
MyString::~MyString()
{
    len = 0;
    if (s != nullptr)
    {
        delete[] s;
        s = nullptr;
    }
}
void MyString::dispose()
{
    delete[]s;
}
void MyString::output()
{
    //puts(s);
    cout << s;
    //for (int i = 0; i < len + 1; i++)
    //  std::cout << s[i];
}
int MyString::input()
{
    char buf[256];
    cin.getline(buf, 255, '\n');//���� ������ �� ������ �������� �����
    delete[]s; s = new char[strlen(buf)];
    strcpy(s, buf);
    //cin.getline(s,len);
    return 1;
}
void MyString::assign(const MyString& MS1)
{
    if (this == &MS1)//�������� �� ������������ ���� ���� ��
        return;
    len = MS1.len;
    delete[]s;//������������ ������
    s = new char[len + 1];//�������� ������
    strcpy(s, MS1.s);//�����������
}
int MyString::ToInt()
{
    int n = 0, i = 0; bool t = false;
    if (s[i] == '-')//�������� �� ����
    {
        t = true;
        i++;
    }
    for (; i < len; i++)
    {
        if (!(isdigit(s[i])))//�� ����� - ������� � �������
            return NotTrue;
        n = (n + i) * 10;
    }
    if (t)
        return -n / 10;//���� �������������
    else
        return n / 10;//���� �������������
}
char* MyString::ToAChar()
{
    char* t = new char[len + 1];//��������� ������
    strcpy(t, s);//�����������
    return t;
}
double MyString::ToDouble(const char separator)
{
    if (separator == '\0')
    {
        cout << "Uncorrect separator!\n";
        return NotTrue;
    }
    int INT = 0, FLOAT = 0, i = 0, count = 0;
    double del; bool t = false;
    if (s[i] == '-')//�������� �� ����
    {
        t = true;
        i++;
    }
    for (; i < len; i++)
    {
        if (!(isdigit(s[i])) && s[i] != separator)//���� �� ����� � �� ����������� - ������� � �������
            return NotTrue;
        if (s[i] == separator && i > t)//���� ����������� � ����������� �� ����� �����
        {
            INT = FLOAT;
            FLOAT = 0;
            count++;
            del = pow(10, len - i);
            if (count == 2)//���� ������������ ������ 1 - ������� � �������
                return NotTrue;
        }
        FLOAT = (FLOAT + i) * 10;
    }
    double n = INT + double(FLOAT) / del;//������������ ������� � ����� ������
    if (t)
        return -n / 10;//�������������
    else
        return n / 10;//������������
}
int MyString::cmp(const MyString& MS1)
{
    return strcmp(s, MS1.s);
}
int MyString::cmp_with_len(const MyString& MS1)
{
    //��������� ���-�� ��������
    if (len != MS1.len)
        return len - MS1.len;
    return strcmp(s, MS1.s);//��������� �����
}
bool MyString::equal(const MyString& MS1)
{
    return *this == MS1;
}
MyString* MyString::copy()
{
    return new MyString(*this);
}
MyString* MyString::Concate(const MyString& MS1)
{
    MyString* MS2 = new MyString(s);
    MS2->resize(MS1.len);
    strcpy(&MS2->s[len - MS1.len], MS1.s);
    return MS2;
}
int MyString::write(FILE* fp)
{
    fprintf(fp, "%d\n", len);//������ ���-�� �������� � ������
    int i = fputs(s, fp); char endline = '\n';//������ ������
    fprintf(fp, "%c", endline);//������� �� ����� ������
    return i;
}
int MyString::read(FILE* fp)
{
    if (fscanf(fp, "%d\n", &len) == EOF)//������ ���-�� �������� ������
        return EOF;//���� ����� ����� �� �����
    if (*s != '\0')
        delete[]s;//���� �� ������ ������ - ������������ ������
    s = new char[len + 1];//��������� ����� ������
    if (fgets(s, len + 1, fp) != nullptr)//������
        return len;
    return EOF;
}
void MyString::resize(int n)
{
    if (len + n <= 0)//���� ������ ����� 0 ��� ������, ��:
    {
        delete[]s;
        s = nullptr;
        return;
    }
    char* tmp = s;//���������� ������
    s = new char[len + n + 1];//��������� ����� ������
    strcpy(s, tmp);//�����������
    delete[]tmp; len += n;//������������ ������ � ��������� �����
}
MyString& MyString::operator+=(const MyString& MS1)
{
    //������������
    resize(MS1.len);
    strcpy(&s[len - MS1.len], MS1.s);
    return *this;
}
MyString operator+(const MyString& MS1, const MyString& MS2)
{
    //������������
    MyString tmp(MS1);
    return tmp += MS2;
}
MyString& MyString::operator =(const MyString& MS1)
{
    //������������
    assign(MS1);
    return *this;
}
std::istream& operator>>(std::istream& i, MyString& MS1)
{
    //���� � ����������
    char buf[256];
    i.getline(buf, 255, '\n');
    delete[] MS1.s; MS1.len = strlen(buf);
    MS1.s = new char[MS1.len + 1];
    strcpy(MS1.s, buf);
    return i;
}
MyString& MyString::operator +=(const char* t)
{
    int f = strlen(t);
    resize(f);//��������� ������ ��� �������������
    strcpy(&s[len - f], t);//�������������
    return *this;
}
MyString operator +(const MyString& MS1, const char* t)
{
    MyString tmp(MS1);//�������� �������
    return tmp += t;//�������������
}
MyString* MyString::Concate(char* t)
{
    MyString* tmp = new MyString(s);//�������� �������
    *tmp += t;//������������
    return tmp;
}