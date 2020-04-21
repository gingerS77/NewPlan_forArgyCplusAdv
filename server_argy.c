#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <pthread.h>

void* socketThread(void *arg)
{
	int newSocket = (int*)arg;
  	printf("client started inside socketserverthread  on socket # %d\n",newSocket);
  
  	char client_message[1000];  // this buffer is meant to recv the bytes from the client side
  	char buffer[1024];          // this buffer we'll be finally sending back to client 

  	unsigned int noOfBytesRecd = recv(newSocket,client_message, sizeof(client_message),NULL);

  	strcpy(buffer,"Hello Client # ");
  	char idnewsock[10];
  	sprintf(idnewsock,"%d",newSocket);   // would write the newsocket valute to the buffer 'idnewsock'
  	strcat(buffer, idnewsock);
  	strcat(buffer,client_message);
  	strcat(buffer,"\n");

  	send(newSocket,buffer,strlen(buffer),NULL);   // the actual no. of bytes which are being sent is specified in the third parameter of the send() function
  	printf("Exit socketThread with id - %d\n",newSocket);
  	close(newSocket);
	
}

int main()
{

  int serverSocket, newSocket;
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;  // we're using it to get the client's information int this, like client's IP address
  socklen_t addr_size;

  //Create the socket. 
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  // Configure settings of the server address struct
  // Address family = Internet 
  serverAddr.sin_family = AF_INET;
  //Set port number, using htons function to use proper byte order 
  serverAddr.sin_port = htons(8899);
  //Set IP address to localhost 
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // localhost

  //Set all bits of the padding field to 0 
  memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

  //Bind the address struct to the socket , in simpler words, we can say
  // it binds the socket to some particulat IP address and port number
  bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  if(0 == listen(serverSocket,5))
    printf("Listening\n");
  else
    printf("Error\n");
  
  pthread_t tid[4];  // array of 4 threads
  int i = 0;
  while(1)
  {
  	  addr_size = sizeof serverStorage;
  	  newSocket = accept(serverSocket, (struct sockaddr *) &serverStorage, &addr_size);
  	  printf("after accept call on newsocket # %d and i = %d\n",newSocket,i);
  	  if( pthread_create(&tid[i++], NULL, socketThread, (void*)newSocket) != 0 )
          printf("Failed to create thread\n"); 
      else
          printf("thread succesfully created\n");

      if(i == 4)
      	break;
  }

  for(i = 0;i < 4; ++i)
  	pthread_join(tid[i], NULL); // 
  return 0;	
}