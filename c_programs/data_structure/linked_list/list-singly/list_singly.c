#include<stdio.h>
#include<stdlib.h>

#include"node_t.h"
#include"list_t.h"
#include"list_operations.h"
#include"list_traversal.h"

int main(){              // 50 40 30 
    node_t *head = NULL; // head[.]->[40,.]->[50,x]
                                        
    int menu;
    do{
        printf("\n\nPick Choice\n");
        printf("\t1-Add Front, 2-Delete Front\n");
        printf("\t3-Traversal\n");
        printf("\t0-Exit\n");
        printf("Your Choice:"); scanf("%d",&menu);
        printf("\n");
        if(1 == menu){
            double salary = 0.0;
            printf("Enter data:"); scanf("%lf",&salary);
            push_front(&head, salary);
        }else if(2 == menu){
            if(head == NULL){
                printf("List is empty.\n");
            }else{
                double salary = front(head);
                pop_front(&head);
                printf("%.2lf is Deleted.\n",salary);
            }
        }else if(3 == menu){
            traversal(head);
        }else{
            printf("Application is shutting down....\n");    
        }
    }while((1 <= menu) && (menu <= 3));
    
    destroy(&head);
    return EXIT_SUCCESS;
}

