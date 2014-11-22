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
    // zstr_send (client, "hello");
    char *reply = zstr_recv (client);
    if (reply) {
        puts (reply);
        free (reply);
    }
    else
        puts ("-");

    zsock_destroy (&client);
    return 0;
}




// //  Hello World client
// #include <zmq.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>




// void checkRetCode(int rc)
// {
//     if ( rc < 0 )
//     {
//         printf("Invalid return code: %d\n", rc);
//         exit(rc);
//     }
// }

// int main (int argc, char** argv)
// {
//     if ( argc < 2 )
//     {
//         printf("No arguments given\n");
//         return -1;
//     }

//     const char* ip_base = argv[1];

//     zmq_pollitem_t items[256];
//     memset(items, 0, sizeof(items));
//     void* sockets[256];

//     // Set up the items for listening
//     for ( int i=0; i<256; ++i )
//     {
//         char uri[1024];
//         sprintf(uri, "tcp://%s.%d:5556", ip_base, i);
//         printf ("Seeking to server at URI '%s'\n", uri);

//         void *context = zmq_ctx_new ();
//         sockets[i] = zmq_socket (context, ZMQ_DEALER);
//         // printf("socket %d: %p\n", i, sockets[i]);

//         items[i].socket = sockets[i];
//         items[i].events = ZMQ_POLLIN;
//     }

//     // Poll for events
//     int rc = zmq_poll (items, 256, 2000);
//     checkRetCode(rc);

//     // Process messages from the sockets
//     int found = 0;
//     for ( int i=0; i<256; ++i )
//     {
//         if (items [i].revents & ZMQ_POLLIN)
//         {
//             printf("Possible hit\n");
//             char message[1000];
//             rc = zmq_recv (sockets[i], message, 1000, 0);
//             checkRetCode(rc);
//             printf("Found server: %s\n", message);
//             found = 1;
//         }
//     }
//     if ( !found )
//         printf("No servers found!\n");
//     return 0;
// }
