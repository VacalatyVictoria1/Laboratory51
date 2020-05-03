#include <iostream>
#include <fstream>
#include<string>
#include<cstdlib>

using namespace std;

struct Date
{
    short day;
    short month;
    short  year;
    bool isCorrect();
};

bool Date::isCorrect()
{
    bool result = false;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if ((day <= 31) && (day > 0))
        {
            result = true;
            break;
        }
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if ((day <= 30) && (day > 0))
        {
            result = true;
            break;
        }
    }
    case 2:
    {
        if (year % 4 != 0)
        {
            if ((day <= 28) && (day > 0))
                result = true;
        }
        else
            if (year % 400 == 0)
            {
                if ((day <= 29) && (day > 0))
                    result = true;
            }
            else
                if ((year % 100 == 0) && (year % 400 != 0))
                {
                    if ((day == 28) && (day > 0))
                        result = true;
                }
                else
                    if ((year % 4 == 0) && (year % 100 != 0))
                        if ((day <= 29) && (day > 0))
                            result = true;
        break;
    }
    default:
        result = false;
    }
    return result;
}

struct Base
{
    char F[56];
    char I[56];
    char O[56];
    char gender[10];
    char nat[56];
    unsigned int height;
    unsigned int weight;
    Date bith;
    unsigned int Phone_number;
    unsigned int postcode;
    char country[56];
    char region[56];
    char area[56];
    char town[56];
    char street[56];
    unsigned int house;
    unsigned int apartment;
    char university[256];
    unsigned int course;
    unsigned int group;
    double ball_average;
    char specialty[256];
};

int main()
{
    setlocale(LC_ALL, "Rus");
    const int N = 2;
    Base SStudent[N];
    for (int i = 0; i < N; i++)
    {
        cout << "\n������� �������: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].F, 56);

        cout << "\n������� ���: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].I, 32);

        cout << "\n������� ��������: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].O, 48);

        cout << "\n������� ���:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].gender, 10);

        cout << "\n������� ��������������:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].nat, 10);

        cout << "\n������� ����:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].height;

        cout << "\n������� ���:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].weight;

        do
        {
            cout << "\n������� ���� ��������: ";
            cin.ignore(std::cin.rdbuf()->in_avail());
            cin >> SStudent[i].bith.day >> SStudent[i].bith.month >> SStudent[i].bith.year;
        } while (!SStudent[i].bith.isCorrect());

        cout << "\n������� �������� ������:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].postcode;

        cout << "\n������� ������: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].country, 56);

        cout << "\n������� �������: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].region, 56);

        cout << "\n������� �����: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].area, 56);

        cout << "\n������� �����: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].town, 56);

        cout << "\n������� �����: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].street, 56);

        cout << "\n������� ���:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].house;

        cout << "\n������� ��������:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].apartment;

        cout << "\n������� �����������: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].university, 256);

        cout << "\n������� �������������: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].specialty, 256);

        cout << "\n������� ����:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].course;

        cout << "\n������� ������:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].group;

        cout << "\n������� ������� ���:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].ball_average;

        cin.clear();

    }
    cout << endl << endl << endl << endl;

    ofstream out;
    out.open("5.1.txt");

    for (int i = 0; i < N; i++)
    {
        if (70 <= SStudent[i].ball_average)
        {
            if (out.is_open())
            {
                out << "\n�������:" << SStudent[i].F << " " << SStudent[i].I << " " << SStudent[i].O;
                out << "\n���� ��������: " << SStudent[i].bith.day << "." << SStudent[i].bith.month << "." << SStudent[i].bith.year;
                out << "\n���: " << SStudent[i].gender;
                out << "\n��������������: " << SStudent[i].nat;
                out << "\n����:" << SStudent[i].height;
                out << "\n���: " << SStudent[i].weight;
                out << "\n����� ��������: " << SStudent[i].Phone_number;
                out << "\n�������� ������: " << SStudent[i].postcode;
                out << "\n������: " << SStudent[i].country;
                out << "\n�������: " << SStudent[i].region;
                out << "\n�����: " << SStudent[i].area;
                out << "\n�����: " << SStudent[i].town;
                out << "\n�����: " << SStudent[i].street;
                out << "\n���: " << SStudent[i].house;
                out << "\n��������: " << SStudent[i].apartment;
                out << "\n�����������: " << SStudent[i].university;
                out << "\n�������������: " << SStudent[i].specialty;
                out << "\n����: " << SStudent[i].course;
                out << "\n������: " << SStudent[i].group;
                out << "\n������� ��� : " << SStudent[i].ball_average << endl;
            }
        }
        cout << "End of program" << endl;
        return 0;
    }
}


