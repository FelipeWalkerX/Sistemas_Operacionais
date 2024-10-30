#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){

    int status;
    int pid = fork();

    if (pid == 0){
        printf("filho: %d \n", getpid());
        while(1); //criar um loop para eles ficarem rodando
        
    }else if (pid < 0){
        printf("Deu bom nao ;-; \n");
   }else{
        printf("Pai: %d \n", getpid());
        while(1); //criar um loop para eles ficarem rodando
   }

    if(WIFSIGNALED(status)){
        printf("\n Mataram o pai \n");
    }
    
    return 0;

}
