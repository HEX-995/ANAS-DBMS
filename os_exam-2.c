#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int fifoPageFaults(int ref[], int n, int frames)
{
    if (frames == 0)
        return n;
    int *mem = (int *)malloc(frames * sizeof(int));
    int front = 0, size = 0, faults = 0;

    for (int i = 0; i < n; i++)
    {
        int hit = 0;
        for (int j = 0; j < size; j++)
        {
            if (mem[j] == ref[i])
            {
                hit = 1;
                break;
            }
        }
        if (!hit)
        {
            faults++;
            if (size < frames)
            {
                mem[size++] = ref[i];
            }
            else
            {
                mem[front] = ref[i];
                front = (front + 1) % frames;
            }
        }
    }
    free(mem);
    return faults;
}

int lruPageFaults(int ref[], int n, int frames)
{
    if (frames == 0)
        return n;
    int *mem = (int *)malloc(frames * sizeof(int));
    int *last = (int *)malloc(frames * sizeof(int));
    int size = 0, faults = 0;

    for (int i = 0; i < frames; i++)
        last[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int pos = -1;
        for (int j = 0; j < size; j++)
        {
            if (mem[j] == ref[i])
            {
                pos = j;
                break;
            }
        }
        if (pos != -1)
        {
            last[pos] = i;
        }
        else
        {
            faults++;
            if (size < frames)
            {
                mem[size] = ref[i];
                last[size] = i;
                size++;
            }
            else
            {
                int lru = 0;
                for (int j = 1; j < frames; j++)
                    if (last[j] < last[lru])
                        lru = j;
                mem[lru] = ref[i];
                last[lru] = i;
            }
        }
    }
    free(mem);
    free(last);
    return faults;
}

int optimalPageFaults(int ref[], int n, int frames)
{
    if (frames == 0)
        return n;
    int *mem = (int *)malloc(frames * sizeof(int));
    int size = 0, faults = 0;

    for (int i = 0; i < n; i++)
    {
        int hit = 0;
        for (int j = 0; j < size; j++)
        {
            if (mem[j] == ref[i])
            {
                hit = 1;
                break;
            }
        }
        if (!hit)
        {
            faults++;
            if (size < frames)
            {
                mem[size++] = ref[i];
            }
            else
            {
                int farthest = -1, victim = -1;
                for (int j = 0; j < frames; j++)
                {
                    int k;
                    for (k = i + 1; k < n; k++)
                        if (ref[k] == mem[j])
                            break;
                    if (k > farthest)
                    {
                        farthest = k;
                        victim = j;
                    }
                }
                mem[victim] = ref[i];
            }
        }
    }
    free(mem);
    return faults;
}

int main()
{
    int n, frames;
    printf("length of reference string: ");
    scanf("%d", &n);

    int *ref = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("reference string ");
        scanf("%d", &ref[i]);
    }

    printf("number of frames: ");
    scanf("%d", &frames);

    int fifo = fifoPageFaults(ref, n, frames);
    int lru = lruPageFaults(ref, n, frames);
    int opt = optimalPageFaults(ref, n, frames);

    printf("FIFO Page Faults: %d\n", fifo);
    printf("FIFO Fault Rate: %.2f\n\n", (float)fifo / n);

    printf("LRU Page Faults: %d\n", lru);
    printf("LRU Fault Rate: %.2f\n\n", (float)lru / n);

    printf("Optimal Page Faults: %d\n", opt);
    printf("Optimal Fault Rate: %.2f\n\n", (float)opt / n);

    int best = fifo;
    if (lru < best)
        best = lru;
    if (opt < best)
        best = opt;

    if (best == opt)
        printf("Most Efficient: Optimal\n");
    else if (best == lru)
        printf("Most Efficient: LRU\n");
    else
        printf("Most Efficient: FIFO\n");

    free(ref);
    return 0;
}
