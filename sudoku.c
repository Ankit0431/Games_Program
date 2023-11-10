#include<stdio.h>
#include<stdlib.h>

struct sudoku{
    int **a;
    int size,n;
}*s;

void solve(struct sudoku *s,int r,int c);
void findEmptyCell(struct sudoku *s,int r,int c);

void display(struct sudoku *s){
    for(int i=0;i<s->n;i++){
        for(int j=0;j<s->n;j++){
            if(j%3==0){
                printf("|\t");
            }
            printf("%d\t",s->a[i][j]);
            if(j==8){
                printf("|\t");
            }
        }
        printf("\n");
        if(i%3==2){
            printf("_________________________________________________");
        }
        printf("\n");
    }
}

void board1(struct sudoku *s){
    s->a[0][0]=5;
    s->a[0][1]=3;
    s->a[0][4]=7;
    
    s->a[1][0]=6;
    s->a[1][3]=1;
    s->a[1][4]=9;
    s->a[1][5]=5;
    
    s->a[2][1]=9;
    s->a[2][2]=8;
    s->a[2][7]=6;
    
    s->a[3][0]=8;
    s->a[3][4]=6;
    s->a[3][8]=3;
    
    s->a[4][0]=4;
    s->a[4][3]=8;
    s->a[4][5]=3;
    s->a[4][8]=1;
    
    s->a[5][0]=7;
    s->a[5][4]=2;
    s->a[5][8]=6;
    
    s->a[6][1]=6;
    s->a[6][6]=2;
    s->a[6][7]=8;
    
    s->a[7][3]=4;
    s->a[7][4]=1;
    s->a[7][5]=9;
    s->a[7][8]=5;
    
    s->a[8][4]=8;
    s->a[8][7]=7;
    s->a[8][8]=9;
    
}

void board2(struct sudoku *s){
    s->a[0][0]=3;
    s->a[0][3]=8;
    s->a[0][5]=1;
    s->a[0][8]=2;
    
    s->a[1][0]=2;
    s->a[1][2]=1;
    s->a[1][4]=3;
    s->a[1][6]=6;
    s->a[1][8]=4;
    
    s->a[2][3]=2;
    s->a[2][5]=4;
    
    s->a[3][0]=8;
    s->a[3][2]=9;
    s->a[3][6]=1;
    s->a[3][8]=6;
    
    s->a[4][1]=6;
    s->a[4][7]=5;
    
    s->a[5][0]=7;
    s->a[5][2]=2;
    s->a[5][6]=4;
    s->a[5][8]=9;
    
    s->a[6][3]=5;
    s->a[6][5]=9;
    
    s->a[7][0]=9;
    s->a[7][2]=4;
    s->a[7][4]=8;
    s->a[7][6]=7;
    s->a[7][8]=5;
    
    s->a[8][0]=6;
    s->a[8][3]=1;
    s->a[8][5]=7;
    s->a[8][8]=3;
}

void board3(struct sudoku *s){
    s->a[0][0]=7;
    s->a[0][1]=3;
    s->a[0][4]=8;

    s->a[1][0]=5;
    s->a[1][3]=4;
    s->a[1][4]=2;
    s->a[1][5]=7;
    
    s->a[2][1]=2;
    s->a[2][2]=9;
    s->a[2][7]=5;
    
    s->a[3][0]=9;
    s->a[3][4]=5;
    s->a[3][8]=3;
    
    s->a[4][0]=6;
    s->a[4][3]=9;
    s->a[4][5]=3;
    s->a[4][8]=4;
    
    s->a[5][0]=8;
    s->a[5][4]=1;
    s->a[5][8]=5;
    
    s->a[6][1]=5;
    s->a[6][6]=1;
    s->a[6][7]=9;
    
    s->a[7][3]=6;
    s->a[7][4]=4;
    s->a[7][5]=2;
    s->a[7][8]=7;
    
    s->a[8][4]=9;
    s->a[8][7]=8;
    s->a[8][8]=2;
}

void create(struct sudoku *s){
    int choice;
    s->n=9;
    s->size=s->n*s->n;
    s->a=(int **)malloc(sizeof(int *)*s->n);
    for(int i=0;i<s->n;i++){
        s->a[i]=(int *)malloc(sizeof(int)*s->n);
    }
    printf("Choose any number from 1 to 3 for a board: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            board1(s);
        }
        break;
        case 2:{
            board2(s);
        }
        break;
        case 3:{
            board3(s);
        }
        break;
        default:{
            printf("Incorrect Choice! Choose again.\n");
        }
    }
    display(s);
}

int checkRow(struct sudoku *s,int r,int num){ // checks if that number is present in any column of that whole row
    for(int c=0;c<s->n;c++){
        if(s->a[r][c]==num){
            return 0; 
        }
    }
    return 1;
}

int checkColumn(struct sudoku *s,int c,int num){ // checks if that number is present in any row of that whole column
    for(int r=0;r<s->n;r++){
        if(s->a[r][c]==num){
            return 0;
        }
    }
    return 1;
}

int checkBox(struct sudoku *s,int row,int col,int num){ // checks if that number is already present in that grid or box ( 3x3 box )
    int r,c;
    r=row;
    c=col;
    if(row!=0 && row!=3 && row!=6){
        if(row==1 || row==2){
            r=0;
        }
        else if(row==4 || row==5){
            r=3;
        }
        else{
            r=6;
        }
    }
    if(col!=0 && col!=3 && col!=6){
        if(col==1 || col==2){
            c=0;
        }
        else if(col==4 || col==5){
            c=3;
        }
        else{
            c=6;
        }
    }
    for(int i=r;i<(r+3);i++){
        for(int j=c;j<(c+3);j++){
            if(s->a[i][j]==num){
                return 0;
            }
        }
    }
    return 1;
} 

void solve(struct sudoku *s,int r,int c){
    if(r>8){
        printf("\n\n<<<<<<<<<<<<< THE SOLVED SUDOKU >>>>>>>>>>>>>>>>>>>\n\n");
        display(s);
    }
    if(s->a[r][c]!=0){ // looks for empty cells i.e. cells with zero
        findEmptyCell(s,r,c);
    }
    else{
        for(int i=1;i<=9;i++){
            if(checkRow(s,r,i)==1 && checkColumn(s,c,i)==1 && checkBox(s,r,c,i)==1){
                s->a[r][c]=i;
                findEmptyCell(s,r,c);
            }
        }
        s->a[r][c]=0;
    }
}

void findEmptyCell(struct sudoku *s,int r,int c){
    if(c<8){ // checks each column of a row for empty cell
        solve(s,r,c+1);
    }
    else{ // moves to the next row to check for new empty cells
        solve(s,r+1,0);
    }
}

int main(){
    int i,j;
    s=(struct sudoku*)malloc(sizeof(struct sudoku));
    printf("\n<<<<<<<<<<<<< THE SUDOKU SOLVER >>>>>>>>>>>>>>>>>>>\n");
    create(s);
    // int x=checkBox(s,3,3,3);
    // printf("\nCheck Box: %d\n",x);
    solve(s,0,0);
    // printf("\n<<<<<<<<<<<<< THE SOLVED SUDOKU >>>>>>>>>>>>>>>>>>>\n");
    // display(s);
    return 0;
}