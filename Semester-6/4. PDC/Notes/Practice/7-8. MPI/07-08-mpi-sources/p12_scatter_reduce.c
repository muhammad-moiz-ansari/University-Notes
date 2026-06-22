
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc,char**argv){
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int N=1000000;
    int localN=N/size;
    int *data=NULL;
    if(rank==0){
        data=malloc(N*sizeof(int));
        for(int i=0;i<N;i++) data[i]=1;
    }
    int *local=malloc(localN*sizeof(int));
    MPI_Scatter(data,localN,MPI_INT,local,localN,MPI_INT,0,MPI_COMM_WORLD);
    long long sum=0;
    for(int i=0;i<localN;i++) sum+=local[i];
    long long global;
    MPI_Reduce(&sum,&global,1,MPI_LONG_LONG,MPI_SUM,0,MPI_COMM_WORLD);
    if(rank==0) printf("Global=%lld\n",global);
    MPI_Finalize();
    return 0;
}
