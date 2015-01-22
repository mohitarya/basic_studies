#ifndef __SHM__
#define __SHM__

#define TXT_SIZE 2048

struct shared_data_st {
	int data_written;
	char some_txt[TXT_SIZE];
};

#endif
