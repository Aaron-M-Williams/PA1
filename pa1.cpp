#include <iostream>

int main() {
    //Declares all of the functions which will be used later
    //They are all of type void because they are either manipulating the array itself,
    //or printing their result out to the console.
    void printArray(int** square, int size);
    void verticalFlip(int** square, int size);
    void horizontalFlip(int** square, int size);
    void sumColRowsDiag(int** square, int size);
    void createMagicSquare(int** square, int size);
    void bothFlip(int** square, int size);

    int size=0;
    //Logic for taking in size and checking if it is odd and between 3 and 15.
    bool error = true;
    while (error) {
        std::cout << "Input the size of a magic square: ";
        std::cin >> size;

        if(size>2 && size<16 && size%2 ==1)
            error = false;
        else
            std::cout<<"The number you entered was either out of range, or even. Try again. \n";
        }


    //Creates the array dynamically
    int ** square = new int *[size];
    //Creates arrays within the base array, (multi-dimensional array).
    for (int i = 0; i < size; i++) {
        square[i] = new int[size];
    }



    //Calls upon createMagicSquare function with the parameters of square (2d array) and an integer size.
    //This function also prints to console the array and calls upon sumColRowsDiag to sum everything.
    createMagicSquare(square, size);

    //Calls upon the horizontalFlip function with the parameters of square (2d array) and an integer size.
    //This function also prints to console the flipped array and calls upon sumColRowsDiag to sum everything.
    horizontalFlip(square, size);

    //Calls upon the vericalFlip function with the parameters of square (2d array) and an integer size.
    //This function also prints to console the flipped array and calls upon sumColRowsDiag to sum everything.
    verticalFlip(square, size);

    //Calls upon the bothFlip function with the parameters of square (2d array) and an integer size.
    //This function also prints to console the flipped array and calls upon sumColRowsDiag to sum everything.
    bothFlip(square, size);



    //Deletes the array "square"
    delete square;
   //returns 1 for main method.
    return 1;


}



//PrintArray function, takes in a 2d array and an int of size. Prints the array to console.
void printArray(int** square, int size){

    //Prints out the Array
    for(int i=0; i<size ;i++) {
        for (int j = 0; j < size; j++) {
            std::cout << square[i][j] << "\t";
        }
        std::cout << "\n";
    }

}



//sumColRowsDiag function takes in a 2d array and an int of size.
//Prints the sums of the columns, rows, and diagonals on seperate lines.
void sumColRowsDiag(int** square, int size){

    //Checks the sum of each row and prints to console
    std::cout<<"Checking the sum of each row: ";
    for (int i=0; i<size; i++) {
        int sum =0;
        for (int j = 0; j < size; j++) {
            sum+= square[i][j];
        }
        std::cout <<sum<<"\t";
    }
    std::cout<<"\n";



    //Checks the sum of each column and prints to console.
    std::cout<<"Checking the sum of each column: ";
    for (int i=0; i<size; i++) {
        int sum =0;
        for (int j = 0; j < size; j++) {
            sum+= square[j][i];
        }
        std::cout <<sum<<"\t";
    }
    std::cout<<"\n";


    //Checks the sums of each diagonal
    std::cout<<"Checking the sum of each diagonal: ";
    int sumdiagonal=0;
    for(int i =0;i<size;i++)
        sumdiagonal+=square[i][i];
    std::cout<<sumdiagonal<<"\t";
    sumdiagonal=0;
    for(int i =0;i<size;i++)
        sumdiagonal+=square[i][i];
    std::cout<<sumdiagonal<<"\t";
    std::cout<<"\n";
}



