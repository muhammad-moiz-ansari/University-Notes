
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc,char**argv){
    int rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int buf[100000];
    if(rank==0){
        MPI_Send(buf,100000,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Recv(buf,100000,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    } else {
        MPI_Send(buf,100000,MPI_INT,0,0,MPI_COMM_WORLD);
        MPI_Recv(buf,100000,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    }
    MPI_Finalize();
    return 0;
}
