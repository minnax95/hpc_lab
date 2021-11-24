%%writefile VectorVectorMultiply.cu

#include<stdio.h>
#include<cuda.h>
#define size 4 /* Number of rows of first matrix */


_global_ void matproduct(int *l,int *m, int *n)
{
    int k;
 
  for(k=0;k<size;k++)
    {
      n[k]=l[k]*m[k];
    }
}

int main()
{
    int a[size];
    int b[size];
    int c[size];
    int *d,*e,*f;
    int i;

    printf("\nElements of first vector of size 4\n");
    for(i=0;i<size;i++)
    {
        a[i] = i+1;
        printf("%d ",a[i]);
    
            
    }
  printf("\n");
    printf("\nElements of second vector of size 4\n");
        for(i=0;i<size;i++)
        {
            b[i] = i+2;
            printf("%d ",b[i]);
            
        }
 printf("\n");

    cudaMalloc((void **)&d,size*sizeof(int));
    cudaMalloc((void **)&e,size*sizeof(int));
    cudaMalloc((void **)&f,size*sizeof(int));

 cudaMemcpy(d,a,size*sizeof(int),cudaMemcpyHostToDevice);
 cudaMemcpy(e,b,size*sizeof(int),cudaMemcpyHostToDevice);

  dim3 grid(1,size);

    matproduct<<<grid,1>>>(d,e,f);

 cudaMemcpy(c,f,size*sizeof(int),cudaMemcpyDeviceToHost);
    printf("\nProduct of two vectors:\n ");
    for(i=0;i<size;i++)
    {
       printf("%d ",c[i]);
   
        
    }

    cudaFree(d);
    cudaFree(e);
    cudaFree(f);

    return 0;
}