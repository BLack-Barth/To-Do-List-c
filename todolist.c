#include <stdio.h>
#include <string.h>
#define MAX_COLOS 50
#define MAX_TASKS 20

void addTask(char task[MAX_TASKS][MAX_COLOS], int task_index){
    printf("Enter the task: ");
    getchar();
    fgets(task[task_index], MAX_COLOS, stdin);
    printf("Task added successfully!\n");
}

void viewTask(char task[MAX_TASKS][MAX_COLOS], int count){
    if (count == 0) {
        printf("! The list is empty; there are no tasks currently !\n");
        return;
    }
    printf("=== Your To-Do-List ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s", i + 1, task[i]);
    }
    printf("---------------------------------\t .the number of tasks = %d\n", count);
}

int deletTask(char task[MAX_TASKS][MAX_COLOS], int count){
    if (count == 0) {
        printf("There are no tasks to delete!\n");
        return count;
    }
    int task_num;
    printf("Enter the number of task you want to delete: ");
    scanf("%d", &task_num);
    
    if (task_num < 1 || task_num > count) {
        printf("The number does not exist!\n");
        return count;
    }
    
    int index_delete = task_num - 1;
    
    for (int i = index_delete; i < count - 1; i++) {
        strcpy(task[i], task[i + 1]);
    }
    count--;
    printf("Task deleted successfully!\n");
    return count;
}

int main(){
    char task[MAX_TASKS][MAX_COLOS];
    int count_task = 0;
    int choose;
    while (1) {
        printf("=== TO-DO LIST MANAGER ===\n");
        printf("1. Add Task\n2. View Tasks \n3. Delete Task \n4. Exit \nChoose an option: ");
        scanf("%d", &choose);
        switch (choose) {
        case 1:
            addTask(task, count_task);
            count_task++;
            break;
        case 2:
            viewTask(task, count_task);
            break;
        case 3:
            count_task = deletTask(task, count_task);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid option!\n");
            break;
        }
    }
    return 0;
}