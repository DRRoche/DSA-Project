# DSA-Project
 
### Summary: 
---
This program allows for the user to input two matrices, an output file, and a mode depending on what type of matrices the user inputted. This program stores all
the matrices, either given or created as a linked list. The program will display menus, which the user will choose the value, inorder to bring them to another menu,
perform the tak specified, or bring them back to the previous menu. The different tasks this program performs is adding or multiplying the two given matrices,
printing the matrices given by the user to terminal, printing the output matrice to user;if there is one; determining if a specific matrix is considered a sparse matrix, and printing to the user the sparsity of a given matrix. 

If the user inputs too many or too few inputs the program will inform inform you of the error and will end the session.  

---
### File format

For a simple matrix file:
For a linked List matrix file:

---
### Running the program 
To run this program on CLion ensure all your .ccp and .h files are in the CMakeLists.txt. The files should include:  
-[ ] main.cpp  
-[ ] MatrixLinkedList.cpp and .h  
-[ ] MatrixNode.cpp and .h  
Then ensure you have the two matrix files in the folder with your .exe file for the program. Ensure the matrix files are either in simple matrix form or linked list form, both files should be the same form and .txt files. Once these files are in their proper location you can click run>>edit configurations. Once this window opens in your program arguements line put in your first matrix .txt file, then your second matrix .txt file, then the .txt file for the output, and a mode; either 1 for simple matrices or 2 for linked list matrix files. Then click apply>>ok. Once back on the main screen you can press the play button in the toolbar and your program should run properly.

---
### Runtime Instructions:

At runtime, the program will automatically read the given matrices files and
store its data as linked lists. It will then print out a set of instructions
that informs the user of what to input, and what each option presented
does. If an option requires additional input from the user, it will
specify. After a certain function has been carried out, the program
will print out the menu again, and allow the user to perform additional
functions. Once the user is done, choosing the final option will close the
program and the user has the choice to save the results or not, and if the user would like for the results to be saved in simple matrix form or linked list form.
