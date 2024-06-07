#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <fstream>

// SOLID

class Phone
{
    std::string model;
    int price;
public:
    std::string& Model() { return model; }
    int& Price() { return price; }

    Phone(std::string model, int price)
        : model{ model }, price{ price } {}
};

//Bad
/*
class PhonesStore
{
    std::vector<Phone> phones;
public:
    void Process()
    {
        std::string model;
        std::string price;

        // input data
        std::cout << "Input model: ";
        std::cin >> model;
        std::cout << "Input price: ";
        std::cin >> price;

        // validate
        int priceInt;
        try
        {
            priceInt = std::stoi(price);
        }
        catch (...)
        {
            throw new std::exception("Error with format price");
        }

        // create object
        Phone phone(model, priceInt);

        // save to file
        std::ofstream file;
        file.open("phones.txt", std::ios::app);
        file << phone.Model() << " " << phone.Price() << "\n";
        file.close();
    }

};
*/

class IPhoneReader
{
public:
    virtual std::vector<std::string> GetInputData() = 0;
};

class IPhoneCreater
{
public:
    virtual Phone* CreatePhone(std::vector<std::string> data) = 0;
};

class IPhoneValidator
{
public:
    virtual bool IsValid(Phone phone) = 0;
};

class IPhoneSaver
{
public:
    virtual void Save(Phone phone) = 0;
};

class PhonesStore
{
    std::vector<Phone> phones;
    
    IPhoneReader* reader;
    IPhoneValidator* validator;
    IPhoneCreater* creator;
    IPhoneSaver* saver;
public:
    PhonesStore(IPhoneReader* reader,
                IPhoneValidator* validator,
                IPhoneCreater* creator,
                IPhoneSaver* saver)
        : reader{ reader },
        validator{ validator },
        creator{ creator },
        saver{ saver } {};

    void Process()
    {
        std::vector<std::string> data = reader->GetInputData();

        Phone* phone;
        try
        {
            phone = creator->CreatePhone(data);
        }
        catch (std::exception ex)
        {
            std::cout << ex.what() << "\n";
            return;
        }

        if (validator->IsValid(*phone))
        {
            phones.push_back(*phone);
            saver->Save(*phone);
        }
        else
        {
            std::cout << "Incorrect phones info\n";
        }
        
    }
};


// Implemetations
class ConsolePhoneReader : public IPhoneReader
{
public:
    std::vector<std::string> GetInputData() override
    {
        std::string model;
        std::string price;

        // input data
        std::cout << "Input model: ";
        std::cin >> model;
        std::cout << "Input price: ";
        std::cin >> price;

        return std::vector<std::string>{ model, price };
    }
};

class GeneralPhoneCreater : public IPhoneCreater
{
public:
    Phone* CreatePhone(std::vector<std::string> data) override
    {
        std::string price = data[1];

        int priceInt;
        try
        {
            priceInt = std::stoi(price);
        }
        catch (...)
        {
            throw new std::exception("Error with format price");
        }

        // create object
        return new Phone(data[0], priceInt);
    }

    
};

class GeneralPhoneValidator : public IPhoneValidator
{
public:
    bool IsValid(Phone phone) override
    {
        return phone.Model() != "" && phone.Price() > 0;
    }
};

class FilePhoneSaver : public IPhoneSaver
{
    std::string fileName;
public:
    FilePhoneSaver(std::string fileName) : fileName{ fileName } {}

    void Save(Phone phone) override
    {
        std::ofstream file;
        file.open(fileName, std::ios::app);
        file << phone.Model() << " " << phone.Price() << "\n";
        file.close();
    }
};


int main()
{
    // S - Single Responsibility Principle
    // Принцип Единственной отвественности

    PhonesStore store(new ConsolePhoneReader(),
        new GeneralPhoneValidator(),
        new GeneralPhoneCreater(),
        new FilePhoneSaver("phones.txt"));

    for (int i{}; i < 2; i++)
        store.Process();

}
 

