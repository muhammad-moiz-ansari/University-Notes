
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc,char**argv){
    int rank; MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0){
        int n=13;
        int a[13]; for(int i=0;i<n;i++) a[i]=i;
        MPI_Send(a,n,MPI_INT,1,0,MPI_COMM_WORLD);
    } else {
        MPI_Probe(0,0,MPI_COMM_WORLD,&status);
        int count;
        MPI_Get_count(&status,MPI_INT,&count);
        int *b=malloc(count*sizeof(int));
        MPI_Recv(b,count,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Received count=%d\n",count);
    }
    MPI_Finalize();
    return 0;
}
