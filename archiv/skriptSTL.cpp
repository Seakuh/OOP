#include <iostream>


int main(){
int anArray[] = {20,40,60,80,100};
IntSet numbers(anArray,anArray+5);
cout << "The contents of both sequences " ;
if (equal (numbers.begin(), numbers.end(), anArray))
cout << "are equal." << endl;
else
cout << "differ." << endl;
}


