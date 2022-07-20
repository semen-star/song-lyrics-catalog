#pragma once
#include <iostream>
#define NotTrue -842150451
using namespace std;
class MyString {
    char* s;
    int len;
public:
    char* start() { return s; }//возврат указателя на начальный элемент
    MyString();//конструктор по умолчанию
    //MyString(char[]) { s = new char[len]; }
    MyString(const char* S1);//конструктор с параметром
    MyString(const MyString& MS1);//конструктор копирования
    ~MyString();//деструктор
    void assign(const MyString& MS1);//присваивание
    void dispose();//освобождение памяти
    MyString* copy();//копирование
    int getlens() { return len; }//возврат длины строки
    //int getlens()const { return len; }
    int input();//ввод с клавиатуры
    int write(FILE* fp);//запись в файл
    int read(FILE* fp);//чтение из файла
    //int readtext(TextBox* t);
    char* ToAChar();//из строки в массив символов
    int ToInt();//в int
    double ToDouble(const char separator = '.');//в вещественное число
    //String* ToString();
    void output();//вывод на экран
    int cmp(const MyString& MS1);//сравнение текущей строки с переданной
    bool equal(const MyString& MS1);//сравнение на равенство
    MyString* Concate(const MyString& MS1);//соединение текущей строки и переданной
    MyString* Concate(char* t);//соединение текущей строки и массива символов
    int cmp_with_len(const MyString& MS1);//сравнение строк по символам и длине
    void resize(int n);//изменение размера
    MyString& operator =(const MyString& MS1);//оператор присваивания
    bool operator ==(const MyString& MS1) { return cmp(MS1) == 0; }//оператор сравнения
    bool operator >=(const MyString& MS1) { return cmp(MS1) >= 0; }//больше или равно?
    bool operator <=(const MyString& MS1) { return cmp(MS1) <= 0; }//меньше или равно?
    bool operator <(const MyString& MS1) { return cmp(MS1) < 0; }//меньше?
    bool operator >(const MyString& MS1) { return cmp(MS1) > 0; }//больше?
    MyString& operator +=(const MyString& MS1);//оператор присоединения строки
    MyString& operator +=(const char* t);//оператор присоединения массива символов
    friend MyString operator +(const MyString& MS1, const MyString& MS2);//оператор соединения двух строк
    friend MyString operator +(const MyString& MS1, const char* t);//оператор соединения строки и массива символов
    friend std::istream& operator>>(std::istream& i, MyString& MS1);//ввод с клавиатуры
    friend std::ostream& operator<<(std::ostream& o, const MyString& MS1) { return o << MS1.s; }//вывод на экран
};