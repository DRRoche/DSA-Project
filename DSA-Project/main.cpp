#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MatrixLinkedList.h"

MatrixLinkedList* MatrixMultiplier(MatrixLinkedList* matrix_a, MatrixLinkedList* matrix_b, MatrixLinkedList* result);
MatrixLinkedList* MatrixAddition(MatrixLinkedList* matrix_a, MatrixLinkedList* matrix_b, MatrixLinkedList* result);

//following linked list lab slightly
void ReadFile(std::string file_name, std::vector<std::vector<int>> * image_data);
MatrixLinkedList* ReadFile(std::string file_name, MatrixLinkedList* matrix);
void WriteFile(std::string file_name, MatrixLinkedList* matrix,std::string option);
int calculate_sparcity(MatrixLinkedList* matrix);

int main(int argc, char* argv[]) {
    //load sparse matrices from files
    if(argc < 4){
        std::cout<<"You were missing files";
    }
    else if(argc > 6){
        std::cout<<"Too many inputs";
    }
    else{
        std::string input1_fn = argv[1];
        std::string input2_fn = argv[2];
        std::string output_fn = argv[3];
        std::string choice = "-1";
        int mode = std::stoi(argv[4]);

        MatrixLinkedList* ll_matrix_a = new MatrixLinkedList();
        MatrixLinkedList* ll_matrix_b = new MatrixLinkedList();
        MatrixLinkedList* result = new MatrixLinkedList();

        if (mode == 1) {
            //Temporarily reads and stores matrix from file into 2D vector
            std::vector<std::vector<int> >* matrix_a = new std::vector<std::vector<int> >;
            std::vector<std::vector<int> >* matrix_b = new std::vector<std::vector<int> >;
            ReadFile(input1_fn, matrix_a);
            ReadFile(input2_fn, matrix_b);

            //Convert 2D vector into Matrix Linked List
            ll_matrix_a = new MatrixLinkedList(*matrix_a);
            ll_matrix_b = new MatrixLinkedList(*matrix_b);

            /**/
            //save to LL data file
            WriteFile("cll_" + input1_fn, ll_matrix_a, "2");
            WriteFile("cll_" + input2_fn, ll_matrix_b, "2");
            //*/
        }
        else if (mode == 2) {
            ll_matrix_a = ReadFile(input1_fn, ll_matrix_a);
            ll_matrix_b = ReadFile(input2_fn, ll_matrix_b);

        }
        else{
            std::cout<<"Invalid mode: try again"<<std::endl;
            return 0;
        }
        bool run = true;
        while(run) {
            std::cout << "Choose a value from the menu" << std::endl;
            std::cout << "1.)View Sparse Matrix" << std::endl;
            std::cout << "2.)Add or Multiply Sparse Matrix" << std::endl;
            std::cout << "3.)Check sparsity of matrix"<<std::endl;
            std::cout << "4.)Check if matrix is considered sparse or not"<<std::endl;
            std::cout << "5.)Exit" << std::endl;
            std::cin >>choice;

            //This if statement will output the different sparse matrices
            if(choice=="1"){
                choice ="0";
                while(run) {
                    std::cout << "Which Sparse Matrix do you want to view" << std::endl;
                    std::cout << "1.)Matrix from file1: " << input1_fn << std::endl;
                    std::cout << "2.)Matrix from file2: " << input2_fn << std::endl;
                    std::cout << "3.)Both file1 and file2 matrices" << std::endl;
                    std::cout << "4.)Current output matrix" << std::endl;
                    std::cout << "5.)Go back to main menu" << std::endl;
                    std::cin >> choice;

                    //Will Show the matrix from input1_fn
                    if (choice == "1") {
                        std::cout << ll_matrix_a->to_string()<<std::endl;
                    }
                        //will show the matrix from input2_fn
                    else if (choice == "2") {
                        std::cout << ll_matrix_b->to_string()<<std::endl;
                    }
                        //will show both input1_fn and input2_fn matrices
                    else if (choice == "3") {
                        std::cout<<input1_fn + ": "<<std::endl;
                        std::cout << ll_matrix_a->to_string();
                        std::cout<<std::endl;
                        std::cout<<input2_fn + ": "<<std::endl;
                        std::cout << ll_matrix_b->to_string()<<std::endl;
                    }
                        //Will show the matrix that will be put into the output file
                    else if (choice == "4") {
                        std::cout << result->to_string()<<std::endl;
                    }
                        //input is not valid
                    else if(choice != "5"){std::cout<<"Invalid input: try again"<<std::endl;}
                    else{
                        run =false;
                    }
                }
                run = true;
            }
                //This choice will let the user either multiply or add the given matrices
            else if(choice == "2"){
                choice = "0";
                while(run) {
                    std::cout << "Which math action do you want performed" << std::endl;
                    std::cout << "1.)Multiply matrices" << std::endl;
                    std::cout << "2.)Add Matrices" << std::endl;
                    std::cout << "3.)return to main menu" << std::endl;
                    std::cin >> choice;

                    //Will multiply the matrices
                    if (choice == "1") {
                        result = MatrixMultiplier(ll_matrix_a, ll_matrix_b, result);
                        std::cout<< "Matrix multiplication is complete"<<std::endl;
                    }
                        //Will add the matrices
                    else if (choice == "2") {
                        result = MatrixAddition(ll_matrix_a, ll_matrix_b, result);
                        std::cout<<"Matrix addition is complete"<<std::endl;
                    }
                    else if (choice != "3") {std::cout<<"Invalid option: try again"<<std::endl;}
                    else{
                        run = false;
                    }
                }
                run = true;
            }
            //This choice will check a specified matrices sparsity
            else if(choice == "3"){
                choice = "0";
                while(run) {
                    std::cout << "Which matrix do you want to check the sparsity for" << std::endl;
                    std::cout << "1.)Matrix from file1: " << input1_fn << std::endl;
                    std::cout << "2.)Matrix from file2: " << input2_fn << std::endl;
                    std::cout << "3.)Current output matrix" << std::endl;
                    std::cout << "4.)Go back to main menu" << std::endl;
                    std::cin >> choice;

                    if(choice == "1"){
                        std::cout << ll_matrix_a->getSparsity()<<std::endl<<std::endl;
                    }
                    else if(choice == "2"){
                        std::cout << ll_matrix_b->getSparsity()<<std::endl<<std::endl;
                    }
                    else if(choice == "3"){
                        float value = result->getSparsity();
                        if(value == -1){
                            std::cout<< "Matrix does not exist" <<std::endl;
                        }
                        else{
                            std::cout<< value<<std::endl;
                        }

                    }
                    else if(choice == "4"){run = false;}
                    else{std::cout<<"Invalid choice: Try again"<<std::endl;}
                }
                run = true;
            }
            //This choice will let the user know if the given matrix is considered sparse or not
            else if(choice == "4"){
                choice = "0";
                while(run) {
                    std::cout << "Which matrix do you want to check if it sparse or not" << std::endl;
                    std::cout << "1.)Matrix from file1: " << input1_fn << std::endl;
                    std::cout << "2.)Matrix from file2: " << input2_fn << std::endl;
                    std::cout << "3.)Current output matrix" << std::endl;
                    std::cout << "4.)Go back to main menu" << std::endl;
                    std::cin >> choice;

                    if(choice == "1"){
                        if(ll_matrix_a->isSparse()){
                            std::cout<<"The matrix from "<<input1_fn<<" is sparse"<<std::endl;
                        }
                        else{
                            std::cout<<"The matrix from "<<input1_fn<<" is not sparse"<<std::endl;
                        }
                    }
                    else if(choice == "2"){
                        if(ll_matrix_b->isSparse()){
                            std::cout<<"The matrix from "<<input2_fn<<" is sparse"<<std::endl;
                        }
                        else{
                            std::cout<<"The matrix from "<<input2_fn<<" is not sparse"<<std::endl;
                        }
                    }
                    else if(choice == "3"){
                        if(result->isSparse()){
                            std::cout<<"The current output matrix is sparse"<<std::endl;
                        }
                        else{
                            if(result->getSparsity()==-1){
                                std::cout<<"Matrix does not exist"<<std::endl;
                            }
                            else{
                                std::cout<<"The current output matrix from is not sparse"<<std::endl;
                            }
                        }

                    }
                    else if(choice == "4"){run = false;}
                    else{std::cout<<"Invalid choice: Try again"<<std::endl;}
                }
                run = true;
            }
                //This choice will let the user exit the program and save the output matrix if they like
            else if(choice == "5"){
                while(run) {
                    std::cout << "Do you want to save current output matrix: (y)es or (n)o?" << std::endl;
                    std::cin >> choice;
                    if (choice == "y") {
                        run = false;
                        std::cout<<"Would you like the output matrix to be saved:\n";
                        std::cout<<"1.) Matrix form\n";
                        std::cout<<"2.) Linked list form\n";
                        std::cin>>choice;
                        std::cout << "Saving output matrix to: " << output_fn << std::endl;
                        WriteFile(output_fn,result,choice);

                    }
                    else if (choice != "n") {
                        std::cout << "Wrong input: Try again" << std::endl;
                    }
                    else{run= false;}
                }

            }
            else{std::cout<<"Invalid option: try again"<<std::endl;}
        }
        std::cout<<"Thank you for using our program";
    }
}

