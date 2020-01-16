#include <iostream>
#include "hfu.h"
#include <ctime>
#include <iomanip>
#include <assert.h>
#include <set>

hfu::Book::Book(const char *autor, const char *titel) : autor(autor), buchTitel(titel), anschaffungsDatum(getToday()), status(true){};
hfu::Book::Book(const char *autor, const char *titel, const char *datum) : autor(autor), buchTitel(titel), anschaffungsDatum(datum), status(true){};
hfu::Book::Book(const char *autor, const char *titel, const char *datum, bool status) : autor(autor), buchTitel(titel), anschaffungsDatum(datum), status(status){};

std::ostream &hfu::operator<<(std::ostream &os, const hfu::Book &buch)
{
    os << "Titel: " << buch.getBuchTitel() << "\tAutor: " << buch.getAutor() << "\tDatum: " << buch.getAnschaffungsDatum() << "\tStatus: " << buch.getStatus();
    return os;
}

bool hfu::operator==(const hfu::Book &buch1, const hfu::Book &buch2)
{
    if (buch1.getAutor() == buch2.getAutor() && buch1.getBuchTitel() == buch2.getBuchTitel() && buch1.getAnschaffungsDatum() == buch2.getAnschaffungsDatum() && buch1.getStatus() == buch2.getStatus())
    {
        return true;
    }
    return false;
}

bool hfu::operator!=(const hfu::Book &buch1, const hfu::Book &buch2)
{
    if (buch1 == buch2)
    {
        return false;
    }
    return true;
}

bool hfu::operator<(const hfu::Book &buch1, const hfu::Book &book2)
{
    return (buch1.getBuchTitel() < book2.getBuchTitel());//Wegen Set ordnung 
}

std::string hfu::Book::getBuchTitel() const
{
    return buchTitel;
}

std::string hfu::Book::getAutor() const
{
    return autor;
}

std::string hfu::Book::getAnschaffungsDatum() const
{
    return anschaffungsDatum;
}

std::string hfu::Book::getStatus() const
{
    if (status == true)
    {
        return "ausgeliehen";
    }
    else
    {
        return "verfügbar";
    }
}

void hfu::Book::setStatus(bool av)
{
    if (av == true)
    {
        status = true;
    }
    else
    {
        status = false;
    }
}

//Datum erhalten mit ctime Marker ignorieren
std::string hfu::Book::getToday() const
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::string datum = "";
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    datum = oss.str();
    return datum;
}

void hfu::Book::dump() const
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Buchtitel:\t\t" << getBuchTitel() << std::endl;
    std::cout << "Autor:\t\t\t" << getAutor() << std::endl;
    std::cout << "Anschaffungsdatum:\t" << getAnschaffungsDatum() << std::endl;
    std::cout << "Status:\t\t\t" << getStatus() << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "" << std::endl;
}

int main()
{

    //Aufgabe 05.2 --------------------------------------------------------

    std::set<hfu::Book> books;
    auto book1 = hfu::Book("Disney", "LTB1");
    auto book2 = hfu::Book("Disney", "LTB2");
    books.insert(book1);
    books.insert(book2);
    for (auto book : books)
    {
        std::cout << book << std::endl;
    }

    //Aufgabe 05.3 --------------------------------------------------------

    hfu::Arraylist<int, 4> numbers;
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    for (auto number : numbers)
        std::cout << number << std::endl;

    //Aufgabe 05.4 --------------------------------------------------------

    hfu::Arraylist<int, 4> numbers1;
    numbers1[0] = 1;
    numbers1[1] = 2;
    numbers1[2] = 3;
    numbers1[3] = 4;
    auto it = numbers1.begin();
    auto end = numbers1.end();
    while (it != end)
    {
        std::cout << *it << std::endl;
        ++it;
    };
}