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
        cout << "\nВведите фамилию: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].F, 56);

        cout << "\nВведите имя: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].I, 32);

        cout << "\nВведите отчество: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].O, 48);

        cout << "\nВведите пол:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].gender, 10);

        cout << "\nВведите национальность:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].nat, 10);

        cout << "\nВведите рост:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].height;

        cout << "\nВведите вес:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].weight;

        do
        {
            cout << "\nВведите дату рождения: ";
            cin.ignore(std::cin.rdbuf()->in_avail());
            cin >> SStudent[i].bith.day >> SStudent[i].bith.month >> SStudent[i].bith.year;
        } while (!SStudent[i].bith.isCorrect());

        cout << "\nВведите постовый индекс:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].postcode;

        cout << "\nВведите страну: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].country, 56);

        cout << "\nВведите область: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].region, 56);

        cout << "\nВведите район: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].area, 56);

        cout << "\nВведите город: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].town, 56);

        cout << "\nВведите улицу: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].street, 56);

        cout << "\nВведите дом:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].house;

        cout << "\nВведите квартиру:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].apartment;

        cout << "\nВведите университет: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].university, 256);

        cout << "\nВведите специальность: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(SStudent[i].specialty, 256);

        cout << "\nВведите курс:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].course;

        cout << "\nВведите группу:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> SStudent[i].group;

        cout << "\nВведите средний бал:";
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
                out << "\nСтудент:" << SStudent[i].F << " " << SStudent[i].I << " " << SStudent[i].O;
                out << "\nДата рождения: " << SStudent[i].bith.day << "." << SStudent[i].bith.month << "." << SStudent[i].bith.year;
                out << "\nПол: " << SStudent[i].gender;
                out << "\nНациональность: " << SStudent[i].nat;
                out << "\nРост:" << SStudent[i].height;
                out << "\nВес: " << SStudent[i].weight;
                out << "\nНомер телефона: " << SStudent[i].Phone_number;
                out << "\nПочтовый индекс: " << SStudent[i].postcode;
                out << "\nСтрана: " << SStudent[i].country;
                out << "\nОбласть: " << SStudent[i].region;
                out << "\nРайон: " << SStudent[i].area;
                out << "\nГород: " << SStudent[i].town;
                out << "\nУлица: " << SStudent[i].street;
                out << "\nДом: " << SStudent[i].house;
                out << "\nКвартира: " << SStudent[i].apartment;
                out << "\nУниверситет: " << SStudent[i].university;
                out << "\nСпециальность: " << SStudent[i].specialty;
                out << "\nКурс: " << SStudent[i].course;
                out << "\nГруппа: " << SStudent[i].group;
                out << "\nСредний бал : " << SStudent[i].ball_average << endl;
            }
        }
        cout << "End of program" << endl;
        return 0;
    }
}


