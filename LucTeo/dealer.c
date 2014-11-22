//  Hello World server

#include <czmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

void checkRetCode(int rc)
{
    if ( rc < 0 )
    {
        printf("Invalid return code: %d\n", rc);
        exit(rc);
    }
}

int main (void)
{
    printf("Starting dealer...\n");
    //  Socket to talk to clients
    zsock_t *server = zsock_new (ZMQ_DEALER);
    int rc = zsock_bind (server, "tcp://*:5556");
    checkRetCode(rc);

    printf("Hiding from others...\n");

    char* msg = "LucTeo (blue shirt + red)";
    int caught = 0;
    while ( 1 )
    {
        rc = zstr_send (server, msg);
        checkRetCode(rc);

        if ( !caught )
        {
            printf("I'm caught. :(\n");
            msg = "Too late, secret was secret but it's taken";
            caught = 1;
        }
    }

    // zsock_destroy (&server);
    return 0;
}