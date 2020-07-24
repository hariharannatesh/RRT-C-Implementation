# RRT-C-Implementation
To compile the code: g++ -o rrt.exe RRT.cpp -std=c++11 \
To run the program: ./rrt.exe \
Enter the start coordinates, goal coordinates, number of obstacles, number of nodes, obstacle coordinates once you see the following messages:\
"Enter starting point as X and Y coordinates"\
"Enter goal point as X and Y coordinates"\
"Enter number of obstacles"\
"Enter number of nodes"\
"Enter obstacle coordinates"\
The output will be whether a path is found or not. If a path is found, then the coordinates are printed.\

# RRT-using-headers
Each function prototype is written in a separate .h file \
Each function definition is written in separate .cpp file \
They are compiled into objective files (.o files) \
For eg:\
To compile "add_edge.cpp:" g++ -c add_edge.cpp -std=c++11 \
This is done for all the .cpp files.\
To compile and link all objective files into one executable file:\
g++ -o final.exe * .o -std=c++11 \
To run the program: .\final.exe \

# RRT-OOPS 
To generate objective files: g++ -c * .cpp -std=c++11 \
To generate executable file: g++ -o output.exe * .o -std=c++11 <br>
To run the program: .\output.exe <br>       

