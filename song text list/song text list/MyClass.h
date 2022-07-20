#pragma once
#include "Class_MyString.h"
#include "Class_date.h"
class MyClass
{
    MyString band, singer, song, email, adress;
    int count;
    double price;
    date Date;
public:
    MyClass() :Date(), band(), singer(), song(), email(), adress() { price = count = -1; }//����������� ��-���������
    MyClass(char*, char*, char*, char*, char*, int, double, int, int, int);//����������� � �����������
    MyClass(char*, char*, char*, char*, char*, int, double, char*, const char);//����������� � �����������
    MyClass(const MyString&, const MyString&, const MyString&, const MyString&, const MyString&, int, double, int, int, int);//����������� � �����������
    MyClass(const MyString&, const MyString&, const MyString&, const MyString&, const MyString&, int, double, char*, const char);//����������� � �����������
    MyClass(const MyClass& MC1) { this->assign(MC1); }//����������� �����������
    ~MyClass() { ; }
    MyClass* copy();//�����������
    int read(FILE* fp);//������ �� �����
    int write(FILE* fp);//������ � ����
    void assign(const MyClass& MC1);//������������
    void output(ostream& os = cout);//����� �� �����
    int input(istream& is = cin);//���� � ����������
    int cmp(const MyClass& MC1);//������������ ���������
    int equal(const MyClass& mo2) { return cmp(mo2) == 0; }
    void dispose() { if (this != nullptr)this->~MyClass(); }
    MyString ToMyString()const { return MyString("MyClass"); };
    MyClass& operator =(const MyClass& MS1);//�������� ������������
    int operator ==(const MyClass& MS1) { return cmp(MS1) == 0; }//�������� ��������� �� ���������
    int operator !=(const MyClass& MS1) { return cmp(MS1) != 0; }//�������� ��������� �� �����������
    int operator >=(const MyClass& MS1) { return cmp(MS1) >= 0; }//������ ��� �����?
    int operator <=(const MyClass& MS1) { return cmp(MS1) <= 0; }//������ ��� �����?
    int operator <(const MyClass& MS1) { return cmp(MS1) < 0; }//������?
    int operator >(const MyClass& MS1) { return cmp(MS1) > 0; }//������?
    friend std::ostream& operator <<(std::ostream& o, const MyClass& MC1);//�������� ������ �� �����
    friend std::istream& operator >>(std::istream& i, MyClass& MC1);//�������� �����
    int is_empty() { return this == nullptr; }
};