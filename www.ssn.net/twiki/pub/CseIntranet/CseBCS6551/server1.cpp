//EX2 SIMPLE CLIENT SERVER
//simple client:
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char **argv)
{
int len;
int sockfd,n;
struct sockaddr_in servaddr,cliaddr;
char str[1000];
char buff[1024];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
perror("cannot create socket");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr(argv[1]);
servaddr.sin_port=htons(7228);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
printf("Enter the message \t");
scanf("%s",buff);
n=write(sockfd,buff,sizeof(buff));
close(sockfd);
return 0;
}


//simple server
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char **argv)
{
int len;
int sockfd,newfd,n;
struct sockaddr_in servaddr,cliaddr;
char buff[1024];
char str[1000];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
perror("cannot create socket");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;
servaddr.sin_port=htons(7228);
if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
perror("Bind error");
listen(sockfd,2);
len=sizeof(cliaddr);
newfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len);
// printf("hi");
//Receiving the message
n=read(newfd,buff,sizeof(buff));
printf("\nReceived Message is \t%s",buff);
close(sockfd);
close(newfd);
return 0;
}

//==========================


//EX3 Echo client Server Using TCP
//echoclient
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035
int main(int argc,char*argv[])
{
       int sockfd;
       struct sockaddr_in serv_addr;
       struct hostent *server;
       char buffer[4096];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nReady for sending...");
       connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       printf("\nEnter the message to send\n");
       printf("\nClient: ");
       fgets(buffer,4096,stdin);
       write(sockfd,buffer,4096);
       printf("Serverecho:%s",buffer);
       printf("\n");
       close(sockfd);
       return 0;
}


//echoserver
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035
int main(int argc,char*argv[])
{
       int sockfd;
       struct sockaddr_in serv_addr;
       struct hostent *server;
       char buffer[4096];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nReady for sending...");
       connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       printf("\nEnter the message to send\n");
       printf("\nClient: ");
       fgets(buffer,4096,stdin);
       write(sockfd,buffer,4096);
       printf("Serverecho:%s",buffer);
       printf("\n");
       close(sockfd);
       return 0;
}


//====================

//EX4 Chat using TCP
//chatclient
#include"stdio.h"  
#include"stdlib.h"  
#include"sys/types.h"  
#include"sys/socket.h"  
#include"string.h"  
#include"netinet/in.h"  
#include"netdb.h"
#define PORT 4444 
#define BUF_SIZE 2000 
int main(int argc, char**argv) {  
 struct sockaddr_in addr, cl_addr;  
 int sockfd, ret;  
 char buffer[BUF_SIZE];  
 struct hostent * server;
 char * serverAddr;
 if (argc < 2) {
  printf("usage: client < ip address >\n");
  exit(1);  
 }
serverAddr = argv[1]; 
 sockfd = socket(AF_INET, SOCK_STREAM, 0);  
 if (sockfd < 0) {  
  printf("Error creating socket!\n");  
  exit(1);  
 }  
 printf("Socket created...\n");   
 memset(&addr, 0, sizeof(addr));  
 addr.sin_family = AF_INET;  
 addr.sin_addr.s_addr = inet_addr(serverAddr);
 addr.sin_port = PORT;     
 ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));  
 if (ret < 0) {  
  printf("Error connecting to the server!\n");  
  exit(1);  
 }  
 printf("Connected to the server...\n");  
 memset(buffer, 0, BUF_SIZE);
 printf("Enter your message(s): ");
 while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
  ret = sendto(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &addr, sizeof(addr));  
  if (ret < 0) {  
   printf("Error sending data!\n\t-%s", buffer);  
  }
  ret = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);  
  if (ret < 0) {  
   printf("Error receiving data!\n");    
  } else {
   printf("Received: ");
   fputs(buffer, stdout);
   printf("\n");
  }  
 }
 return 0;    
}  



//chatserver
#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"sys/socket.h"
#include"string.h"
#include"netinet/in.h"
#define PORT 4444
#define BUF_SIZE 2000
#define CLADDR_LEN 100
void main() {
 struct sockaddr_in addr, cl_addr;
 int sockfd, len, ret, newsockfd;
 char buffer[BUF_SIZE];
 pid_t childpid;
 char clientAddr[CLADDR_LEN];
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 if (sockfd < 0) {
  printf("Error creating socket!\n");
  exit(1);
 }
 printf("Socket created...\n");
 memset(&addr, 0, sizeof(addr));
 addr.sin_family = AF_INET;
 addr.sin_addr.s_addr = INADDR_ANY;
 addr.sin_port = PORT;
 ret = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
 if (ret < 0) {
  printf("Error binding!\n");
  exit(1);
 }
 printf("Binding done...\n");
 printf("Waiting for a connection...\n");
 listen(sockfd, 5);
 for (;;) { //infinite loop
  len = sizeof(cl_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cl_addr, &len);
  if (newsockfd < 0) {
   printf("Error accepting connection!\n");
   exit(1);
  }
  printf("Connection accepted...\n");
  inet_ntop(AF_INET, &(cl_addr.sin_addr), clientAddr, CLADDR_LEN);
  if ((childpid = fork()) == 0) { 
  close(sockfd); 
  for (;;) {
    memset(buffer, 0, BUF_SIZE);
    ret = recvfrom(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &cl_addr, &len);
    if(ret < 0) {
     printf("Error receiving data!\n");  
     exit(1);
    }
    printf("Received data from %s: %s\n", clientAddr, buffer); 
    ret = sendto(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &cl_addr, len);   
    if (ret < 0) {  
     printf("Error sending data!\n");  
     exit(1);  
    }  
    printf("Sent data to %s: %s\n", clientAddr, buffer);
   }
  }
  close(newsockfd);
 }
}


//==========================



//EX5 Transfer Files
//tcpclient
#include<stdio.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h> 
int main(int argc,char **argv) 
{ 
int len; 
int sockfd,newfd,n,a; 
struct sockaddr_in servaddr,cliaddr; 
char str[1000]; 
char buff[1024];
sockfd=socket(AF_INET,SOCK_STREAM,0); 
if(sockfd<0) 
	perror("cannot create socket"); 
bzero(&servaddr,sizeof(servaddr)); 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=inet_addr(argv[1]); 
servaddr.sin_port=htons(atoi(argv[2])); 
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
FILE *f,*f1;
if((f1=fopen("/student/csea061/Desktop/4/outt.txt","r"))==NULL)
	printf("Wrong File");
f=fopen("/student/csea061/Desktop/4/in.txt","r");
fscanf(f,"%s",buff);
write(sockfd,buff,sizeof(buff));
printf("the file was sent successfully");
close(sockfd); 
return 0; 
} 


