#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1048576
#define MAX_PROCESS_NAME 10

typedef struct
{
    char processName[MAX_PROCESS_NAME];
    int startAddress;
    int size;
} Process;

typedef struct
{
    int startAddress;
    int size;
} Hole;

Process *processes[MAX];
Hole *holes[MAX];
int numProcesses = 0;
int numHoles = 1;

void initializeMemory(int size)
{
    holes[0] = malloc(sizeof(Hole));
    holes[0]->startAddress = 0;
    holes[0]->size = size;
}

void requestMemory(char *processName, int size, char strategy)
{
    Process *newProcess = malloc(sizeof(Process));
    strncpy(newProcess->processName, processName, MAX_PROCESS_NAME);
    newProcess->size = size;

    int i, index;
    int foundHole = 0;
    int bestFitSize = MAX;
    int worstFitSize = -1;

    switch (strategy)
    {
    case 'F': // First Fit
        for (i = 0; i < numHoles; i++)
        {
            if (holes[i]->size >= size)
            {
                newProcess->startAddress = holes[i]->startAddress;
                holes[i]->startAddress += size;
                holes[i]->size -= size;
                foundHole = 1;
                break;
            }
        }
        break;
    case 'B': // Best Fit
        for (i = 0; i < numHoles; i++)
        {
            if (holes[i]->size >= size && holes[i]->size - size < bestFitSize)
            {
                bestFitSize = holes[i]->size - size;
                index = i;
                foundHole = 1;
            }
        }
        if (foundHole)
        {
            newProcess->startAddress = holes[index]->startAddress;
            holes[index]->startAddress += size;
            holes[index]->size -= size;
        }
        break;
    case 'W': // Worst Fit
        for (i = 0; i < numHoles; i++)
        {
            if (holes[i]->size >= size && holes[i]->size - size > worstFitSize)
            {
                worstFitSize = holes[i]->size - size;
                index = i;
                foundHole = 1;
            }
        }
        if (foundHole)
        {
            newProcess->startAddress = holes[index]->startAddress;
            holes[index]->startAddress += size;
            holes[index]->size -= size;
        }
        break;
    default:
        printf("Invalid strategy!\n");
        return;
    }

    if (!foundHole)
    {
        printf("Insufficient memory to allocate for process %s\n", processName);
        free(newProcess);
        return;
    }

    processes[numProcesses++] = newProcess;
    printf("Memory allocated for process %s starting from address %d\n", processName, newProcess->startAddress);
}

void releaseMemory(char *processName)
{
    int i;
    int processIndex = -1;

    for (i = 0; i < numProcesses; i++)
    {
        if (strcmp(processes[i]->processName, processName) == 0)
        {
            processIndex = i;
            break;
        }
    }

    if (processIndex == -1)
    {
        printf("Process %s not found!\n", processName);
        return;
    }

    Hole *newHole = malloc(sizeof(Hole));
    newHole->startAddress = processes;
    [processIndex] -> startAddress;
    newHole->size = processes[processIndex]->size;

    int mergeStart = -1;
    int mergeEnd = -1;

    // Merge with preceding hole
    for (i = 0; i < numHoles; i++)
    {
        if (holes[i]->startAddress + holes[i]->size == newHole->startAddress)
        {
            mergeStart = i;
            break;
        }
    }

    // Merge with succeeding hole
    for (i = 0; i < numHoles; i++)
    {
        if (holes[i]->startAddress == newHole->startAddress + newHole->size)
        {
            mergeEnd = i;
            break;
        }
    }

    if (mergeStart != -1)
    {
        holes[mergeStart]->size += newHole->size;
        free(newHole);
    }
    else
    {
        holes[numHoles++] = newHole;
    }

    if (mergeEnd != -1)
    {
        holes[mergeStart]->size += holes[mergeEnd]->size;
        free(holes[mergeEnd]);
        for (i = mergeEnd; i < numHoles - 1; i++)
        {
            holes[i] = holes[i + 1];
        }
        numHoles--;
    }

    free(processes[processIndex]);
    for (i = processIndex; i < numProcesses - 1; i++)
    {
        processes[i] = processes[i + 1];
    }
    numProcesses--;

    printf("Memory released for process %s\n", processName);
}

void compactMemory()
{
    int i;
    int compactSize = 0;

    for (i = 0; i < numHoles; i++)
    {
        compactSize += holes[i]->size;
        free(holes[i]);
    }

    holes[0] = malloc(sizeof(Hole));
    holes[0]->startAddress = 0;
    holes[0]->size = compactSize;

    numHoles = 1;

    for (i = 0; i < numProcesses; i++)
    {
        processes[i]->startAddress = compactSize;
        compactSize += processes[i]->size;
    }

    printf("Memory compacted\n");
}

void statusReport()
{
    int i;
    int lastAddress = 0;
    int holeIndex = 0;
    int processIndex = 0;

    while (holeIndex < numHoles || processIndex < numProcesses)
    {
        if (holeIndex < numHoles && holes[holeIndex]->startAddress < processes[processIndex]->startAddress)
        {
            printf("Addresses [%d:%d] Unused\n", lastAddress, holes[holeIndex]->startAddress - 1);
            lastAddress = holes[holeIndex]->startAddress + holes[holeIndex]->size;
            holeIndex++;
        }
        else
        {
            printf("Addresses [%d:%d] Process %s\n", lastAddress, lastAddress + processes[processIndex]->size - 1, processes[processIndex]->processName);
            lastAddress += processes[processIndex]->size;
            processIndex++;
        }
    }

    printf("Addresses [%d:%d] Unused\n", lastAddress, MAX - 1);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid arguments! Usage: ./allocator <memory_size>\n");
        return 1;
    }
    int memorySize = atoi(argv[1]);
    if (memorySize <= 0 || memorySize > MAX)
    {
        printf("Invalid memory size!\n");
        return 1;
    }

    initializeMemory(memorySize);
    char command[10];
    char processName[MAX_PROCESS_NAME];
    int size;
    char strategy;

    while (1)
    {
        printf("allocator> ");
        scanf("%s", command);

        if (strcmp(command, "RQ") == 0)
        {
            scanf("%s %d %c", processName, &size, &strategy);
            requestMemory(processName, size, strategy);
        }
        else if (strcmp(command, "RL") == 0)
        {
            scanf("%s", processName);
            releaseMemory(processName);
        }
        else if (strcmp(command, "C") == 0)
        {
            compactMemory();
        }
        else if (strcmp(command, "STAT") == 0)
        {
            statusReport();
        }
        else if (strcmp(command, "X") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command!\n");
        }
    }

    return 0;
}