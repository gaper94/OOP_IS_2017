#include "Person.h"
#include "LibraryBook.h"
#include "Library.h"

int main()
{
    Person Silvi("Silvi", 9411111111, Female);
    Person Ivan("Ivan", 9422222222, Male);
    Person Petar("Petar", 9433333333, Male);
    Person Reneta("Reneta", 9444444444, Female);

    LibraryBook gameOfThrones("Game Of Thrones", Person("George R. R. Martin", 8711111111, Male), "0345535529", LibraryBook::Fantasy, 29.30);
    LibraryBook harryPotter("Harry Potter", Person("J. K. Rowling", 8412341144, Male), "0545162076", LibraryBook::Fiction, 34.43);

    LibraryBook libraryBooks[2] = { gameOfThrones, harryPotter };
    Person libraryUsers[4] = { Silvi, Ivan, Petar, Reneta };

    Library centralnaBiblioteka(libraryBooks, 2, libraryUsers, 2, 1000.0);
    centralnaBiblioteka.RentBook(Silvi, gameOfThrones);
    centralnaBiblioteka.RentBook(Silvi, harryPotter);
    centralnaBiblioteka.PrintInfoForAllBooksRentedByUser(Silvi);
    return 0;
}
