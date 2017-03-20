#include "Product.h"

Date::Date(int newYear, Month newMonth, int newDay)
    : year(newYear), eMonth(newMonth), day(newDay)
{
}

Product::Product( ProductType newProductType, 
                  double newPrice,
                  double newWeight,
                  const Date& expDate )

{
}

void Product::SetProductType(ProductType newProductType)
{
    eProductType = newProductType;
}

ProductType Product::GetProductType() const
{
    return eProductType;
}

void Product::SetPrice(double newPrice)
{
    price = newPrice;
}

double Product::GetPrice() const
{
    return price;
}

void Product::SetWeight(double newWeight)
{
    weight = newWeight;
}

double Product::GetWeight() const
{
    return weight;
}

void Product::SetExpDate(const Date& newExpDate)
{
    expiryDate = newExpDate;
}

Date Product::GetExpDate() const
{
    return expiryDate;
}
