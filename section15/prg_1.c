#include <stdio.h>
#define V 5
void init(int arr[][V])
{
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}
void addEdge(int arr[][V], int src, int dest)
{
    arr[src][dest] = 1;
}
void printAdjMatrix(int arr[][V])
{
    int i, j;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int adjMatrix[V][V];
    init(adjMatrix);
    int ch, e1, e2;
    while (ch != 3)
    {
        printf("1.Add edges\n2.Display\n3.Exit\nEnter your option:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the edges one:");
            scanf("%d", &e1);
            printf("Enter the edges two:");
            scanf("%d", &e2);
            addEdge(adjMatrix, e1, e2);
            break;

        case 2:
            printf("The Martix is\n");

            printAdjMatrix(adjMatrix);
            break;
        case 3:
            break;
        default:
            printf("Worng option");
        }
    }
    return 0;
}