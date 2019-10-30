#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "header.h"


const char *mypath[] = { "./",
"/usr/bin/", "/bin/", NULL
};


int execute(char **args){

  pid_t pid,wpid;
  int stat;
  int counter = 0;
  int numOne, numTwo = 0;
  int numFinal = 0;
  int i,gcd;


  pid = fork();
  if(pid == 0){

    if(execvp(args[0], args) ==1){
      perror("ish");
    }
    exit(EXIT_FAILURE);
  }
  else if(pid<0){
    //error forking
    perror("ish");
  }
  else{
    do{
    wpid = waitpid(pid, &stat, WUNTRACED);

    if(strcmp(args[0], "args") == 0){


      printf("args =");
      while(*args){
        counter++;
        if(strcmp(*args, "args")==0){
          printf(" ");
        }
        else{
        printf("%s ", *args);
        }
        args++;
    }




    printf(" argc = %d", counter-1);
    printf("\n");
    }

    else if(strcmp(args[0], "add") == 0){
      sscanf(args[1],"%d", &numOne);
      sscanf(args[2],"%d", &numTwo);

      numFinal = numOne + numTwo;
      printf("The sum of the two numbers is %d\n", numFinal);
    }



    else if(strcmp(args[0], "gcd") == 0 || strcmp(args[0], "GCD") == 0){
      sscanf(args[1],"%x", &numOne);
      sscanf(args[2], "%x", &numTwo);
      for(i=1; i <= numOne && i <= numTwo; i++){
        if(numOne%i == 0 && numTwo%i == 0){
          gcd = i;
        }
      }
      printf("GCD(%s,%s) = %x\n",args[1], args[2], gcd);
    }


  else if(strcmp(args[0], "exit") == 0){
    printf("Exiting the shell\n");
    exit(EXIT_FAILURE);
  // find out how to exit without seg faulting
    }


  }while(!WIFEXITED(stat) && !WIFSIGNALED(stat));
  }

  return 1;
}

void loop(){


  char **args;
  int status;
  char hostName[100];


  struct passwd *pwd;

  pwd = getpwuid(getuid());


  //char userName[50];

    // read the commands entered from user input
    // then parse commands so computer can understand the commands
    // execute the commands

    gethostname(hostName, sizeof hostName);

do{
  if(geteuid() != 0){
    printf("[%s@%s]$ ", pwd->pw_name, hostName);
  }
  else{
  printf("[%s@%s]# ", pwd->pw_name, hostName);
}
  //line = read();
  /*args is an array of strings*/
  args = getln();

  status = execute(args);

  }while(status);
  free(args);
}

int main(int argc, char** argv){

  // load the configuration

  //run an REPL loop
  loop();

  //Perform any shutdown cleanup

  return 0;
}
