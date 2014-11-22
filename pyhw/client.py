import zmq
import time

port = "5556"
context = zmq.Context()
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:%s" % port)

while True:
    socket.send(b"Hello, ")

    msg = socket.recv()
    print(msg)
    time.sleep(1)