
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};

void processHiloRead(void);
void processHiloWrite(void);


int main(void) {
   system("touch msgq1.txt");
   system("touch msgq2.txt");

    pthread_t id_hiloWrite;
    pthread_t id_hiloRead;
    pthread_create(&id_hiloWrite, NULL, &processHiloWrite,NULL);
    pthread_create(&id_hiloRead, NULL, &processHiloRead,NULL);
    pthread_join(id_hiloWrite,NULL);
    pthread_join(id_hiloRead,NULL);

    exit(EXIT_SUCCESS);

}

void processHiloWrite(){
   struct my_msgbuf buf;
   int msqid;
   int len;
   key_t key;
   
   
   if ((key = ftok("msgq1.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
   
   if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1) {
      perror("msgget");
      exit(1);
   }
  
   buf.mtype = 1; 
   
   while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
      len = strlen(buf.mtext);
   
      if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';
      if (msgsnd(msqid, &buf, len+1, 0) == -1) 
      perror("msgsnd");
   }
   strcpy(buf.mtext, "cerrar");
   len = strlen(buf.mtext);
   if (msgsnd(msqid, &buf, len+1, 0) == -1)
   perror("msgsnd");
   
   if (msgctl(msqid, IPC_RMID, NULL) == -1) {
      perror("msgctl");
      exit(1);
   }
}


void processHiloRead(){
     struct my_msgbuf buf;
   int msqid;
   int toend;
   key_t key;
   
   if ((key = ftok("msgq2.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
   
   if ((msqid = msgget(key, PERMS)) == -1) {
      perror("msgget");
      exit(1);
   }
   printf("Chat:\n");
   
   while(1) { 
      if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1) {
         perror("msgrcv");
         exit(1);
      }
      printf("recvd: \"%s\"\n", buf.mtext);
      toend = strcmp(buf.mtext,"cerrar");
      if (toend == 0)
      break;
   }
   printf("Se ha cerrado el chat\n");
   system("rm msgq2.txt");
}


