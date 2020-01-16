#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    string line;
    fstream myfile;
    myfile.open("bookmarks_22.10.19.html", ios::in);
    if (!myfile)
        cout << "file cannot open!";

    bool inside = false;
    while (getline(myfile, line))
    {
        for (char c : line) {
            if (c == '"')
                inside = true;
            else if (c == '"')
                inside = false;
            else if (inside)
                cout << c;
        }
        cout << '\n';
    }

    return 0;
}