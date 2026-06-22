
#include <mpi.h>
int main(int argc,char**argv){
    int rank,buf[100000];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0){
        MPI_Send(buf,100000,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Recv(buf,100000,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    } else {
        MPI_Recv(buf,100000,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Send(buf,100000,MPI_INT,0,0,MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