//chatserver
#include<stdio.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h> 
int main(int argc,char **argv) 
{ 
int len; 
int sockfd,newfd,n;
struct sockaddr_in servaddr,cliaddr; 
char buff[1024];
char str[1000]; 
sockfd=socket(AF_INET,SOCK_STREAM,0); 
if(sockfd<0) 
perror("cannot create socket"); 
bzero(&servaddr,sizeof(servaddr)); 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=INADDR_ANY; 
servaddr.sin_port=htons(atoi(argv[1])); 
if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0) 
perror("Bind error"); 
listen(sockfd,2); 
len=sizeof(cliaddr); 
newfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len); 
FILE *fp;
read(newfd,buff,100);
printf("\nReceived Message is \t%s",buff);
fp=fopen("/student/csea061/Desktop/4/out.txt","w");
fprintf(fp,"%s",buff);
printf("\nthe file was received successfully");
printf("\nthe new file created");
close(sockfd); 
close(newfd); 
return 0; 
} 



//=============================


//EX5b File transfer using UDP
//UDPclient
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(int argc,char** argv)
{
	int sockfd,filefd,len;
	struct sockaddr_in servaddr,cliaddr;
	char buff[5120],dest[1024],filename[64];
	sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockfd < 0)
		{
		 perror("Creation error");
		}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	servaddr.sin_port = htons(7228);
	printf("Filename");
	scanf("%s",filename);
	strcpy(buff,filename);
	len = sizeof(servaddr);
	sendto(sockfd,buff,5120,0,(struct sockaddr*)&servaddr,len);
	printf("Destination to save:");
	scanf("%s",dest);
	strcat(dest,filename);
	if((filefd = creat(dest,S_IRWXU)) != -1)
		{
		 sendto(sockfd,buff,5120,0,(struct sockaddr*)&servaddr,len);
		 recvfrom(sockfd,buff,5120,0,(struct sockaddr*)&servaddr, &len);
		 if(strcmp(buff,"ERROR")!=0)
			{
			 write(filefd,buff,strlen(buff));
			}
		else
			{
			printf("File not found...\n");
			close(filefd);
			}
		}
	else
		{
		 printf("%s\n",dest);
		 close(sockfd);
		 return 0;
		}	
}

//UDPserver
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(int argc, char** argv)
{
	int sockfd,neffd,len,filefd,i;
	struct sockaddr_in servaddr,cliaddr;
	char buff[5120],filename[64],data;
	sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockfd < 0)
		{
		 perror("Creation error");
		}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(7228);
	if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0);
		{
		 perror("Bind error");
		}
	len = sizeof(cliaddr);
	recvfrom(sockfd,filename,64,0,(struct sockaddr *)&cliaddr,&len);
	printf("Filename:%s\n",filename);
	if((filefd = open(filename,O_RDONLY))!= -1)
		{
		 i=0;
 		 strcpy(buff,"\0");
		 while(read(filefd,&data,sizeof(data))!= 0)
			{
			  buff[i++]=data;
			}
		 buff[i]='\0';
		 close(filefd);
		 printf("File sent...\n");
		}
	else
		{
		 strcpy(buff,"Error!!!!");
		}	
	sendto(sockfd,buff,5120,0,(struct sockaddr*)&cliaddr,len);
	close(sockfd);
	return 0;
}


//=========================


//EX6a stopandwaitpro
//swclient
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr
//EVEN PARITY
int main(int argc,char *argv[])
{
char buff[MAX];
int n=0;
char buff1[MAX];
int sockfd,connfd;
char buffer[MAX];
int l;
char k='0';
int j;
int i=0;
int l1;
struct sockaddr_in servaddr,cli;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else
printf("Socket successfully created..\n");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr(argv[1]);
servaddr.sin_port=htons(PORT);
if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr))!=0)
{
printf("connection with the server failed...\n");
exit(0);
}
else
printf("connected to the server..\n");
bzero(buff,sizeof(buff));
printf("Enter 16-bit data:");
while((buff[n++]=getchar())!='\n');
buff[n+1]='\n';
printf("%s",buff);
for(i=0;i<16;i+=4)
{
k='0'; 
bzero(buff1,sizeof(buff1));
for(j=0;j<4;j++)
{
 buff1[j]=buff[i+j];
 if(buff1[j]=='1' && k=='0')
   k='1';
 else if(buff1[j]=='1' && k=='1')
   k='0';
}
buff1[j]=k;
buff1[j+1]='\n';
printf("Buffer-%s",buff1);
printf("Do you want to introduce an error 1-YES 0-NO:");
scanf("%d",&l);
if(l==1)
{
 printf("Introduce error in which position:");
 scanf("%d",&l);
 if(buff1[l-1]=='0')
  buff1[l-1]='1';
 else
  buff1[l-1]='0';
}
lab1:

if(i==0 || i==8)
 l1=0;
else
 l1=1;  

printf("Transmitting Frame %d-%s",l1,buff1);
write(sockfd,buff1,sizeof(buff1));
bzero(buffer,sizeof(buffer));

read(sockfd,buffer,sizeof(buffer));
if(buffer[0]=='N'&&buffer[1]=='A'&&buffer[2]=='C'&&buffer[3]=='K')
{
 if(buff1[l-1]=='0')
  buff1[l-1]='1';
 else
  buff1[l-1]='0';
 goto lab1;
} 
}
close(sockfd);
}

//swserver
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr
void func(int sockfd)
{
char buff[MAX];
int n,z;
for(int i=0;i<4;i++)
{
bzero(buff,MAX);
read(sockfd,buff,sizeof(buff));
printf("From client:%s\n",buff);
n=0;
for(int j=0;j<5;j++)
 if(buff[j]=='1')
  n++;
bzero(buff,MAX);

if(n%2!=0)
{
 z=0;
 strcpy(buff,"NACK-");
 printf("\nError in data\n");
 
}
else
{
 z=1; 
 strcpy(buff,"ACK-");
}
int ack=i%2;
if(z==1 && ack==0)
 ack=1;
else if(z==1 && ack==1)
 ack=0;
   
printf("Transmitting %s%d",buff,ack);

write(sockfd,buff,sizeof(buff));
if(buff[0]=='N'&&buff[1]=='A'&&buff[2]=='C'&&buff[3]=='K')
 i--;
}
}
int main()
{
int sockfd,connfd,len;
struct sockaddr_in servaddr,cli;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
//printf("socket creation failed...\n");
exit(0);
}
else
//printf("Socket successfully created..\n");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);
if((bind(sockfd,(SA*)&servaddr, sizeof(servaddr)))!=0)
{
printf("socket bind failed...\n");
exit(0);
}
else
printf("Socket successfully binded..\n");
if((listen(sockfd,5))!=0)
{
//printf("Listen failed...\n");
exit(0);
}
else
//printf("Server listening..\n");
len=sizeof(cli);
connfd=accept(sockfd,(SA *)&cli,&len);
if(connfd<0)
{
//printf("server acccept failed...\n");
exit(0);
}
else
//printf("server acccept the client...\n");
func(connfd);
close(sockfd);
}

