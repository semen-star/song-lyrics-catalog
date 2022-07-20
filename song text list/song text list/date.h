#pragma once
#include "Class_MyString.h"
class date
{
    short day, month, year;
    int* adtoi(const char* D, const char separator);//�������, �������������� ������ � ����� �����
    const static int daytap[2][13];//������ ���-�� ���� � ������ ������ ������������� ��� ����������� ����(��������������)
    const static char* MonthName[13];//�������� �������
    const static char* DayName[8];//�������� ���� ������
public:
    static char get_separator(char* t);//�������, ���������� �������������� ����
    static int checkright(int day, int month = 1, int year = 1);//�������� ������������ ������
    date(int d, int m, int y);//����������� � �������
    date();//����������� �� ���������
    date(const char* D, const char separator);//����������� �� �������
    date(const date& d2);//����������� �����������
    void output(ostream& os = cout);//����� �� �����
    int input(int d, int m, int y);//���� ��������
    int input(const char* D, const char separator);//���� ���������
    void assign(const date& d1);//������������
    int input(istream& is);
    ~date();//����������
    int get_day() { return day; }//��������� ���
    int get_month() { return month; }//��������� ������
    int get_year() { return year; }//��������� ����
    int validate();//�������� ������������ ������
    void set_day(int d);//������ ���
    void set_month(int m);//������ ������
    void set_year(int y);//������ ����
    void Add_days(int days);//���������� ����
    void Add_monthes(int monthes);//���������� �������
    void Add_years(int years);//���������� �����
    static int days_from_year(int y, int d, int m);//���-�� ���� � ������ ����
    static date date_from_days(int d, int y);//������� ���� �� ���-�� ���� � ������ ����
    static int vis(int y)//���������� ��?
    {
        if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
            return 1;
        return 0;
    }
    char* ToPChar(const char separator = '.');//���� � ������
    static date* newdate(char* date);//������ � ����
    int equal(const date& d1);//�������� �� ��������
    int cmp(const date& d1);//���������
    void day_month(int d, int y, int* m, int* dd);//���������� ���� � ���-�� ���� � ������ ���� � ����
    static int between(const date& d1, const date& d2);//������� ����� ����� ������
    date& operator = (char* d1);//������������ �� ������ � ����
    int operator <= (const date& d1) { return cmp(d1) <= 0; }//< ��� =?
    int operator >= (const date& d1) { return cmp(d1) >= 0; }//> ��� =?
    int operator > (const date& d1) { return cmp(d1) > 0; }//>?
    int operator < (const date& d1) { return cmp(d1) < 0; }//<?
    date& operator ++() { Add_days(1); return *this; }//���������� ���� �� 1 ����
    date& operator --() { Add_days(-1); return *this; }//���������� ���� �� 1 ����
    date& operator +=(int d) { Add_days(d); return *this; }//���������� ���� �� d ����
    date& operator -=(int d) { Add_days(-d); return *this; }//���������� ���� �� d ����
    friend date operator +(const date& d1, int d);//���������� ���� d1 �� d ����
    friend date operator -(const date& d1, int d);//���������� ���� d1 �� d ����
    date* copy() { return new date(*this); }
    MyString ToMyString()const { return MyString("date"); }
    void dispose() { if (this != nullptr) this->~date(); }
    friend std::istream& operator>>(std::istream& i, date& d1);//���� ���� � ����������
    friend std::ostream& operator<<(std::ostream& o, const date& d1) { return o << "Date: " << d1.day << '.' << d1.month << '.' << d1.year; }//����� �� ����
};