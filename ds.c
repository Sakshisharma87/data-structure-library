# include <stdio.h>
# include<stdlib.h>
# include<string.h>
void element(){
    
}
	struct s{
		int info;
		struct s *next;
	};
    struct tre{
        int info;
        struct tre *lc;
        struct tre *rc ;
    };
    typedef struct tre t;
t* new(int x){
      t *n;
      n=(t*)malloc(sizeof(t));
     n->info=x;
     n->lc=NULL;
     n->rc=NULL;
     return n;
}
t* insert(t* r,int x){
    if(r==NULL){
        return new(x);
    }
    else if(x>r->info){
      r->rc=insert(r->rc,x);
    }
    else{
        r->lc=insert(r->lc,x);
    }
    return r;
}
void array(int a){
   int i,x[100];
   printf("enter data:");
   for(i=0;i<a;i++){
     scanf("%d",&x[i]);
   }
   printf("the array is:");
   for(i=0;i<a;i++){
     printf("%d\n",x[i]);
   }
}
int link(int x, int y){
    char ch;
    typedef struct s node;
     node *ptr,*start,*next,*f,*r,*n;
   ptr=NULL;
    do{
    	n=(node*)malloc(sizeof(node));
    	printf("enter data:");
    	scanf("%d",&n->info);
    	if(ptr!=NULL){
    		ptr->next=n;
    		ptr=ptr->next;
		}
		else{
			start=n;
			ptr=n;
		}
		scanf("%c",&ch);
		printf("do you want to continue(enter y/n):");
		scanf("%c",&ch);
	}while(ch=='y');
	
	ptr->next=NULL;
   if(x==2){
        printf("\nthe linklist is:");
	}
   
   if(x==4){
    printf("the queue is:");
    f=start;
    r=ptr;
    
   }
    ptr=start;
	while(ptr!=NULL){
		printf("%d\n",ptr->info);
		ptr=ptr->next;
    }
    if(x==4 &&y==2){
       ptr=f;
       f=f->next;
       ptr=start;
       printf("the queue after deletion is:");
       ptr=f;
	while(ptr!=NULL){
		printf("%d\n",ptr->info);
		ptr=ptr->next;
    }
      free(ptr);
    }
}
int  push(int t,int m,int s[]){
     int i;
     if(t==m-1){
        printf("stack overflow");
        exit(0);
     }
     else{
        printf("enter element to insert:");
        scanf("%d",&i);
        t=t+1;
        s[t]=i;
        return t;
     }

}
int pop(int s[],int t){
    int i;
    if(t==-1){
        printf("stack underflow");
        exit(0);
    }
    else{
        i=s[t];
        t=t-1;
        return i;
    }


}
void transverse(int t,int s[]){
    int i;
    if(t==-1){
        printf("stack underflow");
        exit(0);
    }
    else{
        printf("the stack is:");
        for (i = t; i >=0; i--)
        {
            printf("%d\n",s[i]);
        }
        
    }
}
void inorder(t *r){
    // printf("the inorder transversal of tree :\n");
    if(r!=NULL){
        inorder(r->lc);
        printf("%d\n",r->info);
        inorder(r->rc);
    }

}
int main(){
    int a,b=1,n=1,i,z;
    struct s *p,*tr;
    t *root;
    char ch='y';
    printf("select data structure:\n1.array\n2.linklist\n3.stack\n4.queue\n5.tree(BST)\n");
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("enter the no. of element:(not more than 100 elements)");
        scanf("%d",&n);
        array(n);
        break;
        case 2:
         link(a,b);
         break;
         case 3:
        //   while(n==1){
         printf("(stack should not exceed 100 elements)\n");
         printf("select operation:-\n");
        //  scanf("%d",&b);
         int st[100];
         int top=-1;
         int max=100;
         while(n==1){
             printf("1.push\n2.pop\n3.traverse\n");
         scanf("%d",&b);
         switch (b)
         {
         case 1:
           top= push(top,max,st);
            break;
         case 2:
          printf("the deleted item is %d\n",pop(st,top));
          top=top-1;
          break;
            case 3:
            transverse(top,st);
            break;
         default:
         printf("incorrect choice...");
            break;
         }
         printf("do you want to continue (1/0):");
         scanf("%d",&n);

         } 
         break;
         case 4:
          printf("select operation\n1.insertion only\n2.insertion and deletion\n");
         scanf("%d",&b);
         link(a,b);
         break;
         case 5:
         printf("enter value of root node:");
         scanf("%d",&n);
          root=new(n);
         scanf("%c",&ch);
         printf("do you want to continue insertion(y/n):");
         scanf("%c",&ch);
        while(ch=='y'){
          printf("enter data:");
          scanf("%d",&z);
          insert(root,z);
           scanf("%c",&ch);
          printf("do you want to continue insertion(y/n):");
         scanf("%c",&ch);
        }
    printf("the inorder transversal of BST :\n");
         inorder(root);
         break;
    }
}