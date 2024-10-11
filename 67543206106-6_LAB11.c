#include <stdio.h>
#include <stdbool.h>
int main() {
    int num, sum, pp, x = 0 ;
    printf("Enter Number : ") ;
    scanf("%d", &num ) ;
    pp = num ;

    while (num) {
        sum = num % 10 ;
        x = x + (sum*sum*sum) ;
        num = num / 10 ;
    }//end whule

    if (pp == x) {
        printf("\nPass.\n") ;
    }//end if

    else {
        printf("\nNot Pass.\n") ;
    }//end else

    return 0 ;
    
}//end function
