#define max 5
int queue[50];
int front=-1,rear=-1;
void main(){
    int c;
    do{
	printf("\nEnter your choice-\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.Exit");
    scanf("%d",&c);
    switch(c){
        case 1:
           enqueue();
           break;
        case 2:
            dequeue();
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
void enqueue(){
    int x;
    printf("enter the number to be added");
    scanf("%d",&x);
        if(rear==max-1){
            printf("Overflow condition");
        }
        else  if(front==-1 && rear==-1){
            front=rear=0;
            queue[rear]=x;
        }
        else{
            rear++;
            queue[rear]=x;
        }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("underflow condition");
    }
    else if(front==rear){
        front=rear-1;
    }
    else{
        printf("%d",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else{
        int i;
        for(i=front;i<=rear;i++){
            printf(" %d ",queue[i]);
        }
    }
}
void peek(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else{
        printf("%d",queue[front]);
    }
}