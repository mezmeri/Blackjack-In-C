#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Type in size of array:");
    scanf("%d", &size);

    int *pSize = (int *)malloc(size * sizeof(int));

    if (pSize == NULL)
    {
        printf("Memory allocation unsuccesfull\n");
        exit(0);
    }
    else
    {
        printf("Memory has been succesfully allocated!\n");
        printf("Memory allocated: %d\n", sizeof(pSize));

        for (int i = 0; i < size; i++)
        {
            int input;
            printf("Type in value:");
            scanf("%d", &input);

            pSize[i] = input;
        }

        printf("The values are:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d, ", pSize[i]);
        }
    }

    free(pSize);
    printf("\n%d", sizeof(pSize));

    return 0;
}