#include<stdio.h>
#include<conio.h>
int main()
{
    int score ;
    int result ;
    
    printf( "Enter score :") ;
    result = scanf ( "%d" , &score ) ;

    if ( result != 1 ) {
        printf ( "Please enter number only.") ;
        return 1 ;
    }
    
    switch (score)
    {
    case 80 ... 100:
        printf ( "A") ;
        break ;
    case 75 ... 79:
        printf ( "B+") ;
        break ;
    case 70 ... 74:
        printf ( "B") ;    
        break ;
    case 65 ... 69:
        printf ( "C+") ;
        break ;
    case 60 ... 64:
        printf ( "C") ;
        break ;
    case 55 ... 59:
        printf ( "D+") ;
        break ;
    case 50 ... 54:
        printf ( "D") ;
        break ;
    case 0 ... 49:
        printf ( "F") ;
        break ;
    default:
        printf ( "Invalid score") ;
        break ;
    }
    getch() ;
}