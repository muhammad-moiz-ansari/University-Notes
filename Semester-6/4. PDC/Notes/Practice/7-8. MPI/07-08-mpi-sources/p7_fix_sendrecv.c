
#include <mpi.h>
int main(int argc,char**argv){
    int rank,buf[100000];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int peer = (rank==0)?1:0;
    MPI_Sendrecv(buf,100000,MPI_INT,peer,0,
                 buf,100000,MPI_INT,peer,0,
                 MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    MPI_Finalize();
    return 0;
}
