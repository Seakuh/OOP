#ifndef book
#define book_h
#include <string>
#include <iostream>

class book
{

private:
    //Atribute von der Klasse book
    const std::string buchTitel = "";
    const std::string autor = "";
    const std::string anschaffungsDatum = "";
    bool status;
    //Funktionen der Klasse book oeffentlich
public:
    std::string getBuchTitel() const;
    std::string getAutor() const;
    std::string getAnschaffungsDatum() const;
    std::string getStatus() const;
    std::string getToday() const;
    void dump() const;
    void setStatus(bool av);
    void changeAutor(std::string autor);
    //Konstruktoren der Klasse book
    book(const char *autor, const char *titel);
    book(const char *autor, const char *titel, const char *datum);
    book(const char *autor, const char *titel, const char *datum, bool status);
    //Copy-Konstruktor
    book(const book &buch) = default; //Kopiekonstruktor
    // //Destruktor
    ~book();

    //Operator
    friend std::ostream &operator<<(std::ostream &os, const book &buch);
};

#endif