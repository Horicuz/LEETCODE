bool isValidSudoku(char** v, int google, int booble) {
    
    
    for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++)
            {
                if(v[i][j] != '.')
                    {
                        //columncheck
                        for(int z = i+1;z<9;z++)
                                if(v[z][j] == v[i][j])
                                    return false;
                        //linecheck
                        for(int z = j+1;z<9;z++)
                                if(v[i][z] == v[i][j])
                                    return false;

                        //boxcheck
                        int inou = i%3;
                        int jnou = j%3;
                        for(int z = i-inou;z<i-inou+3;z++)
                            for(int s = j-jnou;s<j-jnou+3;s++)
                                if(z!=i && s!=j)
                                    {
                                        if(v[z][s] == v[i][j])
                                            return false;
                                    }
                        
                    }
            }
    return true;
}
