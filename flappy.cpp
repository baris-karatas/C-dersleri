class wall {
public :
    int x, y,z;
    int wall_x[3]= {40,y,z };
        void move() {
        wall_x[0]--;
    }
};
#include <thread>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <conio.h> 

using namespace std;
int duvar=1;
wall wall_a[100];
char map[20][40];
void update(char map[][40]);
int k = 0;
bool tmp=true;
bool change=false;
int bird[2] = { 8,10 };
int c;
void key_down() {
    c = 8;
   
    while (1) {
        c = getch();
        if (c==8){
        }
    }
}
void bird_move() {
    int vector;//this will be gravity
    vector = 1;
    int counter = 1;
    while (1) {
        counter++;
        bird[0] += vector;
        if (bird[0]<= 1) {
            bird[0] = 0;
            //break;//   this means bird has 05
        }
        if (c==8) {
            bird[0] -= 2;
        }
        Sleep(300 - counter * 20);
    }
}
void move_wall() {    
    while(1) {
        for (int i = 0;i < duvar;i++) {
            wall_a[i].move();
            if (wall_a[i].wall_x[0] == 0) {
                wall_a[i].wall_x[0] = 39;
               //duvar--;
               tmp = false;
               change = true;
               wall_a[i].wall_x[2] = rand();
               wall_a[i].wall_x[2] = wall_a[i].wall_x[2] % 3;
               wall_a[i].wall_x[2] += 3;
               wall_a[i].wall_x[1] = rand();
               wall_a[i].wall_x[1] = wall_a[i].wall_x[1] % 8;
               wall_a[i].wall_x[1] += wall_a[i].wall_x[2];
            }
        }
        Sleep(400);
    } 
}
void load() {
    while (tmp) {
            wall_a[k].wall_x[2] = rand();
            wall_a[k].wall_x[2] = wall_a[k].wall_x[2] % 3;
            wall_a[k].wall_x[2] += 3;
            wall_a[k].wall_x[1] = rand();
            wall_a[k].wall_x[1] = wall_a[k].wall_x[1] % 8;
            wall_a[k].wall_x[1] += wall_a[k].wall_x[2];
            duvar++;
            Sleep(4000);  
    }
}
void map_update() {
    //while (1) {
        for (k = 0;k < duvar;k++){
            for (int i = 1;i < 19;i++) {
                    if (wall_a[k].wall_x[1] == i) {
                            i += wall_a[k].wall_x[2];
                    }
                    map[i][wall_a[k].wall_x[0]] = '#';
                }
            }
        map[bird[0]][bird[1]] = '*';
       // Sleep(100);
        //move_wall();
        /*for (int i = 1;i < 19;i++) {
            for (int j = 1;j < 39;j++) {
                map[i][j] = '\0';
            }
        }*/
   // }   
}
void update(char map[][40]) {  
    while (1) {
        map_update();
        for (int i = 0;i < 20;i++) {
            for (int j = 0;j < 40;j++) {
                cout << " " << map[i][j];
            }
            cout << endl;
        }
        for (int i = 1;i < 39;i++) {
            for (int j = 1;j < 19;j++) {
                map[j][i] = '\0';
            }
        }
        Sleep(60);
        //map_update();
        system("cls");
    }
}
int main()
{
    int bird[2] = { 10,15 };
    srand(time(NULL));
    for (int i = 0;i < 20;i++) {
        for (int j = 0;j < 40;j++) {
           
            if (i == 0||i==19||j==0||j==39) {
                map[0][j] = '#';
                map[i][0] = '#';
                map[i][39] = '#';
                map[19][j] = '#';
            }
            else
            {
                map[i][j] = '\0';
            }
            
           
        }
    }
    /*for (int i = 0;i < 20;i++) {
        for (int j = 0;j < 40;j++) {
            cout <<" "<< map[i][j];
        }
        cout<<"\n";
    }*/
   // thread thread_map(map_update);
    thread thread_load(load);
    thread thread_move(move_wall);
    thread thread_bird(bird_move);
    thread thread_key(key_down);
    update(map);
}


