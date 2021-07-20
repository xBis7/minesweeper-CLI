
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/*
if min number of rows and cols equals 5 then for difficulty level 1 and 2 we would have the same amount of mines
but for 6 we have a different amount of mines in each level
*/
#define MIN_N 6   
#define MIN_M 6

#define MAX_N 50
#define MAX_M 50

//board struct
typedef struct{
    int cell;
    bool isOpen;
    bool isMarked;
}Board;

//declaring functions
void game_start(Board **board, int rows, int cols);

void fill_board(Board **board, int rows, int cols, int mine_num, int in_rows, int in_cols);

void display_board(Board **board, int rows, int cols, int level, int diff_num);

void show(Board **board, int rows, int cols, int in_rows, int in_cols);

void markMine(Board **board, int rows, int cols, int level, int diff_num);

void help(Board **board, int rows, int cols);

void wisdom(Board **board, int rows, int cols);

//global variables
int mines=0;                        
int closedSq;

//main                                      
int main(void){
    
	Board **board;
    int M,N;
    int i,j;
    int level;
    int difficulty_num;
    int level_num;
    char input[10];
	int r,c;
    
    //initialising the random generator function
	srand(time(NULL));

    printf("--- Welcome! ---\n");
    printf("This is a command line version of the well known game minesweeper\n");
    printf("Enter the board dimensions\n");
    printf("The number of rows can't be less than %d \n",MIN_M);
    printf("and more than %d \n",MAX_M);
    printf("The number of cols can't be less than %d \n",MIN_N);
    printf("and more than %d \n",MAX_N);

    //rows,cols input
    printf("Enter the number of rows:");
    scanf("%d",&M);
    while(M<MIN_M || M>MAX_M && M != getchar()){
        printf("\nWrong input! Try again...\n");
        printf("Enter the number of rows:");
        scanf("%d",&M);
    }

    printf("Enter the number of cols:");
    scanf("%d",&N);
    while(N<MIN_N || N>MAX_N && N != getchar()){
        printf("\nWrong input! Try again...\n");
        printf("Enter the number of cols:");
        scanf("%d",&N);
    }

    //board memory allocation
    board = (Board**) malloc (M * sizeof(Board*));

    if(board == NULL){
        printf("\nNot available memory... exiting...\n");
        exit(0);    
    }

    for(i=0; i<M; i++){
		board[i] = (Board*) malloc (N * sizeof(Board));
        if(board[i] == NULL){
            printf("\nNot available memory... exiting...\n");
            exit(0);  
        }
    }

    //level of difficulty input
    printf("Choose a level of difficulty:\n");
    printf("1.Easy\n");
    printf("2.Medium\n");
    printf("3.Hard\n");
    printf("4.Really Hard\n");
    printf("Enter an integer(1,2,3,4):");
    scanf("%d",&difficulty_num);
    while(difficulty_num != 1 && difficulty_num != 2 && difficulty_num != 3 && difficulty_num != 4 && difficulty_num != getchar()){
        printf("Wrong input! Try again...\n");
        printf("Enter an integer(1,2,3,4):");
        scanf("%d",&difficulty_num);
    }

    level_num = 1;

    do{
        
        if(difficulty_num == 1){
            mines = (M * N) / 8;
        }
        else if(difficulty_num == 2){
            mines = (M * N) / 7;
        }
        else if(difficulty_num == 3){
            mines = (M * N) / 6;
        }
        else{
            mines = (M * N) / 5;
        }

        closedSq = (M*N) - mines;
         
        game_start(board, M, N);

        display_board(board, M, N, level_num, difficulty_num); 

        printf("Make your move: ");
        scanf("%s",input);

        if (strcmp(input, "s") == 0 || strcmp(input, "S") == 0){
            scanf("%d,%d",&r,&c);
            if(r<=0 || r>M || c<=0 || c>N){
                printf("\nWrong input... Try again...\n");
                continue;
            }
            if(board[r-1][c-1].isOpen == true){
                printf("\nSquare already open try opening an other one\n");
                continue;
            }
            show(board, M, N, r-1, c-1);
                
        }
        else if (strcmp(input, "m") == 0 || strcmp(input, "M") == 0){
            markMine(board, M, N, level_num, difficulty_num);                  
        }
        else if (strcmp(input, "h") == 0 || strcmp(input, "H") == 0){
            help(board, M, N);
        }
        else if (strcmp(input, "w") == 0 || strcmp(input, "W") == 0){
            wisdom(board, M, N);
        }
        else if (strcmp(input, "x") == 0 || strcmp(input, "X") == 0){
            for(i=0;i<M;i++){
                free(board[i]);
            }
            free(board);

            printf("\nExiting game...\n");
            return 0;
        }
        else{
            printf("\nWrong input... Try again...\n");
        }
       
        fill_board(board, M, N, mines, (r-1), (c-1));        

        display_board(board, M, N, level_num, difficulty_num);

//print the board with all squares open for debugging
/*       
    printf("\n");
    printf("    ");    
    for(j=0;j<N;j++){
        printf("%2d ",j+1);    	
	}
	printf("\n");
	printf("---");
	for(j=0;j<N;j++){
		printf("---");    	
	}	
	for(i=0;i<M;i++){
		printf("\n");
		if(i<9){
			printf("%d | ",i+1);
		}
		if(i>=9){
			printf("%d| ",i+1);
		} 
		for(j=0;j<N;j++){  
            if(board[i][j].cell == 10){
                printf("%d ",board[i][j].cell);
            }
            else{
                printf(" %d ",board[i][j].cell);
            }                         
			
		}
	}
    printf("\n");
*/
//-------------------------------------------------        

        do{ 
        
            printf("Make your move: ");
            scanf("%s",input);

            if (strcmp(input, "s") == 0 || strcmp(input, "S") == 0){
                scanf("%d,%d",&r,&c);
                if(r<=0 || r>M || c<=0 || c>N){
                    printf("\nWrong input... Try again...\n");
                    continue;
                }
                if(board[r-1][c-1].isOpen == true){
                    printf("\nSquare already open try opening an other one\n");
                    continue;
                }
                show(board, M, N, r-1, c-1);
                display_board(board, M, N, level_num, difficulty_num);
                
                if(board[r-1][c-1].cell == 10){
                    printf("\nYou were blown by a mine!\n");
                    printf("GAME OVER! \nBetter luck next time!\n");
                    return 0;
                }
                
            }
            else if (strcmp(input, "m") == 0 || strcmp(input, "M") == 0){
                markMine(board, M, N, level_num, difficulty_num);                  
            }
            else if (strcmp(input, "h") == 0 || strcmp(input, "H") == 0){
                help(board, M, N);
            }
            else if (strcmp(input, "w") == 0 || strcmp(input, "W") == 0){
                wisdom(board, M, N);
            }
            else if (strcmp(input, "x") == 0 || strcmp(input, "X") == 0){
                for(i=0;i<M;i++){
                    free(board[i]);
                }
                free(board);

                printf("\nExiting game...\n");
                return 0;
            }
            else{
                printf("\nWrong input... Try again...\n");
            }

            //printing remaining closed square for debugging
            //printf("\nRemaining closed squares without mines: %d\n",closedSq);
            
        }while(closedSq > 0 && mines != 0);               

        M++;
        N++;
        level_num++;

        if(M<=MAX_M && N<=MAX_N){

            //board memory reallocation
            board = (Board**) realloc (board, M * sizeof(Board*));              

            if(board == NULL){
                printf("\nNot available memory... exiting...\n");
                exit(0);    
            }

            for(i=0; i<M; i++){
                board[i] = NULL;
            }

            for(i=0; i<M; i++){
                board[i] = (Board*) realloc (board[i], N * sizeof(Board));
                if(board[i] == NULL){
                    printf("\nNot available memory... exiting...\n");
                    exit(0);  
                }
            }

            printf("\nMoving to the next level!\n\n");
        }

    }while(M<=MAX_M && N<=MAX_N);      
    
    printf("\nCongratulations! YOU WON!\n");
	
    //board memory deallocation
    for(i=0; i<M; i++){
		free(board[i]);
	}
	free(board);

    return 0;
}


