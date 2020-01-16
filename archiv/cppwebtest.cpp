
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);
string eingabe;
int i = 8;
int a = 0;
	
	cout << "Moin, kopiere hier bitte den Link rein, der regelm" << ae << ss <<"ig alle 10 Minuten aufgerufen werden soll:" << endl <<">";
	cin >> eingabe;
	cout << "Wie oft soll er aufgerufen werden?" << endl << ">";
	cin >> i;
	cout << endl;

	while(a < i)
	{
		ShellExecute(0, "open", eingabe, 0, 0, 0);
		cout << "Link aufgerufen";
		a++;
		cout << " [ " << a << " ]" << endl;
		cout << "------------------------------------" << endl << "Bitte 10 Minuten warten..." << endl;
		Sleep( 2000 );

	}

	

	return 0;
}