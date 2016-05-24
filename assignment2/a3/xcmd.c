main(int argc, char *argv[])
{
	char            cmd[100];
	int             i;
	for (i = 1; i < argc; i++) {
		strcat(cmd, argv[i]);
		strcat(cmd, " ");
	}
	system(cmd);
	sleep(10);
}
