#include <iostream>

using namespace std;


void convert(double km) {
	double mm = km * 1.8;
	double ml = km * 1.609;

	cout << km << " kilometrow to: " << endl << mm << " mil morskich" << endl << ml << " mil ladowych";

}




int main() {

	double  x;
	cout << "PODAJ LICZBE KILOMETROW ";
	cin >> x;

	convert(x);
}