//===========================


//EX6b gobacknarq
//gbnarqclient
#include<stdio.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<strings.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

int main(int argcc,char * argv[])
{
	struct sockaddr_in addr;
	char a[20]="1",b[10],c[10],ch[2],ackk[3],f[3];
	int x=0,sockfd,s=0,p=0,pos,f_no=0,i,j;
	int LAR=-1,LFS=-1;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	perror("Cannot create socket");
	bzero(&addr,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr(argv[1]);
	addr.sin_port=htons(8080);
	printf("Enter 16-bit data\n");
	while(strlen(a)!=16)
	scanf("%s",a);
	if(connect(sockfd,(struct sockaddr*)&addr,sizeof(addr))<0)
	perror("Connection failed\n");
	while(LAR !=3)
	{
		if(LFS+1 <=3)
		printf("\nFrame %d- \n",LFS+1);
		x=(LFS+1)*4;
		s=0;
		strcpy(c,"\0");
		strncpy(b,a+x,4);
		p=0;
		while(s<4)
		{
			if(b[s++]=='1')	
			p++;
		}
		if(p%2==0)
			b[s]='0';
		else
			b[s]='1';
			b[s+1]='\0';
	printf("%s",b);
	if(LFS+1 <=3)
	{
		printf("\nDo you want to introduce error(y/n)\t:");
		scanf("%s",ch);
	}
	if(ch[0]=='y' && LFS+1 <=3)
	{
		printf("Enter position\t:");
		scanf("%d",&pos);
		if(b[pos]=='0')
		b[pos]='1';
		else
		b[pos]='o';
	}
	for(i=0;i<5;i++)
	{
		printf("%c",b[i]);
		if(i==3)
		printf("");
	}
	f[0]=(char)((LFS)+49);
	f[1]='0';
	strcat(b,f);
	write(sockfd,b,strlen(b));
	LFS++;
	read(sockfd,c,6);
	if(!strncmp(c,"ack",3))
	{
	strcpy(ackk,c+3);
	LAR=atoi(ackk);
	printf("\nAck received for frame %d\n",LAR);
	}
	else
	{
	if(LFS==LAR+2)
	{
	LFS=LAR;
	}
	}
	}
	close(sockfd);
}


//gbnarqserver
#include<stdio.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<strings.h>
int main()
{
char b[0],mess[20],temp[5];
struct sockaddr_in addr;
char ackmsg[7];
int RW=0,fl;
int x=0,cf=0,g,fd,sockfd,s=0,p=0,i,j,ackchar,q,m,ackno=-1,ll,count;

sockfd=socket(AF_INET,SOCK_STREAM,0);
strcpy(ackmsg,"ackxx\0");

if(sockfd<0)
perror("cannot creat socket");

bzero(&addr,sizeof(addr));
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=INADDR_ANY;
addr.sin_port=htons(8080);
s=sizeof(addr);

	if(bind(sockfd,(struct sockaddr*)&addr,sizeof(addr))<0)
	perror("Bind error");

        listen(sockfd,2);
		if((fd=accept(sockfd,(struct sockaddr*)&addr,&s))<0)
		{
		printf("No connection\n");
		return;
		}

 do
 {
    ll=x=p=0;
    printf("\nReceiving Frame%d\n",RW);
    read(fd,b,7);
    for(i=0;i<6;++i)
     {
      printf("%c",b[i]);
      if(i==3||i==4)
      printf("");
       }

    while(x<5)
    {
    if(b[x++]=='1')
     p++;
      }


    if(p%2!=0)
    {
    printf("\nError\n");
    //write(fd."Nak",4);
    count--;
    }

    else
    {
    g=RW;
    printf("\nNo Error");
    if(b[5]==(char)(RW+48))
    {
    RW++;
    strncpy(temp,b,4);
    strcat(mess,temp);
    printf("Do you want to send ack?(0/1):\t");
    scanf("%d",&ackchar);
    if(ackchar==1)
    {
    cf=g;
    ackmsg[3]=(char)((g)+48);
    write(fd,ackmsg,5);
    }
    else fl++;
    }
    else fl++;
    }
    if(fl!=0)
    {
    write(fd,"Soc",5);
    fl=0;
    if(RW-cf==2)
    {
    RW=cf+1;
    mess[RW*4]='\0';
    }

}
}
while(RW<4);
printf("\n Message Received\t %s \n",mess);
return;
}


//====================


//EX7 ARP
//arpclient
#include<stdio.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h>
#include<string.h> 
#include <netdb.h>
int main(int argc,char **argv) 
{ 
   char buff[1024],ip1[1024],ip[1024],mac[1024];
   int len,k=0,i,j=0; 
   int sockfd,newfd,n,a,n1,n2; 
   struct sockaddr_in servaddr,cliaddr; 
   char str[1000]; 
   char buffer[1024],buf[1024],buff1[50];
   sockfd=socket(AF_INET,SOCK_STREAM,0); 
if(sockfd<0) 
   perror("cannot create socket"); 
  bzero(&servaddr,sizeof(servaddr)); 
   servaddr.sin_family=AF_INET; 
   servaddr.sin_addr.s_addr=inet_addr(argv[1]); 
   servaddr.sin_port=htons(atoi(argv[2])); 
   connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)); 
   printf("Enter the Ip Address");
   scanf("%s",ip);
   printf("Enter the MAC Address");
   scanf("%s",mac);
   read(sockfd,buff,sizeof(buff));
   puts(buff);
n=strlen(buff);
for(i=0;i<n;i++)
{
 if(buff[i]=='|')
   j++;
     if(j==2){
       ip1[k]=buff[i+1];
         k++;
}
}
if(strcmp(ip,ip1)==0)
 {
  printf("\nThis is ur client\n");
  strcat(buff,"|");
  strcat(buff,mac);
  printf("\nclient to server%s\n",buff);
  write(sockfd,buff,sizeof(buff));
  read(sockfd,buffer,sizeof(buffer));
  printf("\nReceived packets:%s\n",buffer);

}
}


