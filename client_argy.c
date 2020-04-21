#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <pthread.h>

void* clientThread(void* arg)
{
  unsigned long int idThread = pthread_self();
  printf("In client thread having id = %lu\n",idThread);
  char message[1000];
  char buffer[1024];
  int clientSocket;
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  
  // Create the socket. 
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  printf("socket created client thread # %d\n",clientSocket);
  //Configure settings of the server address
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8899);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  //Connect the socket to the server using the address
  addr_size = sizeof serverAddr;
  int connResp = connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
  printf("client thread after Connect, response # %d\n",connResp);

  strcpy(message,"Client message: saying hello to Server");
  //char msg[4];
  //pthread_mutex_lock(&Indexlock);
  //sprintf(msg,"%d", Index++);
  //pthread_mutex_unlock(&Indexlock);
  //strcat(message, msg);	
  if( send(clientSocket , message , strlen(message) , 0) < 0)
  {
       printf("Send failed\n");
  }  
  
  int bytesRecd=0;
  //Read the message from the server into the buffer
  if((bytesRecd = recv(clientSocket, buffer, 1024, 0)) < 0)
  {
      printf("Receive failed\n");
  }
  
  //Print the received message
  printf("Data received: %s and bytes recd = %d\n",buffer,bytesRecd);
  close(clientSocket);
  pthread_exit(NULL);
}

int main()
{
  //int i = 0;
  pthread_t tid;
  if( pthread_create(&tid, NULL, clientThread, NULL) != 0 )
          printf("Failed to create thread\n");
    

  printf("Main thread at the client side\n");

  pthread_join(tid,NULL);
  printf("Main: Child thread: joined\n");
  
  return 0;
}