#include <stdio.h>
#include <Stdlib.h>


struct node
{
    int info;
    struct node *link;
};


int count=0;
int oneTicketCost=1200;
struct node *emplist(struct node *start,int data);
struct node *beg(struct node *start,int data);
struct node *end(struct node *start,int data);
struct node *npos(struct node *start,int data,int pos);
struct node *delOnly(struct node * start,int data);
struct node *delBeg(struct node * start,int data);
struct node *delEnd(struct node * start,int data,int pos);
void disp(struct node *start);
int main()
{
    int ch,data,pos;
    int coachlen=72;
    struct node *start=NULL;

    printf("There is a train in the railway junction which often need to be repaired\n");
    printf("The train has some coaches and in each coach there are 72 seats available for passengers\n");
    printf("All the coaches are AC coach");
    printf("Sometimes some coach need to be removed\n");
    printf("Some of the operations you need to do in this train\n");
    printf("1. No. of Seats booked in an only coach\n");
    printf("2. No. of seats booked in the first coach\n");
    printf("3. No of seats booked in the last coach\n");
    printf("4. No of seats booked in nth coach\n");                            ;
    printf("5. Display the no. of seats booked in each coach\n");
    printf("6. Exit\n");
    printf("7. Removal of the only coach-data\n");
    printf("8. Removal of the first coach-data from the whole data\n");
    printf("9. Removal of coach-data from the last or from nth position\n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            if(start!=NULL)
            {
                printf("List is not empty\n");
                break;
            }
            printf("\nEnter Coach-data:");
            scanf("%d",&data);
            start=emplist(start,data);
            if(data>coachlen)
            {
                printf("You can only enter the value less than or equal to 72");
            }
            else
            {
                count=count+data;
            }
            break;

        case 2:
            printf("\nEnter Coach-data:");
            scanf("%d",&data);
            start=beg(start,data);
            if(data>coachlen)
            {
                printf("You can only enter the value less than or equal to 72");
            }
            else
            {
                count=count+data;
            }
            break;

        case 3:
            printf("\nEnter Coach-data:");
            scanf("%d",&data);
            start=end(start,data);
            if(data>coachlen)
            {
                printf("You can only enter the value less than or equal to 72");
            }
            else
            {
                count=count+data;
            }
            break;

        case 4:
            printf("\nEnter Coach-data:");
            scanf("%d",&data);
            if(data>coachlen)
            {
                printf("You can only enter the value less than or equal to 72");
            }
            else
            {
                count=count+data;
            }
            printf("\nEnter position:");
            scanf("%d",&pos);
            start=npos(start,data,pos);
            break;

        case 5:
            disp(start);
            break;

        case 6:
            exit(0);

        case 7:
            printf("\nEnter the only coach-data which you want to remove to update the no. of seats booked:");
            scanf("%d",&data);
            start=delOnly(start,data);
            break;

        case 8:
            printf("\nEnter the coach-data which you want to remove from the beginning to update the no. of seats booked:");
            scanf("%d",&data);
            start=delBeg(start,data);
            break;

        case 9:
            printf("\nEnter the coach-data which you want to remove from the end to update the no. of seats booked:");
            scanf("%d",&data);
            count=count-data;
            printf("\nEnter the position:");
            scanf("%d",&pos);
            start=delEnd(start,data,pos);
            break;

        default:
            printf("\nWrong choice");
            break;

        }
    }
    return 0;

}



struct node *emplist(struct node *start,int data)
{
    struct node *temp;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    start=temp;
    return start;
};

struct node *beg(struct node *start,int data)
{
    struct node *temp;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
    return start;
};


struct node *end(struct node * start,int data)
{

    struct node *temp,*p;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->info=data;
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=temp;
    temp->link=NULL;
    return start;
};


struct node *npos(struct node *start,int data,int pos)
{
    int i;
    struct node *temp,*p;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->info=data;
    if(pos==1)
    {
        temp->link=start;
        start=temp;
    }
    p=start;
    for(i=0;i<pos-1 && p!=NULL;i++)
    {
        p=p->link;
    }
    if(p==NULL)
    {
        printf("There are less than %d coach",pos);
    }
    else
    {
        temp->link=p->link;
        p->link=temp;
    }
    return start;
};


void disp(struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("No coach Available\n");
    }
    p=start;
    printf("Total seats booked in each coach:-");
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->link;
    }
    printf("\nTotal seats booked by the passengers for the journey till now is:%d",count);
    printf("\nTotal money collected by ticket booking till now is:%d",(oneTicketCost*count));
    return start;
}

struct node *delOnly(struct node *start,int data)
{
    struct node * temp;
    if(start==NULL)
    {
        printf("No coach Available\n");
        return start;
    }
    if(start->info==data)
    {
        temp=start;
        start=NULL;
        free(temp);
        return start;
    }
};

struct node *delBeg(struct node *start,int data)
{
    struct node * temp;
    if(start==NULL)
    {
        printf("No coach Available\n");
        return start;
    }
    if(start->info==data)
    {
        temp=start;
        start=start->link;
        free(temp);
        return start;
    }
};


struct node *delEnd(struct node * start,int data,int pos)
{
    struct node * temp,*p;
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==data)
        {
            temp=p->link;
            p->link=temp->link;
            free(temp);
            return start;
        }
        p=p->link;
    }
    printf("coach-data %d not found\n",data);
    return start;
};
