#include <iostream>
// SOLID

//S
//Bad
// 
//class Report
//{
//    std::string text;
//public:
//    std::string& Text() { return text; }
//    void GotoFirstPage()
//    {
//        std::cout << "Go to first page of report";
//    }
//
//    void GotoLastPage()
//    {
//        std::cout << "Go to last page of report";
//    }
//
//    void Gotoage(int page)
//    {
//        std::cout << "Go to " << page << " page of report";
//    }
//
//    void Print()
//    {
//        std::cout << "Print of report:\n";
//        std::cout << text << "\n";
//    }
//};

//Good
class Report
{
    std::string text;
public:
    std::string& Text() { return text; }
    void GotoFirstPage()
    {
        std::cout << "Go to first page of report";
    }

    void GotoLastPage()
    {
        std::cout << "Go to last page of report";
    }

    void Gotoage(int page)
    {
        std::cout << "Go to " << page << " page of report";
    }
};

class Printer
{
public:
    void ConsolePrint(Report report)
    {
        std::cout << "Print of report:\n";
        std::cout << report.Text() << "\n";
    }
};