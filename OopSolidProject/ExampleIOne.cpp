# include <iostream>

/*
class IMessage
{
    std::string subject;
    std::string text;
    std::string toAddress;
    std::string fromAddress;
public:
    virtual std::string& Subject() { return subject; }
    virtual std::string& Text() { return text; }
    virtual std::string& ToAddress() { return toAddress; }
    virtual std::string& FromAddress() { return fromAddress; }

    virtual void Send() = 0;
};

class EmailMessage : public IMessage
{
public:
    void Send() override
    {
        std::cout << "From: " << FromAddress() << "\n";
        std::cout << "To: " << ToAddress() << "\n";
        std::cout << "Subject: " << Subject() << "\n";
        std::cout << "Text of message: " << Text() << "\n";
        std::cout << "\nMessage send!\n";

    }
};

class SmsMessage : public IMessage
{
public:
    std::string& Subject() override {}

    void Send() override
    {
        std::cout << "From: " << FromAddress() << "\n";
        std::cout << "To: " << ToAddress() << "\n";
        std::cout << "Text of message: " << Text() << "\n";
        std::cout << "\Sms send!\n";
    }
};

class VoiseMessage : public IMessage
{
    int* voiseBuffer = new int;
public:
    std::string& Subject() override {}
    std::string& Text() override {}

    int* VoiseBuffer() { return voiseBuffer; }
};
*/

class IMessage
{
    std::string toAddress;
    std::string fromAddress;
public:
    virtual std::string& ToAddress() { return toAddress; }
    virtual std::string& FromAddress() { return fromAddress; }

    virtual void Send() = 0;
};

class ITextMessage : public IMessage
{
    std::string text;
public:
    virtual std::string& Text() { return text; }
};

class IVoiceMessage : public IMessage
{
    int* voiceBuffer;
public:
    virtual int* VoiseBuffer() { return voiceBuffer; }
};

class IEmailMessage : public ITextMessage
{
    std::string subject;
public:
    virtual std::string& Subject() { return subject; }
};

class EmailMessage : public IEmailMessage
{
public:
    void Send() override
    {
        std::cout << "From: " << FromAddress() << "\n";
        std::cout << "To: " << ToAddress() << "\n";
        std::cout << "Subject: " << Subject() << "\n";
        std::cout << "Text of message: " << Text() << "\n";
        std::cout << "\nMessage send!\n";

    }
};

class SmsMessage : public ITextMessage
{
public:
    void Send() override
    {
        std::cout << "From: " << FromAddress() << "\n";
        std::cout << "To: " << ToAddress() << "\n";
        std::cout << "Text of message: " << Text() << "\n";
        std::cout << "\Sms send!\n";
    }
};

class VoiceMessage : public IVoiceMessage
{
public:
    void Send() override
    {
        std::cout << "From: " << FromAddress() << "\n";
        std::cout << "To: " << ToAddress() << "\n";
        std::cout << "Voice: " << VoiseBuffer() << "\n";
        std::cout << "\Voice send!\n";
    }
};