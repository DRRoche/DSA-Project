#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//following linked list lab slightly
void ReadFile(std::string file_name, std::vector<std::vector<double>> * image_data);
int main(int argc, char* argv[]) {
    //load sparse matrices from files


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
        double token;

        // While there are still numbers in this string, extract them as doubles
        while(ss >> token){
            // Push these doubles into our temp vector
            new_row.push_back(token);
        }

        // The line is empty, push our completed row into our 2D vector
        image_data->push_back(new_row);
    }
}