/*
# $Id: mpi-ring.c,v 1.9 2012/11/27 00:49:01 phil Exp $
#
# @Copyright@
# 
# 				Rocks(r)
# 		         www.rocksclusters.org
# 		         version 6.2 (SideWinder)
# 
# Copyright (c) 2000 - 2014 The Regents of the University of California.
# All rights reserved.	
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
# 
# 1. Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright
# notice unmodified and in its entirety, this list of conditions and the
# following disclaimer in the documentation and/or other materials provided 
# with the distribution.
# 
# 3. All advertising and press materials, printed or electronic, mentioning
# features or use of this software must display the following acknowledgement: 
# 
# 	"This product includes software developed by the Rocks(r)
# 	Cluster Group at the San Diego Supercomputer Center at the
# 	University of California, San Diego and its contributors."
# 
# 4. Except as permitted for the purposes of acknowledgment in paragraph 3,
# neither the name or logo of this software nor the names of its
# authors may be used to endorse or promote products derived from this
# software without specific prior written permission.  The name of the
# software includes the following terms, and any derivatives thereof:
# "Rocks", "Rocks Clusters", and "Avalanche Installer".  For licensing of 
# the associated name, interested parties should contact Technology 
# Transfer & Intellectual Property Services, University of California, 
# San Diego, 9500 Gilman Drive, Mail Code 0910, La Jolla, CA 92093-0910, 
# Ph: (858) 534-5815, FAX: (858) 534-7345, E-MAIL:invent@ucsd.edu
# 
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS''
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
# BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
# IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
# @Copyright@
#
# $Log: mpi-ring.c,v $
# Revision 1.9  2012/11/27 00:49:01  phil
# Copyright Storm for Emerald Boa
#
# Revision 1.8  2012/05/06 05:49:10  phil
# Copyright Storm for Mamba
#
# Revision 1.7  2011/07/23 02:31:05  phil
# Viper Copyright
#
# Revision 1.6  2010/09/07 23:53:20  bruno
# star power for gb
#
# Revision 1.5  2009/05/01 19:07:18  mjk
# chimi con queso
#
# Revision 1.4  2009/02/06 00:30:54  anoop
# Oh god!! I'm a dumbass. Even the presence of
# comment chars inside a comment can terminate
# the comment. Aaaarrrgh!!!
#
# Revision 1.3  2009/02/06 00:28:05  anoop
#
# Revision 1.2  2009/01/26 22:26:50  mjk
# added missing copyright
#
*/

#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"


int
main(int argc, char *argv[])
{
	MPI_Request	sendreq;
	MPI_Request	recvreq;
	MPI_Status	status;
	int		numprocs;
	int		myid;
//myid = rand()%(&argv);
	int		namelen;
	int		left, right,root;
	int		bufsize;
	char		processor_name[MPI_MAX_PROCESSOR_NAME];
	char		*sendbuf, *recvbuf;
        double          starttime,endtime, sum=0;
        double          time[2] = {0,0};
        double          gtime[2] = {0,0};
root = 1;
//starttime = MPI_Wtime();
MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Get_processor_name(processor_name, &namelen);

//	fprintf(stderr,"Process %d on %s\n", myid, processor_name);
	right = (myid + 1) % numprocs;
	if (myid == 0) {
		left = numprocs - 1;
	} else {
		left = (myid - 1) % numprocs;
	}

	if (argc == 2) {
		bufsize = atoi(argv[1]);
	} else {
		bufsize = 1024 * 1024;
	}
//MPI_Barrier(MPI_COMM_WORLD);
time[0] = MPI_Wtime();

	if ((sendbuf = (char *)malloc(bufsize)) == NULL) {
		fprintf(stderr,"Process %d on %s:malloc failed\n",
			myid, processor_name);

		MPI_Finalize();
		exit(-1);
	}
	if ((recvbuf = (char *)malloc(bufsize)) == NULL) {
		fprintf(stderr,"Process %d on %s:malloc failed\n",
			myid, processor_name);

		MPI_Finalize();
		exit(-1);
	}

	if (MPI_Isend(sendbuf, bufsize, MPI_CHAR, right, 1,
			MPI_COMM_WORLD, &sendreq) != MPI_SUCCESS) {
fprintf(stderr,"Process %d on %s:MPI_Isend failed\n",
			myid, processor_name);

		MPI_Finalize();
		exit(-1);
	}

	if (MPI_Irecv(recvbuf, bufsize, MPI_CHAR, left, 1,
			MPI_COMM_WORLD, &recvreq) != MPI_SUCCESS) {

		fprintf(stderr,"Process %d on %s:MPI_Irecv failed\n",
					myid, processor_name);

		MPI_Finalize();
		exit(-1);
	}

	if (MPI_Wait(&sendreq, &status) != MPI_SUCCESS) {
		fprintf(stderr,"Process %d on %s:MPI_Wait failed:sendreq\n",
			myid, processor_name);

		MPI_Finalize();
		exit(-1);
	}
if(myid!=0){
	fprintf(stderr,
		"Process %d on %s:successfully sent (%d) bytes to id (%d)\n",
			root, processor_name, bufsize, right);
}
	if (MPI_Wait(&recvreq, &status) != MPI_SUCCESS) {
		fprintf(stderr,"Process %d on %s:MPI_Wait failed:sendreq\n",
			myid, processor_name);

		MPI_Finalize();
		exit(-1);
	}

//	fprintf(stderr,
//		"Process %d on %s:successfully received (%d) bytes from id (%d)\n",
		//	root, processor_name, bufsize, left);

//	MPI_Barrier(MPI_COMM_WORLD);

//	MPI_Finalize();
//MPI_Barrier(MPI_COMM_WORLD);
time[1] = MPI_Wtime();
//time = endtime-starttime;
MPI_Reduce(time,gtime,2,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);
if(myid==0){
//printf("global time 1 is %f \n", gtime[0]);
//printf("global time 2 is: %f \n", gtime[1]);
double gettime = gtime[1] - gtime[0];
printf("total time is %f \n",gettime);
}
 MPI_Finalize();

}
