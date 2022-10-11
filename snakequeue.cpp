#include<bits/stdc++.h>
using namespace std;
#define size 50
void initialize_board(char M[size][size])
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            M[i][j]  = ' ';
        }
    }

    for(int i=1;i<size;i++)
    {
        M[i][0] = '|';
    }


    for(int i=1;i<size;i++)
    {
        M[i][size-1] = '|';
    }


    for(int i=0;i<size;i++)
    {
        M[0][i] = '-';
    }

    for(int i=0;i<size;i++)
    {
        M[size-1][i] = '-';
    }
}



void initialize_matrix(char M[size][size],queue <pair <int,int>> q)
{

    queue <pair<int,int>> temp=q;
    while(!temp.empty())
    {
        M[temp.front().first][temp.front().second] = '*';
        temp.pop();
    }

}

void print_matrix(char M[size][size])
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

void move_forward(char M[size][size],char dir,int &flag,queue <pair<int,int>> &q)
{
    pair <int,int> p1;
    switch(dir)
    {
        case '\n': switch(flag)
                    {

                        case 1: q.pop();
                                q.push(make_pair(q.back().first-1,q.back().second));
                                break;
                        case 2: q.pop();
                                q.push(make_pair(q.back().first,q.back().second-1));   
                                break;
                        case 3: q.pop();
                                q.push(make_pair(q.back().first+1,q.back().second));
                                break;
                        case 0: q.pop();
                                q.push(make_pair(q.back().first,q.back().second+1));
                                break;
                        case 4: q.pop();
                                q.push(make_pair(q.back().first,q.back().second+1));  
                                break;
                    }
                    break;
        case 'w':   q.pop();
                    q.push(make_pair(q.back().first-1,q.back().second));
                    flag = 1;
                    break;
         case 'a':  q.pop();
                    q.push(make_pair(q.back().first,q.back().second-1));                     
                    flag = 2;
                    break;
         case 's':  q.pop();
                    q.push(make_pair(q.back().first+1,q.back().second));
                    flag=3;
                    break;
        case 'd':   q.pop();
                    q.push(make_pair(q.back().first,q.back().second+1));   
                    flag = 4;
                    break;

    }

}


int main()
{
    queue <pair<int,int>> q;
    q.push(make_pair(1,1));
    q.push(make_pair(1,2));
    q.push(make_pair(1,3));
    q.push(make_pair(1,4));
    q.push(make_pair(1,5));
    char M[size][size];
    initialize_board(M);
    initialize_matrix(M,q);
    print_matrix(M);
    char x;
    int flag = 0;
    while(1)
    {
        cin.get(x);
        cout<<x<<endl;
        if(x=='q')
            break;
        move_forward(M,x,flag,q);

        initialize_board(M);

        initialize_matrix(M,q);
        system("clear");
        print_matrix(M);
    }

    return 0;
}