// CLIENT
#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define SERVERPORT 1450

int main(){

    struct sockaddr_in servizio;
    char stringa[20];
    int socketfd, fromlen = sizeof(servizio);

    //ASSEGNAZIONE VALORI ALLA STRUTTURA
    servizio.sin_family= AF_INET;
    servizio.sin_addr.s_addr= htonl(INADDR_ANY);
    servizio.sin_port= htons(SERVERPORT);

    //CREAZIONE DELLA SOCKET
    if((socketfd= socket(AF_INET,SOCK_STREAM,0))==-1){
        printf("Errore nella chiamata alla system call socket");
        exit(0);
    }

    if(connect(socketfd,(struct sockaddr*) &servizio, sizeof(servizio))==-1){
        printf("Errore nella chiamata alla system call connect");
        exit(0);
    }
    printf("Inserisci una stringa: \n");
    scanf("%s", stringa);

    //INVIO STRINGA AL SERVER
    write(socketfd,stringa,sizeof(stringa));
    read(socketfd,stringa,sizeof(stringa));
    printf("Risposta del server %s\n", stringa);

    close(socketfd);
}
