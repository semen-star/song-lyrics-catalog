#include "Class_date.h"
#pragma warning(disable: 4996)
const int date::daytap[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31} };
const char* date::MonthName[13] = { "Wrong","January","February","March","April","May","June","July","August","September","October","November","December" };
const char* date::DayName[8] = { "Wrong","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
date::date()
{
    day = month = year = 1;//���������� ��������� ��������
}
date::date(int d, int m, int y)
{//���������� ���������� ��������
    day = d;
    month = m;
    year = y;
}
date::date(const date& d2)
{//���������� �������� �� ������ ����
    day = d2.day;
    month = d2.month;
    year = d2.year;
}
int* date::adtoi(const char* D, const char separator)
{
    char buf[5] = {}; int j = 0, k = 0, * mass = new int[3];//��������� ����� ��� ��������, ������ ����� ���� � ������ ���������� �����
    for (int i = 0; D[i] != '\0' && j < 5; i++)
    {
        if (!isdigit(D[i]) && D[i] != separator)//�������� �� ����� ��� �����������
        {
            delete[] mass;
            return nullptr;
        }
        buf[j++] = D[i];
        if (D[i] == separator || D[i + 1] == '\0')//�������� �� ����� �����
        {
            j = 0;
            mass[k++] = atoi(buf);
        }
    }
    return mass;
}
date::date(const char* D, const char separator)
{
    if (separator == '\0')
        exit(3);
    int* mass = adtoi(D, separator);//����������� ������ � �����
    if (mass == nullptr)//���� ������ �� ����
    {
        day = month = year = 1;
    }
    else
    {//�����������
        if (checkright(mass[0], mass[1], mass[2]))//�������� �� ������������
        {
            day = *mass;
            month = mass[1];
            year = mass[2];
        }
    }//������������ ������������ �����
    delete[] mass;
}
int date::checkright(int day, int month, int year)//�������� ������������ ���䪪���� ������
{
    return year > 0 && month > 0 && month < 13 && day>0 && day <= daytap[vis(year)][month];
}
void date::output(ostream& os)//����� �� �����
{
    os << "Date:\n" << day << '.' << month << '.' << year << '\n';
}
int date::input(int d, int m, int y)
{//���������� ������������
    day = d;
    month = m;
    year = y;
    return 1;
}
int date::input(const char* D, const char separator)
{//���������� ������������
    int* mass = adtoi(D, separator);
    day = *mass;
    month = mass[1];
    year = mass[2];
    delete[] mass;
    return 1;
}
date::~date()
{//��� �������� ������������ �����
    ;
}
int date::validate()
{//�������� ������������ ������� ����
    return year > 0 && month > 0 && month < 13 && day>0 && day <= daytap[vis(year)][month];
}
void date::set_day(int d)
{//��������� ������ �� � �������� ������������
    int tmp = day;
    day = d;
    if (validate())
        return;
    day = tmp;
    std::cout << "Incorrect day!\nRepeat please.\n";
}
void date::set_month(int m)
{//��������� ������ ����� � �������� ������������
    int tmp = month;
    month = m;
    if (validate())
        return;
    month = tmp;
    std::cout << "Incorrect month!\nRepeat please.\n";
}
void date::set_year(int y)
{//��������� ������ ���� � �������� ������������
    int tmp = year;
    year = y;
    if (validate())
        return;
    year = tmp;
    std::cout << "Incorrect year!\nRepeat please.\n";
}
int date::cmp(const date& d1)
{
    if (year != d1.year)//���� �� ����� �� ������� �������
        return year - d1.year;
    if (day != d1.day)
        return day - d1.day;
    if (month != d1.month)
        return month - d1.month;
    return 0;//���� ����� �� 0
}
int date::equal(const date& d1)
{//�������� ���� ��� ����������� �� ���������
    return cmp(d1) == 0;
}
date* date::newdate(char* dat)
{
    //if (isdigit(dat[1]))//���� �� ��������� ��������� ��������� ����������
    //  return date(dat, dat[2]);
    return new date(dat, get_separator(dat));
}
void date::assign(const date& d1)//���������� �������� �� ���� d1 � ������� ����
{
    day = d1.day;
    month = d1.month;
    year = d1.year;
}
char* date::ToPChar(const char separator)//������� �� ����� � ������
{
    char d[3]{};
    itoa(day, d, 10);
    char m[3]{};
    itoa(month, m, 10);
    char y[4]{};
    itoa(year, y, 10); int cur;
    char* tmp = new char[strlen(m) + (cur = strlen(d)) + strlen(y) + 3];
    strcpy(tmp, d);
    tmp[cur++] = separator;
    strcpy(&tmp[cur], m); cur += strlen(m);
    tmp[cur++] = separator;
    strcpy(&tmp[cur], y);
    return tmp;
}
int date::days_from_year(int d, int m, int y)//�� ������
{
    int dd = d, ye = vis(y);
    while (--m)
        dd += daytap[ye][m];
    return dd;
}
void date::day_month(int d, int y, int* m, int* dd)//�� ������
{
    *m = 1; int ye = vis(y);
    while (d > daytap[y][*m])
        d -= daytap[ye][(*m)++];
    *dd = d;
    return;
}
void date::Add_days(int d)//�� ������
{
    if (d > 0)
        while (d--)
        {
            day++;
            if (day > daytap[vis(year)][month])
            {
                day = 1; month++;
                if (month > 12)
                {
                    month = 1;
                    year++;
                }
            }
        }
    else
        while (d++)
        {
            day--;
            if (!day)
            {
                month--;
                if (!month)
                {
                    year--;
                    if (!year)
                    {
                        year = month = day = 1;
                        break;
                    }
                    month = 12;
                }
                day = daytap[vis(year)][month];
            }
        }
}
void date::Add_monthes(int m)//�� ������
{
    if (m > 0)
        while (m--)
        {
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    else
        while (m++)
        {
            month--;
            if (!month)
            {
                year--;
                if (!year)
                {
                    year = month = day = 1;
                    break;
                }
                month = 12;
            }
        }
    if (day > daytap[vis(year)][month])
        day = daytap[vis(year)][month];
}
void date::Add_years(int y)//���������� ������
{
    year += y;
    if (year < 1)
    {
        year = month = day = 1;
    }
    if (day > daytap[vis(year)][month])
        day = daytap[vis(year)][month];
}
date date::date_from_days(int d, int y)
{
    int m = 1, ye = vis(y);
    if ((d > 365 && ye == 0) || d > 366)//������������ �������� ������
        return date();
    while (d > daytap[ye][m])//������� ������
    {
        d -= daytap[ye][m];
        m++;
    }
    return date(d, m, y);//������� ����� ����
}
int date::between(const date& d1, const date& d2)//�� ������
{
    int dd = 0;
    if (d1.year < d2.year)
    {
        vis(d1.year) ? dd += 366 : dd += 365;
        dd = dd - days_from_year(d1.day, d1.month, d1.year) + days_from_year(d2.day, d2.month, d2.year);
        int ye = d1.year + 1;
        while (ye++ < d2.year)
            vis(ye) ? dd += 366 : dd += 365;
    }
    else
    {
        vis(d2.year) ? dd += 366 : dd += 365;
        dd = dd - days_from_year(d2.day, d2.month, d2.year) + days_from_year(d1.day, d1.month, d1.year);
        int ye = d2.year + 1;
        while (ye++ < d1.year)
            vis(ye) ? dd += 366 : dd += 365;
    }
    return dd;
}
char date::get_separator(char* t)//���������� ��������������� �����
{
    for (int i = 0; t[i] != '\0'; i++)
        if (!isdigit(t[i]))
            return t[i];
    return '\0';
}
date& date::operator=(char* d1)//�������� ����������� �� ������ � ����
{
    char sep = get_separator(d1);
    int* t = adtoi(d1, sep);
    day = t[0]; month = t[1]; year = t[2];
    delete[] t;
    return *this;
}
date operator +(const date& d1, int d)//�������� ���������� d ���� � d1 ����
{
    date tmp = d1;
    return tmp += d;
}
date operator -(const date& d1, int d)//���������� ��������� +
{
    date tmp = d1;
    return tmp -= d;
}
std::istream& operator>>(std::istream& i, date& d1)//�������� ������������� �����
{
    i >> d1.day >> d1.month >> d1.year;
    i.get();
    return i;
}
int date::input(istream& is)
{
    is >> day >> month >> year;
    is.get();
    return 1;
}