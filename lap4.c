#include <stdio.h>
int main(){
   int a = 0 ;
   float b = 0 , c = 0 ;
    printf( "Test case :\n " ) ;
    printf( "   Input the Employees ID(Max. 10 chars) :\n " ) ;
    scanf( "%d",&a ) ;
    printf( "   Input the working hrs :\n " ) ;
    scanf( "%f",&b ) ;
    printf( "   Salary amount/hr :\n " ) ;
    scanf( "%f",&c ) ;
    printf( "output :\n " ) ;
    printf( "   Expected Output : \n " ) ;
    printf( "   Employees ID = %d\n " , a  ) ;
    printf( "   Salary = U$ %.2f\n " , b * c ) ;
 return 0 ;
}//end function 