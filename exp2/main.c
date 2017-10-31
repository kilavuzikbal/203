#include <stdio.h>
#include <stdlib.h>

struct Stack{
    char value;
    struct Stack *sonraki;
};
typedef struct Stack stack;

struct Queue{
    char value;
    struct Queue *sonraki;
};
typedef struct Queue queue;

struct client_Server{
    queue *first;
    stack *last;
    int client_no;   /* if it is equal 0,it is server */
    int stack_element_size;
    int queue_elemen_size;
    int stack_max;
    int queue_max;
    queue *output;
    struct clientServer *sonraki;
};

typedef struct client_Server clientServer;
clientServer *node = NULL;


FILE * openFile(char *);
void addClientServer(int ,int ,int );
void addStack(clientServer *temprorary,char);
clientServer * findClientorServer(int );


int main()
{
    int how_many;
    /* input files are opening */
    FILE *file1=openFile("input1.txt");
    FILE *file2=openFile("input2.txt");

    fscanf(file1,"%d",&how_many);
    printf("%d",how_many);

    addClientServer(5,6,1);
    /* input files are closing */
    fclose(file1);
    fclose(file2);
}

/* this method open the files and return the pointer of files */
FILE * openFile(char *filename ){
    FILE * file;
    if((file = fopen(filename,"r"))==NULL){
        printf("%s file didn't open!!!",filename);
        return NULL;
    }else{
        return file;
    }
}

/* add clients and server in linkedList and create their first elements */
void addClientServer(int queueMax,int stackMax,int clientNo){
    clientServer *temprorary;
    if(node==NULL){
        node = (clientServer* )malloc(sizeof(clientServer));
        temprorary = node;

    }else{
        temprorary = node;
        while(temprorary->sonraki!=NULL){
            temprorary = temprorary->sonraki;
        }
        temprorary->sonraki = (clientServer* )malloc(sizeof(clientServer));
        temprorary = temprorary->sonraki;
    }
        temprorary->queue_elemen_size=0;
        temprorary->stack_element_size=0;
        temprorary->client_no= clientNo;
        temprorary->queue_max=queueMax;
        temprorary->stack_max=stackMax;
        temprorary->first=NULL;
        temprorary->last=NULL;
        temprorary->output=NULL;
        temprorary->sonraki=NULL;
}

/* Check client's stack is full?
 * if it is full,give a error message 1
 * else add the value on stack
 * increase the client_no value 1
 */
void addStack(clientServer *temprorary,char request){
    stack *temp;
    if(temprorary->last==NULL){
        temprorary->last=(stack *)malloc(sizeof(stack));
        temp=temprorary->last;
    }else{
        if(temprorary->stack_element_size < temprorary->stack_max){
            /* hata mesajý 1 */
        }else{
            temp=temprorary->last;
            while(temp->sonraki!=NULL){
                temp=temp->sonraki;
            }
            temp->sonraki=(stack *)malloc(sizeof(stack));
            temp=temp->sonraki;
        }
    }
    temp->value=request;
    temp->sonraki=NULL;
    temprorary->stack_element_size+=1;
}

/* find the will be calculated client and return its adress.if it is not exist return NULL*/
clientServer * findClientorServer(int find){
    clientServer *temprorary;
    while(temprorary!=NULL){
            if(find==temprorary->client_no){
                return temprorary;
            }
        temprorary = temprorary->sonraki;
    }
return NULL;
}






