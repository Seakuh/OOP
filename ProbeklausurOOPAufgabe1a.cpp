#include <iostream>
using namespace std;
struct Punkt
{
    double x;
    double y;
};
class PFeld
{
    Punkt *pp;
    int dim;

public:
    PFeld &operator=(const PFeld &dieser);

    PFeld()
    {
        pp->x = 0;
        pp->y = 0;
        dim = 0;
    }
    PFeld(int dim)
    {
        dim = dim;
        pp = 0;
    }

    PFeld(const PFeld &diese) : pp(diese.pp), dim(diese.dim)
    {
        cout << "in ctor..." << endl;
    }

    Punkt get(int i)
    {
        return pp[i];
    }
    void set(int i, double x, double y)
    {
        (pp + i)->x = x;
        (pp + i)->y = y;
    }
    ~PFeld()
    {
        free(pp);
    }
};

PFeld &PFeld::operator=(const &PFeld dieser)
{
}