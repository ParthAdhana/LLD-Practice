#include<iostream>
using namespace std;


class IPriceStratergy
{
    public:
    virtual double StratergyPrice(double orignalPrice)=0;
    virtual ~IPriceStratergy()=default;
};
class DiscountStratergy : public IPriceStratergy
{
    public:
    double  StratergyPrice(double orignalPrice) override
    {
        return 0.8*orignalPrice;
    }
};
class SurgeStratergy : public IPriceStratergy
{
    public:
    double StratergyPrice(double orignalPrice) override
    {
        return 1.2*orignalPrice;
    }
};
class DefaultStratergy : public IPriceStratergy
{
    public:
    double StratergyPrice(double originalPrice) override
    {
        return originalPrice;
    }
};
class PriceStratergyFactory
{

    public:
        static IPriceStratergy* PriceStratergy(string stgType)
        {
            if(stgType=="Discount")
            {
                return new DiscountStratergy();
            }
            else if(stgType == "Surge")
            {
                return new SurgeStratergy();
            }
            else{
                return new DefaultStratergy();
            }
        }
};
class Order
{
    private :
        double price;
        IPriceStratergy *stg;

    public:
        Order(double price,IPriceStratergy* stg)
        {
            this->price=price;
            this->stg=stg;
        }
        double OrderPrice()
        {
            return stg->StratergyPrice(price);
        }
};
int main()
{
    IPriceStratergy* priceStg=PriceStratergyFactory::PriceStratergy("Discount");
    Order order(3000,priceStg);
    cout<<order.OrderPrice();
    
}