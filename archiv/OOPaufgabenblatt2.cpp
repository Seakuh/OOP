#include <iostream>
#include <ctime>
#include <iomanip>
#include "book.h"

book::book(const char *autor, const char *titel) : autor(autor), buchTitel(titel), anschaffungsDatum(getToday()), status(true){};
book::book(const char *autor, const char *titel, const char *datum) : autor(autor), buchTitel(titel), anschaffungsDatum(datum), status(true){};
book::book(const char *autor, const char *titel, const char *datum, bool status) : autor(autor), buchTitel(titel), anschaffungsDatum(datum), status(status){};

book::~book()
{
    //std::cout << "book deleted..." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const book &buch)
{
    os << "Titel: " << buch.buchTitel << "\tAutor: " << buch.autor << "\tDatum: " << buch.anschaffungsDatum << "\tStatus: " << buch.getStatus();
    return os;
}

std::string book::getBuchTitel() const
{
    return buchTitel;
}

std::string book::getAutor() const
{
    return autor;
}

std::string book::getAnschaffungsDatum() const
{
    return anschaffungsDatum;
}

std::string book::getStatus() const
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

void book::setStatus(bool av)
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
std::string book::getToday() const
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::string datum = "";
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    datum = oss.str();
    return datum;
}

void book::dump() const
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Buchtitel:\t\t" << getBuchTitel() << std::endl;
    std::cout << "Autor:\t\t\t" << getAutor() << std::endl;
    std::cout << "Anschaffungsdatum:\t" << getAnschaffungsDatum() << std::endl;
    std::cout << "Status:\t\t\t" << getStatus() << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "" << std::endl;
}

void function(book buchWert, book &buchReferenz, book *buchZeiger)
{
    bool setter = true;
    std::string h = "Horst";

    buchReferenz.setStatus(setter);
    buchReferenz.dump();
    (*buchZeiger).dump();
}

int main()
{
    book book1("Goethe", "Faust");
    book book2("Goethe", "Faust", "2018-10-13");
    book book3("Goethe", "Faust", "2018-10-13", true);
    book book4("Schiller", "Der Handschuh");

    book wert("Schiller", "Die Bürgerschaft", "2016-6-27", false);
    book referenz("Nietzsche", "Der Antichrist", "2014-5-27", false);
    book zeiger("Schopenhauer", "Eristische Dialekt");

    function(wert, referenz, &zeiger);

    //zeiger1.dump();
    book1.dump();

    //wert.dump();
    //referenz.dump();
    zeiger.dump();

    std::cout << book1 << std::endl;

    return 0;
}
