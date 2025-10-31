#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi 
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#define SERVERPORT 1450

int main(int argc,char** argv)
{   
    //dichiarazione necessaria definizione della struttura
    struct sockaddr_in serv;

    //socket file descriptor (che è variabile di tipo intero)
    int socketfd //identificatore della socket
    char str1[30] = "ciao", str2[30]; //dati della socket
    //settaggio del socket locale
    //valorizzazione dei membri della struttura
    serv.sin_family=AF_INET; //dominio
    serv.sin_addr.s_addr=htnol(INADDR_ANY); //indirizzo
    serv.sin_port=htnos(SERVERPORT); //porta
    //creo la socket
    soscket(AF_INET,SOCK_STREAM,0);
    //richiesta connessione al server
    connect(socketfd,(struct sockaddr*)&serv,sizeof(serv));
    write(socketfd, str1, sizeof(str1));
    read(socketfd, str2, sizeof(str2));
    printf("Stringa ricevuta dal server");
    close(socketfd);

    return 0;
}
