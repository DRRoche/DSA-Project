#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MatrixLinkedList.h"

//following linked list lab slightly
void ReadFile(std::string file_name, std::vector<std::vector<double>> * image_data);
int main(int argc, char* argv[]) {
    //load sparse matrices from files
    if(argc < 3){
        std::cout<<"You were missing files";
    }
    else if(argc > 4){
        std::cout<<"Too many inputs";
    }
    else{
        std::string input1_fn = argv[1];
        std::string input2_fn = argv[2];
        std::string output_fn = argv[3];
        std::string choice = "-1";
        bool run = true;
        while(run) {
            std::cout << "Choose a value from the menu" << std::endl;
            std::cout << "1.)View Sparse Matrix" << std::endl;
            std::cout << "2.)Add or Multiply Sparse Matrix" << std::endl;
            std::cout << "3.)Exit" << std::endl;
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
                    if (choice == "1") {}
                    //will show the matrix from input2_fn
                    else if (choice == "2") {}
                    //will show both input1_fn and input2_fn matrices
                    else if (choice == "3") {}
                    //Will show the matrix that will be put into the output file
                    else if (choice == "4") {}
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
                    if (choice == "1") {}
                    //Will add the matrices
                    else if (choice == "2") {}
                    else if (choice != "3") {std::cout<<"Invalid option: try again"<<std::endl;}
                    else{
                        run = false;
                    }
                }
                run = true;
            }
            //This choice will let the user exit the program and save the output matrix if they like
            else if(choice == "3"){
                while(run) {
                    std::cout << "Do you want to save current output matrix: (y)es or (n)o?" << std::endl;
                    std::cin >> choice;
                    if (choice == "y") {
                        run = false;
                        std::cout << "Saving output matrix to: " << output_fn << std::endl;
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

MatrixLinkedList MatrixMultiplier(MatrixLinkedList matrix_a, MatrixLinkedList matrix_b) {
    MatrixLinkedList result;
    if (matrix_a.getNumCols() == matrix_b.getNumRows()) {

    }

    return result;

}
