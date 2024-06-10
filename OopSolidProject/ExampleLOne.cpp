#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <fstream>

class Rectangle
{
protected:
    int width;
    int height;
public:
    int Width() { return width; }
    int Height() { return height; }

    virtual void SetWidth(int width)
    {
        this->width = width;
    }

    virtual void SetHeight(int height)
    {
        this->height = height;
    }

    int Area()
    {
        return width * height;
    }
};

class Square : public Rectangle
{
public:
    void SetWidth(int width) override
    {
        this->width = width;
        this->height = width;
    }

    void SetHeight(int height) override
    {
        this->width = height;
        this->height = height;
    }
};

void TestRectangleArea(Rectangle* rect, int w, int h, int testResult)
{
    rect->SetWidth(w);
    rect->SetHeight(h);
    if (rect->Area() != testResult)
        std::cout << "ERROR: area " << rect->Area()
        << " not equals test result "
        << testResult << "\n";
    else
        std::cout << "OK: area equals test result\n";

}

void ExampleL()
{
    TestRectangleArea(new Rectangle(), 20, 40, 800);
    TestRectangleArea(new Square(), 20, 40, 800);
}