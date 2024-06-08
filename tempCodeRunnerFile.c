            }
        }

        if (ok == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}
// determinarea numarului de componente conexe

void populate(int mat[8][8], int viz[8], int nod)
{
    viz[nod] = 1;
    for (int i = 0; i < 8; i++)
    {
        if (mat[nod][i] == 1 && viz[i] == 0)
        {
            populate(mat, viz, i);
        }
    }
}