//  Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char** argv)
{
    char ip_port[1024];
    if ( argc < 2 )
        strcpy(ip_port, "localhost:5556");
    else
        strcpy(ip_port, argv[1]);

    char uri[1024];
    sprintf(uri, "tcp://%s", ip_port);

    printf ("Connecting to hello world server…\n");
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, uri);

    int request_nbr;
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
        char buffer [1000];
        printf ("Sending Hello %d…\n", request_nbr);
        zmq_send (requester, "Hello LT", 8, 0);
        zmq_recv (requester, buffer, 1000, 0);
        printf ("Received World (%s) %d\n", buffer, request_nbr);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
