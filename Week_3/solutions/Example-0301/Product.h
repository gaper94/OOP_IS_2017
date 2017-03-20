#ifndef PRODUCT_H
#define PRODUCT_H

struct Date
{
    enum Month
    {
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };

    Date(int newYear = 1900, Month newMonth = January, int newDay = 1);

    int year;
    Month eMonth;
    int day;
};

enum ProductType
{
    None,
    Food,
    Drinks,
    Alcohol,
    Detergant,
};

class Product
{
public:
    Product( ProductType newProductType = None, 
             double newPrice = 0.0,
             double newWeight = 0.0,
             const Date& expDate = Date()
            );

    void SetProductType(ProductType);
    ProductType GetProductType() const;

    void SetPrice(double);
    double GetPrice() const;

    void SetWeight(double);
    double GetWeight() const;

    void SetExpDate(const Date&);
    Date GetExpDate() const;

private:
    ProductType eProductType;
    double price;
    double weight;
    Date expiryDate;
};

#endif // PRODUCT_H
