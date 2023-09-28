#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  
  pid_t pid; // variável para guardar o valor do pid

  char * argv[] = {"/bin/ls","-l",NULL}; // Verificar o fim da string

  pid = fork(); // Fork para gerar os dois processos, pai e filho
  
  if (pid == -1){ // Teste de erro
    return -1;
  }

  if (pid == 0){ // Checando entrada no Processo Filho
    int teste = execve(argv[0], argv , NULL); // Caso tenha erro, retorna valor -1. Usando variável teste para saber o retorno
    if ( teste == -1 ){ // Mensagem de erro
      perror("Erro, erro no processo filho");
    }
  }else { // Processo Pai
    wait(NULL); // Processo Pai vai esperar o fim do Processo Filho
    printf("Processo Executado");
  }
  
  return 0;
}
