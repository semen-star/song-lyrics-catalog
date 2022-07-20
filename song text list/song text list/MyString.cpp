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
    cin.getline(buf, 255, '\n');//ввод строки не больше заданной длины
    delete[]s; s = new char[strlen(buf)];
    strcpy(s, buf);
    //cin.getline(s,len);
    return 1;
}
void MyString::assign(const MyString& MS1)
{
    if (this == &MS1)//проверка на присваивание себя себе же
        return;
    len = MS1.len;
    delete[]s;//освобождение памяти
    s = new char[len + 1];//выдление памяти
    strcpy(s, MS1.s);//копирование
}
int MyString::ToInt()
{
    int n = 0, i = 0; bool t = false;
    if (s[i] == '-')//проверка на знак
    {
        t = true;
        i++;
    }
    for (; i < len; i++)
    {
        if (!(isdigit(s[i])))//не число - возврат с ошибкой
            return NotTrue;
        n = (n + i) * 10;
    }
    if (t)
        return -n / 10;//если отрицательное
    else
        return n / 10;//если положительное
}
char* MyString::ToAChar()
{
    char* t = new char[len + 1];//выделение памяти
    strcpy(t, s);//копирование
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
    if (s[i] == '-')//проверка на знак
    {
        t = true;
        i++;
    }
    for (; i < len; i++)
    {
        if (!(isdigit(s[i])) && s[i] != separator)//если не число и не разделитель - возврат с ошибкой
            return NotTrue;
        if (s[i] == separator && i > t)//если разделитель и разделитель не после знака
        {
            INT = FLOAT;
            FLOAT = 0;
            count++;
            del = pow(10, len - i);
            if (count == 2)//если разделителей больше 1 - возврат с ошибкой
                return NotTrue;
        }
        FLOAT = (FLOAT + i) * 10;
    }
    double n = INT + double(FLOAT) / del;//суммирование дробной и целой частей
    if (t)
        return -n / 10;//отрицательное
    else
        return n / 10;//положительно
}
int MyString::cmp(const MyString& MS1)
{
    return strcmp(s, MS1.s);
}
int MyString::cmp_with_len(const MyString& MS1)
{
    //сравнение кол-ва символов
    if (len != MS1.len)
        return len - MS1.len;
    return strcmp(s, MS1.s);//сравнение строк
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
    fprintf(fp, "%d\n", len);//запись кол-ва символов в строке
    int i = fputs(s, fp); char endline = '\n';//запись строки
    fprintf(fp, "%c", endline);//переход на новую строку
    return i;
}
int MyString::read(FILE* fp)
{
    if (fscanf(fp, "%d\n", &len) == EOF)//чтение кол-ва символов строки
        return EOF;//если конец фаула то выход
    if (*s != '\0')
        delete[]s;//если не пустая строка - освобождение памяти
    s = new char[len + 1];//выделение новой памяти
    if (fgets(s, len + 1, fp) != nullptr)//чтение
        return len;
    return EOF;
}
void MyString::resize(int n)
{
    if (len + n <= 0)//если размер будет 0 или меньше, то:
    {
        delete[]s;
        s = nullptr;
        return;
    }
    char* tmp = s;//сохранение строки
    s = new char[len + n + 1];//выделение новой памяти
    strcpy(s, tmp);//копирование
    delete[]tmp; len += n;//освобождение памяти и изменение длины
}
MyString& MyString::operator+=(const MyString& MS1)
{
    //конкатинация
    resize(MS1.len);
    strcpy(&s[len - MS1.len], MS1.s);
    return *this;
}
MyString operator+(const MyString& MS1, const MyString& MS2)
{
    //конкатинация
    MyString tmp(MS1);
    return tmp += MS2;
}
MyString& MyString::operator =(const MyString& MS1)
{
    //присваивание
    assign(MS1);
    return *this;
}
std::istream& operator>>(std::istream& i, MyString& MS1)
{
    //ввод с клавиатуры
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
    resize(f);//выделение памяти под присоединение
    strcpy(&s[len - f], t);//присоединение
    return *this;
}
MyString operator +(const MyString& MS1, const char* t)
{
    MyString tmp(MS1);//создание объекта
    return tmp += t;//присоединение
}
MyString* MyString::Concate(char* t)
{
    MyString* tmp = new MyString(s);//создание объекта
    *tmp += t;//конкатинация
    return tmp;
}