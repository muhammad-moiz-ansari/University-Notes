
#include <stdio.h>
#include <mpi.h>
typedef struct { double x,y,z; int id; } Particle;
int main(int argc,char**argv){
    MPI_Init(&argc,&argv);
    Particle p={1,2,3,42};
    printf("Particle id=%d\n",p.id);
    MPI_Finalize();
    return 0;
}
