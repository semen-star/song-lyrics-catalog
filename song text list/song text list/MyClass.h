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
    MyClass() :Date(), band(), singer(), song(), email(), adress() { price = count = -1; }//конструктор по-умолчанию
    MyClass(char*, char*, char*, char*, char*, int, double, int, int, int);//конструктор с параметрами
    MyClass(char*, char*, char*, char*, char*, int, double, char*, const char);//конструктор с параметрами
    MyClass(const MyString&, const MyString&, const MyString&, const MyString&, const MyString&, int, double, int, int, int);//конструктор с параметрами
    MyClass(const MyString&, const MyString&, const MyString&, const MyString&, const MyString&, int, double, char*, const char);//конструктор с параметрами
    MyClass(const MyClass& MC1) { this->assign(MC1); }//конструктор копирования
    ~MyClass() { ; }
    MyClass* copy();//копирование
    int read(FILE* fp);//чтение из файла
    int write(FILE* fp);//запись в файл
    void assign(const MyClass& MC1);//присваивание
    void output(ostream& os = cout);//вывод на экран
    int input(istream& is = cin);//ввод с клавиатуры
    int cmp(const MyClass& MC1);//поэлементное сравнение
    int equal(const MyClass& mo2) { return cmp(mo2) == 0; }
    void dispose() { if (this != nullptr)this->~MyClass(); }
    MyString ToMyString()const { return MyString("MyClass"); };
    MyClass& operator =(const MyClass& MS1);//оператор присваивания
    int operator ==(const MyClass& MS1) { return cmp(MS1) == 0; }//оператор сравнения на равенство
    int operator !=(const MyClass& MS1) { return cmp(MS1) != 0; }//оператор сравнения на неравенство
    int operator >=(const MyClass& MS1) { return cmp(MS1) >= 0; }//больше или равно?
    int operator <=(const MyClass& MS1) { return cmp(MS1) <= 0; }//меньше или равно?
    int operator <(const MyClass& MS1) { return cmp(MS1) < 0; }//меньше?
    int operator >(const MyClass& MS1) { return cmp(MS1) > 0; }//больше?
    friend std::ostream& operator <<(std::ostream& o, const MyClass& MC1);//оператор вывода на экран
    friend std::istream& operator >>(std::istream& i, MyClass& MC1);//оператор ввода
    int is_empty() { return this == nullptr; }
};