void show(Board **board, int rows, int cols, int in_rows, int in_cols){
    int k,l;
    int count=0;

    for(k=0; k<rows; k++){
        for(l=0; l<cols; l++){
            if(board[k][l].isOpen == true){
                count++;
            }
        }
    }

    //if it is the first play we dont open all empty squares recursively
    if(count == 0){
        board[in_rows][in_cols].isOpen = true;
        closedSq--; 
    }
    else{
        if(board[in_rows][in_cols].isOpen == false){
            board[in_rows][in_cols].isOpen = true;
            closedSq--;                                     
            if(board[in_rows][in_cols].cell != 0){
                return;
            }
        }
        else{
            return;
        }

        for(k=(in_rows-1); k<(in_rows+2); k++){
            for(l=(in_cols-1); l<(in_cols+2); l++){
                if(k>-1 && l>-1 && k<rows && l<cols && board[k][l].cell != 10){
                    show(board, rows, cols, k, l);
                } 
            }
        }
    }
    
}

void markMine(Board **board, int rows, int cols, int level, int diff_num){
    int r,c;

    scanf("%d,%d",&r,&c);
    
    if(r<=0 || r>rows || c<=0 || c>cols){
        printf("\nWrong input... Try again...\n");
        return;
    }

    if(board[r-1][c-1].isMarked == true){
    	printf("\nSquare already marked try marking an other one\n");
        return;
    }

    if(board[r-1][c-1].isOpen == true){
        printf("\nSquare is open, it can't be marked\n");
        return;
    }

    board[r-1][c-1].isMarked = true;
    
    if(board[r-1][c-1].cell == 10){
        mines--;
    }

    display_board(board, rows, cols, level, diff_num);

}

