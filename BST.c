#include<stdio.h>
#include<stdlib.h>


typedef struct  Node
{
    struct Node *left;
    int data;
    struct  Node *right;   
}node;



node* createNode(int data){
  node *newNode = (node*)malloc(sizeof(node));
newNode->left = NULL;
newNode->data = data;
newNode->right = NULL;
 return newNode;
}
node* insert(node *root,int data){
     if(root == NULL){
        return createNode(data);
     } 
     if(data< root->data){
        root->left = insert(root->left,data);
     }
     else if(data> root->data){
        root->right = insert(root->right,data);
     }
     return root;
}

void preorder(node *root){
   if(root!=NULL){
   printf("%d->",root->data);
   preorder(root->left);
   preorder(root->right);
   }
}
void inorder(node *root){
   if(root==NULL) return;
   inorder(root->left);
   printf("%d->",root->data);
   inorder(root->right);
}
void postorder(node *root){
   if(root==NULL) return;
   postorder(root->left);
   postorder(root->right);
   printf("%d->",root->data);
}

int menu(){
    
    system("cls");
    printf("\t\t\t\t-----------BINARY TREE-------------\n");
    printf("\t\t\t\t1.INSERT\n");
    printf("\t\t\t\t2.PRE-ORDER\n");
    printf("\t\t\t\t3.IN-ORDER\n");
    printf("\t\t\t\t4.POST-ORDER\n");
    printf("\t\t\t\t5.EXIT\n");
    printf("\n\t\t\t\tEnter choice:");
    int n;scanf("%d",&n);
    return n;
}

int main(){
     node *root=NULL;
    int ch;
     while(1){
       ch = menu();
    if(ch==1){
      printf("\n\t\t\t\tENTER DATA:");
      int d;scanf("%d",&d);
      root = insert(root,d);
      printf("\n\t\t\t\tData inseted");
      fflush(stdin);
      getchar();

    }
    else if(ch==2){
        system("cls");
        printf("PRE-ORDER:");
        preorder(root);
        fflush(stdin);
        getchar();
    }
    else if(ch==3){
         system("cls");
        printf("IN-ORDER:");
        inorder(root);
        fflush(stdin);
        getchar();
    }
    else if(ch==4){
        system("cls");
        printf("POST-ORDER:");
        postorder(root);
        fflush(stdin);
        getchar();
    }
    else if(ch==5){
        exit(0);
    }


     }
    return 0;
}