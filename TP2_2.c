#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc, char *argv[])
{
	printf("Nombre d'arguments : %d \n", argc); // Nombre d'arguments dans la ligne de commande
	printf("Message: %s \n", argv[1]);			// Récupération du deuxième argument (Le premier mot après la commande)

	int pid;
	pid = fork();

	if (pid == 0)								// Exécution du processus fils
	{
		int fpid = getpid();
		printf("Je suis le fils et mon PID est: %d\n", fpid);
		close(1);													 //Fermeture du descripteur 1 (STDOUT)
		int fd = open("/tmp/proc-exercise",O_CREAT | O_RDWR, 0777);	 //Ouverture du fichier temporaire
		int newfd = dup2(fd,5);
		printf("Descripteur du fichier ouvert : %d \n", newfd);     //STDOUT étant fermé, l'affichage sera écrit directement dans le fichier temporaire
		execv("./TP2_2",argv);									    //Exécution du programme
	}

	else
	{
		printf("Je suis le père et mon PID est: %d \n", getpid());
		wait();
		printf("That's all folks ! \n");
	}

	return EXIT_SUCCESS;
}
