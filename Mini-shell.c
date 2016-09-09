#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void Wiri(char* comando, char* parametro)
{
  pid_t pid = fork();
  char * prog[] = {" ", parametro};
  if(pid == 0)
  {
      printf("\t%s%s\n", comando, parametro);
      execvp(comando, prog);
      perror("FAllo el execv");
      exit(1);
  }
}

int main ()
{
  char comando[70];
  char parametro[70];

  gets(comando);
  while(strcmp(comando,"exit"))
  {
    gets(parametro);
    Wiri(comando, parametro);
    gets(comando);
    //lo del medio va aqui
  };
  printf("Bye bye Charley\n");

  return 0;

}

//gcc shell.c -o shell
//./shell
