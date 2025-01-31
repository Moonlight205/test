#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct{
    char data[MaxSize];
    int top;
}SqStack; //定义栈来储存左括号
bool bracketCheck(char str[],int length){
    SqStack S;
    InitStack(S); //初始化一个栈
    for(int i=0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            Push(S,str[i]);
        }else{
            if(StackEmpty(S))//扫描到右括号且当前栈空
                return false;
            char topElem;
            Pop(S,topElem); //栈顶元素出栈
            if(str[i]==')'&& topElem!='(')
                return false;
            if(str[i]==']'&& topElem!='[')
                return false;
            if(str[i]=='}'&& topElem!='{')
                return false;    
        }
    }
    return StackEmpty(S);
}
int main(){

} 