//arpc1
#include<stdio.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h>
#include<string.h> 
#include <netdb.h>
int main(int argc,char **argv) 
{ 
   char buff[1024],ip1[1024],ip[1024],mac[1024];
   int len,k=0,i,j=0; 
   int sockfd,newfd,n,a,n1,n2; 
   struct sockaddr_in servaddr,cliaddr; 
   char str[1000]; 
   char buffer[1024],buf[1024],buff1[50];
   sockfd=socket(AF_INET,SOCK_STREAM,0); 
if(sockfd<0) 
   perror("cannot create socket"); 
  bzero(&servaddr,sizeof(servaddr)); 
   servaddr.sin_family=AF_INET; 
   servaddr.sin_addr.s_addr=inet_addr(argv[1]); 
   servaddr.sin_port=htons(atoi(argv[2])); 
   connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)); 
   printf("Enter the Ip Address");
   scanf("%s",ip);
   printf("Enter the MAC Address");
   scanf("%s",mac);
   read(sockfd,buff,sizeof(buff));
   puts(buff);
n=strlen(buff);
for(i=0;i<n;i++)
{
 if(buff[i]=='|')
   j++;
     if(j==2){
       ip1[k]=buff[i+1];
         k++;
}
}
if(strcmp(ip,ip1)==0)
 {
  printf("\nThis is ur client\n");
  strcat(buff,"|");
  strcat(buff,mac);
  printf("\nclient to server%s\n",buff);
  write(sockfd,buff,sizeof(buff));
  read(sockfd,buffer,sizeof(buffer));
  printf("\nReceived packets:%s\n",buffer);

}
}


//arpc2
#include<stdio.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h>
#include<string.h> 
#include <netdb.h>
int main(int argc,char **argv) 
{ 
   char buff[1024],ip1[1024],ip[1024],mac[1024];
   int len,k=0,i,j=0; 
   int sockfd,newfd,n,a,n1,n2; 
   struct sockaddr_in servaddr,cliaddr; 
   char str[1000]; 
   char buffer[1024],buf[1024],buff1[50];
   sockfd=socket(AF_INET,SOCK_STREAM,0); 
if(sockfd<0) 
   perror("cannot create socket"); 
  bzero(&servaddr,sizeof(servaddr)); 
   servaddr.sin_family=AF_INET; 
   servaddr.sin_addr.s_addr=inet_addr(argv[1]); 
   servaddr.sin_port=htons(atoi(argv[2])); 
   connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)); 
   printf("Enter the Ip Address");
   scanf("%s",ip);
   printf("Enter the MAC Address");
   scanf("%s",mac);
   read(sockfd,buff,sizeof(buff));
   puts(buff);
n=strlen(buff);
for(i=0;i<n;i++)
{
 if(buff[i]=='|')
   j++;
     if(j==2){
       ip1[k]=buff[i+1];
         k++;
}
}
if(strcmp(ip,ip1)==0)
 {
  printf("\nThis is ur client\n");
  strcat(buff,"|");
  strcat(buff,mac);
  printf("\nclient to server%s\n",buff);
  write(sockfd,buff,sizeof(buff));
  read(sockfd,buffer,sizeof(buffer));
  printf("\nReceived packets:%s\n",buffer);

}
}

//arpserver
#include<stdio.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h>
#include<string.h> 
#include <netdb.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
   char ip[1024],ip1[20],mac[20],d[1024];
   int len; 
   int sockfd,newfd,n,a,n1=0,i; 
   struct sockaddr_in servaddr,cliaddr; 
    char buff[1024]; 
   char str[1000]; 
   char buffer[1024],buf[1024],buff1[50];
   sockfd=socket(AF_INET,SOCK_STREAM,0); 
if(sockfd<0) 
   perror("cannot create socket"); 
bzero(&servaddr,sizeof(servaddr)); 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=INADDR_ANY; 
servaddr.sin_port=htons(atoi(argv[1]));
if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0) 
   perror("Bind error"); 
   listen(sockfd,2); 
   

printf("Enter the Data:");
scanf("%s",d);
printf("Enter the Source IP Address:");
scanf("%s",ip);
printf("%s",ip);
printf("Enter the Destination IP Address");
scanf("%s",ip1);
n=strlen(ip1);
printf("%d",n);
printf("Enter the MAC Address");
scanf("%s",mac);
strcat(ip,"|");
strcat(ip,mac);
strcat(ip,"|");
strcat(ip,ip1);
puts(ip);
 
while(1)
{	
if(fork()==0)
{	
len=sizeof(cliaddr); 
newfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len);
write(newfd,ip,sizeof(ip));
}
else
{
read(newfd,buf,sizeof(buf));
		//printf("\nReceived message is %s\n",buf);
strcat(buf,"|");
strcat(buf,d);
write(newfd,buf,sizeof(buf)); 
close(newfd);
return;
	}
}

}




//========================



//EX8 subnetting
//subclient
#include<stdio.h> 
#include<stdlib.h>
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include <unistd.h>
#include<arpa/inet.h>
#include<string.h> 
int main(int argc,char **argv) 
{
char subnet[20];int i=0,j=0,k,b,a;
printf("Enter a subnet addr :");
scanf("%s",subnet);

printf("Trying to connect");

char packet[60],match[40],destaddr[40];
	int len;char flag[10];
	int sockfd,newfd,n; 
	struct sockaddr_in servaddr,cliaddr; 
	sockfd=socket(AF_INET,SOCK_STREAM,0); 
	if(sockfd<0) 
		perror("cannot create socket"); 
	bzero(&servaddr,sizeof(servaddr)); 
	servaddr.sin_family=AF_INET; 
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1"); 
	servaddr.sin_port=htons(atoi(argv[1])); 
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));  
//	n=write(sockfd,subnetaddr,sizeof(subnetaddr)); 
	//sleep(3);	
	n=read(sockfd,match,sizeof(match));
	printf("\nConnection established: %s\n",match);
printf("\n %s", match);
printf("\n %s",subnet);
if(strcmp(match,subnet)==0)
{
	printf("\npacket can be send");
	strcpy(flag,"yes");
}
//printf("%d",flag);
a=write(sockfd,flag,sizeof(flag));

if(strcmp(flag,"yes")==0)
{
n=read(sockfd,packet,sizeof(packet));
printf("\n Recieved packet : %s ", packet);
}
else 
	return 0;
close(sockfd);


}

