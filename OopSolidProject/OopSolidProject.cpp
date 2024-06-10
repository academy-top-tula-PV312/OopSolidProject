#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <fstream>
#include <algorithm>

//Predconditions:
// 
//void funcPred(int value)
//{
//    if (value < 0)
//        throw new std::exception();
//
//    std::cout << value;
//}

// Postconditions
//
//int funcPost(std::vector<int> numbers)
//{
//    if (numbers.size() == 0)
//        throw new std::exception("size of vector is zero");
//
//    int sum = 0;
//    std::for_each(std::begin(numbers),
//                std::end(numbers),
//                [](auto item) {
//                    sum += item;
//                });
//
//    if (sum < 0)
//        throw new std::exception("result is negative");
//
//    return sum;
//}


class Account
{
protected:
    int amount;
public:
    int Amount() { return amount; }
    virtual void SetAmount(int amount)
    {
        if (amount < 0)
            throw new std::exception("amount negative!");
        this->amount = amount;
    }

    virtual int GetInterest(int month, int rate)
    {
        if (month < 1 || month > 12 || rate < 0)
            throw new std::exception("incorrect input date");

        int sum = this->amount;
        for (int i{}; i < month; i++)
            sum += sum * rate / 100;

        if (this->amount >= 10000)
            sum += 1000;

        this->amount = sum;

        return sum;
    }
};

class MicroAccount : public Account
{
public:
    void SetAmount(int amount) override
    {
        if (amount < 0)
            throw new std::exception("amount negative!");
        /*if (amount > 1000)
            throw new std::exception("amount more than 1000!");*/
        this->amount = amount;
    }

    int GetInterest(int month, int rate) override
    {
        if (month < 1 || month > 12 || rate < 0)
            throw new std::exception("incorrect input date");

        int sum = this->amount;
        for (int i{}; i < month; i++)
            sum += sum * rate / 100;

        this->amount = sum;

        return sum;
    }
};

void InitAmount(Account* account)
{
    try
    {
        account->SetAmount(15000);
    }
    catch (std::exception* ex)
    {
        throw ex;
    }
}

void CalculateInterest(Account* account, int testResult)
{
    int sum = account->GetInterest(1, 10);
    if (sum != testResult)
        std::cout << "Error! " << sum << " != " << testResult << "\n";
    else
        std::cout << "Ok\n";
}

int main()
{
    try
    {
        Account* account = new MicroAccount();
        InitAmount(account);
        //std::cout << account->GetInterest(1, 10);
        CalculateInterest(account, 17500);
    }
    catch (std::exception* ex)
    {
        std::cerr << ex->what() << "\n";
    }
    
}
 

