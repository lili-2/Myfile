bool isValid(char* s)
{
    if(s==NULL)
        return false;
    char *stack =(char *)malloc(sizeof(char)* (strlen(s)+1));
    int top=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            stack[++top]=s[i];
        else if((s[i]==')'&&stack[top]=='(')||(s[i]==']'&&stack[top]=='[')||(s[i]=='}'&&stack[top]=='{'))
            top--;
        else    
            return false;
    }
    if(top==0)  
        return true;
    return false;
}