//subserver
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include<arpa/inet.h>
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
int main(int argc,char **argv)
{
char str[50],c[10],add[10],subm[50],def[50],class,sub1[4][3],sub[4][3];
char dest[20],dest1[40][40],data[20],pack[40],Add1[40],Add2[20],Add3[20],Add4[20];
int dec_sub[4],dec_dest[4];
char str1[20],subnetaddr[20];
int a,m,k,dec=0,rem,bin=0,i=0,j=0,base=1,AND1[10];
printf("Enter the network address:\n");
scanf("%s",str);

printf("Enter the number of subnets:");
scanf("%d",&a);


while(str[i]!='.')
{
	
	c[i]=str[i];
 	i++;
}
if(strcmp(c,"0")>0 && strcmp(c,"128")<0 )
 	class = 'A';
else if(strcmp(c,"127")>0 && strcmp(c,"192")<0 )
	class = 'B';
else if(strcmp(c,"191")>0 && strcmp(c,"224")<0 )
	class = 'C';
else if(strcmp(c,"223")>0 && strcmp(c,"240")<0 )
	class = 'D';
else if(strcmp(c,"239")>0 && strcmp(c,"255")<0 )
	class = 'E';

printf("\nclass : %c\n",class);

while(1)
{
if(pow(2,j)>=a)
{		
	k=j;
	break;
}
j++;
}
i=k;
for(m=0;m<8;m++)
{
  if(i>0)
  {
	add[m]='1';	
	i--;
  }
  else
	add[m]='0';
}
for(i=0; i<8; i++)
{
	bin = bin * 10 + ( add[i] - '0' );
}
printf("\nones : %d",bin);
while(bin>0)
{
rem=bin%10;
dec=dec+rem*base;
bin=bin/10;
base=base*2;
}
def[0]='\0';
sprintf(def,"%d",dec);
subm[0]='\0';
if(class == 'A')
{
	
	strcpy(subm,"255.");	
	strcat(subm,def);
	
	strcat(subm,".0.0");
}
else if(class == 'B')
{
	strcpy(subm,"255.255.");
	strcat(subm,def);
	subm[strlen(subm)]='\0';
	strcat(subm,".0");
}
else
{
	strcpy(subm,"255.255.255.");
	strcat(subm,def);
	
}
printf("\nSubnet mask : %s ",subm);
k=0;
for(i=0;subm[k]!='\0';)
{
	for(j=0;subm[k]!='.'&&subm[k]!='\0';j++)
		{
		sub1[i][j]=subm[k];
		k++;
		}
sub[i][j]='\0';
strcpy(sub[i],sub1[i]);
dec_sub[i]=atoi(sub[i]);
i++;
k++;
}
sub[i][j]='\0';
printf("\nEnter the destination ip:\n");
scanf("%s",dest);

printf("\nIts Splitting:\n");

k=0;
for(i=0;dest[k]!='\0';i++)
{
	for(j=0;dest[k]!='.'&&dest[k]!='\0';j++)
		{
		dest1[i][j]=dest[k];
			k++;
		
}
if(dest[k]!='\0')
	k++;
dest1[i][j]='\0';		
}
printf("\nAgain:\n");
for(i=0;i<4;i++)
{
	for(j=0;dest1[i][j]!='\0';j++)
{
		printf("%c",dest1[i][j]);
}
printf("\n");

}
for(i=0;i<4;i++)
{
dec_dest[i]=atoi(dest1[i]);
AND1[i]=dec_sub[i]&dec_dest[i];
printf("AND: %d ",AND1[i]);
}
sprintf(Add1,"%d",AND1[0]);
sprintf(Add2,"%d",AND1[1]);
sprintf(Add3,"%d",AND1[2]);
sprintf(Add4,"%d",AND1[3]);


strcat(Add1,".");
strcat(Add1,Add2);
strcat(Add1,".");
strcat(Add1,Add3);
strcat(Add1,".");
strcat(Add1,Add4);
printf("\nAddr : %s" ,Add1);
printf("\nData :");
scanf("%s",data);

strcpy(pack,dest);
strcat(pack,"||");
strcat(pack,data);
printf("packet: %s",pack);


char resp[50],match[4];
	int len;char flag[10];int b;
	int sockfd,newfd,n; 
	struct sockaddr_in servaddr,cliaddr; 
	sockfd=socket(AF_INET,SOCK_STREAM,0); 
	if(sockfd<0) 
			perror("cannot create socket"); 
	bzero(&servaddr,sizeof(servaddr)); 
	servaddr.sin_family=AF_INET; 
	servaddr.sin_addr.s_addr=INADDR_ANY; 
	servaddr.sin_port=htons(atoi(argv[1])); 
	if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0) 
		perror("Bind error"); 
	listen(sockfd,2); 
	len=sizeof(cliaddr);
while(1){ 
	newfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len); 
	printf("\nConnection done ");

	n=write(newfd,Add1,sizeof(Add1));
     b=read(newfd,flag,sizeof(flag));
if(strcmp(flag,"yes")==0)

{

a=write(newfd,pack,sizeof(pack));
break;
}
}
close(sockfd);
close(newfd);
}


//======================


//EX9 DNS
//dnsclient
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h> 
int main(int argc,char **argv) 
{ 
int len; 
int sockfd,n,i; 
struct sockaddr_in servaddr,cliaddr; 
char str[1000]; 
char buff[1024]; 
char rv[1024];
sockfd=socket(AF_INET,SOCK_DGRAM,0); 
if(sockfd<0) 
perror("cannot create socket"); 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=inet_addr(argv[1]); 
servaddr.sin_port=htons(atoi(argv[2])); 
printf("Enter the server name :");
scanf("%s",buff);
len=sizeof(servaddr);
sendto(sockfd,buff,sizeof(buff),0,( struct sockaddr*)&servaddr,sizeof(servaddr));
recvfrom(sockfd,str,sizeof(str),0,(struct sockaddr*)&servaddr,&len);
printf("The IP address is :%s",str);
}

