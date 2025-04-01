#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    message.msg_type = 1;
    strcpy(message.msg_text, "Hello from message queue!");
    msgsnd(msgid, &message, sizeof(message), 0);

    printf("Message sent: %s\n", message.msg_text);


    
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Message received: %s\n", message.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}