#include "String.h"
#include "ServiceJob.h"
#include "ServiceEntry.h"

int main()
{
    // String examples
    String ownerName("Ivan Petrov");
    String licensePlate("CB1221BC");

    // Service jobs examples
    ServiceJob job1(0.5, Engine);
    ServiceJob job2(1, Maintenance);
    ServiceJob job3(3, Body);
    ServiceJob job4(2, Suspension);

    // Service entry example
    ServiceJob jobs[4] = { job1, job2, job3, job4 };
    ServiceEntry entry(ownerName, licensePlate, Subaru, Regular, jobs, 4);
    entry.PrintInfo();

    return 0;
}