//dnsserver
#include<stdio.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<string.h> 
#include <unistd.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
int main(int argc,char **argv) 
{ 
int len,flag=0; 
int sockfd,newfd,n,y,y1,y2,i; 
struct sockaddr_in servaddr,cliaddr;
char rv[100],rv1[100]; 
char buff[100][100],buff1[100]; 
char str[100][100],str1[100];
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0) 
perror("cannot create socket"); 
bzero(&servaddr,sizeof(servaddr)); 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=INADDR_ANY; 
servaddr.sin_port=htons(atoi(argv[1])); 
if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0) 
perror("Bind error");
printf("Enter the Number\n");
scanf("%d",&n);
for(i=0;i<n;i++){
 printf("Enter the Server name:");
 scanf("%s",str[i]);
 printf("Enter the IP Address");
 scanf("%s",buff[i]);
}
printf("Lookup Table Details\n");
printf("S_name\t IP\n");
for(i=0;i<n;i++){
 printf("%s\t",str[i]);
 printf("%s\t",buff[i]);
 printf("\n");

}
label:
{
printf("1.Update\t 2.Modify\n");
printf("Enter ur Choice\n");
scanf("%d",&y);
switch(y){
  case 1:
     printf("Enter the server name ");
     scanf("%s",str[n]);
     printf("Enter the IP address");
     scanf("%s",buff[n]);
     n++;   
     printf("Updated Lookup Table Details\n");
     printf("S_name\t IP\n");
     for(i=0;i<n;i++){
     printf("%s\t",str[i]);
     printf("%s\t",buff[i]);
      printf("\n"); 
} 
      break;
  case 2:
    flag=0;
    printf("Enter the domain name");
    scanf("%s",rv);
      for(i=0;i<n;i++){
           if(strcmp(str[i],rv)==0)
              y1=i;
}
    printf("Enter the valid IP Adress");
    scanf("%s",rv1);
    for(i=0;i<n;i++){
       if(strcmp(rv1,buff[i])==0){
          printf("Given ip adress was already exit\n");
          flag=1;
         //break;
        }
}
      if(flag!=1){
          strcpy(buff[y1],rv1);
           
     printf("Modified Lookup Table Details\n");
     printf("S_name\t IP\n");
     for(i=0;i<n;i++){
     printf("%s\t",str[i]);
     printf("%s\t",buff[i]);
     printf("\n"); 
} 
   break;
}
}
}printf("Do you want to continue this process 1/0");
scanf("%d",&y2);
if(y2==1){
goto label;
}
       len=sizeof(cliaddr);
      recvfrom(sockfd,buff1,sizeof(buff1),0,(struct sockaddr*)&cliaddr,&len);
       for(i=0;i<n;i++){
         if(strcmp(str[i],buff1)==0){
           strcpy(str1,buff[i]);
             sendto(sockfd,str1,sizeof(str1),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
              
}
}
}


//====================



//EX10 RPC
/*  make ready add.x 
1 compile the idl using
rpcgen -C -a add.x


2 CFLAGS += -g -DRPC_SVC_FG
RPCGENFLAGS = -C

Compile the make file using
make -f Makefile.add
*/

ADD.X
struct intpair {
int a;
int b;
char c;
};
program ADD_PROG {
version ADD_VERS {
int ADD(intpair) = 1;
} = 1;
} = 0x23451111;

ADH.C

#ifndef _ADD_H_RPCGEN
#define _ADD_H_RPCGEN
#include <rpc/rpc.h>
#ifdef __cplusplus
extern "C" {
#endif
struct intpair {
int a;
int b;
char c;
};
typedef struct intpair intpair;
#define ADD_PROG 0x23451111
#define ADD_VERS 1
#if defined(__STDC__) || defined(__cplusplus)
#define ADD 1
extern int * add_1(intpair *, CLIENT *);
extern int * add_1_svc(intpair *, struct svc_req *);
extern int add_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);
#else /* K&R C */
#define ADD 1
extern int * add_1();
extern int * add_1_svc();
extern int add_prog_1_freeresult ();
#endif /* K&R C */
/* the xdr functions */
#if defined(__STDC__) || defined(__cplusplus)
extern bool_t xdr_intpair (XDR *, intpair*);
#else /* K&R C */
extern bool_t xdr_intpair ();
#endif /* K&R C */
#ifdef __cplusplus
}
#endif
#endif /* !_ADD_H_RPCGEN */

<<ADD_CLIENT.C>>

#include "add.h"
void add_prog_1(char *host, int a, int b,char c)
{
CLIENT *clnt;
int *result_1;
intpair add_1_arg;
#ifndefDEBUG
clnt = clnt_create (host, ADD_PROG, ADD_VERS, "udp");
if (clnt == NULL) {
clnt_pcreateerror (host);
exit (1);
} else
{ add_1_arg.a
=
a;
add_1_arg.b = b;
add_1_arg.c = c;
printf("The parameters are %d %d %c\n", add_1_arg.a,add_1_arg.b,add_1_arg.c);
}
#endif /* DEBUG */
result_1 = add_1(&add_1_arg, clnt);
if (result_1 == (int *) NULL) {
clnt_perror (clnt, "call failed");
}
else {
printf("Result = %d\n", *result_1);
}
#ifndefDEBUG
clnt_destroy (clnt);
#endif /* DEBUG */
}
int main(int argc, char *argv[])
{ char *
host, c; int a, b;
if (argc != 5)
{
printf ("usage: %s server_host num1 num2\n", argv[0]); exit(1);
}
host = argv[1];
if ((a = atoi(argv[2])) == 0 && *argv[2] != '0')
{
fprintf(stderr, "invalid value: %s\n", argv[2]); exit(1);
}
if ((b = atoi(argv[3])) == 0 && *argv[3] != '0')
{
fprintf(stderr, "invalid value: %s\n", argv[3]); exit(1);
} if ((c
=
*(argv[4])) == 0
&& *
argv[2] != '
0')
{
fprintf(stderr, "invalid value: %s\n", argv[2]); exit(1);
}
add_prog_1(host, a, b, c);
}


ADD_CLNT.C
/*
* Please do not edit this file.
* It was generated using rpcgen.
*/
#include <memory.h> /* for memset */
#include "add.h"
/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };
int *
add_1(intpair *argp, CLIENT *clnt)
{
static int clnt_res;
memset((char *)&clnt_res, 0, sizeof(clnt_res));
if (clnt_call (clnt, ADD,
(xdrproc_t) xdr_intpair, (caddr_t) argp,
(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
TIMEOUT) != RPC_SUCCESS) {
return (NULL);
}
return (&clnt_res);
}


<<AD_SERVER.C>>

#include "add.h"
int *
add_1_svc(intpair *argp, struct svc_req *rqstp)
{
static int result;
printf("Calling add function\n");
printf("Parameters: %d, %d, %c\n", argp->a, argp->b,argp->c);
if(argp->c == '+')
result = argp->a + argp->b;
else if(argp->c == '-')
result = argp->a - argp->b;
else if(argp->c == 'x')
result = argp->a * argp->b;
else if(argp->c == '/')
result = argp->a / argp->b;
else if(argp->c == '%')
result = argp->a % argp->b;
printf("Returning: %d\n", result);
return &result;
}


ADD_SVC.C
#include "add.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif
static void
add_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
union {
intpair add_1_arg;
} argument;
char *result;
xdrproc_t _xdr_argument, _xdr_result;
char *(*local)(char *, struct svc_req *);
switch (rqstp->rq_proc) {
case NULLPROC:
(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
return;
case ADD:
_xdr_argument = (xdrproc_t) xdr_intpair;
_xdr_result = (xdrproc_t) xdr_int;
local = (char *(*)(char *, struct svc_req *)) add_1_svc;
break;
default:
svcerr_noproc (transp);
return;
}
memset ((char *)&argument, 0, sizeof (argument));
if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
svcerr_decode (transp);
return;
}
result = (*local)((char *)&argument, rqstp);
if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
svcerr_systemerr (transp);
} if (!svc_freeargs (
transp, (
xdrproc_t) _
xdr_argument, (
caddr_t) &
argument)) {
fprintf (stderr, "%s", "unable to free arguments");
exit (1);
}
return;
}
int
main (int argc, char **argv)
{
register SVCXPRT *transp;
pmap_unset (ADD_PROG, ADD_VERS);
transp = svcudp_create(RPC_ANYSOCK);
if (transp == NULL) {
fprintf (stderr, "%s", "cannot create udp service.");
exit(1);
} if (!svc_register(transp, ADD_PROG, ADD_VERS, add_prog_1, IPPROTO_UDP)) {
fprintf (stderr, "%s", "unable to register (ADD_PROG, ADD_VERS, udp).");
exit(1);
}
transp = svctcp_create(RPC_ANYSOCK, 0, 0);
if (transp == NULL) {
fprintf (stderr, "%s", "cannot create tcp service.");
exit(1);
} if (!svc_register(transp, ADD_PROG, ADD_VERS, add_prog_1, IPPROTO_TCP)) {
fprintf (stderr, "%s", "unable to register (ADD_PROG, ADD_VERS, tcp).");
exit(1);
}
svc_run ();
fprintf (stderr, "%s", "svc_run returned");
exit (1);
/* NOTREACHED */
}


