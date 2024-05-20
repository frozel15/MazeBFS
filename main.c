#include "bfs.h"
#include <conio.h>

int main() {
    // char *namafile = "Maze1.txt";
    char namafile[10];
    printf("Masukkan nama file: ");
    scanf("%s", namafile);
    clock_t s_time = clock();
    int row = 0, column = 0;
    if (getRowColumn(namafile, &row, &column)) {
        return 1;
    }

    int **maze;
    Coords start, end;
    initializeMaze(&maze, row, column); 
    addToMaze(namafile, maze, row, column, &start, &end);

    Node *head = malloc(sizeof(Node));
    setNextNull(head);
    head->prev = NULL;
    head->pos.x = start.x; head->pos.y = start.y;

    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    enqueue(queue, head);
    system("cls");

    solveBFS(queue, maze, row, column, end);
    clock_t e_time = clock();
    printf("True time spent: %f\n", (double)(e_time-s_time)/CLOCKS_PER_SEC);
    printf("Press any key to close program...");
    getch();
    return 0;
}

