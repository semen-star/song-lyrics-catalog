#pragma once
#include "Class_MyString.h"
class date
{
    short day, month, year;
    int* adtoi(const char* D, const char separator);//функция, конвертирующая строку в набор чисел
    const static int daytap[2][13];//массив кол-ва дней в каждом месяце невысокосного или высокосного года(соответственно)
    const static char* MonthName[13];//названия месяцев
    const static char* DayName[8];//название дней недели
public:
    static char get_separator(char* t);//функция, получающая разделительный знак
    static int checkright(int day, int month = 1, int year = 1);//проверка правильности данных
    date(int d, int m, int y);//конструктор с числами
    date();//конструктор по умолчанию
    date(const char* D, const char separator);//конструктор со строкой
    date(const date& d2);//конструктор копирования
    void output(ostream& os = cout);//вывод на экран
    int input(int d, int m, int y);//ввод числовой
    int input(const char* D, const char separator);//ввод строковой
    void assign(const date& d1);//присваивание
    int input(istream& is);
    ~date();//деструктор
    int get_day() { return day; }//получение дня
    int get_month() { return month; }//получение месяца
    int get_year() { return year; }//получение года
    int validate();//проверка правильности данных
    void set_day(int d);//замена дня
    void set_month(int m);//замена месяца
    void set_year(int y);//замена года
    void Add_days(int days);//добавление дней
    void Add_monthes(int monthes);//добавление месяцев
    void Add_years(int years);//добавление годов
    static int days_from_year(int y, int d, int m);//кол-во дней с начала года
    static date date_from_days(int d, int y);//возврат даты по кол-ву дней с начала года
    static int vis(int y)//высокосный ли?
    {
        if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
            return 1;
        return 0;
    }
    char* ToPChar(const char separator = '.');//дату в строку
    static date* newdate(char* date);//строку в дату
    int equal(const date& d1);//проверка на равность
    int cmp(const date& d1);//сравнение
    void day_month(int d, int y, int* m, int* dd);//првращение года и кол-ва дней с начала года в дату
    static int between(const date& d1, const date& d2);//разница между двумя датами
    date& operator = (char* d1);//присваивание из строки в дату
    int operator <= (const date& d1) { return cmp(d1) <= 0; }//< или =?
    int operator >= (const date& d1) { return cmp(d1) >= 0; }//> или =?
    int operator > (const date& d1) { return cmp(d1) > 0; }//>?
    int operator < (const date& d1) { return cmp(d1) < 0; }//<?
    date& operator ++() { Add_days(1); return *this; }//увеличение даты на 1 день
    date& operator --() { Add_days(-1); return *this; }//уменьшение даты на 1 день
    date& operator +=(int d) { Add_days(d); return *this; }//увеличение даты на d дней
    date& operator -=(int d) { Add_days(-d); return *this; }//уменьшение даты на d дней
    friend date operator +(const date& d1, int d);//увеличение даты d1 на d дней
    friend date operator -(const date& d1, int d);//уменьшение даты d1 на d дней
    date* copy() { return new date(*this); }
    MyString ToMyString()const { return MyString("date"); }
    void dispose() { if (this != nullptr) this->~date(); }
    friend std::istream& operator>>(std::istream& i, date& d1);//ввод даты с клавиатуры
    friend std::ostream& operator<<(std::ostream& o, const date& d1) { return o << "Date: " << d1.day << '.' << d1.month << '.' << d1.year; }//вывод на эран
};