/*
	double pointer example 
	https://stackoverflow.com/questions/42118190/dereferencing-a-double-pointer

*/


#include <stdio.h>
#include <stdlib.h>


void afunction(int**x){
    *x = malloc(2 * sizeof(int));
    **x = 12;
    *(*x + 1) = 13;
}

int main(){
    int *v = 10;
    afunction(&v);

    printf("%d %d\n", v[0], v[1]);
    return 1;
}