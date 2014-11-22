#include <czmq.h>

int main (int argc, char** argv) {
    zsock_t *client = zsock_new (ZMQ_DEALER);
    int i;
    for (i = 0; i < 255; i++)
    {
        int port = 5556;
        // printf ("Seeking to server at '%s.%d:%d'\n", argv [1], i, port);
        zsock_connect (client, "tcp://%s.%d:%d", argv [1], i, port);
    }

    zsock_set_rcvtimeo (client, 2000);

    while ( 1 )
    {
        char *reply = zstr_recv (client);
        if (reply) {
            puts (reply);
            free (reply);
        }
        else
        {
            puts ("-");
            break;
        }
    }

    zsock_destroy (&client);
    return 0;
}
