//index file allocation
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct block bloc;
struct file
{
    char filename[5];
    int no_of_block;
    struct block *start;
    int index;
};
struct block
{
    int filesize;
    struct block *next;
};
void main()
{
    int no,i,j,a,flag=0;
    char x[5];
    printf("enter total no of files");
    scanf("%d",&no);
    struct file S1[no];
    for(i=0;i<no;i++)
    {
        printf("enter filename and number of block ");
        scanf("%s", S1[i].filename);
        scanf("%d", &S1[i].no_of_block);
        if(S1[i].no_of_block==0)
        {
        	S1[i].index=0;
        	S1[i].start=NULL;
		}
		else
		{
			S1[i].index=1;
        S1[i].start=(bloc*)malloc(sizeof(bloc));
        printf("enter filesize of block 1 ");
        scanf("%d", &S1[i].start->filesize);
        S1[i].start->next=NULL;
        bloc *p=S1[i].start;
        for(j=2;j<=S1[i].no_of_block;j++)
        {
        	int data;
            printf("enter filesize of block %d ",j);
            scanf("%d",&data);
        p->next=(bloc*)malloc(sizeof(bloc));
        p=p->next;
		p->filesize=data;
        p->next=NULL;
        }
    }
    }
    printf("enter filename to which you want to add block ");
    scanf("%s",x);
    for(i=0;i<no;i++)
    {
    	a=strcmp(x,S1[i].filename);
        if(a==0)
		{
			flag=1;
		if(S1[i].index==0)
        {
            printf("Enter no. of block ");
            scanf("%d", &S1[i].no_of_block);
            S1[i].start=(bloc*)malloc(sizeof(bloc));
        printf("enter filesize of block 1 ");
        scanf("%d", &S1[i].start->filesize);
        S1[i].start->next=NULL;
            bloc *p=S1[i].start;
            for(j=2;j<=S1[i].no_of_block;j++)
            {
                int data;
            printf("enter filesize of block %d ",j);
            scanf("%d",&data);
        p->next=(bloc*)malloc(sizeof(bloc));
        p=p->next;
		p->filesize=data;
        p->next=NULL;
            }
        }
        else
        printf("file is not empty");
        printf("filename is %s ",S1[i].filename);
            printf("no. of block is %d ",S1[i].no_of_block);
            bloc *p=S1[i].start;
            for(j=1;j<=S1[i].no_of_block;j++)
            {
                printf("filesize of block %d is %d ",j,p->filesize);
                p=p->next;
            }
    }}
    if(flag!=1)
    printf("file not found");
    getch();
}
