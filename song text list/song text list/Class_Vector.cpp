#include "Class_Vector.h"
MyVector::MyVector(const MyClass& mass1)
{
    curr = 1;
    mass = new MyClass(mass1);
}
MyVector::MyVector(int sz)
{
    curr = sz; mass = new MyClass[sz];
}
MyVector::MyVector(const MyVector& vec1)
{
    this->curr = vec1.curr;
    this->mass = new MyClass[curr];
    for (int i = 0; i < curr; i++)
        this->mass[i].assign(vec1.mass[i]);
}
MyVector::~MyVector()
{
    delete[] mass;
    mass = nullptr;
}
/*void MyVector::sort()//сортировка методом пузырька
{
    MyClass tmp;
    for (int i = 0; i < curr - 1; i++)
        for (int j = i + 1; j < curr - 1; j++)
            if (mass[i] > mass[j])
            {
                tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
}*/
MyVector* MyVector::copy()
{
    return new MyVector(*this);
}
void MyVector::assign(const MyVector& vec1)
{
    if (this == &vec1)//если присваивание самому себе - выход
        return;
    delete[]mass;
    curr = vec1.curr;
    mass = new MyClass[curr + 1];
    for (int i = 0; i < curr + 1; i++)
        mass[i].assign(vec1.mass[i]);
}
void MyVector::output(ostream& os)const
{
    for (int i = 0; i < curr; i++)
        os << mass[i] << '\n';
}
int MyVector::input(istream& is)
{
    int i = 0;
    for (; i < curr; i++)
    {
        is >> mass[i];
        if (cin.get() == '0')
        {
            cin.get();
            break;
        }
    }
    return i;
}
MyClass& MyVector::get_item(int n)
{
    if (n <= curr && n >= 0)
        return*(mass + n);
    std::cout << "Uncorrect index!";
    exit(2);
}
int MyVector::write(FILE* fp, int cur)
{
    int i;
    if (cur == -1)
        cur = curr;
    for (i = 0; i < cur - 1; i++)
    {
#pragma warning(disable:4996)
        mass[i].write(fp);
        fprintf(fp, "\n");
    }
    mass[i].write(fp);
    return i;
}
int MyVector::read(FILE* fp, int car)
{
    int o;
    for (; car < curr; car++)
    {
        o = mass[car].read(fp);
        if (o == EOF)
            break;
    }
    if (o == EOF)
        cout << "Succesfuly!\n";
    else
        cout << "Succes, but SMALL TAB!\nPlease expand tab to read all items from file.\n";
    return car;
}
int MyVector::dispose(int n, int cur)
{
    if (cur == -1)
        cur = curr;
    for (int i = n; i < curr - 1; i++)
        mass[i] = mass[i + 1];
    mass[curr - 1].assign(MyClass());
    return 1;
}
int MyVector::remove(const MyClass& MS1, int cur)
{
    if (cur == -1)
        cur = curr;
    int j = 0;
    for (int i = 0; i < cur; i++)
        if (!mass[i].equal(MS1))
            mass[j++].assign(mass[i]);
    for (; cur > j; cur--)
        mass[j].assign(MyClass());
    return curr - cur;
}
int MyVector::find(const MyClass& MS1, int cur)
{
    if (cur == -1)
        cur = curr;
    for (int i = 0; i < cur; i++)
        if (mass[i].equal(MS1))
            return i;
    return -1;
}
int MyVector::change_at(int n, const MyClass& MS2, int cur)
{
    if (cur == -1)
        cur = curr;
    if (n >= cur)
        return 0;
    mass[n].assign(MS2);
    return 1;
}
int MyVector::change_all(const MyClass& MS1, const MyClass& MS2, int cur)
{
    int count = 0;
    if (cur == -1)
        cur = curr;
    for (int i = 0; i < cur; i++)
        if (mass[i].equal(MS1))
        {
            mass[i].assign(MS2);
            count++;
        }
    return count;
}
void MyVector::resize(int n)
{
    MyClass* tmp = mass;
    mass = new MyClass[curr + n];
    for (int i = 0; i < curr; i++)
        mass[i].assign(tmp[i]);
    delete[] tmp; curr += n;
}
MyClass& MyVector::operator[](int i)
{
    return get_item(i);
}
int MyVector::cmp(const MyVector& vec2)
{
    int tmp;
    for (int i = 0; i < curr && i < vec2.curr; i++)
        if ((tmp = mass[i].cmp(vec2.mass[i])) != 0)
            return tmp;
    return curr - vec2.curr;
}
int MyVector::equal(const MyVector& vec2)
{
    return cmp(vec2) == 0;
}