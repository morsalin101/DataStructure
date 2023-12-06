#include<stdio.h>
#include<stdlib.h>


typedef struct  Node
{
    struct Node *left;
    int data;
    struct  Node *right;  
    int ht; 
}node;



node* createNode(int data){
node *newNode = (node*)malloc(sizeof(node));
newNode->left = NULL;
newNode->data = data;
newNode->right = NULL;
 return newNode;
}



int bf(node *root){
   
    if(root==NULL) return 0;

    int lefth =  height(root->left);
    int righth = height(root->right);

    return lefth- righth ; 


}

int height(node *root){
   
    if(root==NULL) return 0;
     int lh = height(root->left);
     int rh = height(root->right);
     
    if(lh > rh)
    return lh + 1;
    else
    return rh + 1;

     
}

int  search(node *root,int data){
  if(root==NULL) return 0;
  if(root->data == data) return 1;
   if(data < root->data)
    {
        return search(root->left,data);
    }
    else if(data > root->data)
    {
        return search(root->right,data);
    }
}

node* leftRotation(node *root){
    node *left_child  = root->right;
        root->right = left_child->left;
        left_child->left = root;

        root->ht = height(root);
        left_child->ht = height(left_child);

         return left_child;
}

node* rightRotation(node *root){
    node* right_child = root->left;
        root->left  = right_child->right;
        right_child->right = root;

        root->ht = height(root);
        right_child->ht = height(right_child);

    return right_child;
}

node* insert(node *root,int data){
     if(root == NULL){
        return createNode(data);
     } 
     if(data< root->data){
        root->left = insert(root->left,data);
        if(bf(root) == 2){
            if(data < root->left->data) root = rightRotation(root);
            else{
                root->left  = leftRotation(root->left);
                root = rightRotation(root);
            }
        }
     }
     else if(data> root->data){
        root->right = insert(root->right,data);
        if(bf(root) == -2){
            if(data > root->right->data) root = leftRotation(root);
            else{
                root->right = rightRotation(root->right);
                root = leftRotation(root);
            }
        }

     }
     root->ht = height(root);
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
    printf("\t\t\t\t5.SEARCH\n");
    printf("\t\t\t\t6.EXIT\n");
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
      printf("\n\t\t\t\tENTER DATA FOR SEARCHING:");
      int d;scanf("%d",&d);
      int flag = search(root,d);
      if(flag==1) printf("FOUND\n");
      else printf("NOT FOUND\n");
      fflush(stdin);
      getchar();
    }
    else if(ch==6){
        exit(0);
    }


     }
    return 0;
}
