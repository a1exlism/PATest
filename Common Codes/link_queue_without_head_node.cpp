/*
  https://www.cnblogs.com/zangkuo/p/6143171.html
  不带头结点的链式队列进出队操作
*/
#include <stdio.h>
#include <stdlib.h>
#define ElementType int
typedef struct QNode *Queue;
typedef struct Node{
    ElementType Data;
    struct Node *Next;
};
typedef struct QNode{
    struct Node *front;
    struct Node *rear;
};
void InintQueue(Queue &PtrQ){//虽然是指针，但是没赋值之前也不能乱指
    PtrQ = (Queue)malloc(sizeof(struct QNode));
    PtrQ->front=PtrQ->rear=NULL;
}
 
bool EnQueue(Queue PtrQ, ElementType X){
    struct Node *RearCell = PtrQ->rear;
    struct Node *Tmp = (struct Node *)malloc(sizeof(struct Node));
    Tmp->Data = X;
    Tmp->Next=NULL;
    if(PtrQ->front==NULL)//队列为空，进第一个元素
        PtrQ->rear=PtrQ->front=Tmp;
    else{
        PtrQ->rear->Next = Tmp;
        PtrQ->rear = Tmp;
    }
    return true;
}
ElementType DeleteQ(Queue PtrQ){
    struct Node *FrontCell;
    ElementType FrontElem;
    if(PtrQ->front==NULL){
        printf("队列为空\n");
        return 1;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front==PtrQ->rear)//若队列中只有一个元素
        PtrQ->front=PtrQ->rear=NULL;//删除后置空
    else
        PtrQ->front = PtrQ->front->Next;
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}
bool Is_EmptyQ(Queue PtrQ){
    return PtrQ->front==NULL;
}
 
int main(){
    Queue PtrQ;
    InintQueue(PtrQ);
    for(int i = 0;i<10;i++)
        EnQueue(PtrQ,i);
    while(!Is_EmptyQ(PtrQ))
        printf("%d\n",DeleteQ(PtrQ));
    return 0;
}