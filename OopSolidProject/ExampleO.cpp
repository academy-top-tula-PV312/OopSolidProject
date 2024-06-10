#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <fstream>

// O Open-closed
// ������� ���������� ����������:
// ������ ��� ��������� (�����������), ������ ��� ����������

// Bad
//class Cook
//{
//    std::string name;
//public:
//    std::string& Name() { return name; }
//
//    Cook(std::string name) : name{ name } {};
//
//    void MakeDinner()
//    {
//        std::cout << "������ ��������\n";
//        std::cout << "������ �� �����\n";
//        std::cout << "������ �������� ���������\n";
//        std::cout << "��������� ����� � ������\n";
//        std::cout << "������������ ���� ������\n";
//    }
//};

// Extended with interface
class IDish
{
public:
    virtual void Make() = 0;
};

class �ulinaryDish
{
protected:
    virtual void Prepare() = 0;
    virtual void Cook() = 0;
    virtual void Final() = 0;
public:
    void Make()
    {
        Prepare();
        Cook();
        Final();
    }
};

class CookGood
{
    std::string name;
public:
    std::string& Name() { return name; }

    CookGood(std::string name) : name{ name } {};

    void MakeDish(IDish* dish)
    {
        dish->Make();
    }

    void MakeDinner(std::vector<�ulinaryDish*> dinner)
    {
        for (auto dish : dinner)
            dish->Make();
    }
};

class PotateMashDish : public IDish
{
public:
    void Make() override
    {
        std::cout << "������ ��������\n";
        std::cout << "������ �� �����\n";
        std::cout << "������ �������� ���������\n";
        std::cout << "��������� ����� � ������\n";
        std::cout << "������������ ���� ������\n\n";
    }
};

class SaladDish : public IDish
{
public:
    void Make() override
    {
        std::cout << "���� �����\n";
        std::cout << "�������� �����\n";
        std::cout << "��������� �����\n";
        std::cout << "��������� ��������� ����� � ������\n";
        std::cout << "����� �����\n\n";
    }
};


// Template abstract class


class PotateMashCulinary : public �ulinaryDish
{
protected:
    void Prepare() override
    {
        std::cout << "������ ��������\n";
    }

    void Cook() override
    {
        std::cout << "������ �� �����\n";
        std::cout << "������ �������� ���������\n";
    }

    void Final() override
    {
        std::cout << "��������� ����� � ������\n";
        std::cout << "������������ ���� ������\n\n";
    }
};

class SaladCulinary : public �ulinaryDish
{
protected:
    void Prepare() override
    {
        std::cout << "���� �����\n";
    }

    void Cook() override
    {
        std::cout << "�������� �����\n";
        std::cout << "��������� �����\n";
    }

    void Final() override
    {
        std::cout << "��������� ��������� ����� � ������\n";
        std::cout << "����� �����\n\n";
    }
};


void ExampleO()
{
    setlocale(LC_ALL, "Russian");
    std::vector<IDish*> dishes;
    dishes.push_back(new PotateMashDish());
    dishes.push_back(new SaladDish());

    CookGood* cook = new CookGood("Bobby");

    /*for (auto dish : dishes)
        cook->MakeDish(dish);*/

    std::vector<�ulinaryDish*> dinner;
    dinner.push_back(new PotateMashCulinary());
    dinner.push_back(new SaladCulinary());

    cook->MakeDinner(dinner);
}


