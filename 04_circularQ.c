#include<stdio.h>
#define MAX 5 

int queue[MAX];
int front = -1,rear = -1;

void enQ(int value)
{
    if((front == 0 && rear == MAX-1) || (front == rear+1) )
    {
        printf("Queue Overflow! Cannot insert %d\n",value);
    }
    else{
        if(front == -1) front = 0;

        rear = (rear +1)  % MAX ;
        queue[rear] = value;
        printf("%d inserted into the queue.\n",value);
    }

}

//function to delete an element from the queue :(DEQUEUE)
void deQ()
{
    if(front == -1)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    int ele = queue[front];
    
    if (front == rear) front = rear = -1;
    else front = (front+1) % MAX;
    
    printf("Deleted element : %d\n",ele);
    
}

//FUNTION TO DISPLAY THE ELEMENTS OF THE QUEUE
void display()
{
    if(front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements:\n");

        int i = front;
        while (1) {

            printf("%d\n",queue[i]);
            
            if (i == rear) break;
            i =  (i+1) % MAX;
        }
    }
}

//FUNCTION TO GET FRONT ELEMENT:
void displayFront()
{
    if(front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("The Front element is %d.\n",queue[front]);
}
void displayRear()
{
    if(front == -1 )
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("The Rear element is %d.\n",queue[rear]);
}
int main()
{
    int choice ,value;
    while(1)
    {
        printf("\nQueue Operations:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n5.Display Front\n6.Display Rear\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                enQ(value);
                break;

            case 2:
                deQ();
                break;

            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program!!!");
                return 0;
            case 5:
                displayFront();
                break;
            case 6:
                displayRear();
                break;

            default:
                printf("Invalid choice! PLease try again.\n");
        }
    }
    return 0;
}