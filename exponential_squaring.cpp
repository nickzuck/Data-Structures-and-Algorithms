#include<iostream>

#define LL long long

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

// Modular exponential squaring
LL exponential_squaring_mod(LL a, LL b, LL m)
{
	if(b == 0) return 1 % m;

	LL x = a, ans = 1;

	while(b)
	{
		if(b&1) ans = (ans * x)%m;
		b >>= 1;
		x = (x*x)%m;
	}
	return ans ;	
}

int main (){
	cout << exponential_squaring(2, 1);

}