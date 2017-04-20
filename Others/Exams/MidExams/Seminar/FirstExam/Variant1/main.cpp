#include "GramophoneRecord.h"
#include "Collection.h"
#include <iostream>

int main()
{
    GramophoneRecord Whitesnake(1981, GramophoneRecord::Genre::Rock, "Whitesnake", "Come and get it", 60);
    GramophoneRecord DeepPurple(1972, GramophoneRecord::Genre::Rock, "Deep Purple", "Machine Head", 70);
    GramophoneRecord Rainbow(1978, GramophoneRecord::Genre::Rock, "Rainbow", "Long Live Rock \'n\' Roll", 65);
    GramophoneRecord Metallica(1988, GramophoneRecord::Genre::Metal, "Metallica", "...And Justice for All", 96);
    GramophoneRecord Megadeth(1990, GramophoneRecord::Genre::Metal, "Megadeth", "Rust in Peacse", 66);

    GramophoneRecord records[4]
    {
        Whitesnake,
        DeepPurple,
        Rainbow,
        Metallica
    };

    Collection oldRecords(records, 4);
    std::cout << "Number of records: " << oldRecords.GetNumberOfRecords() << std::endl;
    for (size_t i = 0; i < oldRecords.GetNumberOfRecords(); i++)
    {
        std::cout << oldRecords.GetRecords()[i] << std::endl;
    }

    Collection newRecords;
    newRecords = oldRecords;
    newRecords += Megadeth;

    std::cout << "Printing all rock records: \n";
    newRecords.PrintByGenre(GramophoneRecord::Genre::Rock);
    newRecords.ListenRecords(200);
    return 0;
}