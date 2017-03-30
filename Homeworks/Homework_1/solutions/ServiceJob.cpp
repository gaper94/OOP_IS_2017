#include "ServiceJob.h"

ServiceJob::ServiceJob(double newDuration, ServiceType newServiceType)
    : duration(newDuration), eServiceType(newServiceType)
{
}

double ServiceJob::GetServiceJobPrice(const ServiceJob& job)
{
    switch (job.eServiceType)
    {
        case Maintenance: return 10 * job.duration;
        case Engine: return 40 * job.duration;
        case Body: return 50 * job.duration;
        case Suspension: return 25 * job.duration;
        default:    return 0.0;
    }
}

const char* GetEnumName(ServiceType eServiceType)
{
    switch (eServiceType)
    {
        case Maintenance: return "Maintenance";
        case Engine: return "Engine";
        case Body: return "Body";
        case Suspension: return "Suspension";
        default: return "??????";
    }
}