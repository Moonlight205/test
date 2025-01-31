/*静态顺序表 */
/*
#include<iostream>
using namespace std;
#define MaxSize 10 //定义最大长度
typedef struct{
    int data[MaxSize]; //用静态的“数组”存放数据元素
    int length; //顺序表当前长度
}SqList;        //顺序表的类型定义

//初始化这个顺序表
void InitList(SqList &L){

    for(int i=0;i<MaxSize;i++){
        L.data[i] = 0;
    }
    L.length=0;//顺序表初始长度为
}


int main(){
    SqList L;    //声明一个顺序表
    InitList(L); //初始化
    //打印顺序表
    for(int i=0;i<MaxSize;i++){
        cout<<"data["<<i<<"]="<<L.data[i]<<endl;
    }
}
/*
//1.静态顺序表的插入（健壮性）
bool ListInsert(SqList &L,int i,int e){
    if(i<1||i>L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for(int j=L.length;j>=i;j--)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}
//2.静态顺序表的删除
bool ListDelete(SqList &L,int i,int &e){
    if(i<1||i>L.length)
        return false;
    e = L.data[i-1];
    for(int j=i;j<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}
/*
//顺序表的查找（未写健壮性代码)
//1.按位查找
ElemType GetElem(SeqList L,int i)
    return L.data[i-1];
//2.按值查找
ElemTtpe LocateElem(SeqList L,int e){
    for(int i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1； //返回的是位序
}
*/
//动态数组
#include<iostream>
#include<stdlib.h>
using namespace std;
#define InitSize 10
//定义顺序表
typedef struct{
    int*data;//ElemType
    int MaxSize;
    int length;
}SeqList;
//初始化
void InitList(SeqList&L){
    L.data=(int*)malloc(InitSize*sizeof(int));
    L.length=0;
    L.MaxSize = InitSize ;
    for(int i=0;i<L.MaxSize;i++){
        L.data[i] = 0;
    }
}
//增加动态数组的长度
void IncreaseSize(SeqList &L,int len){
    int *p = L.data;
    L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
    for(int i=0;i<L.length;i++){
        L.data[i]=p[i];//将数据复制到新区域
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}
int main(){
    SeqList L;
    InitList(L);
    //顺序表中插入元素
    int n;//插入元素个数
    cin>>n;
    L.length = n;
    for(int i=0;i<n;i++){
        cin>>L.data[i];
    }
    IncreaseSize(L,5);
    for(int j=InitSize;j<L.MaxSize;j++){
        cin>>L.data[j];
    }
    //打印顺序表
    for(int k=0;k<L.MaxSize;k++){
        cout<<"data["<<k<<"]="<<L.data[k]<<endl;
    }
}
