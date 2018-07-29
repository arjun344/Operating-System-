#include<stdio.h>
    #include<stdlib.h>
    // Linked list to keep track of allocated blocks
    struct Node
    {
        int start, end, number, size;
        struct Node *next;
    };
    // Insert a node when a new process is allocated
    void insert_allocated(struct Node **head, int size, int start)
    {
        // ‘size’ is the size of process, ‘start’ is the starting address of                ‘free’linked list before // allocating the new process
        struct Node* new_node = NULL;
        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node -> start = start;
        new_node -> end = start + size;
        new_node -> size = size;
        if((*head) == NULL)  // check if head is null
        {
            (*head) = new_node;
            return;
        }
        struct Node* pointer1 = NULL;
        pointer1 = (struct Node*)malloc(sizeof(struct Node));
        pointer1 = (*head);
        struct Node* pointer2 = NULL;
        pointer2 = (struct Node*)malloc(sizeof(struct Node));
        pointer2 = (*head);
        pointer1 = pointer1 -> next;
        while(pointer1 != NULL)  // insert node at the tail of linked list
        {
            pointer2 = pointer1;
            pointer1 = pointer1 -> next;
        }
        pointer2 -> next = new_node;
    }   

    int move_allocated(struct Node **head, int num_process)
    {
        int free_start;
        int current_proc = 1;
        struct Node* pointer = NULL;
        pointer = (struct Node*)malloc(sizeof(struct Node));
        pointer = (*head);
        struct Node* pointer_prev = NULL;
        pointer_prev = (struct Node*)malloc(sizeof(struct Node));
        pointer_prev = (*head);
        while(current_proc != num_process)  // search for process                                           ‘num_process’
        {
            if(current_proc = num_process - 1)
                pointer_prev = pointer;
            pointer = pointer -> next;
            current_proc++;
        }
        pointer_prev -> next = pointer -> next; 
        int size_current = pointer -> size;
        pointer = pointer -> next;
        while(pointer != NULL)
        {
            if(pointer -> next == NULL)
            {
                free_start = pointer -> end;  // change start address of                                                ‘free’ linked                                               list
            }
            pointer -> start -= size_current;  // shift start and end address of                                    ‘allocated’     linked // list
            pointer -> end -= size_current;
            pointer = pointer -> next;
            }
            return size_current;
        }
        // print linked list
        void print(struct Node **head)
        {
        struct Node* pointer = NULL;
        pointer = (struct Node*)malloc(sizeof(struct Node));
        pointer = (*head);
        while(pointer != NULL)
        {
            printf("%d %d\n", pointer -> start, pointer -> end);
            pointer = pointer -> next;
        }
    }
    int main()
    {
        int n;
        printf("Enter number of processes:");
        scanf("%d", &n);
        int a[1024];   // array which stores processes.
        struct Node* free = NULL;
        struct Node* allocated = NULL;
        free = (struct Node*)malloc(sizeof(struct Node)); // Linked list for free                                               memory
        allocated  = (struct Node*)malloc(sizeof(struct Node)); // Linked list for                                              allocated                                               memory
            free -> start = 0;  // Initially, whole memory is free
            free -> end = 1024;
            free -> next = NULL;
        printf("Enter size of %d processes:\n", n);
        for(int i = 0; i < n; i++)
        {
            int size;
            scanf("%d", &size);
            int ref = free -> start;
            free -> start += size;  // increment start address of ‘free’ linked                                             list by                                                 size  // process
            insert_allocated(&allocated, size, ref); // insert a node for                                           allocated memory
        }
        printf("Allocated Linked list:\n");
        print(&allocated);
        printf("Free linked list:\n");
        print(&free);
        printf("Enter number of processes to delete:");
        int num_del;
        scanf("%d", &num_del);
        printf("Enter process numbers:\n");
        for(int i = 0; i < num_del; i++)
        {
            int num_process;
            scanf("%d", &num_process);
            int free_start = move_allocated(&allocated, num_process);      //           make    memory // allocation contiguous by calling the function                                         ‘move_allocated’
            // printf("%d\n", free_start);
            free -> start -= free_start;  // change start address of ‘free’ linked                                                  list
        }
        printf("Allocated Linked list:\n");
        print(&allocated);
        printf("Free linked list:\n");
        print(&free);
        printf("Enter number of processes to add:");
        int add_process;
        scanf("%d", &add_process);
        printf("Enter size of processes to add:\n");
        for(int i = 0; i < add_process; i++)
        {
            int size;
            scanf("%d", &size);
            int ref = free -> start;
            free -> start += size;
            insert_allocated(&allocated, size, ref); // insert a node for                                           allocated memory
        }
        printf("Allocated Linked list:\n");
        print(&allocated);
        printf("Free linked list:\n");
        print(&free);
    }