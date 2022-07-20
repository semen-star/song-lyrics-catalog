#pragma once
#include "MyClass.h"
class MyVector {
    MyClass* mass;
    int curr;
public:
    MyVector() { curr = 1; mass = new MyClass; }//����������� ��-���������
    MyVector(int sz);//����������� � ����������
    MyVector(const MyClass& mass1);//����������� � ����������
    MyVector(const MyVector& vec1);//����������� �����������
    ~MyVector();//����������
    MyClass* first() { return mass; }//��������� �� ������ �������
    MyClass* last() { return mass + curr - 1; }//��������� �� ��������� �������
    int getMylen() { return curr; }//������� ���� �����
    MyClass& get_item(int n);//��������� ������� � ��������
    MyVector* copy();//�����������
    int read(FILE* fp, int car = 0);//������ �� ����� � ������� ������� � car-�����
    int write(FILE* fp, int cur = -1);//������ � ���� �� cur-�������
    void assign(const MyVector& vec1);// ������������
    void output(ostream& os = cout)const;//����� �� ����� �� cur-��������
    int input(istream& is = cin);//���� �����������
    friend ostream& operator<<(ostream& os, const MyVector& mv1) { mv1.output(os); return os; }
    friend istream& operator>>(istream& is, MyVector& mv1) { mv1.input(is); return is; }
    //void sort();//����������
    int cmp(const MyVector& vec2);
    int equal(const MyVector& vec2);
    int dispose(int n, int cur = -1);//������������ ������ �� ��� n-�� ��������, �� �������� cur
    int remove(const MyClass& MS1, int cur = -1);//�������� ���� ����� �������� (���� �� cur-�� ��������)
    int find(const MyClass& MS1, int cur = -1);//����� ������� ������ �������� (����� ��� �� cur-�� ��������)
    int change_at(int n, const MyClass& MS2, int cur = -1);//������� �������� �� ������� n, �� n < cur
    int change_all(const MyClass& MS1, const MyClass& MS2, int cur = -1);//������ ���� ����� �� ������ �������� (����� ��� �� cur-�� ��������)
    void resize(int n);//��������� �������
    MyClass& operator[](int i);//�������� ������� � ��������
    MyString ToMyString()const { return MyString("MyVector"); };
    void dispose() { if (this != nullptr) this->~MyVector(); }
    MyVector& operator = (const MyVector& mo2) { assign(mo2); return *this; }
    int operator == (const MyVector& mo2) { return cmp(mo2) == 0; }//��������� �� ���������
    int operator != (const MyVector& mo2) { return cmp(mo2) != 0; }//��������� �� �����������
};