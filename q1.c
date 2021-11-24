#include<stdio.h>
#include<omp.h>

int main()
{
	int m,n;
	printf("Enter a number m:\n");
	scanf("%d",&m);
	printf("Enter a number n:\n");
	scanf("%d",&n);
    	omp_set_num_threads(4);
   	int result1;
    	int result2;
    	double time = omp_get_wtime();
   	#pragma omp parallel shared(m,n)
	{
        	int thread=omp_get_thread_num();
        	int p=m;
        	int q=n;
        	while ( p != 0)  
		{
        		long long previous_p = p;
        		p = q % p;
        		q = previous_p;
        	}
       		result1=q;
       		result2=(m/result1)*n;
	}
        printf("GCD is : %d\n",result1);
        printf("HCF is : %d\n",result2);
        printf ("task done in %f seconds",omp_get_wtime() - time); 
        printf("\n Using %d Threads",omp_get_max_threads());
        return 0;
    	
}