#include <iostream> 
using namespace std; 
int main() { 
	string bill; 
	int price; 
	float cost; 
 
	cout << "Enter Bill name: "; 
	cin >> bill; 


	cout << "Enter quantity: "; 
	cin >> price; 

	
	cout << "Enter cost: "; 
	cin >> cost; 
 
	cout << "Total cost for " << bill << ": $" << (price * cost) << endl; 
	return 0; 
}