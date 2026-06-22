
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc,char**argv){
    int rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int n= (argc>1)?atoi(argv[1]):16;
    int *buf=malloc(n*sizeof(int));
    if(rank==0){
        for(int i=0;i<n;i++) buf[i]=1;
        MPI_Send(buf,n,MPI_INT,1,0,MPI_COMM_WORLD);
        for(int i=0;i<n;i++) buf[i]=9;
    } else if(rank==1){
        MPI_Recv(buf,n,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("First element=%d\n",buf[0]);
    }
    MPI_Finalize();
    return 0;
}
