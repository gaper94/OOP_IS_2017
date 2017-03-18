#define _CRT_SECURE_NO_WARNINGS // uncomment for warning C4996
#include <iostream>
#include <cstring>
using namespace std;

#if __cplusplus < 201103L
#define nullptr NULL
#endif

enum FuelType
{
    None,
    Petrol,
    Diesel,
    LPG,
    CNG,
};

class Car
{
public:
    Car( const char* newBrand = "",
         const char* newModel = "",
         size_t newProductionYear = 0,
         double newDisplacement = 0.0,
         double newMaxPower = 0.0,
         size_t newMileage = 0,
         FuelType newFuelType = None);

    void SetBrand(const char*);
    const char* GetBrand() const;

    void SetModel(const char*);
    const char* GetModel() const;

    void SetProductionYear(size_t);
    size_t GetProductionYear() const;

    void SetDisplacement(double);
    double GetDisplacement() const;

    void SetMaxPower(double);
    double GetMaxPower() const;

    void SetMileage(size_t);
    size_t GetMileage() const;

    void SetFuelType(FuelType);
    FuelType GetFuelType() const;

    bool IsNew() const;
    void AddMileage(size_t);
    void PrintInfo() const;

private:
    static const size_t txtFieldLength = 64;
    char brand[txtFieldLength + 1];
    char model[txtFieldLength + 1];
    size_t productionYear;
    double displacement;
    double maxPower;
    size_t mileage;
    FuelType eFuelType;
};

const size_t Car::txtFieldLength;

const char* GetFuelTypeName(FuelType eFuelType)
{
    switch (eFuelType)
    {
        case None: return "None";
        case Petrol: return "Petrol";
        case Diesel: return "Diesel";
        case LPG: return "LPG";
        case CNG: return "CNG";
        default: return "??????";
    }
}

Car::Car( const char* newBrand,
          const char* newModel,
          size_t newProductionYear,
          double newDisplacement,
          double newMaxPower,
          size_t newMileage,
          FuelType newFuelType)
{
    SetBrand(newBrand);
    SetModel(newModel);
    SetProductionYear(newProductionYear);
    SetDisplacement(newDisplacement);
    SetMaxPower(newMaxPower);
    SetMileage(newMileage);
    SetFuelType(newFuelType);
}

void Car::SetBrand(const char* newBrand)
{
    if (newBrand != nullptr)
    {
        size_t len = strlen(newBrand);
        if (len <= txtFieldLength)
        {
            strcpy(brand, newBrand);
        }
        else
        {
            cout << "Given buffer for brand is more than " << txtFieldLength << " charachters length!" << endl;
            memcpy(brand, newBrand, txtFieldLength);
            brand[txtFieldLength] = '\0';
        }
    }
    else
    {
        strcpy(brand, "");
    }
}

const char* Car::GetBrand() const
{
    return brand;
}

void Car::SetModel(const char* newModel)
{
    if (newModel != nullptr)
    {
        size_t len = strlen(newModel);
        if (len <= txtFieldLength)
        {
            strcpy(model, newModel);
        }
        else
        {
            cout << "Given buffer for model is more than " << txtFieldLength << " charachters length!" << endl;
            memcpy(model, newModel, txtFieldLength);
            model[txtFieldLength] = '\0';
        }
    }
    else
    {
        strcpy(model, "");
    }
}

const char* Car::GetModel() const
{
    return model;
}

void Car::SetProductionYear(size_t newProductionYear)
{
    productionYear = newProductionYear;
}

size_t Car::GetProductionYear() const
{
    return productionYear;
}

void Car::SetDisplacement(double newDisplacement)
{
    displacement = newDisplacement;
}

double Car::GetDisplacement() const
{
    return displacement;
}

void Car::SetMaxPower(double newMaxPower)
{
    maxPower = newMaxPower;
}

double Car::GetMaxPower() const
{
    return maxPower;
}

void Car::SetMileage(size_t newMileage)
{
    mileage = newMileage;
}

size_t Car::GetMileage() const
{
    return mileage;
}

void Car::SetFuelType(FuelType newFuelType)
{
    eFuelType = newFuelType;
}

FuelType Car::GetFuelType() const
{
    return eFuelType;
}

bool Car::IsNew() const
{
    return mileage == 0;
}

void Car::AddMileage(size_t newMileage)
{
    mileage += newMileage;
}

void Car::PrintInfo() const
{
    cout << "Car info:" << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Production year: " << productionYear << endl;
    cout << "Displacement: " << displacement << endl;
    cout << "Max Power: " << maxPower << endl;
    cout << "Mileage: " << mileage << endl;
    cout << "Fuel type: " << GetFuelTypeName(eFuelType) << endl;
}

Car newestCar(const Car* cars, size_t numberOfCars)
{
    int newest = 0;
    for (size_t i = 1; i < numberOfCars; i++)
    {
        if (cars[i].GetProductionYear() > cars[newest].GetProductionYear())
        {
            newest = i;
        }
    }
    return cars[newest];
}

Car mostPowerfulCar(const Car* cars, size_t numberOfCars)
{
    int power = 0;
    for (size_t i = 1; i < numberOfCars; i++)
    {
        if (cars[i].GetMaxPower() > cars[power].GetMaxPower())
        {
            power = i;
        }
    }
    return cars[power];
}

Car leastMileageCar(const Car* cars, size_t numberOfCars)
{
    int mileage = 0;
    for (size_t i = 1; i < numberOfCars; i++)
    {
        if (cars[i].GetMileage() < cars[mileage].GetMileage())
        {
            mileage = i;
        }
    }
    return cars[mileage];
}

void printInfoNewCars(const Car* cars, size_t numberOfCars)
{
    for (size_t i = 0; i < numberOfCars; i++)
    {
        if (cars[i].IsNew() == true)
        {
            cars[i].PrintInfo();
        }
    }
}


int main()
{
    Car Passat("VW", "Passat", 2008, 2000, 170, 186543, Diesel);
    Car E36("BMW", "328", 1996, 2800, 192, 245123, Petrol);
    Car GTR("Nissan", "GTR", 2007, 3600, 540, 23000, Petrol);
    Car Octvaia("Skoda", "Octavia", 2017, 2000, 140, 0, Diesel);

    Car cars[4];
    cars[0] = Passat;
    cars[1] = E36;
    cars[2] = GTR;
    cars[3] = Octvaia;
    cout << "Newest car: " << endl;
    newestCar(cars, 4).PrintInfo();
    cout << endl;
    cout << "Most powerful car: " << endl;
    mostPowerfulCar(cars, 4).PrintInfo();
    cout << endl;
    cout << "Least mileage car: " << endl;
    mostPowerfulCar(cars, 4).PrintInfo();
    cout << endl;
    cout << "Info only for new cars: " << endl;
    printInfoNewCars(cars, 4);
    return 0;
}
