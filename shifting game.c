#include<stdio.h>
#include<stdlib.h>
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
int shiftUp(int a[][4]);
int shiftDown(int a[][4]);
int shiftLeft(int a[][4]);
int shiftRight(int a[][4]);
int win(int a[][4]);
void showMatrix(int a[][4]);
void setMatrix(int a[][4]);
int readkey();
void main()
{
    int a[4][4],moves=400;
    setMatrix(a);
    while(moves)
    {
        printf("\nRemaining moves=%d",moves);
        showMatrix(a);
        if(win(a))
        {
            printf("congrats you win in %d moves",400-moves);
            printf("\npress any key to exit..");
            getch();
            exit(0);
        }
        switch(readKey())
            {
            case ESC:
                exit(0);
                break;
            case UP:
                if(!shiftUp(a))
                moves++;
                break;
            case DOWN:
                if(!shiftDown(a))
                moves++;
                break;
            case LEFT:
                if(!shiftLeft(a))
                moves++;
                break;
            case RIGHT:
                if(!shiftRight(a))
                moves++;
                break;
            default:
                moves++;
            }
            system("cls");
            moves--;
    }
    getch();
}
void showMatrix(int a[][4])
{
    int i,j;
    printf("\n-------------------------------\n|");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]!=0)
                printf(" %-2d  |  ",a[i][j]);
            else
                printf("     |  ");
        }
        printf("\n-------------------------------\n");
        if(i!=3)
            printf("|");
    }
}
void setMatrix(int a[][4])
{
    int initial[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int maxindex=14,index,i,j;
    srand(time(NULL));
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(maxindex>=0)
            {
                index=rand()%(maxindex+1);
                a[i][j]=initial[index];
                initial[index]=initial[maxindex];
                maxindex--;
            }
            else
                a[i][j]=0;
        }
    }
}
int readKey()
{
    int ch;
    ch=getch();
    if(ch==224)
        ch=getch();
    switch(ch)
    {
    case 27:
        return(ESC);
    case 72:
        return(UP);
    case 80:
        return(DOWN);
    case 75:
        return(LEFT);
    case 77:
        return(RIGHT);
    default:
        return 5;
    }
}
int win(int a[][4])
{
    int i,j,z=0; // z for check matrix win condition
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            z<15?z++:(z=0);
            if(a[i][j]!=z)
                return(0);
        }
    }
    return 1;
}
int shiftRight(int a[][4])
{
    int i,j,temp; // here temp for shifting
    int spaceFound=0; // for founding space
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0){
                spaceFound=1;
                break;
            }
        }
        if(spaceFound)
            break;
    }
    if(j==0)
        return 0;
    else
    {
        temp=a[i][j];
        a[i][j]=a[i][j-1];
        a[i][j-1]=temp;
        return 1;
    }
}
int shiftLeft(int a[][4])
{
    int i,j,temp; // here temp for shifting
    int spaceFound=0; // for founding space
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0){
                spaceFound=1;
                break;
            }
        }
        if(spaceFound)
            break;
    }
    if(j==3)
        return 0;
    else
    {
        temp=a[i][j];
        a[i][j]=a[i][j+1];
        a[i][j+1]=temp;
        return 1;
    }
}
int shiftUp(int a[][4])
{
    int i,j,temp; // here temp for shifting
    int spaceFound=0; // for founding space
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0){
                spaceFound=1;
                break;
            }
        }
        if(spaceFound)
            break;
    }
    if(i==3)
        return 0;
    else
    {
        temp=a[i][j];
        a[i][j]=a[i+1][j];
        a[i+1][j]=temp;
        return 1;
    }
}
int shiftDown(int a[][4])
{
    int i,j,temp; // here temp for shifting
    int spaceFound=0; // for founding space
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0){
                spaceFound=1;
                break;
            }
        }
        if(spaceFound)
            break;
    }
    if(i==0)
        return 0;
    else
    {
        temp=a[i][j];
        a[i][j]=a[i-1][j];
        a[i-1][j]=temp;
        return 1;
    }
}
