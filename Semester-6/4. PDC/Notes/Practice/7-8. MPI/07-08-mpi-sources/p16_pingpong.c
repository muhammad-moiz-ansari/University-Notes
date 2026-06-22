
#include <mpi.h>
#include <stdio.h>
int main(int argc,char**argv){
    int rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int buf[1];
    double t0=MPI_Wtime();
    if(rank==0){
        MPI_Send(buf,1,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Recv(buf,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("RTT=%f\n",MPI_Wtime()-t0);
    } else {
        MPI_Recv(buf,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Send(buf,1,MPI_INT,0,0,MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
