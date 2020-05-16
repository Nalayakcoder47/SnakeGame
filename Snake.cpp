#include<iostream>
#include<conio.h>
using namespace std;
/*---------------Global Variables----------*/
bool gameOver;
int width=20;//map width=20 block
int height=15;//map height=20 block
int x,y;//snake head position
int fruitX,fruitY;//fruit position
int tailX[100],tailY[100];//tail array
int ntail=0;//specify the length of tail
int score;//optional variable
enum Direction {STOP=0, LEFT, RIGHT, UP, DOWN};
Direction dir;
string str1="CREATOR:- RAVIJOT SINGH";
string str2="PRESS 'W' FOR UP, 'S' FOR DOWN, 'A' FOR LEFT AND 'D' FOR RIGHT";
/*-------Required Functions-----*/
void InitialSetup(){
gameOver=false;
dir=STOP;//snake will not stop once it start moving in particular direction
x=width/2;
y=height/2;//snake is at center of map at initial
fruitX=rand()%width;//will create random position of fruit between 0 and width-1;
fruitY=rand()%height;//will create random position of fruit between 0 and height-1;
score=0;//initially score is 0;
}
void Drawing(){
system("cls");//clearing the screen (console window). for Linux, we should use system("clear");
//Drawing map
for(int i=0;i<=6;i++){
        for(int j=0;j<=str2.length()+5;j++){
            if(j==0 || j==str2.length()+5 || i==0 && j>=0 || i==6 && j>=0){
                cout<<"#";
            }else{
                if(i==2 && j>=3 && j<=str1.length()+2){
            cout<<str1[j-3];
            }else if(i==4 && j>=3){
            cout<<str2[j-3];
            }
            else{
            cout<<" ";
            }
            }
        }cout<<"\n";
    }
for(int i=0;i<width+2;i++){
    cout<<"#";
}cout<<endl;
/*printing a map like this:-
#####
#   #
#   #
#####
*/
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        if(j==0){
            cout<<"#";
        }
            if(i==y && j==x){
                cout<<"X";//printing single snake head at center
            }
            else if(i==fruitY && j==fruitX){
            cout<<"o";//printing fruit at random position;
            }
            else{
                    bool print=false;
                    for(int k=0;k<ntail;k++){
                        if(tailX[k]==j && tailY[k]==i){
                            cout<<"o";
            print=true;
                        }
                    }
                    if(!print){
        cout<<" ";
                    }
            }
        if(j==width-1){
            cout<<"#";
        }
    }cout<<"\n";
}
for(int i=0;i<width+2;i++){
    cout<<"#";
}cout<<"\n\n";
cout<<" SCORE:- "<<score<<"\n";
}
void Input(){
    //This will Handle controls of movements
    if(_kbhit()){//_kbhit() function will return +ve number if key is pressed in keyboard else return 0 if nothing is pressed
        switch(_getch())//_getch() will return ascii value of character that is pressed on keyboard
        {
            //W=upward, S=Downward, A=Left, D=right
        case 'a':
            dir=LEFT;
            break;
            case 's':
            dir=DOWN;
            break;
            case 'w':
            dir=UP;
            break;
            case 'd':
            dir=RIGHT;
            break;
            case 'x':
            gameOver=true;
            break;
        }
    }
}
void Algorithm(){
    //Real logic
    int prevX=tailX[0];
    int prevY=tailY[0];//Remember previous X and Y coordinates of tail
    int prev2X, prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<ntail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
switch(dir)
        {
            //W=upward, S=Downward, A=Left, D=right
        case LEFT:
            x--;//decreasing x coordinate because snake is moving left
            break;
            case RIGHT:
            x++;//increasing x coordinate because snake is moving right
            break;
            case UP:
            y--;//decreasing y coordinate because snake is moving up
            break;
            case DOWN:
            y++;//increasing y coordinate because snake is moving down
            break;
            default:
            break;
        }
        /*if((x>width || x<0)||(y>height || y<0)){//check if snake head hit the boundary, then game over.
            gameOver=true;
        }*/
        if(x>=width) x=0; else if(x<0) x=width-1;//uncomment this if you want to not to game over on hit of wall. Snake will arrive from opposite side
        if(y>=height) y=0; else if(y<0) y=height-1;//uncomment this if you want to not to game over on hit of wall. Snake will arrive from opposite side
        for(int i=0;i<ntail;i++){
            if(tailX[i]==x && tailY[i]==y){//check if current head position is colliding with any tail position
                gameOver=true;//game over, because snake hit himself;
                cout<<"\nOOPS______GAME OVER-----\n";
            }
        }
        if(x==fruitX && y==fruitY){//if snake head hit the fruit, then increase the score
            score+=10;
            fruitX=rand()%width;//generate a fruit on new random position
            fruitY=rand()%height;
            ntail++;
        }
}
/*-----Main Function----*/
int main(){

InitialSetup();
while(!gameOver){
        Drawing();
    Input();
    Algorithm();
}
return 0;
}
