# minesweeper-CLI

This is a command line version of the well known Minesweeper game. 

At the start the user gives the number of rows and cols and the level of difficulty.

The board is created and filled with mines and warning bells in the neighboring cells. 

There are four levels of difficulty. At the first level we place at the board a number of mines equal to 1/8 * (number of squares), at the second 
1/7 * (number of squares), at the third 1/6 * (number of squares) and at the fourth 1/5 * (number of squares). 

At first all squares are closed and the player makes his first move. The player can enter 's' followed by a square position to open a square, 'm' to mark a square, 'h' to ask the game for help, 'w' to ask the game for wisdom and 'x' to exit the game. 

If with the command 's' the player opens an empty square, all neighboring empty squares are opened recursively.

If with the command 'm' the player successfully marks a square with a mine, then the total amount of mines decreases.

The command 'h' shows a square that doesn't contain a mine.

The command 'w' shows the square that has the most empty neighboring cells.

If the player marks successfully all mine squares or if he opens all empty squares or bell squares except the ones with the mines, then he wins and a new game is started with both board dimensions increased by one. This will happen until the max dimensions are reached to which point the player has won and the game ends. 

EXAMPLE of playing with 8x8 board and level 2 of difficulty(medium)

--- Welcome! ---
This is a command line version of the well known game minesweeper
Enter the board dimensions
The number of rows can't be less than 6
and more than 50
The number of cols can't be less than 6
and more than 50
Enter the number of rows:8
Enter the number of cols:8
Choose a level of difficulty:
1.Easy
2.Medium
3.Hard
4.Really Hard
Enter an integer(1,2,3,4):2

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  #  #  #  #  #
2 |  #  #  #  #  #  #  #  #
3 |  #  #  #  #  #  #  #  #
4 |  #  #  #  #  #  #  #  #
5 |  #  #  #  #  #  #  #  #
6 |  #  #  #  #  #  #  #  #
7 |  #  #  #  #  #  #  #  #
8 |  #  #  #  #  #  #  #  #

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 3,4

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  #  #  #  #  #
2 |  #  #  #  #  #  #  #  #
3 |  #  #  #  2  #  #  #  #
4 |  #  #  #  #  #  #  #  #
5 |  #  #  #  #  #  #  #  #
6 |  #  #  #  #  #  #  #  #
7 |  #  #  #  #  #  #  #  #
8 |  #  #  #  #  #  #  #  #

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 5,4

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  #  #  #  #  #
2 |  #  #  #  #  #  #  #  #
3 |  #  #  #  2  #  #  #  #
4 |  #  #  #  #  #  #  #  #
5 |  #  #  #  2  #  #  #  #
6 |  #  #  #  #  #  #  #  #
7 |  #  #  #  #  #  #  #  #
8 |  #  #  #  #  #  #  #  #

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: h
Try to open square 6,6 
Make your move: s 6,6

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  #  #  #  #  #
2 |  #  #  #  #  #  #  #  #
3 |  #  #  #  2  #  #  #  #
4 |  #  #  #  #  #  #  #  #
5 |  #  #  #  2  #  #  #  #
6 |  #  #  #  #  #  1  #  #
7 |  #  #  #  #  #  #  #  #
8 |  #  #  #  #  #  #  #  #

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: w

Best square is 7,7
Make your move: s 7,7

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  #  #  #  1  .
2 |  #  #  #  #  #  #  1  .
3 |  #  #  #  2  #  #  1  .
4 |  #  #  #  #  #  #  1  .
5 |  #  3  2  2  #  2  1  .
6 |  #  1  .  1  #  1  .  .
7 |  #  2  .  1  1  1  .  .
8 |  #  1  .  .  .  .  .  .

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 2,2

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  #  #  #  1  .
2 |  #  2  #  #  #  #  1  .
3 |  #  #  #  2  #  #  1  .
4 |  #  #  #  #  #  #  1  .
5 |  #  3  2  2  #  2  1  .
6 |  #  1  .  1  #  1  .  .
7 |  #  2  .  1  1  1  .  .
8 |  #  1  .  .  .  .  .  .

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 4,1

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  #  #  #  1  .
2 |  #  2  #  #  #  #  1  .
3 |  #  #  #  2  #  #  1  .
4 |  1  #  #  #  #  #  1  .
5 |  #  3  2  2  #  2  1  .
6 |  #  1  .  1  #  1  .  .
7 |  #  2  .  1  1  1  .  .
8 |  #  1  .  .  .  .  .  .

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 1,4

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  1  #  #  1  .
2 |  #  2  #  #  #  #  1  .
3 |  #  #  #  2  #  #  1  .
4 |  1  #  #  #  #  #  1  .
5 |  #  3  2  2  #  2  1  .
6 |  #  1  .  1  #  1  .  .
7 |  #  2  .  1  1  1  .  .
8 |  #  1  .  .  .  .  .  .

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 5,5

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  1  #  #  1  .
2 |  #  2  #  #  #  #  1  .
3 |  #  #  #  2  #  #  1  .
4 |  1  #  #  #  #  #  1  .
5 |  #  3  2  2  2  2  1  .
6 |  #  1  .  1  #  1  .  .
7 |  #  2  .  1  1  1  .  .
8 |  #  1  .  .  .  .  .  .

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 4,5

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  1  #  #  1  .
2 |  #  2  #  #  #  #  1  .
3 |  #  #  #  2  #  #  1  .
4 |  1  #  #  #  1  #  1  .
5 |  #  3  2  2  2  2  1  .
6 |  #  1  .  1  #  1  .  .
7 |  #  2  .  1  1  1  .  .
8 |  #  1  .  .  .  .  .  .

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 4,4

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  1  #  #  1  .
2 |  #  2  #  #  #  #  1  .
3 |  #  #  #  2  #  #  1  .
4 |  1  #  #  1  1  #  1  .
5 |  #  3  2  2  2  2  1  .
6 |  #  1  .  1  #  1  .  .
7 |  #  2  .  1  1  1  .  .
8 |  #  1  .  .  .  .  .  .

Level: 1
Difficulty: medium
Uncovered mines: 9
Make your move: s 4,6

     1  2  3  4  5  6  7  8
---------------------------
1 |  #  #  #  1  #  #  1  .
2 |  #  2  #  #  #  #  1  .
3 |  #  #  #  2  #  #  1  .
4 |  1  #  #  1  1  @  1  .
5 |  #  3  2  2  2  2  1  .
6 |  #  1  .  1  #  1  .  .
7 |  #  2  .  1  1  1  .  .
8 |  #  1  .  .  .  .  .  .

Level: 1
Difficulty: medium
Uncovered mines: 9

You were blown by a mine!
GAME OVER!
Better luck next time!