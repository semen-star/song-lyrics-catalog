#include "MyClass.h"
void MyClass::assign(const MyClass& MC1)
{
    if (this == &MC1)
        return;
    band.assign(MC1.band);//поэлементное присваивание
    singer.assign(MC1.singer);
    song.assign(MC1.song);
    email.assign(MC1.email);
    adress.assign(MC1.adress);
    Date.assign(MC1.Date);
    price = MC1.price;
    count = MC1.count;
}
MyClass* MyClass::copy()
{
    return new MyClass(*this);//создание динамической копии текущего объекта
}
int MyClass::input(istream& is)
{
    std::cout << "input band: ";
    is >> band;
    std::cout << "input singer: ";
    is >> singer;
    std::cout << "input song: ";
    is >> song;
    std::cout << "input email: ";
    is >> email;
    std::cout << "input adress: ";
    is >> adress;
    std::cout << "input count&price: ";
    is >> count >> price;
    std::cout << "input date: ";
    is >> Date;
    return 1;
}
void MyClass::output(ostream& os)
{
    os << "band: " << band;
    os << "\nsinger: " << singer;
    os << "\nsong: " << song;
    os << "\nemail: " << email;
    os << "\nadress: " << adress;
    os << '\n' << Date;
    os << "\nprice: " << price << "\ncount: " << count << '\n';
}
MyClass::MyClass(char* b, char* si, char* so, char* e, char* a, int c, double p, int d, int m, int y) :band(b), singer(si), song(so), email(e), adress(a), Date(d, m, y)
{
    count = c; price = p;
}
MyClass::MyClass(char* b, char* si, char* so, char* e, char* a, int c, double p, char* d, const char se) : band(b), singer(si), song(so), email(e), adress(a), Date(d, se)
{
    count = c; price = p;
}
MyClass::MyClass(const MyString& b, const MyString& si, const MyString& so, const MyString& e, const MyString& a, int c, double p, int d, int m, int y) : band(b), singer(si), song(so), email(e), adress(a), Date(d, m, y)
{
    count = c; price = p;
}
MyClass::MyClass(const MyString& b, const MyString& si, const MyString& so, const MyString& e, const MyString& a, int c, double p, char* d, const char se) : band(b), singer(si), song(so), email(e), adress(a), Date(d, se)
{
    count = c; price = p;
}
int MyClass::write(FILE* fp)
{
    band.write(fp);
    singer.write(fp);
    song.write(fp);
    email.write(fp);
    adress.write(fp);
    MyString(Date.ToPChar()).write(fp);
    return fprintf(fp, "price: %lf\ncount: %d", price, count);
}
#pragma warning(disable:4996)
int MyClass::read(FILE* fp)
{
    if (band.read(fp) == EOF)//проверка на конец файла
        return EOF;
    singer.read(fp);
    song.read(fp);
    email.read(fp);
    adress.read(fp);
    int t; fscanf(fp, "%d\n", &t);
    char* buf = new char[t + 1];
    fgets(buf, t + 1, fp); buf[t] = '\0';
    Date.input(buf, '.');
    delete[] buf;
    return fscanf(fp, "\nprice: %lf\ncount: %d\n", &price, &count);
}
int MyClass::cmp(const MyClass& MC1)
{
    int i;//поэлементное сравнение на равенство, если не равны, то возврат разницы (cmp)
    if ((i = band.cmp(MC1.band)) != 0)
        return i;
    if ((i = singer.cmp(MC1.singer)) != 0)
        return i;
    if ((i = song.cmp(MC1.song)) != 0)
        return i;
    if ((i = email.cmp(MC1.email)) != 0)
        return i;
    if ((i = adress.cmp(MC1.adress)) != 0)
        return i;
    if ((i = Date.cmp(MC1.Date)) != 0)
        return i;
    if (price != MC1.price)
        return price - MC1.price;
    if (count != MC1.count)
        return count - MC1.count;
    return 0;
}
MyClass& MyClass::operator =(const MyClass& MC1)
{
    assign(MC1);//присваивание
    return *this;
}
std::ostream& operator <<(std::ostream& o, const MyClass& MC1)
{
    o << "band: " << MC1.band << "\nsinger: " << MC1.singer << "\nsong: " << MC1.song << "\nemail: " << MC1.email;
    return o << "\nadress: " << MC1.adress << '\n' << MC1.Date << "\nprice: " << MC1.price << "\ncount: " << MC1.count << '\n';
}
std::istream& operator>>(std::istream& i, MyClass& MC1)
{
    std::cout << "input band: "; i >> MC1.band;
    std::cout << "input singer: "; i >> MC1.singer;
    std::cout << "input song: "; i >> MC1.song;
    std::cout << "input email: "; i >> MC1.email;
    std::cout << "input adress: "; i >> MC1.adress;
    std::cout << "input date: "; i >> MC1.Date;
    std::cout << "input price: "; i >> MC1.price;
    std::cout << "input count: "; i >> MC1.count;
    i.get();
    return i;
}