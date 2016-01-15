#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CONN_CAPABILITY = 10

#define TO 0
#define FROM 1

int main(int argc, char **argv) {
    int socket_id, socket_client;
    int *pipes[2] = (int *)malloc(2 * sizeof(int) * MAX_CONN_CAPABILITY);

    int client_counter;
    
    socket_id = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in listener;
    listener.sin_family = AF_INET; // socket type = ipv4
    listener.sin_port = htons(6668); // port # --> convert to network format
    listener.sin_addr.s_addr = INADDR_ANY; // bind to any incoming address

    bind(socket_id, (struct sockaddr *)&listener, sizeof(listener));

    listen(socket_id, 1);
    printf("<server> listening\n");

    socket_client = accept(socket_id, NULL, NULL);

}
