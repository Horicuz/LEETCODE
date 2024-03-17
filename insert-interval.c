/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{   
    intervals = (int**)malloc(intervalsSize*sizeof(int));
    for(int i = 0;i<intervalsSize;i++)
    {
        intervals[i] = (int*)malloc(2*sizeof(int));
    }

    if(newInterval[0] > intervals[intervalsSize-1][1])
    {
        intervalsSize++;
        intervals = (int**)realloc(intervals,intervalsSize*sizeof(int));
        intervals[intervalsSize-1] = (int*)malloc(2*sizeof(int));
        intervals[intervalsSize-1][0] = newInterval[0];
        intervals[intervalsSize-1][1] = newInterval[1];
        return intervals;
    }

    //if()
    for(int i = 0;i < intervalsSize; i++)
    {
        if(newInterval[0] >= intervals[i][0] && newInterval[0]<= intervals[i][1])
        {
            if(newInterval[1] <= intervals[i][1])
                {
                    return intervals;
                }
            else
                {   
                    if(newInterval[1])
                    for(int j = i+1;j < intervalsSize; j++)
                        {   
                            if(newInterval[1] < intervals[j][0])
                                {
                                    intervals[i][1] = newInterval[1];
                                    for(int k = 0; k < (j-i-1); k++)
                                    {
                                        for(int z = i+1;z < intervalsSize - 1;z++)
                                            {
                                                *intervals[z] = *intervals[z+1];   
                                            }
                                        intervalsSize--;
                                    }
                                    return intervals;
                                }
                            else if(newInterval[1] >= intervals[j][0] && newInterval[1] <= intervals[j][1]) 
                                {
                                    intervals[i][1] = intervals[j][1];
                                    for(int k = 0; k < (j-i); k++)
                                    {
                                        for(int z = i+1;z < intervalsSize - 1;z++)
                                            {
                                                *intervals[z] = *intervals[z+1];   
                                            }
                                        intervalsSize--;
                                    }
                                    return intervals;
                                }   
                        }

                }
            
        }
    }
    return intervals;
}