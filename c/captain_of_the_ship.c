#include <stdio.h>


void pFactors(int *p, int *q, int pq);
int coFactors(int p, int q, int pq);

int main()
{

	int pubKey, p, q, u, coFacs;
	
	
	printf("Enter Le input: ");
	scanf("%d", &pubKey);

	pFactors(&p, &q, pubKey);
	coFacs = coFactors(p, q, pubKey);
	
	u = pubKey - coFacs;
	
	printf("\nThis is Sparta: %d", u);
	

}




void pFactors(int *p, int *q, int pq)		// Assumes only two prime factors
{

	int divisor;
	
	divisor = pq;		

	while(divisor > 0)
	{
			
		divisor--;
		
		if(pq%divisor == 0)
		{
			
			*q = pq/divisor;
			*p = divisor;
				
			printf("We have found Le factors: %d %d", *p, *q);
			
			divisor = 0;
		}
	}
}


int coFactors(int p, int q, int pq)		// Finds total number of u integers that share a factor with pq (based on mathematical proof)
{
	
	int x = 0, a = 0, b = 0;
	int multiple = 0, counter = 0;
	

	for(b = p ; x < pq ; b = multiple*b)		// Loop to test whether an integer x = a*p + b*q is divisble by p
	{											// Hence x/p = a + b(q/p), so only possible when b = multiple*p
		
		while(x < pq)
		{
			counter++;
			
			printf("Hatred && %d %d %d %d %d\n", a, p, multiple, b, q);
			
			a++;
			x = a*p + b*q;
		}
		
		multiple++;
		
		a = 0;			
		x = a*p + b*q;		// Both initialization conditions
		
		if(x >= pq)		// This condition is only true (since a = 0) when b solely exceeds the upper pq bound
		{
			break;
		}
		
	}
	
	
	multiple = 1;
	counter--;			//	eliminates the overlap counter of a = 0 && b = 0.
	
	
	for(a = 0 ; x < pq ; a = multiple*a*q)
	{
	
		x = a*p + b*q;
	
		for(b = 0 ; x < pq ; b++)
		{
			x = a*p + b*q;
			counter++;
		}
		
		multiple++;
	
	}

	printf("\nI expert counter: %d", counter);
	
	return counter;

}

// OP formula: pq - (p + q - 1) = u;