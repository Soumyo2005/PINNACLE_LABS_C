#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_LENGTH 200

typedef struct {
    char description[MAX_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void display_menu() {
    printf("\nTo-Do List Manager\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Edit Task\n");
    printf("4. Mark Task as Complete\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    
    printf("Enter task description: ");
    getchar();
    fgets(tasks[task_count].description, MAX_LENGTH, stdin);
    tasks[task_count].description[strcspn(tasks[task_count].description, "\n")] = '\0';
    tasks[task_count].completed = 0;
    task_count++;
    printf("Task added successfully!\n");
}

void view_tasks() {
    if (task_count == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    
    printf("\nTask List:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s\n", i+1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
    }
}

void edit_task() {
    int task_num;
    view_tasks();
    
    if (task_count == 0) return;
    
    printf("Enter task number to edit: ");
    scanf("%d", &task_num);
    
    if (task_num < 1 || task_num > task_count) {
        printf("Invalid task number!\n");
        return;
    }
    
    printf("Enter new description: ");
    getchar();
    fgets(tasks[task_num-1].description, MAX_LENGTH, stdin);
    tasks[task_num-1].description[strcspn(tasks[task_num-1].description, "\n")] = '\0';
    printf("Task updated successfully!\n");
}

void mark_complete() {
    int task_num;
    view_tasks();
    
    if (task_count == 0) return;
    
    printf("Enter task number to mark as complete: ");
    scanf("%d", &task_num);
    
    if (task_num < 1 || task_num > task_count) {
        printf("Invalid task number!\n");
        return;
    }
    
    tasks[task_num-1].completed = 1;
    printf("Task marked as complete!\n");
}

int main() {
    int choice;
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_task(); break;
            case 2: view_tasks(); break;
            case 3: edit_task(); break;
            case 4: mark_complete(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}