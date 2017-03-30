#ifndef SERVICE_ENTRY_H
#define SERVICE_ENTRY_H

#include "String.h"
#include "ServiceJob.h"

enum Manufacturer
{
    Unspecified,
    Subaru,
    Volkswagen,
    Renault,
    Nissan,
    BMW,
    Mercedes,
};

enum ClientType
{
    Regular,
    Business,
    Special,
};

class ServiceEntry
{
public:
    ServiceEntry( const String& newOwner,
                  const String& newLicensePlate,
                  Manufacturer eNewBrand,
                  ClientType eNewClientType,
                  ServiceJob* newServiceJobs,
                  size_t newNumberOfJobs);
    ServiceEntry();
    ~ServiceEntry();

    // Getters
    const String& GetOwner() const;
    size_t GetEntryId() const;
    const String& GetLicensePlate() const;
    Manufacturer GetBrand() const;
    ClientType GetClientType();
    const ServiceJob* GetServiceJobs() const;
    size_t GetNumberOfJobs() const;

    // Setters
    void SetOwner(const String&);
    void SetLicensePlate(const String&);
    void SetBrand(Manufacturer);
    void SetClientType(ClientType);
    void SetServiceJobs(ServiceJob*, size_t);

    double GetTotalPrice() const;
    void PrintInfo() const;
private:
    String owner;
    static size_t entryCounter;
    const size_t entryId;
    String licensePlate;
    Manufacturer eBrand;
    ClientType eClientType;
    ServiceJob* serviceJobs;
    size_t numberOfJobs;

    double GetReducePrice(const ServiceJob&) const;
};

const char* GetEnumName(Manufacturer);
const char* GetEnumName(ClientType);

#endif // SERVICE_ENTRY_H