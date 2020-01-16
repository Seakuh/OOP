#include <iostream>
using namespace std;

template <class T>
const T &minimum(const T &t1, const T &t2)
{
    if (t1 < t2)
        return t1;
    return t2;
}
int main()
{
    cout << minimum(1, 2) << endl;
    cout << minimum('A', 'B') << endl;
    cout << minimum(47.11, 15.08) << endl;
    return 0;
}