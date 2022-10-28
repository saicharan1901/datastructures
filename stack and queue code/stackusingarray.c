#define max 5
int stack[50];
int top=-1;
void main(){
    int c;
    do{
	printf("\nEnter your choice-\n1.push\n2.pop \n3.peek\n4.display\n5.Exit");
    scanf("%d",&c);
    switch(c){
        case 1:
           push();
           break;
        case 2:
            pop();
            break;
        case 3:
            peek();   
            break;
        case 4:
            display();
            break; 	       
		 }
    }
    while(c!=5);
}
 void push(){
        int x;
        printf("enter the number to be pushed");
        scanf("%d",&x);
        if(top==max-1){
            printf("Overflow condition");
        }
        else{
            top++;
            stack[top]=x;
        }
}
void pop(){
    int x;
    printf("enter the number to be popped");
    scanf("%d",&x);
    if(top==-1){
        printf("Underflow");
    }
    else{
        x=stack[top];
        top--;
        printf("%d",x);
    }
}
void peek(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        printf("%d",stack[top]);
    }
}
void display(){
	int i;
    for(i=top;i>=0;i--){
        printf(" %d ",stack[i]);
    }
}