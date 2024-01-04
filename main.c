#include <stdio.h>
#include <string.h>

#define MAX_TASKS 25
#define MAX_STRING 100

struct Task {
    char title[MAX_STRING];
    char description[MAX_STRING];
    int priority;
    int status; // 1 for completed, 0 for incomplete
};

// Function to load tasks from "tasks.txt" file
void loadTasks(struct Task tasks[]) {
    FILE* file = fopen("tasks.txt", "r");
    if (file != NULL) {
        for (int i = 0; i < MAX_TASKS; ++i) {
            fscanf(file, "%s %s %d %d", tasks[i].title, tasks[i].description, &tasks[i].priority, &tasks[i].status);
        }
        fclose(file);
        printf("Tasks loaded successfully.\n");
    } else {
        printf("Unable to open file.\n");
    }
}

// Function to input task details from the user
void inputTaskData(struct Task* task) {
    printf("Enter task title: ");
    scanf("%s", task->title);

    printf("Enter task description: ");
    scanf("%s", task->description);

    printf("Enter task priority: ");
    scanf("%d", &task->priority);

    printf("Enter task status (1 for completed, 0 for incomplete): ");
    scanf("%d", &task->status);

    // Save information to "tasks.txt" file
    FILE* file = fopen("tasks.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s %d %d\n", task->title, task->description, task->priority, task->status);
        fclose(file);
        printf("Task information saved to file.\n");
    } else {
        printf("Unable to open file.\n");
    }
}

// Function to update task status
void updateTaskStatus(struct Task* task) {
    int newStatus;
    printf("Enter new task status (1 for completed, 0 for incomplete): ");
    scanf("%d", &newStatus);

    task->status = newStatus;
    printf("Task status updated successfully.\n");
}

// Recursive function to adjust task priority
void adjustPriority(struct Task* task) {
    if (task->priority > 0) {
        task->priority--;
        adjustPriority(task);
    }
}

// Function to display task information
void displayTaskInfo(struct Task tasks[]) {
    for (int i = 0; i < MAX_TASKS; ++i) {
        printf("Task %d:\n", i + 1);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Priority: %d\n", tasks[i].priority);
        printf("Status: %s\n\n", tasks[i].status ? "Completed" : "Incomplete");
    }
}

int main() {
    struct Task tasks[MAX_TASKS];

    // Load tasks from file
    loadTasks(tasks);

    // Input task data from the user
    for (int i = 0; i < MAX_TASKS; ++i) {
        inputTaskData(&tasks[i]);
    }

    // Update task status
    updateTaskStatus(&tasks[0]);

    // Adjust task priority recursively
    adjustPriority(&tasks[0]);

    // Display task information
    displayTaskInfo(tasks);

    return 0;
}
