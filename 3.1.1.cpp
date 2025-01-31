#include<iostream>
using namespace std;
/*顺序存储栈*/
#define MaxSize 10 //定义栈中元素的最大个数
typedef struct{
    int data[MaxSize]; //静态数组存放栈中元素
    int top; //栈顶指针
}SqStack;
//初始化栈
void InitStack(SqStack &S){
    S.top = -1; //初始化栈顶指针
}
//栈判空
bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
}
//新元素入栈
bool Push(SqStack &S,int x){
    if(S.top==MaxSize-1)  //栈满报错
        return false;
     //指针先加1，新元素入栈
    S.data[++S.top] = x;  
    return true;
}
//元素出栈
bool Pop(SqStack &S,int &x){
    if(S.top==-1)  //栈空报错
        return false;
    x=S.data[S.top--];//用x带回栈顶元素
    return true;
}
int main(){
    SqStack S;
    InitStack(S);
    StackEmpty(S);
    int x;
    cin>>x;
    Push(S,x);
    Pop(S,x);
}
/*链式存储栈*/
typedef struct Linknode{
    int data;
    struct Linknode *next;
}*LiStack;
//同单链表知识