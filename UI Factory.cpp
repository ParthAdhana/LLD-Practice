#include<iostream>
using namespace std;
class IButton
{
    public : 
    virtual void click()=0;
    virtual ~IButton()=default;
};
class ICheckBox
{
    public:
    virtual void click()=0;
    virtual ~ICheckBox()=default;
};
class WindowsButton: public IButton
{
    public:
    void click()
    {
        cout<<"Windows Button Clicked"<<endl;
    }
};
class MacButton : public IButton
{   
    public:
    void click()
    {
        cout<<"Mac Button Clicked"<<endl;
    }
};
class WindowsCheckBox : public ICheckBox
{
    public:
    void click()
    {
        cout<<"Windows Button Clicked"<<endl;
    }
};
class MacCheckBox: public ICheckBox
{
    public:
    void click()
    {
        cout<<"Mac CheckBox Clicked"<<endl;
    }
};
class IUIFactory{
    public:
    virtual IButton* createButton()=0; 
    virtual ICheckBox* createCheckBox()=0;
    virtual ~IUIFactory()=default;
    
};
class WindowsFactory: public IUIFactory{
    public: 
    IButton* createButton()
    {
        return new WindowsButton();
    }
    ICheckBox* createCheckBox()
    {
        return new WindowsCheckBox();
    }
};
class MacFactory : public IUIFactory{
    public: 
    IButton* createButton()
    {
        return new MacButton();
    }
    ICheckBox* createCheckBox()
    {
        return new MacCheckBox();
    }
};
int main()
{
    IUIFactory* factory = new WindowsFactory();
    IButton* button =factory->createButton();
    ICheckBox* checkbox=factory->createCheckBox();
    button->click();
    checkbox->click();
    delete(button);
    delete(checkbox);
}