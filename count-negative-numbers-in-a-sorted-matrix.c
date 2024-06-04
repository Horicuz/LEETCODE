int countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int count = 0;
    int i = 0;
    for (int i = 0; i < gridSize; i++)
    {
        printf("j: %d\n", i);
        int start_i = 0;
        int end_i = gridColSize[i] - 1;
        printf("start_i: %d\n", start_i);
        printf("end_i: %d\n", end_i);
        int j = (start_i + end_i) / 2;
        if (start_i == end_i)
        {
            if (grid[i][j] < 0)
            {
                count = count + (gridSize - i);
                break;
            }
        }
        else
        {
            printf("i: %d\n", i);
            while (start_i != end_i)
            {
                printf("%d\n", grid[i][j]);
                if (grid[i][j] >= 0)
                {
                    if (j < gridColSize[i] - 1 && grid[i][j + 1] >= 0)
                    {
                        start_i = j;
                        j = (start_i + end_i) / 2 + 1;
                        printf("Nu e la mijloc si nou start_i: %d\n", start_i);
                    }
                    else if (j < gridColSize[i] - 1 && grid[i][j + 1] < 0)
                    {
                        count = count + (gridColSize[i] - (j + 1)) * (gridSize - i);
                        printf("count: %d\n", count);
                        for (int z = i + 1; z < gridSize; z++)
                        {
                            gridColSize[z] = gridColSize[z] - (gridColSize[i] - (j + 1));
                            printf("gridColSize[%d]: %d\n", z, gridColSize[z]);
                        }
                        break;
                    }
                    else
                    {
                        printf("Suntem la final cu i");
                        break;
                    }
                }
                else if (grid[i][j] < 0)
                {
                    if (j > 0 && grid[i][j - 1] < 0)
                    {

                        end_i = j;
                        j = (start_i + end_i) / 2;
                        printf("Nu e la mijloc si nou end_i: %d\n", end_i);
                    }
                    else if (j > 0 && grid[i][j - 1] >= 0)
                    {
                        count = count + (gridColSize[i] - (j)) * (gridSize - i);
                        printf("count: %d\n", count);
                        for (int z = i + 1; z < gridSize; z++)
                        {
                            gridColSize[z] = gridColSize[z] - (gridColSize[i] - (j));
                            printf("gridColSize[%d]: %d\n", z, gridColSize[z]);
                        }
                        break;
                    }
                    else
                    {
                        printf("Suntem la inceput cu i");
                        count = count + (gridColSize[i]) * (gridSize - i);
                        for (int z = i + 1; z < gridSize; z++)
                        {
                            gridColSize[z] = gridColSize[z] - gridColSize[i];
                        }
                        i = gridSize;
                        break;
                    }
                }
            }
        }
    }
    return count;
}