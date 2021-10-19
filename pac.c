#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<sys/time.h>
#define MAPSIZE 15

void pacmove();
int pac_location[2] = {2, 2};
int ene_location[2] = {10, 7};
int count = 0;
int map[MAPSIZE][MAPSIZE] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                            {0, 1, 2, 1, 1, 1, 1, 1, 3, 4, 1, 1, 1, 1, 0},
                            {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
                            {0, 4, 1, 1, 1, 1, 3, 1, 0, 1, 1, 1, 1, 1, 0},
                            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
                            {0, 1, 1, 1, 1, 4, 1, 1, 1, 1, 0, 1, 1, 1, 0},
                            {0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
                            {0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
                            {0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
                            {0, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 0},
                            {0, 1, 1, 1, 4, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                            {0, 1, 1, 3, 1, 0, 0, 1, 1, 1, 1, 1, 3, 1, 0},
                            {0, 1, 3, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

//0 wall
//1 space
//2 pac
//3 point
//4 10points
//5 enemy
int main(){

    int i, j;//i 行　j 列
    int flag1 = 1;
    int finish;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)tv.tv_sec * ((unsigned int)tv.tv_usec+1));


    while(flag1){
        
        printf("count = %d\n", count);
        for(i = 0; i < MAPSIZE; i++){
            for(j = 0; j < MAPSIZE; j++){
                if(map[i][j] == 0){
                    printf("■");
                }
                if(map[i][j] == 1){
                    printf("  ");
                }
                if(map[i][j] == 2){
                    printf("漢");
                }
                if(map[i][j] == 3){
                    printf("〇");
                }
                if(map[i][j] == 4){
                    printf("☆");
                }
                if(map[i][j] == 5){
                    printf("敵");
                }
			
            }
        printf("\n");

        }

        pacmove();
            if(count >= 40){
                flag1 = 0;
                finish = 0;
            }
            else if(ene_location[0] == pac_location[0] && ene_location[1] == pac_location[1]){
                flag1 = 0;
                finish = 1;
            }

        system("cls");
        
    }
    if(finish == 0){
        printf("YOU WIN!!");
    }else{
        printf("GAME OVER…");
    }
}

void pacmove(){

	int dummy;
	int key;
	int flag = 1;
    int temp1, temp2;
    

    map[ene_location[0]][ene_location[1]] = 1;
    temp1 = rand() % 3;
    temp2 = rand() % 3;
    switch(temp1){
        case 0://上
            if(map[ene_location[0]-1][ene_location[1]] == 0){
                break;
            }else{
                ene_location[0]--;
            }
            break;
        case 1://下
            if(map[ene_location[0]+1][ene_location[1]] == 0){
                break;
            }else{
                ene_location[0]++;
            }
            break;
        case 2://stay
            ene_location[0];
            
            break;
    }
    switch(temp2){
        case 0://左
            if(map[ene_location[0]][ene_location[1]-1] == 0){
                break;
            }else{
                ene_location[1]--;
            }
            break;
        case 1://right
            if(map[ene_location[0]][ene_location[1]+1] == 0){
                break;
            }else{
                ene_location[1]++;
            }
            break;
        case 2://stay
            ene_location[1];

            break;
    }
    map[ene_location[0]][ene_location[1]] = 5;

    map[pac_location[0]][pac_location[1]] = 1;
    while(flag){
		if(_kbhit()){
			dummy = _getch();
			if(dummy == 0 || dummy == 224){
				key = _getch();
				flag = 0;
			}
		}
	}

   switch(key){
	case 0x4b://左
        if(map[pac_location[0]][pac_location[1]-1] == 0){
            break;
        }else{
            pac_location[1]--;
        }
		break;
	case 0x48://上
        if(map[pac_location[0]-1][pac_location[1]] == 0){
            break;
        }else{
		    pac_location[0]--;
        }
		break;
	case 0x4d://右
        if(map[pac_location[0]][pac_location[1]+1] == 0){
            break;
        }else{
		    pac_location[1]++;
        }
		break;
	case 0x50: //下
        if(map[pac_location[0]+1][pac_location[1]] == 0){
            break;
        }else{
		    pac_location[0]++;
        }
		break;
   }

    if(map[pac_location[0]][pac_location[1]] == 3){
        count++;
    }else if(map[pac_location[0]][pac_location[1]] == 4){
        count = count + 10;
    }
    map[pac_location[0]][pac_location[1]] = 2;

    system("cls");
}