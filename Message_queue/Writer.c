#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//Structure for message queue
//
struct Mesg_buffer
{
	long mesg_type;
	char mesg_text[100];
}message;

int main()
{
	key_t key;
	int msgid;

	// ftok to generate unique key
	key=ftok("progfile",65);

	//msgget create a message queue
	//and returns identifier
	msgid=msgget(key,0666| IPC_CREAT);
	message.mesg_type=1;
	printf("Write data : ");
	fgets(message.mesg_text,100,stdin);

	//msgsnd to send message
	msgsnd(msgid,&message,sizeof(message),0);

	printf("Data send is : %s \n",message.mesg_text);

	return 0;

}
