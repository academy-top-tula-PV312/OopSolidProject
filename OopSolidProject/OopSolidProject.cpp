#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <fstream>
#include <algorithm>

class IPrinter
{
public:
    virtual void Print(std::string message) = 0;
};

class Employee
{
    std::string name;
    int age;
    IPrinter* printer = nullptr;
public:
    std::string& Name() { return name; }
    int& Age() { return age; }
    IPrinter*& Printer() { return printer; }

    void Info()
    {
        if (printer)
            printer->Print(this->ToString());
    }

    std::string ToString() 
    {
        return "Name: " + name + ", Age: " + std::to_string(age);
    }
};


class ConsolePrinter : public IPrinter
{
public:
    void Print(std::string message) override
    {
        std::cout << message << "\n";
    }
};

int main()
{
    Employee* bob = new Employee();
    bob->Name() = "Bobby";
    bob->Age() = 29;
    bob->Printer() = new ConsolePrinter();
    bob->Info();

    //std::cout << bob->ToString() << "\n";
}
 

