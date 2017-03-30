#ifndef SERVICE_JOB_H
#define SERVICE_JOB_H

enum ServiceType
{
    None,
    Maintenance,
    Engine,
    Body,
    Suspension,
};

struct ServiceJob
{
    double duration;
    ServiceType eServiceType;
    ServiceJob(double = 0.0, ServiceType = None);

    static double GetServiceJobPrice(const ServiceJob&);
};

const char* GetEnumName(ServiceType);
#endif