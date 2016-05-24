#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
        int rank;
        int buf;
        const int root=0;
        double time[2] = {0,0};
        double gtime[2] = {0,0};
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);


	if(rank == root){
		if (argc == 2) {
		buf = atoi(argv[1]);
	} else {
		buf = 1024 * 1024;
	}
	}
time[0] = MPI_Wtime();
        printf("Process [%d]: Before Bcast, buf is %d\n", rank, buf);

        /* everyone calls bcast, data is taken from root and ends up in everyone's buf */
        MPI_Bcast(&buf, 1, MPI_INT, root, MPI_COMM_WORLD);

        printf("[%d]: After Bcast, buf is %d\n", rank, buf);
time[1] = MPI_Wtime();
MPI_Reduce(time,gtime,2,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
if(rank==0){
printf("global time 1 is %f \n", gtime[0]);
printf("global time 2 is: %f \n", gtime[1]);
double gettime = gtime[1] - gtime[0];
printf("total time is %f \n",gettime);
}
        MPI_Finalize();


        return 0;
}
