#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <fstream>

// O Open-closed
// Принцип открытости закрытости:
// Закрыт для изменений (модификации), открыт для расширения

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
//        std::cout << "чистим картошку\n";
//        std::cout << "ставим на огонь\n";
//        std::cout << "толчем отварной картофель\n";
//        std::cout << "добавляем масло и зелень\n";
//        std::cout << "картофельное пюре готово\n";
//    }
//};

// Extended with interface
class IDish
{
public:
    virtual void Make() = 0;
};

class СulinaryDish
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

    void MakeDinner(std::vector<СulinaryDish*> dinner)
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
        std::cout << "чистим картошку\n";
        std::cout << "ставим на огонь\n";
        std::cout << "толчем отварной картофель\n";
        std::cout << "добавляем масло и зелень\n";
        std::cout << "картофельное пюре готово\n\n";
    }
};

class SaladDish : public IDish
{
public:
    void Make() override
    {
        std::cout << "моем овощи\n";
        std::cout << "нарезаем овощи\n";
        std::cout << "смешиваем овощи\n";
        std::cout << "добавляем оливковое масло и зелень\n";
        std::cout << "салат готов\n\n";
    }
};


// Template abstract class


class PotateMashCulinary : public СulinaryDish
{
protected:
    void Prepare() override
    {
        std::cout << "чистим картошку\n";
    }

    void Cook() override
    {
        std::cout << "ставим на огонь\n";
        std::cout << "толчем отварной картофель\n";
    }

    void Final() override
    {
        std::cout << "добавляем масло и зелень\n";
        std::cout << "картофельное пюре готово\n\n";
    }
};

class SaladCulinary : public СulinaryDish
{
protected:
    void Prepare() override
    {
        std::cout << "моем овощи\n";
    }

    void Cook() override
    {
        std::cout << "нарезаем овощи\n";
        std::cout << "смешиваем овощи\n";
    }

    void Final() override
    {
        std::cout << "добавляем оливковое масло и зелень\n";
        std::cout << "салат готов\n\n";
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

    std::vector<СulinaryDish*> dinner;
    dinner.push_back(new PotateMashCulinary());
    dinner.push_back(new SaladCulinary());

    cook->MakeDinner(dinner);
}