//horizontalFlip takes in a 2d array and an int of size. Horizontally
//flips the array, calls upon the printArray function to print the array out
//and then calls upon the sumRowsColumns to check everything
void horizontalFlip(int ** square,int size){

    //Creates a temporary two dimensional array to use later.
    int**temp=new int* [size];
    for (int i = 0; i < size; i++) {
       temp[i] = new int[size];
    }

    //Logic to flip the array into the temporary array.
    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            temp[size-i-1][j] = square[i][j];
        }
    }

    //Prints the temporary array to the console
    printArray(temp, size);
    std::cout<<"\n";
    //Calls upon the sumRowsDiag function to sum all rows, colums, and diagonals.
    sumColRowsDiag(temp, size);
    std::cout<<"\n";
    //Deletes the temporary array to save memory.
    delete temp;
}



//createMagicSquare funciton takes in a 2d array and an int of size.
//Follows the logic to create the square and then calls upon the printArray
//function and the sumColRowsDiag function to check everything.
void createMagicSquare(int** square, int size){

    //Declares all of the variables which will be used to calculate the square.
    int a;
    int b;
    int RowLess;
    int colLess;
    int col;
    int row;

    //Initializes all of the elements of the array to 0.
    for(a=0 ; a<size ; a++) {
        for(b=0 ; b<size ; b++) {
            square[a][b] = 0;
        }
    }

    //Initializes all necessary values.
    row= 1;
    col= (size+1)/2;
    a= 1;
    square[row-1][col-1]=a;

    //Creates the logic square using the Siam Method
    for(a=2 ; a<=size*size ; a++) {
        RowLess = row - 1;
        colLess = col + 1;
        if (RowLess == 0 && colLess == (size + 1)) {
            RowLess = row + 1;
            colLess = size;
            row = RowLess;
            col = colLess;
            square[row - 1][col - 1] = a;
        } else {
            if (RowLess == 0) {
                RowLess = size;
            }
            if (colLess == (size + 1)) {
                colLess = 1;
            }
            if (square[RowLess - 1][colLess - 1] == 0) {
                row = RowLess;
                col = colLess;
                square[row - 1][col - 1] = a;
            } else {
                RowLess = row + 1;
                colLess = col;
                if (RowLess == (size + 1)) {
                    RowLess = 1;
                }
                row = RowLess;
                col = colLess;
                square[row - 1][col - 1] = a;
            }
        }
    }
    //Calls upon PrintArray to print out the array to the console
    printArray(square, size);
    std::cout<<"\n";
    //Calls upon the sum function to check all of the col, rows, and diagonals.
    sumColRowsDiag(square, size);
    std::cout<<"\n";

}



//verticalFlip takes in a 2d array and an int of size. Vertically
//flips the array, calls upon the printArray function to print the array out
//and then calls upon the sumRowsColumns to check everything
void verticalFlip(int** square, int size){
    int**temp=new int* [size];
    for (int i = 0; i < size; i++) {
        temp[i] = new int[size];
    }

    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            temp[j][size-1-i] = square[i][j];
        }
    }


    //Copies temp back to Square
    for(int i =0;i<size;i++){
        for(int j =0; j<size; j++){
            square[i][j]=temp[i][j];
        }
    }
    delete temp;
    printArray(square, size);
    std::cout<<"\n";
    sumColRowsDiag(square, size);
    std::cout<<"\n";

}



//bothFlip takes in a 2d array and an int of size. Flips the array
//horizontally and vertically, calls upon the printArray function to print the array out
//and then calls upon the sumRowsColumns to check everything
void bothFlip(int** square, int size){

    int**temp=new int* [size];
    for (int i = 0; i < size; i++) {
        temp[i] = new int[size];
    }

    //Copies temp back to square.
    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            temp[j][size-1-i] = square[i][j];
        }
    }


    //Copies temp back to Square
    for(int i =0;i<size;i++){
        for(int j =0; j<size; j++){
            square[i][j]=temp[i][j];
        }
    }

    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            temp[size-i-1][j] = square[i][j];
        }
    }

    printArray(temp, size);
    std::cout<<"\n";
    sumColRowsDiag(temp, size);
    std::cout<<"\n";
    delete temp;

}