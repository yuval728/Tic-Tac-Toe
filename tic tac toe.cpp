#include <bits/stdc++.h>
#include <iostream>
#include <time.h>

using namespace std;

#define Side 3

class Game
{
public:
    char Board[Side][Side]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char turn='X';
    int choice,row,column,Comprow,Compcolumn;
    bool draw=false;

    void showboard()
    {

        printf("\t\t\t %c | %c | %c \n",Board[0][0],Board[0][1],Board[0][2]);
        printf("\t\t\t--------------\n");
        printf("\t\t\t %c | %c | %c \n",Board[1][0],Board[1][1],Board[1][2]);
        printf("\t\t\t--------------\n");
        printf("\t\t\t %c | %c | %c \n",Board[2][0],Board[2][1],Board[2][2]);
        cout<<"Choose a number from 1 to 9 to play\n";
    }

    void playerVsplayer()
    {
        if(turn=='X')
        {
            cout<<"Player One turn (X):\n";
        }
        else if(turn=='O')
        {
            cout<<"Player two turn (O):\n";
        }
        cin>>choice;
        switch(choice)
        {
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
        }

        if(turn=='X' && Board[row][column]!='X' && Board[row][column]!='O')
        {
            Board[row][column]='X';
            turn='O';
        }
        else if(turn=='O' && Board[row][column]!='X' && Board[row][column]!='O')
        {
            Board[row][column]='O';
            turn='X';
        }
        else
        {
            cout<<"Box is already taken\n\n";
            playerVsplayer();
        }
       // showboard();
    }
    void CompVsHuman()
    {
        if(turn=='X')
        {
        cout<<"Your turn (X):\n";
        cin>>choice;
        switch(choice)
        {
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
        }

        if( Board[row][column]!='X' && Board[row][column]!='O')
        {
            Board[row][column]='X';
            turn='O';

        }
        else
        {
            cout<<"Box is already taken\n\n";
            CompVsHuman();
        }
        }
        else if(turn=='O')
        {
            cout<<"Computer turn (O)\n ";
            comp:
            srand(time(NULL));
            Comprow=rand()%3;
            Compcolumn=rand()%3;

        if( Board[Comprow][Compcolumn]!='X' && Board[Comprow][Compcolumn]!='O')
        {
            Board[Comprow][Compcolumn]='O';
            turn='X';
        }
        else
        {
            cin.clear();
            goto comp;
        }
        }
    }
    bool winner()
    {
        for(int i=0;i<Side;i++)
        {
            if(Board[i][0]==Board[i][1] && Board[i][1]==Board[i][2] && Board[i][0]!=' ')
            {
                return false;
            }
        }
        for(int i=0;i<Side;i++)
        {
            if(Board[0][i]==Board[1][i] && Board[1][i]==Board[2][i] && Board[0][i]!=' ')
            {
                return false;
            }
        }
        for(int i=0;i<Side;i++)
        {
            if(Board[0][0]==Board[1][1] && Board[1][1]==Board[2][2] && Board[0][0]!=' ')
            {
                return false;
            }
            if(Board[0][2]==Board[1][1] && Board[1][1]==Board[2][0] && Board[0][2]!=' ')
            {
                return false;
            }
        }
        for(int i=0;i<Side;i++)
        {
            for(int j=0;j<Side;j++)
            {
                if(Board[i][j]!='X' && Board[i][j]!='O')
                    return true;
            }
        }
        draw=true;
        return false;
    }
    void playgame()
    {
        while(winner())
        {
            showboard();
            playerVsplayer();
            winner();
        }
        if(turn=='X' && draw==false)
            cout<<"Player 2(O) wins\n";
        else if(turn=='O'&& draw==false)
            cout<<"Player 1(X) wins\n";
        else
            cout<<"It's a draw\n";
    }
    void compgame()
    {
        while(winner())
        {
            showboard();
            CompVsHuman();
            winner();
        }
        if(turn=='X' && draw==false)
            cout<<"Computer(O) win\n";
        else if(turn=='O'&& draw==false)
            cout<<"You(X) win\n";
        else
            cout<<"It's a draw\n";

    }

};
int main()
{
    Game ttt;
    int option;
    cout<<"\t\t\t Tic Tac Toe\n\n";
    cout<<"1.play against computer\n2.play against human\n";
    cin>>option;
    switch(option)
    {
        case 1: ttt.compgame(); break;
        case 2: ttt.playgame(); break;
    }
}