void WriteFile(std::string file_name, MatrixLinkedList* matrix,std::string option) {
    // Opens the file for writing
    std::ofstream out_file(file_name);
    if(option == "1") {
        out_file << matrix->to_string();
    }
    else if(option == "2") {
        //writes matrix demensions as first line of file
        out_file << matrix->getNumRows() << " " << matrix->getNumCols() << "\n";

        //loops through matrix rows
        for (int r = 0; r < matrix->getNumRows(); r++) {
            //loops through matrix columns
            for (int c = 0; c < matrix->getNumCols(); c++) {
                //if non-zero entry write as new line in file
                if (matrix->rowEntry(r, c) != 0) {
                    out_file << r << " " << c << " " << matrix->rowEntry(r, c) << "\n";

                }
            }
        }
    }
    else{
        std::cout<<"option is invalid: resulting matrix will not be saved."<<std::endl;
    }
}

//Mode 1 readfile
void ReadFile(std::string file_name, std::vector<std::vector<int> > * image_data){
    // Opens the file for reading
    std::ifstream file(file_name);

    // Creates a string to hold each line in temporarily
    std::string str;

    // Iterates over the file, storing one line at a time into `str`
    while (std::getline(file, str)) {
        // Create a temporary 1D Vector of doubles
        std::vector<int > new_row;

        // Create a stringstream object with our line of integers from the file
        std::istringstream ss(str);

        // Create a double that will hold our extracted value from the string
        int token;

        // While there are still numbers in this string, extract them as doubles
        while(ss >> token){
            // Push these doubles into our temp vector
            new_row.push_back(token);
        }

        // The line is empty, push our completed row into our 2D vector
        image_data->push_back(new_row);
    }

}

