#include<stdio.h>

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5;

	x2 = number * 0.5;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	printf("%ld\n" ,i);
	i  = 0x5f3759df - ( i >> 1 );          
	printf("%ld\n" ,i);
	y  = * ( float * ) &i;
	printf("%f\n" ,y);
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

int main(int argc,char* argv[]){
	float x ;
	printf("enter your number: ");
    scanf("%f",&x);
    printf("%f\n",Q_rsqrt(x));
    return 0;
}