<<ADD_XDR.C>>
#include "add.h"
bool_t
xdr_intpair (XDR *xdrs, intpair *objp)
{
register int32_t *buf;
if (!xdr_int (xdrs, &objp->a))
return FALSE;
if (!xdr_int (xdrs, &objp->b))
return FALSE;
if (!xdr_char (xdrs, &objp->c))
return FALSE;
return TRUE;
}





//EX11.Evaluation of TCP and UDP connections sharing a bottleneck link :
//#Create a simulator object

set ns [new Simulator]
$ns color 1 Blue
$ns color 2 Red
#Open the nam trace file
set nf [open out.nam w]
$ns namtrace-all $nf
#Define a 'finish' procedure
proc finish {} {
global ns nf
$ns flush-trace
#Close the trace file
close $nf
#Execute nam on the trace file
exec nam out.nam &
exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns simplex-link $n3 $n2 0.3Mb 100ms DropTail
$ns duplex-link $n3 $n4 0.5Mb 40ms DropTail
$ns duplex-link $n3 $n5 0.5Mb 40ms DropTail
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n3 $n4 orient right-up
$ns duplex-link-op $n3 $n5 orient right-down
$ns queue-limit $n2 $n3 10
#Create a TCP agent and attach it to node n0 and set connection between 0-4
set tcp [new Agent/TCP/Newreno]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set window_ 8000
$tcp set packetSize_ 512
# Create a FTP over TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
#Create a UDP agent and attach it to node n1 connection between 1-5
set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0
set null0 [new Agent/Null]
$ns attach-agent $n5 $null0
$ns connect $udp0 $null0
$udp0 set fid_ 2
# Create a CBR traffic source and attach it to udp0
set cbr [new Application/Traffic/CBR]
$cbr set type_ CBR
$cbr set packet_size_ 1024
$cbr set rate_ 0.01mb
$cbr set random_ false
$cbr attach-agent $udp0
#Schedule events for the CBR agent
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 4.5 "$ftp stop"
$ns at 5.0 "$cbr stop"
#Call the finish procedure after 5 seconds simulation time
$ns at 5.0 "finish"
#Run the simulation
$ns run


//EX12. Performance of MAC Protocols:
#Create a simulator object

set ns [new Simulator]
$ns color 1 Blue
$ns color 2 Red
#Open the nam trace file
set nf [open out.nam w]
$ns namtrace-all $nf
#Define a 'finish' procedure
proc finish {} {
global ns nf
$ns flush-trace
#Close the trace file
close $nf
#Execute nam on the trace file
exec nam out.nam &
exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns simplex-link $n3 $n2 0.3Mb 100ms DropTail
set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms LL QueueDropTail MAC/802_3 Channel]
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns queue-limit $n2 $n3 5
#Create a TCP agent and attach it to node n0 and set connection between 0-4
set tcp [new Agent/TCP/Newreno]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set window_ 8000
$tcp set packetSize_ 512
# Create a FTP over TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
#Create a UDP agent and attach it to node n1 connection between 1-5
set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0
set null0 [new Agent/Null]
$ns attach-agent $n5 $null0
$ns connect $udp0 $null0
$udp0 set fid_ 2
# Create a CBR traffic source and attach it to udp0
set cbr [new Application/Traffic/CBR]
$cbr set type_ CBR
$cbr set packet_size_ 1024
$cbr set rate_ 0.01mb
$cbr set random_ false
$cbr attach-agent $udp0
#Schedule events for the CBR agent
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 4.5 "$ftp stop"
$ns at 5.0 "$cbr stop"
#Call the finish procedure after 5 seconds simulation time
$ns at 5.0 "finish"
#Run the simulation
$ns run



//EX13. Distance Vector Routing :-
Program:
#Create a simulator object
set ns [new Simulator]
$ns color 1 Blue
$ns color 2 Red
#Open the nam trace file
set nf [open out.nam w]
$ns namtrace-all $nf
#Define a 'finish' procedure
proc finish {} {
global ns nf
$ns flush-trace
#Close the trace file
close $nf
#Execute nam on the trace file
exec nam out.nam &
exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns simplex-link $n3 $n2 0.3Mb 100ms DropTail
set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms LL QueueDropTail MAC/802_3 Channel]
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns queue-limit $n2 $n3 5

#Create a TCP agent and attach it to node n0 and set connection between 0-4
set tcp [new Agent/TCP/Newreno]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set window_ 8000
$tcp set packetSize_ 512
# Create a FTP over TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
#Create a UDP agent and attach it to node n1 connection between 1-5
set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0
set null0 [new Agent/Null]
$ns attach-agent $n5 $null0
$ns connect $udp0 $null0
$udp0 set fid_ 2
# Create a CBR traffic source and attach it to udp0
set cbr [new Application/Traffic/CBR]
$cbr set type_ CBR
$cbr set packet_size_ 1024
$cbr set rate_ 0.01mb
$cbr set random_ false
$cbr attach-agent $udp0
#Schedule events for the CBR agent
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 4.5 "$ftp stop"
$ns at 5.0 "$cbr stop"
#Call the finish procedure after 5 seconds simulation time
$ns at 5.0 "finish"
#Run the simulation
$ns run



//EX14 .Flooding on Link State Routing() :-
#Create a simulator object
set ns [new Simulator]
#Open the nam trace file
set nf [open out.nam w]
$ns namtrace-all $nf
$ns color 1 Blue
$ns color 2 Red
#Define a 'finish' procedure
proc finish {} {
global ns nf
$ns flush-trace
#Close the trace file
close $nf
#Execute nam on the trace file
#Run the simulation
exec nam out.nam &
$ns run
exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns simplex-link $n3 $n2 0.3Mb 100ms DropTail
$ns duplex-link $n3 $n4 0.5Mb 40ms DropTail
$ns duplex-link $n3 $n5 0.5Mb 40ms DropTail
$ns duplex-link-op $n0 $n2 orientright-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n3 $n2 orient left-down
$ns duplex-link-op $n3 $n4 orient right
$ns duplex-link-op $n3 $n5 orient right
#set the queue size to 10
$ns queue-limit $n2 $n3 10
#Setup a TCP connection over 0 and 4 and its flow id, window size, packet size
set tcp [new Agent/TCP/Newreno]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set window_ 8000
$tcp set packetSize_ 512
#SET FTP OVER TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
#Setup a UDP connection over 1 and 5. Set the flow id
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n5 $null
$ns connect $udp $null
$udp set fid_ 2
#Setup a CBR over UDP connection with type, packet size, rate, random fields
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1024
$cbr set rate_ 0.01mb
$cbr set random_ false
$ns rtproto LS
$ns rtmodel-at 10.0 down $n3 $n0
$ns rtmodel-at 15.0 down $n5 $n1
$ns rtmodel-at 30.0 up $n0 $n2
$ns rtmodel-at 20.0 up $n4 $n5
#Start and stop the cbr and ftp accordingly
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 4.5 "$ftp stop"
#Call the finish procedure after 5 seconds simulation time
$ns at 5.0 "finish"
#Run the simulation
$ns run



//EX15.Ad Hoc On-Demand Distance Vector Routing:-
set val(chan) Channel/WirelessChannel ; # channel type
set val(prop) Propagation/TwoRayGround ; # radio-propagation model
set val(netif) Phy/WirelessPhy ; # network interface type
set val(mac) Mac/802_11 ;# MAC type
set val(ifq) Queue/DropTail/PriQueue ; # interface queue type
set val(ll) LL ; # link layer type
set val(ant) Antenna/OmniAntenna ; # antenna model
set val(ifqlen) 50 ; # max packet in ifq ( use to assign #the buffering capacity of wireless
set val(nn) 3 ; # number of mobilenodes
set val(rp) AODV ; # routing protocol
set val(x) 500 ; # X dimension of topography
set val(y) 400 ; # Y dimension of topography
set val(stop) 150 ; # time of simulationend
set ns_ [new Simulator]
# MAC type
#newtset val(mac) Mac/802_11 ;
# MAC typerace (new format of trace file for wireless)
# for using this write as below
$ns_ use-newtrace
set tracefd [open simple.tr w]
set windowVsTime2 [open win.tr w]
set namtrace [open simple.nam w]
# trace-all $filename causes trace objects to be pushed on all links. If you only want to trace one link, there's no need for this ov
#erhead. Saving is about 14 KB/link.
$ns_ trace-all $tracefd
$ns_ namtrace-all-wireless $namtrace $val(x) $val(y)
# Topographyis the study of Earth's surface shape and features or those of planets, #moons, and asteroids
# set up topography object
#Create and configure topography object (Used for mobile scenario)
set topo [new Topography]
#The load_flatgrid object is used to specify a 2-D terrain. Support is available
#for simulation of 3D terrains for more realistic depiction of scenarios.
$topo load_flatgrid $val(x) $val(y)
# GOD or General Operations Director is a ns-2 simulatorobject, which is used to store global information about the state of the
#environment, network, or nodes that an omniscient observer would have, but that should not be made known to any participant in the simulation
create-god $val(nn)
# configure the nodes
$ns_ node-config -adhocRouting $val(rp) \
-llType $val(ll)\
-macType $val(mac)\
-ifqType $val(ifq) \
-ifqLen $val(ifqlen)\
-antType $val(ant)\
-propType $val(prop)\
-phyType $val(netif)\
-channelType $val(chan)\
-topoInstance $topo\
-agentTrace ON\
-routerTrace ON\
-macTrace ON\
-movementTrace ON
# Create the specified number of nodes [$val(nn)] and "attach" them
# to the channel.
for {set i 0} {$i < $val(nn) } { incr i } {
set node_($i) [$ns_ node]
}
#By default, a node is specified as a unicast node.
# If a multicast protocol is desired, a #separate clause has to be specified during simulator initialization-
# set ns [new Simulator -multicast on]
# Provide initial location of mobilenodes
$node_(0) set X_ 5.0
$node_(0) set Y_ 5.0
$node_(0) set Z_ 0.0
$node_(1) set X_ 490.0
$node_(1) set Y_ 285.0
$node_(1) set Z_ 0.0
$node_(2) set X_ 150.0
$node_(2) set Y_ 240.0
$node_(2) set Z_ 0.0
# Generation of movements
$ns_ at 10.0 "$node_(0) setdest 250.0 250.0 3.0"
$ns_ at 15.0 "$node_(1) setdest 45.0 285.0 5.0"
$ns_ at 110.0 "$node_(2) setdest 480.0 300.0 5.0"
# Set a TCP connection between node_(0) and node_(1)
set tcp [new Agent/TCP/Newreno]
$tcp set class_2
set sink [new Agent/TCPSink]
$ns_ attach-agent $node_(0) $tcp
$ns_ attach-agent $node_(1) $sink
$ns_ connect $tcp $sink
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ns_ at 10.0 "$ftp start"
# Printing the window size
proc plotWindow {tcpSource file}
{
global ns_
set time 0.01
set now[$ns_ now]
set cwnd [$tcpSource set cwnd_]
puts $file "$now $cwnd"
$ns_ at [expr $now+$time] "plotWindow$tcpSource$file"
}
$ns_ at 10.1 "plotWindow$tcp$windowVsTime2"
# Define node initial position in nam
for {set i 0} {$i < $val(nn)} { incr i } {
# 30 defines the node size for nam
$ns_ initial_node_pos $node_($i) 30
}
# Telling nodes when the simulation ends
for {set i 0} {$i < $val(nn) } { incr i } {
$ns_ at $val(stop) "$node_($i) reset";
}
# ending nam and the simulation
$ns_ at $val(stop) "$ns_ nam-end-wireless $val(stop
)"
$ns_ at $val(stop) "stop"
$ns_ at 150.01 "puts \"end simulation\" ; $ns_ halt
"
proc stop {} {
global ns_ tracefd namtrace
$ns_ flush-trace
close $tracefd
close$namtrace
}
$ns_ run
