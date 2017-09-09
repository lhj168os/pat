#include "msg.h"
#include <unistd.h>
#include <string.h>
#include <memory.h>
#include <sys/types.h>

//计算校验码
static unsigned char msg_check(Msg *message)
{
	unsigned char s = 0;
	int i;
	for(i = 0; i < sizeof(message->head); i++){
		s += message->head[i];
	}
	for(i = 0; i < sizeof(message->buff); i++){
		s += message->buff[i];
	}
	return s;
}


/*
 *发送一个基于自定义协议的message
 *发送的数据存放在buff中
 */
int write_msg(int sockfd, char *buff, size_t len)
{
	Msg message;
	memset(&message, 0, sizeof(message));
	strcpy(message.head, "iotek2018");
	memcpy(message.buff, buff, len);
	message.checknum = msg_check(&message);
	if(write(sockfd, &message, 
				sizeof(message)) != sizeof(message)){
		return -1;
	}
}

/*
 *读取一个基于自定义协议的message
 *读取的数据存放在buff中
 */
int read_msg(int sockfd, char *buff, size_t len){
	Msg message;
	memset(&message, 0, sizeof(message));
	size_t size;
	if((size = read(sockfd, &message, sizeof(message))) < 0){
		return -1;
	}else if(size == 0){
		return 0;
	}
	unsigned char s = msg_check(&message);
	if((s == (unsigned char)message.checknum) 
			&& (!strcmp("iotek2018", message.head))){
		memcpy(buff, message.buff, len);
		return sizeof(message);
	}
	return -1;
}

