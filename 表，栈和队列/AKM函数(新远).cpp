#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100000

struct Stack
{
    int X;
    int Y;
    int Flag;
    int rflag;
    int Result;
}S[MaxSize];

int Top = -1;

int Ackerman(int m, int n)
{
    Top++;
    S[Top].Flag = 1;
    S[Top].X = m;
    S[Top].Y = n;
    S[Top].rflag = 0;

    while(Top > -1)
    {
        if(!(S[Top].rflag)) //顶端结果未知
        {
            if(S[Top].X == 0)
            {
                if(S[Top].Flag==1)
                {
                    S[Top].Result = S[Top].Y+1;
                    S[Top].rflag = 1;
                }

                else
                {
                    Top++;
                    S[Top].X = S[Top-1].X+1;
                    S[Top].Y = S[Top-1].Y-1;
                    S[Top].rflag = 0;
                    S[Top].Flag = 1;
                }
            }

            else if(S[Top].Y == 0)
            {
                Top++;
                S[Top].X = S[Top-1].X-1;
                S[Top].Y = 1;
                S[Top].Flag = 1;
                S[Top].rflag = 0;
            }

            else
            {
                if(S[Top].Flag)
                {
                    Top++;
                    S[Top].X = S[Top-1].X-1;
                    S[Top].Y = S[Top-1].Y;
                    S[Top].Flag = 0;
                    S[Top].rflag = 0;
                }

                else
                {
                    Top++;
                    S[Top].X = S[Top-1].X+1;
                    S[Top].Y = S[Top-1].Y-1;
                    S[Top].Flag = 1;
                    S[Top].rflag = 0;
                }

            }
        }




        else if(S[Top].rflag) // 顶端结果已知
        {
            if(!S[Top-1].Flag)
            {
                S[Top-1].Y = S[Top].Result;
                S[Top-1].Flag = 1;
                S[Top-1].rflag = 0;
                Top--;
            }

            else
            {
                S[Top-1].Result = S[Top].Result;
                S[Top-1].rflag = 1;
                Top--;
            }
        }

        if(Top==0 && S[Top].rflag)
            break;
    }

    return (S[Top].Result);
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    printf("\n%d\n", Ackerman(M, N));
    return 0;
}