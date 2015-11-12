#include <iostream>
#include<time.h>

using namespace std ;

int main()
{
   int array[100], n, c, d, position, swap  , k ;
 
   cout << "Enter number of elements\n";
   cin >> n ;
 
   cout << "Enter the elements of the array\n" ;
 
   for ( c = 0 ; c < n ; c++ )
      cin >> array[c];

   clock_t  begin = clock() ;
   for ( c = 0 ; c < ( n - 1 ) ; c++ )
   {
      position = c;
 
      for ( d = c + 1 ; d < n ; d++ )
      {
         if ( array[position] > array[d] )
            position = d;
      }
      if ( position != c )
      {
         swap = array[c];
         array[c] = array[position];
         array[position] = swap;
      }

   }
   clock_t end = clock() ; 
   cout << "Sorted list in ascending order:\n";
 
   for ( c = 0 ; c < n ; c++ )
	cout << array[c] << " "  ; 

   double ans = (double)(end-begin);
   ans /= CLOCKS_PER_SEC;
   cout << "\nTotal time taken = " << ans ; 
   return 0;
}