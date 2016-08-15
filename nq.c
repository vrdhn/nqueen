#include <stdio.h>




int chk(int ar[8])
{
    for ( int x1 = 0 ; x1 < 8 ; x1 ++ )
	for( int x2 = x1+1; x2 < 8 ; x2 ++ ) {
	    int y1 = ar[x1];
	    int y2 = ar[x2];
	    if ( y1 == y2 ) return 0;
	    if ( (x1 - x2 ) * (x1 - x2 ) ==
		 (y1 - y2 ) * (y1 - y2 ) ) return 0;	    
	}
    return 1;
}


int  main () {
    int arr[8];
    for ( long n = 0 ; n < 077777777 ; n ++ ) {
	arr[0] = ( n >> 0 )  & 0x7;
	arr[1] = ( n >> 3 )  & 0x7;
	arr[2] = ( n >> 6 )  & 0x7;
	arr[3] = ( n >> 9 )  & 0x7;
	arr[4] = ( n >> 12 )  & 0x7;
	arr[5] = ( n >> 15 )  & 0x7;
	arr[6] = ( n >> 18 )  & 0x7;
	arr[7] = ( n >> 21 )  & 0x7;
	if ( chk(arr) )  {
	    printf("==== %8.8o ==== \n",n);
	    for ( int j = 0 ; j < 8 ; j ++ ) {
		for ( int k = 0 ; k < arr[j] ; k ++ ) putchar('.');
		putchar('Q');
		for( int k = arr[j] + 1 ; k < 8 ; k ++ ) putchar('.');
		putchar('\n');
	    }

	}
    }

}
