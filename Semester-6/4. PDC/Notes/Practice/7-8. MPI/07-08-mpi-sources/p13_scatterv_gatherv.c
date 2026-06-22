
#include <stdio.h>
#include <mpi.h>
int main(int argc,char**argv){
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int val=rank;
    int sum;
    MPI_Allreduce(&val,&sum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    if(rank==0) printf("Sum=%d\n",sum);
    MPI_Finalize();
    return 0;
}
