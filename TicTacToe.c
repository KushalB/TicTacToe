#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void diagram();
void play();
void playgod();
void check();
void anali();
void ranko();
struct tiptoe
{
    int pos;
    int x;
    char choc;
};
int flag=0;
int flug=0;
int i,j,k,m,n,p,q,a;
struct tiptoe t[3][3];
struct tiptoe user;
struct tiptoe god;
int win=0;
struct analis
{
    int pos1;int pos2;int vac;int res;
};
struct analis ranc;
//void tiptoe();
//void user();
void main()
{
    diagram();
    if(flug==0)
    {
        while(1)
        {
            printf("Enter your Choice in b2n X or O:\t");
            fflush(stdin);
            scanf("%c",&user.choc);
            if(user.choc!='X' && user.choc!='O')
            {
                printf("!! .Wrong Input. !!\n\n");
                fflush(stdin);
                getch();

            }
            else
            {
                if(user.choc=='X')
                    god.choc='0';
                else
                    god.choc='X';
                    break;
            }
        }
        printf("You chose %c",user.choc);
        flug=1;
    }
    if(flag==1)
    {
        printf("You're done\n");
    }
    else
    {
        printf("you have:");
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(t[i][j].x==0)
                {
                    printf("%d ",t[i][j].pos);
                }
            }
        }
        printf("Positions free\n");
    }
    int op;
    if(flug==1)
    {
        printf("\nExplore options:\n1.Play\n2.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: play();
                    break;
            case 2: exit(0);
                    break;
            default: printf("Wrong input..!! enter again\n\n");
                     getch();
        }
    }
}
void diagram()
{
    int n=1;
    t[0][0].pos=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            t[i][j].pos=t[i][j].pos+1;
            t[i][j+1].pos=t[i][j].pos;
            if(t[i][j].x!=1)
            {
                t[i][j].x=0;
            }
            printf("|%c %d",t[i][j].choc,t[i][j].pos);
        }printf("|\n\n");
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(t[i][j].x!=1)
            {
                n=0;
            }
        }
    }
    if(win==1)
    {
         printf("Press Enter to EXIT");
        getch();
        exit(0);
    }
    else if(win!=1 && n==1)
    {
        printf("MATCH draw...");
         printf("\n\nPress Enter to EXIT");
        getch();
        exit(0);
    }
}
void play()
{
    while(1)
    {
    printf("Enter Position in where you wanna enter:\t");
    scanf("%d",&user.pos);
    if(user.pos<10)
    {
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(user.pos==t[i][j].pos)
            {
                if(t[i][j].x==0)
                {
                    t[i][j].choc=user.choc;
                    t[i][j].x=1;
                }
                else
                {
                    printf("Position pre-aquired..!!\t do AGAIN.\n\n");
                }
            }
        }
    }
    }
    else
    {
        printf("please follow the rule..!\n");
        printf("Enter 0 to quit and 1 to do again");
        scanf("%d",&k);
        if(k==0)
        exit(0);
    }
    check();
    playgod();
    check();
    diagram();
    }
}
void playgod()
{
    int r=0;int i,f;
    if(win==0)
    {
      ranc.res=0;
    anali();
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
    {
        if(t[i][j].pos==ranc.vac)
        {
            t[i][j].choc=god.choc;
            t[i][j].x=1;r=1;
            break;
        }
    }
    }
}
void check()
{
     if(win==0){for(j=0,i=0;i<3;i++)
    {
        if(t[i][j].x==1 && t[i][j+1].x==1 && t[i][j+2].x==1)
        {
            if(t[i][j].choc==t[i][j+1].choc && t[i][j].choc==t[i][j+2].choc)
            {
                if(t[i][j].choc==user.choc)
                {
                    printf("Bingo...!! You Won. for %d-%d-%d\n\n",t[i][j].pos,t[i][j+1].pos,t[i][j+2].pos);win=1;break;
                }
                else
                {
                    printf("Dingo...!! CPU Won. for %d-%d-%d\n\n\n",t[i][j].pos,t[i][j+1].pos,t[i][j+2].pos);win=1;break;
                }
            }
        }
        else
        {
            continue;
        }

    }
     }
     if(win==0){for(i=0,j=0;j<3;j++)
    {
        if(t[i][j].x==1 && t[i+1][j].x==1 && t[i+2][j].x==1)
        {
            if(t[i][j].choc==t[i+1][j].choc && t[i+1][j].choc==t[i+2][j].choc)
            {
                if(t[i][j].choc==user.choc)
                {
                    printf("Bingo...!! You Won. for %d-%d-%d\n\n",t[i][j].pos,t[i+1][j].pos,t[i+2][j].pos);
                    win=1;
                    break;
                }
                else
                {
                    printf("Dingo...!! CPU Won. for %d-%d-%d\n\n\n",t[i][j].pos,t[i+1][j].pos,t[i+2][j].pos);
                    win=1;
                    break;
                }

            }

        }
        else
        {
            continue;
        }

    }
     }
     if(win==0)
     {
         if(t[0][0].x==1 && t[1][1].x==1 && t[2][2].x==1)
         {
                if(t[0][0].choc==t[1][1].choc && t[1][1].choc==t[2][2].choc)
            {
                if(t[0][0].choc==user.choc)
                {
                    printf("Bingo...!! You Won. for %d-%d-%d\n\n",t[0][0].pos,t[1][1].pos,t[2][2].pos);
                }
                else
                {
                    printf("Dingo...!! CPU Won. for %d-%d-%d\n\n\n",t[0][0].pos,t[1][1].pos,t[2][2].pos);
                }
                win=1;
            }
         }

     }
     if(win==0)
     {
         if(t[0][2].x==1 && t[1][1].x==1 && t[2][0].x==1)
         {
             if(t[0][2].choc==t[1][1].choc && t[1][1].choc==t[2][0].choc)
            {
                if(t[0][2].choc==user.choc)
                {
                    printf("Bingo...!! You Won. for %d-%d-%d\n\n",t[0][2].pos,t[1][1].pos,t[2][0].pos);
                }
                else
                {
                    printf("Dingo...!! CPU Won. for %d-%d-%d\n\n\n",t[0][2].pos,t[1][1].pos,t[2][0].pos);
                }
                win=1;

            }
         }

     }

}


