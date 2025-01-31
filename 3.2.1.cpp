#include<iostream>
using namespace std;
/*队列顺序实现*/
#define MaxSize 10
typedef struct{
    int data[MaxSize];//静态数组
    int front,rear;//队头指针和队尾指针
    int tag; //最近进行的是删除/插入  0/1
}SqQueue;
//初始化队列
void InitQueue(SqQueue &Q){
    //初始时让队头队尾指针都指向0；
    Q.rear=Q.front=0;
}
//队列判空
bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front) //队空条件
        return false;
    else
        return true;
}
//入队
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear+1)%MaxSize==Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear=(Q.rear+1)%MaxSize;
    Q.tag = 1;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,int &x){
    if(Q.rear==Q.front) //队列判空
        return false; 
    x = Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    Q.tag = 0;
    return true;
}
//队满条件：front==rear&&tag==1
//队空条件：front==rear&&tag==0
int main(){
    SqQueue Q;
    InitQueue(Q);
    QueueEmpty(Q);
    int x;
    cin>>x;
    EnQueue(Q,x);
    DeQueue(Q,x);
}
/*队列链式实现*/
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;
//初始化队列（带头结点）
void InitQueue(LinkQueue &Q){
    //初始时 front,rear都指向头节点
    Q.front=Q.rear= new LinkNode;
    Q.front->next=NULL;
}
//队列判空（不带头节点）
bool IsEmpty(LinkQueue Q){
    if(Q.front==NULL)
        return true;
    else
        return false;
}
//入队（带头节点）
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s=new LinkNode;
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;//新结点插入到rear之后
    Q.rear=s;  //修改表尾指针
}
//入队（不带头结点）
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s=new LinkNode;
    s->data=x;
    s->next=NULL;
    if(Q.front == NULL){ //在空队列插入第一个元素
        Q.front = s;//修改队头队尾指针
        Q.rear = s;
    }else{
        Q.rear->next=s;//新结点插入到rear之后
        Q.rear=s;  //修改表尾指针
    }
}   
//出队（带头结点）
bool DeQueue(LinkQueue &Q,int &x){
    if(Q.front==Q.rear)
        return false;
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    delete p;
    return true;
}
//出队（不带头结点）
bool DeQueue(LinkQueue &Q,int &x){
    if(Q.front==NULL)
        return false;
    LinkNode *p=Q.front;
    x=p->data;
    Q.front=p->next;
    if(Q.rear==p){
        Q.front = NULL;
        Q.rear = NULL;
    }
    delete p;
    return true;
}
void testLinkQueue(){
    LinkQueue Q;  //声明一个队列
    InitQueue(Q); //初始化

}





