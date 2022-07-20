#pragma once
#include <iostream>
#define NotTrue -842150451
using namespace std;
class MyString {
    char* s;
    int len;
public:
    char* start() { return s; }//������� ��������� �� ��������� �������
    MyString();//����������� �� ���������
    //MyString(char[]) { s = new char[len]; }
    MyString(const char* S1);//����������� � ����������
    MyString(const MyString& MS1);//����������� �����������
    ~MyString();//����������
    void assign(const MyString& MS1);//������������
    void dispose();//������������ ������
    MyString* copy();//�����������
    int getlens() { return len; }//������� ����� ������
    //int getlens()const { return len; }
    int input();//���� � ����������
    int write(FILE* fp);//������ � ����
    int read(FILE* fp);//������ �� �����
    //int readtext(TextBox* t);
    char* ToAChar();//�� ������ � ������ ��������
    int ToInt();//� int
    double ToDouble(const char separator = '.');//� ������������ �����
    //String* ToString();
    void output();//����� �� �����
    int cmp(const MyString& MS1);//��������� ������� ������ � ����������
    bool equal(const MyString& MS1);//��������� �� ���������
    MyString* Concate(const MyString& MS1);//���������� ������� ������ � ����������
    MyString* Concate(char* t);//���������� ������� ������ � ������� ��������
    int cmp_with_len(const MyString& MS1);//��������� ����� �� �������� � �����
    void resize(int n);//��������� �������
    MyString& operator =(const MyString& MS1);//�������� ������������
    bool operator ==(const MyString& MS1) { return cmp(MS1) == 0; }//�������� ���������
    bool operator >=(const MyString& MS1) { return cmp(MS1) >= 0; }//������ ��� �����?
    bool operator <=(const MyString& MS1) { return cmp(MS1) <= 0; }//������ ��� �����?
    bool operator <(const MyString& MS1) { return cmp(MS1) < 0; }//������?
    bool operator >(const MyString& MS1) { return cmp(MS1) > 0; }//������?
    MyString& operator +=(const MyString& MS1);//�������� ������������� ������
    MyString& operator +=(const char* t);//�������� ������������� ������� ��������
    friend MyString operator +(const MyString& MS1, const MyString& MS2);//�������� ���������� ���� �����
    friend MyString operator +(const MyString& MS1, const char* t);//�������� ���������� ������ � ������� ��������
    friend std::istream& operator>>(std::istream& i, MyString& MS1);//���� � ����������
    friend std::ostream& operator<<(std::ostream& o, const MyString& MS1) { return o << MS1.s; }//����� �� �����
};