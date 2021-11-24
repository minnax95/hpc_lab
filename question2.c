#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argv,char *argc[]){
	int ranking=0;
	int data=0;
	int t_rank=0;
	int size=0;
	int *buffer=NULL;
	MPI_Init(&argv,&argc);


	MPI_Comm_rank(MPI_COMM_WORLD,&ranking);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	t_rank=ranking+1;
	if(ranking==0){
		 buffer=(int*)malloc(sizeof(int)*4);
	}
	
    MPI_Gather(&t_rank,1,MPI_INT,buffer,1,MPI_INT,0,MPI_COMM_WORLD);
      
     
    if(ranking==0){
    	printf("After gather...\n");
		for(int i=0;i<4;i++){
			printf("%d ",buffer[i]);
		}
	}

    printf("\n");
    
    MPI_Finalize();
    return 0; 


}