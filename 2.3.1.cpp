#include<iostream>
using namespace std;
typedef struct LNode{ //定义单链表节点类型
/*ElemType*/int data;    //每个节点存放一个数据元素
    struct LNode *next; //指针指向下一个节点
}LNode,*LinkList;
//初始化一个单链表（带头结点）
bool InitList(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode)); //分配一个头节点
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}
void test(){
    LinkList L; //声明一个指向单链表的指针
    //初始化一个空表
    InitList(L);
}
//一、创建单链表
/*初始最好都加上（习惯）  L->next=NULL;*/
//1.尾插法建立单链表
LinkList TailInsert(LinkList&L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));//头节点
    LNode *s,*r = L;  //r为表尾指针
    cin>>x;
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r = s;
        cin>>x;
    }
    r->next=NULL; //尾节点
    return L;
}
//2.头插法建立单链表
LinkList HeadInsert (LinkList&L){
    int x;
    LNode *s;
    L=(LinkList)malloc(sizeof(LNode));//头节点
    L->next=NULL; //初始为空链表
    cin>>x;       //输入结点的值
    while(x!=9999){ 
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s; //将新节点插入表中，L为头指针
        cin>>x;
    }
    return L;
}
// 二、单链表的插入、删除

//1.插入
//按位序插入（带头节点）
//在第i个位置插入元素 e (带头结点)
bool ListInsert(LinkList &L,int i,int e){
    if(i<1) return false;
    LNode *p;  
    int j=0;  //当前p指向的是第几个节点
    p = L;    //L指向头节点，头节点是第0个节点（不存数据）
    while (p!=NULL && j<i-1){//循环找到第i-1个节点
        p=p->next;
        j++;
    }
    if(p==NULL) return false; //i值不合法
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;  //将节点s连到p之后
    return true;
}
//在第i个位置插入元素 e (不带头结点)
/*
bool ListInsert(LinkList &L,int i,int e){
    if(i<1) return false;
    if(i=1){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L=s;
        return true;
    }
    LNode *p;  
    int j=1;  //当前p指向的是第几个节点
    p = L;    //L指向头节点，头节点是第0个节点（不存数据）
    while (p!=NULL && j<i-1){//循环找到第i-1个节点
        p=p->next;
        j++;
    }
    if(p==NULL) return false; //i值不合法
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;  //将节点s连到p之后
    return true;
}
*/
//指定节点的后插操作
bool InsertNextNode(LNode *p,int e){
    if(p==NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL) return false;//内存分配失败
    s->data = e;
    s->next=p->next;
    p->next=s;  //将节点s连到p之后
    return true;
}
//指定节点的前插操作
bool InsertPriorNode(LNode *p,int e){
    if(p==NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL) return false;//内存分配失败
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}
//2.删除
//按位序删除（带头结点）
bool ListDelete(LinkList &L,int i,int &e){
    if(i<1) return false;
    LNode *p;  
    int j=0;  //当前p指向的是第几个节点
    p = L;    //L指向头节点，头节点是第0个节点（不存数据）
    while (p!=NULL && j<i-1){//循环找到第i-1个节点
        p=p->next;
        j++;
    }
    if(p==NULL) return false; //i值不合法
    if(p->next == NULL) //第i-1个节点之后已无其他节点
    return false;
    LNode *q=p->next; //q指向被删除的结点
    e = q->data;      //用e返回元素的值
    p->next=q->next;  //将*节点从链中断开
    free(q);          //释放结点的存储空间
    return true;      //删除成功
}
//指定结点的删除
bool DeleteNode(LNode *p){
    if(p==NULL) return false;
    LNode *q=p->next;
    p->data=q->next->data;
    p->next=q->next;
    free(q);
    return true;
}
//三、单链表的查找
//1.按位查找
LNode *GetElem(LinkList L,int i){
    int j=1;
    LNode *p=L->next;
    if(i==0) return L;
    if(i<1)  return NULL;
    while(p!=NULL&&j<i){
        p = p->next;
        j++;
    }
    return p;
}
//2.按值查找
LNode *LocateElem(LinkList L,int e){
    LNode *p = L->next;
    while (p!=NULL&&p->data!=e)
        p = p->next;
    return p;
}
//3.求表长
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}
int main(){
    LinkList L;
    test();
    TailInsert(L);
    //HeadInsert(L);
    int e;
    LNode *p;
    //ListInsert(L, i, e);
    //InsertNextNode(p,e);
    //InsertPriorNode(p,e);
    //ListDelete(L,i,e);
    //DeleteNode(p);
    //GetElem(L,int i);
    //LocateElem(L,e);
    //Length(L);
    while(L->next!=NULL){
        L = L->next;
        cout<<L->data<<endl;
    }
}