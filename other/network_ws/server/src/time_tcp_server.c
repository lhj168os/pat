#include<netdb.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<signal.h>
#include<time.h>

int sockfd;

void sig_handler(int signo)
{
	if(signo == SIGINT){
		printf("server close !\n");
		close(sockfd);
		exit(1);
	}
}

//输出连接上来的客户端信息
void out_addr(struct sockaddr_in *clientaddr)
{
	//网络字节序转主机字节序
	int port = ntohs(clientaddr->sin_port);
	char ip[16];
	memset(ip, 0, sizeof(ip));
	//ip地址转换成点分十进制
	inet_ntop(AF_INET, 
			&clientaddr->sin_addr.s_addr, ip, sizeof(ip));
	printf("client: %s(%d) connected\n", ip, port);
}

void do_service(int fd)
{
	//获取系统时间
	long t = time(0);
	char *s = ctime(&t);
	size_t size = strlen(s) * sizeof(char);
	//向客户端写时间
	if(write(fd, s, size) != size){
		perror("write error!\n");
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("usage: %s #port\n", argv[0]);
		exit(1);
	}
	if(signal(SIGINT, sig_handler) == SIG_ERR){
		perror("signal sigint error");
		exit(1);
	}

	/* 步骤1: 创建 socket(套接字)
	 * 注: socket创建在内核中,是一个结构体
	 * AF_INET: IPV4
	 * SOCK_STREAM: TCP协议
	 */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		perror("socket error!\n");
		exit(1);
	}

	/* 步骤2: 调用bind函数将socket和地址
	 *		  (包括ip, port)进行绑定
	 */
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;   //ipv4
	serveraddr.sin_port = htons(atoi(argv[1]));  //port
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
	{
		perror("bind error!\n");
		exit(1);
	}

	/*步骤三:
	 * listen监听 
	 * 参数二:队列长度
	 * */
	if(listen(sockfd, 10) < 0){
	perror("listen error!\n");
		exit(1);
	}

	/*步骤四:
	 * 调用accept() 函数获取连接上来的客户端
	 *
	 * */
	struct sockaddr_in clientaddr;
	socklen_t clientaddr_len = sizeof(clientaddr);
	while(1){
		int fd = accept(sockfd, 
				(struct sockaddr*) &clientaddr, &clientaddr_len);
		if(fd < 0){
			perror("accept error!\n");
			continue;
		}

		/*步骤五:
	 	* uising io function (read/write) communicat with client was linked 
	 	*
	 	* */
		out_addr(&clientaddr);
		do_service(fd);

		/*步骤六:
	 	* close the socket
	 	* */
		close(fd);
	}
	return 0;
}
