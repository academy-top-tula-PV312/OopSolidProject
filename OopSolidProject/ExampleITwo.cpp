class IPhone
{
public:
    virtual void Call() = 0;
    virtual void TakePhoto() = 0;
    virtual void MakeVideo() = 0;
    virtual void InternetBrowser() = 0;
};




class ICall
{
public:
    virtual void Call() = 0;
};

class IPhoto
{
public:
    virtual void TakePhoto() = 0;
};
class IVideo
{
public:
    virtual void MakeVideo() = 0;
};

class IInternetBrowser
{
public:
    virtual void Browser() = 0;
};

class ICamera : public IPhoto, public IVideo
{

};