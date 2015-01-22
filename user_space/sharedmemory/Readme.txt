Description:
	This program display the implementation of the shared memory. 
	Here we have two programs one is consumer and other is producer.
	producer writes some data to the shared memory and consumer program reads it.

make:
	Execute the make file. It will create two binary one is "consumer"
	and other is "producer".

execution:
	Execute the Binary file "consumer" and "producer" in seprate terminals.
	And write some data to producer and it will apear in the consumer terminal.

Output:
	Producer terminal:
	[root@localhost sharedmemory]# ./producer
	Input the data and write end to finsh the writting
	Hiiii
	waiting for consumer to read
	waiting for consumer to read
	waiting for consumer to read
	Input the data and write end to finsh the writting
	end
	[root@localhost sharedmemory]#

	Consumer terminal:
	[root@localhost sharedmemory]# ./consumer
	Data Written = Hiiii

	Data Written = end

	[root@localhost sharedmemory]#

