#pragma once
#include "MyClass.h"
class MyVector {
    MyClass* mass;
    int curr;
public:
    MyVector() { curr = 1; mass = new MyClass; }//конструктор по-умолчанию
    MyVector(int sz);//конструктор с параметром
    MyVector(const MyClass& mass1);//конструктор с параметром
    MyVector(const MyVector& vec1);//конструктор копирования
    ~MyVector();//деструктор
    MyClass* first() { return mass; }//указатель на первый элемент
    MyClass* last() { return mass + curr - 1; }//указатель на последний элемент
    int getMylen() { return curr; }//возврат макс длины
    MyClass& get_item(int n);//получение доступа к элементу
    MyVector* copy();//копирование
    int read(FILE* fp, int car = 0);//чтение из файла в таблицу начиная с car-места
    int write(FILE* fp, int cur = -1);//запись в файл по cur-элемент
    void assign(const MyVector& vec1);// присваивание
    void output(ostream& os = cout)const;//вывод на экран до cur-элемента
    int input(istream& is = cin);//ввод склавиатуры
    friend ostream& operator<<(ostream& os, const MyVector& mv1) { mv1.output(os); return os; }
    friend istream& operator>>(istream& is, MyVector& mv1) { mv1.input(is); return is; }
    //void sort();//сортировка
    int cmp(const MyVector& vec2);
    int equal(const MyVector& vec2);
    int dispose(int n, int cur = -1);//освобождение памяти из под n-го элемента, но меньшего cur
    int remove(const MyClass& MS1, int cur = -1);//удаление всех таких эементов (ищет до cur-го элемента)
    int find(const MyClass& MS1, int cur = -1);//поиск первого такого элемента (поиск идёт до cur-го элемента)
    int change_at(int n, const MyClass& MS2, int cur = -1);//замента элемента на позиции n, но n < cur
    int change_all(const MyClass& MS1, const MyClass& MS2, int cur = -1);//замена всех таких на другие элементы (поиск идёт до cur-го элемента)
    void resize(int n);//изменение размера
    MyClass& operator[](int i);//оператор доступа к элементу
    MyString ToMyString()const { return MyString("MyVector"); };
    void dispose() { if (this != nullptr) this->~MyVector(); }
    MyVector& operator = (const MyVector& mo2) { assign(mo2); return *this; }
    int operator == (const MyVector& mo2) { return cmp(mo2) == 0; }//сравнение на равенство
    int operator != (const MyVector& mo2) { return cmp(mo2) != 0; }//сравнение на неравенство
};