#include <stdio.h>

int main() {
int a = 0 ;
int b = 0 ;
printf("Enter value\n") ;
scanf("%d", &a) ;
if(a%2==0){
    printf("Series: ") ;
    for(;a>-2;a-=2) {
        printf("%d ",a) ;
    }
}//end if
else{
    printf("Series: ") ;
    for(b=1;b<=a;b+=2){
        printf("%d ",b) ;
    }
}//end else
    return 0 ;
}//end main function