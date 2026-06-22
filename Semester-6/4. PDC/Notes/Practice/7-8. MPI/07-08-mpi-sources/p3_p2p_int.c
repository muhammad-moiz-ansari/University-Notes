
#include <stdio.h>
#include <mpi.h>
int main(int argc,char**argv){
    int rank; MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0){
        int x=42;
        MPI_Send(&x,1,MPI_INT,1,7,MPI_COMM_WORLD);
    } else if(rank==1){
        int y;
        MPI_Recv(&y,1,MPI_INT,0,7,MPI_COMM_WORLD,&status);
        printf("Received %d\n",y);
    }
    MPI_Finalize();
    return 0;
}
