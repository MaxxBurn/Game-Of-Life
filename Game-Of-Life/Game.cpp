#include "GameOfLife.hpp"

//Printing cells on screen

void Render(vec2d table) {
    for (int x = 0; x < 80; x++)
    {
        for (int y = 0; y < 60; y++)
        {
            if (table[x][y] == 1)  std::cout << "*";
            else std::cout << " ";
            if (y == 59)          std::cout << "\n";
        }
    }
}

void rulesOfLife(vec2d& table) {
    //Points are neighbors around the cell
    for (int x = 0; x < 80; x++)
    {
        for (int y = 0; y < 60; y++)
        {
            int Points{};
            //Middle Rows
             if(x!=0 && x!=79 && y!=0 && y!=59){
                if (table[x][y - 1] == 1)  Points++;
                if (table[x][y + 1] == 1)  Points++;
                if (table[x + 1][y - 1] == 1)    Points++;
                if (table[x + 1][y + 1] == 1)    Points++;
                if (table[x + 1][y] == 1)      Points++;
                if(table[x-1][y]==1)        Points++;
                if(table[x-1][y-1]==1)      Points++;
                if(table[x-1][y+1]==1)      Points++;
             }
            else if (y==0)
            {   //Upper-Row
            //S stands for x 
                    for(int s = 0; s < 80;s++)
                    {
                        if(s==0)
                        {
                            if(table[s+1][y]==1)Points++;
                            if(table[s][y+1]==1)Points++;
                            if(table[s+1][y+1]==1)Points++;
                        }
                        else if(s==79)
                        {
                            if(table[s][y+1]==1)Points++;
                            if(table[s+1][y+1]==1)Points++;
                            if(table[s-1][y+1]==1)Points++;
                        }
                        else{
                            if(table[s-1][y]==1)Points++;
                            if(table[s][y+1]==1)Points++;
                            if(table[s+1][y+1]==1)Points++;
                            if(table[s+1][y]==1)Points++;
                            if(table[s-1][y+1]==1)Points++;
                        }
                    }
            }
                //Bottom-Row
                else if(y==59) {

                    for(int s = 0; s < 80; s++)
                    {
                        if(s==0)
                        {
                            if(table[s][y-1]==1)Points++;
                            if(table[s+1][y]==1)Points++;
                            if(table[s+1][y-1]==1)Points++;
                        }
                        else if(s==79)
                        {
                            if(table[s-1][y]==1)Points++;
                            if(table[s][y-1]==1)Points++;
                            if(table[s-1][y-1]==1)Points++;
                        }
                        else{
                            if(table[s-1][y]==1)Points++;
                            if(table[s-1][y-1]==1)Points++;
                            if(table[s][y-1]==1)Points++;
                            if(table[s+1][y-1]==1)Points++;
                            if(table[s+1][y]==1)Points++;
                        }
                    }
                }
            //Killing ~ Reviving cells
            if (table[x][y] == 1)
            {
                if (Points < 2)table[x][y] = 0;
                else if (Points <= 3)table[x][y] = 1;
                else if (Points > 3)table[x][y] = 0;
            }
            else{
                if (Points == 3) table[x][y] = 1;}
            Points = { 0 };
        }
    }
    std::cout<<"\n---------------------------------------------------------------------\n";
    while(true)
    {
        Render(CellStory);
        rulesOfLife(CellStory);
    }
}

//Randomly reviving 1000 cells
void InitializeLife(vec2d& Board)
{
    srand(time(NULL));

    for (int i = 0; i < 800; i++)
        Board[rand() % 80][rand() % 60] = 1;
}
int main()
{
    std::cout << "\nWelcome to my implementation of game of life:\t\n";
    InitializeLife(CellStory);
    rulesOfLife(CellStory); 
    /*std::thread _thread2(rulesOfLife,CellStory);
    _thread1.join();
    _thread2.join();*/

}