//Mode 2 readfile
MatrixLinkedList* ReadFile(std::string file_name, MatrixLinkedList* matrix) {
    int row, col, data;
    // Opens the file for reading
    std::ifstream file(file_name);

    // Creates a string to hold each line in temporarily
    std::string str;

    std::getline(file, str);
    std::istringstream ss(str);

    //loads matrix demensions from file
    ss >> row;
    ss >> col;

    //initializes matrix with the correct demensions
    matrix = new MatrixLinkedList(row, col);

    // Iterates over the file, storing one line at a time into `str`
    while (std::getline(file, str)) {

        // Create a stringstream object with our line of integers from the file
        std::istringstream ss(str);

        //store node details in int variables
        ss >> row;
        ss >> col;
        ss >> data;

        //push node onto LinkedList
        matrix->push_back(row, col, data);
    }
    return matrix;
}


MatrixLinkedList* MatrixMultiplier(MatrixLinkedList* matrix_a, MatrixLinkedList* matrix_b, MatrixLinkedList* result) {
    //holds intermediate values
    int tmp;
    //Checks if matrices are the correct demensions
    if (matrix_a->getNumCols() == matrix_b->getNumRows()) {
        //initialize resulting matrix to the correct demensions.
        result = new MatrixLinkedList(matrix_a->getNumRows(), matrix_b->getNumCols());
        //loops through rows of result.
        for (int r = 0; r < result->getNumRows(); r++) {
            //loops through columns of result.
            for (int c = 0; c < result->getNumCols(); c++) {
                tmp = 0;
                //Performs the multiplication operation on the entires of matrix A & B for the
                //the current row and column location in result matrix.
                for (int k = 0; k < matrix_a->getNumCols(); k++) {
                    //if both entries are non-zeros then they will be multiplied and added to the intermediate value, tmp.
                    if (matrix_a->rowEntry(r, k) != 0 && matrix_b->colEntry(c, k) != 0) {
                        tmp += matrix_a->rowEntry(r, k) * matrix_b->colEntry(c, k);

                    }
                }
                //once all of the operations are done for an entry into result,
                //if the intermediate value doesn't total to zero then it is pushed to result.
                if (tmp != 0) result->push_back(r, c, tmp);
            }
        }
    }
        //if the matrices don't meet the required dimensions for multiplication then an error message is output to user
    else std::cout << "These matrices cannot be multiplied, columns in matrix A must equal rows in matrix B.\n";

    return result;

}

MatrixLinkedList* MatrixAddition(MatrixLinkedList* matrix_a, MatrixLinkedList* matrix_b, MatrixLinkedList* result) {
    //holds intermediate values
    int entry_a;
    int entry_b;
    //Checks if matrices are the correct demensions
    if (matrix_a->getNumRows() == matrix_b->getNumRows() && matrix_a->getNumCols() == matrix_b->getNumCols()) {
        //initialize resulting matrix to the correct demensions.
        result = new MatrixLinkedList(matrix_a->getNumRows(), matrix_a->getNumCols());
        //loops through rows of result.
        for (int r = 0; r < result->getNumRows(); r++) {
            //loops through columns of result.
            for (int c = 0; c < result->getNumCols(); c++) {
                //stores entries of matrix A & B for comparison.
                entry_a = matrix_a->rowEntry(r, c);
                entry_b = matrix_b->rowEntry(r, c);
                //as long as one entry has a non-zero entry and the sum of of both
                //doesn't equal zero, then add and push total onto result.
                if ((entry_a != 0 || entry_b != 0) && (entry_a + entry_b != 0) ) {
                    result->push_back(r, c, (entry_a + entry_b));
                }
            }
        }
    }
        //if the matrices don't meet the required dimensions for addition then an error message is output to user
    else std::cout << "These matrices cannot be added, dimensions of both matrices must match.\n";

    return result;
}
