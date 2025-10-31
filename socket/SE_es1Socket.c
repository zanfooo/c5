#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi 
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#define DIM 50
#define SERVERPORT 1450

int main(int argc,char** argv)
{   
    //dichiarazione necessaria definizione della struttura
    struct sockaddr_in serv;

    //socket file descriptor (che è variabile di tipo intero)
    int socketfd //identificatore della socket
    char str1[30] = "ciao", str2[30]; //dati della socket
    int soa;
    //settaggio del socket locale
    //valorizzazione dei membri della struttura
    serv.sin_family=AF_INET; //dominio
    serv.sin_addr.s_addr=htnol(INADDR_ANY); //indirizzo
    serv.sin_port=htnos(SERVERPORT); //porta
    //creo la socket
    soscket(AF_INET,SOCK_STREAM,0);
    //leghiamo l'indirizzo al transport endpoint
    bind(socketfd,(struct sockaddr*)&serv,sizeof(serv));
    listen(SOCKETFD, 10); //può attendere fino a 10 client

    while(1){
        printf("Server in ascolto.....\n");
        fflush(stodut); //pulisco la socket o il canale di comunicazione
        soa=accept
    }

    return 0;
}
