#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){

    int status;
    int pid = fork();       //Diferenciar cada um dos processos (P1 -> criador // P2 -> pai do P3 e filho do P1 // P3 -> filho do P2 e neto do P1)
    if (pid == 0)
    {
        printf("Sou o processo filho e meu pid eh %d \n", getpid());
        char c = getchar();
        if(c == 's')
            exit(0);
        else
            while(1);
        

    } else if (pid < 0)
    {
        perror("Nao foi possivel criar o procsso \n");
    } else{
        printf("Sou o processo pai e meu pid eh %d \n", getpid());      //pid é o retorno da chamada fork
        wait(&status);
        if(WIFEXITED(status))       //Ver o que é
        printf("Processo filho (com o pid %d) terminou normalmente \n", pid);        //Filho terminando o processo, ai sim que ele imprime essa parte
        if(WIFSIGNALED(status))
        printf("\n\n Aborataram o filho de pid %d \n\n", pid);

    }
    
    

    return 0;
}
