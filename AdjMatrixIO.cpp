#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Declare variables
    int totalnode, node1, node2, weight;
    int mat[10][10] = {0};

    // Open the input file
    ifstream input("input.txt");

    if (input.is_open())
    {
        cout << "File opened\n";

        // Read the total number of nodes
        input >> totalnode;

        // Read node pairs and weights from the input file
        while (input >> node1 >> node2 >> weight)
        {
            // Store the weight in the adjacency matrix
            mat[node1][node2] = weight;
        }

        // Open the output file
        ofstream output("output.txt");

        if (output.is_open())
        {
            cout << "Output file created\n";

            // Write the adjacency matrix to the output file
            for (int i = 1; i <= totalnode; i++)
            {
                for (int j = 1; j <= totalnode; j++)
                {
                    // Write each element of the adjacency matrix to the output file
                    output << mat[i][j] << " ";
                }
                // Start a new line for the next row of the matrix
                output << endl;
            }
        }
        else
        {
            cout << "Output file not created";
        }
    }
    else
    {
        cout << "Input file not opened";
    }

    return 0;
}