void help(Board **board, int rows, int cols){
    int rr, rc;
    int count=0;

    //random cell that doesnt have a mine
    do{
        rr = rand()%rows;
        rc = rand()%cols;
        if(board[rr][rc].isOpen == false){
            if(board[rr][rc].cell != 10){
                printf("Try to open square %d,%d \n",rr+1,rc+1);
                count++;
            }
        }
    }while(count == 0);

}

//best square
void wisdom(Board **board, int rows, int cols){
    int k,l,k1,l1;
    int max=0;
    int count=0; 
    int count1=0;

    //finding the max of empty squares we can open at a time
    for(k=0; k<rows; k++){
        for(l=0; l<cols; l++){ 
            if(board[k][l].isOpen == false){
                if(board[k][l].cell == 0){
                    for(k1=(k-1); k1<(k+2); k1++){
                        for(l1=(l-1); l1<(l+2); l1++){
                            if(k1>-1 && l1>-1 && k1<rows && l1<cols && board[k1][l1].cell == 0){
                                count++;
                            } 
                        }
                    }
                    if(count>max){
                        max=count;
                    }
                    count=0;
                }
            } 
        }
    }

    //finding in which square is the max so that we can print it
    for(k=0; k<rows; k++){
        for(l=0; l<cols; l++){ 
            if(board[k][l].isOpen == false){
                if(board[k][l].cell == 0){
                    for(k1=(k-1); k1<(k+2); k1++){
                        for(l1=(l-1); l1<(l+2); l1++){
                            if(k1>-1 && l1>-1 && k1<rows && l1<cols && board[k1][l1].cell == 0){
                                count1++;
                            } 
                        }
                    }
                    if(count1 == max){
                        printf("\nBest square is %d,%d\n",k+1,l+1);
                        return;
                    }
                    count1=0;
                }
            }   
        }
    }

    if(max == 0){
        printf("\nNo more wisdom for you\n");
    }

    /*
        we dont locate recursively the square that opens the most empty cells like we do in the show() method
        we search the board and find the square surrounded with the most empty neighboring cells 
    */

}

//initializing the board
void game_start(Board **board, int rows, int cols){
    int k,l;

    //filling the board with empty cells, 0
    for(k=0; k<rows; k++){
        for(l=0; l<cols; l++){
            board[k][l].cell = 0;
			board[k][l].isOpen = false;
            board[k][l].isMarked = false;
        }
    }

}

//filling board with mines and bells
void fill_board(Board **board, int rows, int cols, int mine_num, int in_rows, int in_cols){
    int k,l,k1,l1;
    int rr,rc;

    //placing mines in random cells, 10
    //checking that we dont place a mine in a cell with a mine
    do{
        rr = rand()%rows;
        rc = rand()%cols; 
        if(rr != in_rows && rc != in_cols){
            if(board[rr][rc].cell != 10){
                board[rr][rc].cell = 10;
                mine_num--;
            }
        }   
    }while(mine_num > 0);

    //placing bells in the mine's neighboring cells, 1-8
    for(k=0; k<rows; k++){
        for(l=0; l<cols; l++){
            
            if(board[k][l].cell == 10){

                for(k1=(k-1); k1<(k+2); k1++){
                    for(l1=(l-1); l1<(l+2); l1++){
                        if(k1>-1 && l1>-1 && k1<rows && l1<cols && board[k1][l1].cell != 10){
                            board[k1][l1].cell += 1;
                        }
                    }
                }

            }

        }
    }
    
}

//board display
void display_board(Board **board, int rows, int cols, int level, int diff_num){
    
    int k,l;

    printf("\n");
    printf("    ");    
    for(l=0;l<cols;l++){
        printf("%2d ",l+1);    	//"%2d " if l+1=2 output should be _2_
	}
	printf("\n");
	printf("---");
	for(l=0;l<cols;l++){
		printf("---");    	
	}	
	for(k=0;k<rows;k++){
		printf("\n");
		if(k<9){
			printf("%d | ",k+1);
		}
		if(k>=9){
			printf("%d| ",k+1);
		} 
		for(l=0;l<cols;l++){                           
			
			if(board[k][l].isOpen == true){
                if (board[k][l].cell == 0){   
					printf(" . "); 
				}                   
				else if(board[k][l].cell == 10){
				    printf(" @ "); 
			    }
				else{
				    printf(" %d ",board[k][l].cell);
			    }	
			}
			else{
                if(board[k][l].isMarked == true){
                    printf(" * ");
                }
                else{
                    printf(" # ");
                }
			} 

		}
	}

    printf("\n \n");
    printf("Level: %d\n",level);

    if(diff_num == 1){
        printf("Difficulty: easy\n");
    }
    else if(diff_num == 2){
        printf("Difficulty: medium\n");
    }
    else if(diff_num == 3){
        printf("Difficulty: hard\n");
    }
    else{
        printf("Difficulty: really hard\n");
    }
    
    printf("Uncovered mines: %d\n",mines);

}

