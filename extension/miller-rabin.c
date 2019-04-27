#include<stdio.h>
#include<stdbool.h>
#include <time.h> 
#define MIN 3990000000U
#define MAX 4010000000U //In ISO C the behaviour of 4294967295 changed between C90 and C99. 
//In C90, on normal systems this is an unsigned value, unsigned int (on 32-bit system) 
//or unsigned long (on 16-bit system). However in C99 this is a signed long long on those systems.

//Fuction to find (x^y)%p 
unsigned int  modexp( unsigned long long x,int  y,unsigned int p)
{
	unsigned  int result=1;//initialize result
	x = x % p;     //initialize with modulo x
	while(y > 0)  //Examine y's bits until we check all of them(All 0s=0)
	{
		if(y & 1)
		{
			result = (result * x) % p;
		}
		
		y = y>>1;
		x = (x * x) % p; 
	}
	return result;
}
//Fuction miller-rabin  arguments-> d,current odd number,r
bool milrab(unsigned int  d,unsigned int  n,int  r)
{
	int i,a,j; //Declaring variables 
	unsigned long long  x;
	for(i=0; i<3;i++)
	{
		if(i==0)a=2; // á  can take values 2,7,61 which according to Miller-Rabin are enough 
		if(i==1)a=7; //to determine if the number is prime
		if(i==2)a=61;
		
		x= modexp( a, d, n); //x=a^d(mod n) [1]
		if(x==1||x==n-1)/*Miller-Rabin hypothesis is that for n to be prime either*/
	       continue; //a^d=1(mod n) [ or ] a^((2^r)*d)=-1(mod n)
		
		for(j=1;j<r;j++)//j can take values  in range [1,r-1]
		{
			x=modexp(x, 2, n); //x=a^((2^r)*d)(mod n) [2]
			if(x==1)    
			  return false;    //If x never becomes n-1 then n is not prime 
			if(x==n-1)      //Note that if  only for one specific a the equation doesn't hold 
			  break;         //then  a condition returns that the number is composite
		}
		  if(x==n-1)
		  continue;
		  else
		  return false;
	}
	return true;
}
//Fuction that prepares values for miller-rabin set of equations
bool isPrime_Propab(unsigned int  n)
{
	if (n<=1||n==4) return false; //Base cases
	if (n<=3) return true;
	
	unsigned int  d ; //Declaring values
	int r=0;
	
	if(n & 1)  // Checking number if only it is odd.Even numbers can't be primes
	{
		d=n-1;  //Making the [odd] number [even]
		while(!(d&1))//Dividing d with 2 until it becomes odd(d % 2 == 0)
	    {
			d = d >> 1;      //We know every even number can be written in the form
	 		r+= 1;        // (2^r)*d  
	    }
         if (!milrab(d, n, r)) //Calling miller-rabin fuction
            return false;   //If it returns false,then the number is not prime.
		else//So Propabilistic fuctions exit with false.
			return true;
			//If it returns true then it's prime
	}
	else
	return false;//If number is even for sure its not prime
}
