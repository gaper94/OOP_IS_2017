#include "ServiceEntry.h"
#include <iostream>
using namespace std;

// Static members definition
size_t ServiceEntry::entryCounter = 0;

ServiceEntry::ServiceEntry( const String& newOwner,
                            const String& newLicensePlate,
                            Manufacturer eNewBrand,
                            ClientType eNewClientType,
                            ServiceJob* newServiceJobs,
                            size_t newNumberOfJobs)
: owner(newOwner), entryId(entryCounter++), licensePlate(newLicensePlate), eBrand(eNewBrand), eClientType(eNewClientType), serviceJobs(nullptr)
{
    SetServiceJobs(newServiceJobs, newNumberOfJobs);
}

ServiceEntry::ServiceEntry()
: owner(), entryId(entryCounter++), licensePlate(), eBrand(Unspecified), eClientType(Regular), serviceJobs(nullptr), numberOfJobs(0)
{
}

ServiceEntry::~ServiceEntry()
{
    delete[] serviceJobs;
}

const String& ServiceEntry::GetOwner() const
{
    return owner;
}

size_t ServiceEntry::GetEntryId() const
{
    return entryId;
}

const String& ServiceEntry::GetLicensePlate() const
{
    return licensePlate;
}

Manufacturer ServiceEntry::GetBrand() const
{
    return eBrand;
}

ClientType ServiceEntry::GetClientType()
{
    return eClientType;
}

const ServiceJob* ServiceEntry::GetServiceJobs() const
{
    return serviceJobs;
}

size_t ServiceEntry::GetNumberOfJobs() const
{
    return numberOfJobs;
}

void ServiceEntry::SetOwner(const String& newOwner)
{
    owner = newOwner;
}

void ServiceEntry::SetLicensePlate(const String& newLicensePlate)
{
    licensePlate = newLicensePlate;
}

void ServiceEntry::SetBrand(Manufacturer eNewBrand)
{
    eBrand = eNewBrand;
}

void ServiceEntry::SetClientType(ClientType eNewClientType)
{
    eClientType = eNewClientType;
}

void ServiceEntry::SetServiceJobs(ServiceJob* newServiceJobs, size_t newNumberOfJobs)
{
    delete[] serviceJobs;
    if (newServiceJobs != nullptr && newNumberOfJobs != 0)
    {
        numberOfJobs = newNumberOfJobs;
        serviceJobs = new ServiceJob[numberOfJobs];
        for (size_t i = 0; i < numberOfJobs; i++)
        {
            serviceJobs[i] = newServiceJobs[i];
        }
    }
    else
    {
        serviceJobs = nullptr;
        numberOfJobs = 0;
    }
}

double ServiceEntry::GetTotalPrice() const
{
    double totalPrice = 0.0;
    for (size_t i = 0; i < numberOfJobs; i++)
    {
        totalPrice += GetReducePrice(serviceJobs[i]);
    }
    return totalPrice;
}

void ServiceEntry::PrintInfo() const
{
    cout << "Owner name: " << owner.GetData() << endl;
    cout << "Entry id: " << entryId << endl;
    cout << "License plate: " << licensePlate.GetData() << endl;
    cout << "Brand: " << GetEnumName(eBrand) << endl;
    cout << "Client type: " << GetEnumName(eClientType) << endl;
    cout << "Total price: " << GetTotalPrice() << endl;
    if (numberOfJobs > 0)
    {
        cout << "Number of jobs: " << numberOfJobs << endl;
        for (size_t i = 0; i < numberOfJobs; i++)
        {
            cout << "Job[" << i << "]: Type - " << GetEnumName(serviceJobs[i].eServiceType) << ", Price - " << GetReducePrice(serviceJobs[i]) << endl;
        }
    }
}

double ServiceEntry::GetReducePrice(const ServiceJob& job) const
{
    switch (eClientType)
    {
        case Regular:
        {
            switch (job.eServiceType)
            {
                case Engine: return ServiceJob::GetServiceJobPrice(job)*0.95; // 5% discount
                default: return ServiceJob::GetServiceJobPrice(job);
            }
        }
        case Business:
        {
            switch (job.eServiceType)
            {
                case Suspension: return ServiceJob::GetServiceJobPrice(job) * 0.95; // 5% discount
                case Body: return ServiceJob::GetServiceJobPrice(job) * 0.90; // 10% discount
                default: return ServiceJob::GetServiceJobPrice(job);
            }
        }
        case Special:
        {
            return ServiceJob::GetServiceJobPrice(job)*0.90; // 10% discount
        }
        default:
        {
            return 0.0;
        }
    }
}

const char* GetEnumName(Manufacturer eBrand)
{
    switch (eBrand)
    {
        case Unspecified: return "Unspecified";
        case Subaru:      return "Subaru";
        case Volkswagen:  return "Volkswagen";
        case Renault:     return "Renault";
        case Nissan:      return "Nissan";
        case BMW:         return "BMW";
        case Mercedes:    return "Mercedes";
        default:          return "???????";
    }
}

const char* GetEnumName(ClientType eClientType)
{
    switch (eClientType)
    {
        case Regular:  return "Regular";
        case Business: return "Business";
        case Special:  return "Special";
        default:       return "???????";
    }
}