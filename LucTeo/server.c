//  Hello World server

#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main (void)
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5556");
    assert (rc == 0);

    while (1) {
        const char* msg = "LucTeo (blue shirt + red)";
        char buffer [1000];
        zmq_recv (responder, buffer, 1000, 0);
        printf ("Received Hello (%s)\n", buffer);
        sleep (1);          //  Do some 'work'
        zmq_send (responder, msg, sizeof(msg), 0);
    }
    return 0;
}