void anali()
{
    srand(time(NULL));
    for(i=0;i<3;i++)//ROW WISE RANKING.............................................//
    {
        p=0;q=0;
        for(j=0;j<3;j++)
        {
            if(t[i][j].x==1)
            {
                p++;q=q+2;
                if(t[i][j].choc==god.choc)
                {
                    q++;
                }
                else if(t[i][j].choc==user.choc)
                {
                    q--;
                }
            }
        }
        ranko();
        if(p==2 && q>ranc.res)
        {
            ranc.res=q;
            for(j=0;j<3;j++)
            {
                if(t[i][j].x!=1)
                {
                    ranc.vac=3*i+j+1;
                }
            }
        }
        else if(p==1 && q>ranc.res)
        {
            ranc.res=q;
            for(j=0;j<3;j++)
            {
                if(t[i][j].x==1)
                {
                    if(j==0)
                    {
                        ranc.vac=3*i+j+2;
                    }
                    else if(j==2)
                    {
                        ranc.vac=3*i+j;
                    }
                    else if(j==1)
                    {
                        a=rand()%10;
                        if(a%2==0)
                        {
                            ranc.vac=3*i+j+1+1;
                        }
                        else
                        {
                            ranc.vac=3*i+j;
                        }
                    }
                }
            }
        }
    }
    for(j=0;j<3;j++)//COLUMN WISE RANKING..........................................//
    {
        p=0;q=0;
        for(i=0;i<3;i++)
        {
            if(t[i][j].x==1)
            {
                p++;q=q+2;
                if(t[i][j].choc==god.choc)
                {
                    q++;
                }
                else if(t[i][j].choc==user.choc)
                {
                    q--;
                }
            }

        }
        ranko();
        if(p==2 && q>ranc.res)
        {
            ranc.res=q;
            for(i=0;i<3;i++)
            {
                if(t[i][j].x!=1)
                {
                    ranc.vac=3*i+j+1;
                }
            }
        }
        else if(p==1 && q>ranc.res)
        {
            ranc.res=q;
            for(i=0;i<3;i++)
            {
                if(t[i][j].x==1)
                {
                    if(i==0)
                    {
                        ranc.vac=3*i+j+1+3;
                    }
                    else if(i==2)
                    {
                        ranc.vac=3*i+j-2;
                    }
                    else if(i==1)
                    {
                        a=rand()%10;
                        if(a%2==0)
                        {
                            ranc.vac=3*i+j+1+3;
                        }
                        else
                        {
                            ranc.vac=3*i+j-2;
                        }
                    }
                }
            }
        }

    }
    do{
        p=0;q=0;
    for(i=0;i<3;i++)//DIAGONAL RANKING -1.....................................................//
    {
        if(t[i][i].x==1)
        {
            p++;q=q+2;
            if(t[i][i].choc==god.choc)
            {
                q++;
            }
            else if(t[i][i].choc==user.choc)
            {
                q--;
            }
        }
    }
    ranko();
        if(p==2 && q>ranc.res)
        {
            ranc.res=q;
            for(i=0;i<3;i++)
            {
                if(t[i][i].x!=1)
                {
                    ranc.vac=4*i+1;
                }
            }
        }
        else if(p==1 && q>=ranc.res)
        {
            ranc.res=q;
            for(i=0;i<3;i++)
            {
                if(t[i][i].x==1)
                {
                    if(i==0 || i==2)
                    {
                        ranc.vac=5;
                    }
                }

            }
        }
    }while(0);
     do{
        p=0;q=0;
    for(i=0;i<3;i++)//DIAGONAL RANKING -2.....................................................//
    {
        if(t[i][2-i].x==1)
        {
            p++;q=q+2;
            if(t[i][2-i].choc==god.choc)
            {
                q++;
            }
            else if(t[i][2-i].choc==user.choc)
            {
                q--;
            }
        }
    }
    ranko();
        if(p==2 && q>ranc.res)
        {
            ranc.res=q;
            for(i=0;i<3;i++)
            {
                if(t[i][2-i].x!=1)
                {
                    ranc.vac=3*i+(2-i)+1;
                }
            }
        }
        else if(p==1 && q>=ranc.res)
        {
            ranc.res=q;
            for(i=0;i<3;i++)
            {
                if(t[i][2-i].x==1)
                {
                    if(i==0 || i==2)
                    {
                        ranc.vac=5;
                    }
                    else if(i==1)
                    {
                        a=rand()%10;
                        if(a%2==0)
                        {
                            ranc.vac=3;
                        }
                        else
                        {
                            ranc.vac=7;
                        }
                    }
                }

            }
        }
    }while(0);

}
void ranko()
{
    if(q==2)
        {
            q=q*2+1;
        }
        else if(q==4)
        {
            q=1;
        }
        else if(q==3)
        {
            q=4;
        }
        else if(q==4)
        {
            q=1;
        }
        else if(q==1)
        {
            q=3;
        }
}
