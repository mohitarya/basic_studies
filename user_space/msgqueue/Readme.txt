Description:
	Program msg1 amd msg2 shows the basic implementation of the msg queue concept in the user space.
	msg1 - msg1 is used to send the msgs in the queue.
	msg2 - msg2 will receive the msgs from the queue and display them.

make:
	Execute make to create the binary file "msg1" and "msg2".

Execution:
	Execute binary file "msg1" and "msg2" in the different terminals and follow the instruction on the terminal.

Output:
	Terminal One(Sender):
	[root@localhost msgqueue]# ./msg1
	Input msg to send
	qq
	Input msg to send
	ss
	Input msg to send
	ss
	Input msg to send
	sdsd
	Input msg to send
	end
	[root@localhost msgqueue]#

	
	Terminal Two(Reciever):
	
	[root@localhost msgqueue]# ./msg2
	Recieved Msg = qq
	Recieved Msg = ss
	Recieved Msg = ss
	Recieved Msg = sdsd
	Recieved Msg = end
	[root@localhost msgqueue]#

