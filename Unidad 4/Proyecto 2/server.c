 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <pthread.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <signal.h>
 #define PORT 6666
 #define BUF_SIZE 128

 struct client_t{
     int socket;
     int rxState;
 };

    int countClient = 0;
     char buf[BUF_SIZE];
     int status;
     int enable = 1;
     int server_sd;
     int client_sd1;
     int client_sd2;
     int client_sd3;
     int client_sd4;
     int client_sd5;
     int client_sd6;
     int client_sd7;
     int client_sd8;
     int client_sd9;
     int client_sd10;
     pthread_t rxThreadId1;
     pthread_t rxThreadId2;
     pthread_t rxThreadId3;
     pthread_t rxThreadId4;
     pthread_t rxThreadId5;
     pthread_t rxThreadId6;
     pthread_t rxThreadId7;
     pthread_t rxThreadId8;
     pthread_t rxThreadId9;
     pthread_t rxThreadId10;
     pthread_t threadMenu;
     struct client_t client1;
     struct client_t client2;
     struct client_t client3;
     struct client_t client4;
     struct client_t client5;
     struct client_t client6;
     struct client_t client7;
     struct client_t client8;
     struct client_t client9;
     struct client_t client10;

void WriteClient(char bufW[BUF_SIZE] ){
     // Client 1
    if(client1.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client1.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 1 fails: ");
                close(client1.socket);
            }
    }else
    {
        if(0 == client1.rxState){
            client1.rxState=2;
            close(client1.socket);
        }
    }    
     // Client 2
    if(client2.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client2.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 2 fails: ");
                close(client2.socket);
            }
    }else
    {
        if(0 == client2.rxState){
            client2.rxState=2;
            close(client2.socket);
        }
    }
    // Client 3
    if(client3.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client3.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 3 fails: ");
                close(client3.socket);
            }
    }else
    {
        if(0 == client3.rxState){
            client3.rxState=2;
            close(client3.socket);
        }
    }
    // Client 4
    if(client4.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client4.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 4 fails: ");
                close(client4.socket);
            }
    }else
    {
        if(0 == client4.rxState){
            client4.rxState=2;
            close(client4.socket);
        }
    }
    // Client 5
    if(client5.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client5.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 5 fails: ");
                close(client5.socket);
            }
    }else
    {
        if(0 == client5.rxState){
            client5.rxState=2;
            close(client5.socket);
        }
    }
    // Client 6
    if(client6.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client6.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 6 fails: ");
                close(client6.socket);
            }
    }else
    {
        if(0 == client6.rxState){
            client6.rxState=2;
            close(client6.socket);
        }
    }
    // Client 7
    if(client7.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client7.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 7 fails: ");
                close(client7.socket);
            }
    }else
    {
        if(0 == client7.rxState){
            client7.rxState=2;
            close(client7.socket);
        }
    }
    // Client 8
    if(client8.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client8.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 8 fails: ");
                close(client8.socket);
            }
    }else
    {
        if(0 == client8.rxState){
            client8.rxState=2;
            close(client8.socket);
        }
    }
    // Client 9
    if(client9.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client9.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 9 fails: ");
                close(client9.socket);
            }
    }else
    {
        if(0 == client9.rxState){
            client9.rxState=2;
            close(client9.socket);
        }
    }
    // Client 10
    if(client10.rxState==1){
        if( bufW[ strlen(bufW)-1 ] == '\n') bufW[ strlen(bufW) - 1 ] = 0;
            status = write(client10.socket, bufW, strlen(bufW)+1);
            if(-1 == status){
                perror("Server write to client 10 fails: ");
                close(client10.socket);
            }
    }else
    {
        if(0 == client10.rxState){
            client10.rxState=2;
            close(client10.socket);
        }
    }
        
    
}

 void * readThread(void *arg){
     struct client_t *client = ((struct client_t *)arg);
     ssize_t numOfBytes;
     char buf[BUF_SIZE];

     while(1){
         numOfBytes = read(client->socket, buf, BUF_SIZE);
         if(0 == numOfBytes){
             //("client closed the socket end\n");
             break;
         }
         else if(-1 == numOfBytes){
             perror("ReadThread read() fails: ");
             break;
         }
         else{
             WriteClient(buf);
         }
     }
     countClient--;
     client->rxState = 0;
     return NULL;
 }

 void Conectados(){
     printf("Total conectados: %d\n",countClient);
     if(client1.rxState==1) printf("Client 1\n");
     if(client2.rxState==1) printf("Client 2\n");
     if(client3.rxState==1) printf("Client 3\n");
     if(client4.rxState==1) printf("Client 4\n");
     if(client5.rxState==1) printf("Client 5\n");
     if(client6.rxState==1) printf("Client 6\n");
     if(client7.rxState==1) printf("Client 7\n");
     if(client8.rxState==1) printf("Client 8\n");
     if(client9.rxState==1) printf("Client 9\n");
     if(client10.rxState==1) printf("Client 10\n");
 }

 void Cerrar(){
     int clientCerrar;
     scanf("%d",&clientCerrar);
     switch (clientCerrar)
     {
     case 1:
         client1.rxState=0;
         break;
    case 2:
         client2.rxState=0;
         break;
    case 3:
         client3.rxState=0;
         break;
    case 4:
         client4.rxState=0;
         break;
    case 5:
         client5.rxState=0;
         break; 
    case 6:
         client6.rxState=0;
         break;
    case 7:
         client7.rxState=0;
         break;
    case 8:
         client8.rxState=0;
         break;
    case 9:
         client9.rxState=0;
         break;
    case 10:
         client10.rxState=0;
         break;
     default:
         break;
     }
 }
 
