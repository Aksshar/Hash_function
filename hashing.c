#include<stdio.h>

struct Node{
    int data;
    int status;
};

void Insert_new(int data,struct Node hash[])
{
    int key = data;
    int i;
    i = key % 11;
    if(hash[i].status == 1)
    {
        while(hash[i].status == 1)
        {
            i++;
        }
        hash[i].data = key;
        hash[i].status = 1;
    }
    else{
        hash[i].data = key;
        hash[i].status = 1;
    }
}

void Delete_Node(struct Node hash[],int key,int size)
{
    int i=0;
    while(i<size)
    {
        i++;
        if(hash[i].data==key)
        {
             hash[i].status = 0;
             hash[i].data = 0;
             printf("\nKey value is deleted\n");
        }
    }

}

int Search(struct Node hash[],int size,int key)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(hash[i].data == key)
        {
            return 1;
        }
    }
    return 0;
}

void display(struct Node hash[], int size)
{
    int i;
    printf("Elements in the hash table -> \n");
    for(i=0;i<size;i++)
    {
        printf(" %d ",hash[i].data);
    }
    printf("\n");
    
}




int main()
{
    int size,data,result;
    printf("####### - Hash table implementation - #######\n\n");
    printf("enter the size of the hash table :");
    scanf("%d",&size);
    struct Node hash[size];
     int i;

    for(i=0;i<size;i++)
    {
        hash[i].status = 0;
        hash[i].data = 0;
    }
    

    int res = 0;
    while(res!=5)
    {
    printf("===============================================\n");
    printf("1 : Insert an element to the hash table\n");
    printf("2 : Delete an element from the hash table\n");
    printf("3 : Search an element in the hash table\n");
    printf("4 : Display elements in the hash table\n");
    printf("5 : Exit\n\n");
    printf("===============================================\n");
    printf("Enter the Response");
    scanf("%d",&res);

    switch(res)
    {
        case 1 :printf("Enter the key to insert :");scanf("%d",&data);
                Insert_new(data,hash);break;
        case 2 :printf("Enter the key to Delete :");scanf("%d",&data);
                Delete_Node(hash,data,size);break;
        case 3 :printf("Enter the key to Search :");scanf("%d",&data);
                result = Search(hash,size,data);
                if(result==1) printf("Searching Success element exits\n");
                else printf("serching failed, element does not exits\n");
                break;
        case 4 :display(hash,size);break;
    }


  
    }



    return 0;
}