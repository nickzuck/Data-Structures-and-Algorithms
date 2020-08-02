#include<iostream>

using namespace std ; 

long long exponential_squaring(int base, int power){
	if (power == 2) {
		return base * base ;
	}
	if (power %2 == 0){
		return exponential_squaring(base * base, power/2);
	} else {
		return base * exponential_squaring(base* base , (power-1)/2);
	}
	
}

int main (){
	cout << exponential_squaring(2, 11);

}