void * Menu(){
    char comando[10];
    int ret=1;
    while (1)
    {
        scanf("%s", comando);
         ret = strcmp(comando, "conectados");
         if(ret == 0) Conectados();
         ret = strcmp(comando, "cerrar");
         if(ret == 0) Cerrar();
    }
    
}

 int main(int argc, char *argv[]){
     client1.rxState=2;
     client2.rxState=2;
     client3.rxState=2;
     client4.rxState=2;
     client5.rxState=2;
     client6.rxState=2;
     client7.rxState=2;
     client8.rxState=2;
     client9.rxState=2;
     client10.rxState=2;
     // 1. Ignore SIGPIPE
     signal(SIGPIPE, SIG_IGN);

     // 2. Create socket
     server_sd = socket(AF_INET, SOCK_STREAM, 0);
     if (server_sd == -1) {
         perror("Socket creation fails\n");
         exit(EXIT_FAILURE);
     }
     printf("Socket created\n");

     // 3. turn off bind address checking
     status = setsockopt(server_sd, SOL_SOCKET, SO_REUSEADDR,(int *) &enable, sizeof(enable));
     if (-1 == status){
         perror("setsockopt error: ");
     }

     //4. BIND the socket to an address
     // Prepare the address
     struct sockaddr_in addr;
     memset(&addr, 0, sizeof(addr));
     addr.sin_family = AF_INET;
     addr.sin_addr.s_addr = INADDR_ANY;
     addr.sin_port = htons(PORT);

     status = bind(server_sd, (struct sockaddr*)&addr, sizeof(addr));
     if (-1 == status) {
         perror("Bind fails: ");
         close(server_sd);
         exit(EXIT_FAILURE);
     }
     printf("Socket binded\n");

     // 5. Set backlog

     status = listen(server_sd, 1);

     if (-1 == status) {
         perror("Listen fails: ");
         close(server_sd);
         exit(EXIT_FAILURE);
     }

     printf("Server listening\n");


     printf("Waiting for a client\n");
     
     pthread_create(&threadMenu,NULL,&Menu,NULL);
     while (1)
     {
        while(1){
            // Client 1
            if(client1.rxState!=1 && countClient!=10)
            {
                client_sd1 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 1 connected\n");
                if(-1 == client_sd1)
                {
                perror("Accept client 1 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client1.socket = client_sd1; // Create a thread for receiving messages from client
                client1.rxState = 1;
                status = pthread_create(&rxThreadId1,NULL,&readThread,&client1);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 2
            if(client2.rxState!=1 && countClient!=10)
            {
                client_sd2 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 2 connected\n");
                if(-1 == client_sd2)
                {
                perror("Accept client 2 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client2.socket = client_sd2; // Create a thread for receiving messages from client
                client2.rxState = 1;
                status = pthread_create(&rxThreadId2,NULL,&readThread,&client2);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 3
            if(client3.rxState!=1 && countClient!=10)
            {
                client_sd3 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 3 connected\n");
                if(-1 == client_sd3)
                {
                perror("Accept client 3 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client3.socket = client_sd3; // Create a thread for receiving messages from client
                client3.rxState = 1;
                status = pthread_create(&rxThreadId3,NULL,&readThread,&client3);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 4
            if(client4.rxState!=1 && countClient!=10)
            {
                client_sd4 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 4 connected\n");
                if(-1 == client_sd4)
                {
                perror("Accept client 4 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client4.socket = client_sd4; // Create a thread for receiving messages from client
                client4.rxState = 1;
                status = pthread_create(&rxThreadId4,NULL,&readThread,&client4);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 5
            if(client5.rxState!=1 && countClient!=10)
            {
                client_sd5 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 5 connected\n");
                if(-1 == client_sd5)
                {
                perror("Accept client 5 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client5.socket = client_sd5; // Create a thread for receiving messages from client
                client5.rxState = 1;
                status = pthread_create(&rxThreadId5,NULL,&readThread,&client5);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 6
            if(client6.rxState!=1 && countClient!=10)
            {
                client_sd6 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 6 connected\n");
                if(-1 == client_sd6)
                {
                perror("Accept client 6 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client6.socket = client_sd6; // Create a thread for receiving messages from client
                client6.rxState = 1;
                status = pthread_create(&rxThreadId6,NULL,&readThread,&client6);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 7
            if(client7.rxState!=1 && countClient!=10)
            {
                client_sd7 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 7 connected\n");
                if(-1 == client_sd7)
                {
                perror("Accept client 7 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client7.socket = client_sd7; // Create a thread for receiving messages from client
                client7.rxState = 1;
                status = pthread_create(&rxThreadId7,NULL,&readThread,&client7);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 8
            if(client8.rxState!=1 && countClient!=10)
            {
                client_sd8 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 8 connected\n");
                if(-1 == client_sd8)
                {
                perror("Accept client 8 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client8.socket = client_sd8; // Create a thread for receiving messages from client
                client8.rxState = 1;
                status = pthread_create(&rxThreadId8,NULL,&readThread,&client8);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 9
            if(client9.rxState!=1 && countClient!=10)
            {
                client_sd9 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 9 connected\n");
                if(-1 == client_sd9)
                {
                perror("Accept client 9 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client9.socket = client_sd9; // Create a thread for receiving messages from client
                client9.rxState = 1;
                status = pthread_create(&rxThreadId9,NULL,&readThread,&client9);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
            // Client 10
            if(client10.rxState!=1 && countClient!=10)
            {
                client_sd10 = accept(server_sd, NULL, NULL); // Accept:
                printf("Client 10 connected\n");
                if(-1 == client_sd10)
                {
                perror("Accept client 10 fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                client10.socket = client_sd10; // Create a thread for receiving messages from client
                client10.rxState = 1;
                status = pthread_create(&rxThreadId10,NULL,&readThread,&client10);
                if(-1 == status)
                {
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
                }
                countClient++;
                break;
            }
     
        }
    }
     
         
     

     exit(EXIT_SUCCESS);
 }
