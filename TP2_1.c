#include<stdio.h>/
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<getopt.h>


const char* quisuisje = "Le Père";

int main()
{
	int pid;						 // définition de la variable pid
	pid = fork();					 // récupération du pid généré par le fork
	quisuisje = "Le père";
	int retour = pid % 10; 			 //Utilisation de modulo pour obtenir le dernier chiffre du PID fils

	if(pid == 0)					 //Si le pid est de 0, nous traitons le processus fils
	{
		quisuisje = "Le fils";
		printf("Je suis %s\n", quisuisje);
		printf("Mon PID est: %d \n", getpid());
		printf("Le PID de mon père est: %d \n", getppid());
		exit(retour);
	}

	else						     //Si le pid est de 0, nous traitons le processus père
	{
		printf("Je suis %s\n", quisuisje);
		printf("Le PID de mon fils est: %d \n", pid);
		wait(pid);
		printf("Retour : %d\n", retour);
	}

return 0;
}
