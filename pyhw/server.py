import zmq
import time

port = "5556"
context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:%s" % port)

while True:
    msg = socket.recv()
    print(msg)
    socket.send(b"world!")
    time.sleep(1)