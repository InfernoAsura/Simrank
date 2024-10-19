#include <bits/stdc++.h>
#include "ECLgraph.h"
#include <chrono>
using namespace std;


// creating the adjacency list of in_neigbours
unordered_map<int,list<int>> u;
class sim
{
public:
    vector<pair<int, int>> ve; // vector to store different kinds of combinations of nodes to find the simrank
    int iter; // the number of iterations 
    double decay; // decay factor
    double num_nodes; // the number of nodes
    vector<vector<double>> old; // storing the simrank

    void init(){
        // initializing this old vector to store the sim rank values in a lower 
        // triangular matrix fashion
        old.resize(num_nodes, vector<double>(num_nodes,0));
        ve.resize(num_nodes * (num_nodes + 1) /2);
        for (int i = 0; i < num_nodes; i++)
        {
            old[i].resize(i+1);
            for(int j = 0; j < i + 1; j++){
                old[i][j] = 0;
                ve[i*(i+1)/2 + j] = {i,j};
            }
        }
        return;
    }

    sim(int iter, double decay_fac, double num_nodes)
    {
        this->iter = iter;
        this->decay = decay_fac;
        this -> num_nodes = num_nodes;
        init();
    }

    void calculate()
    {
        
        for (int i = 0; i < iter; i++){
            vector<vector<double>> temp(num_nodes, vector<double>(num_nodes,0));
            for (int pqr = 0; pqr < ve.size(); pqr++)
            {
                pair <int,int> j = ve[pqr];

                // this the condition when the nodes are the same
                if (j.first == j.second)
                {
                    temp[j.first][j.second] = 1;
                    continue;
                }

                // finding the in-neighbours and storing them
                int a = u[j.first].size();
                vector<int> ar;
                for (auto p : u[j.first])
                {
                    ar.push_back(p);
                }

                int b = u[j.second].size();
                vector<int> br;
                for (auto p : u[j.second])
                {
                    br.push_back(p);
                }

                // We only find simrank, if both the nodes have atleast 1 in-neighbor
                if(a != 0 && b != 0)
                {
                    double g = this->decay;
                    double scale = g / (a * b);
                    double sim_rank = 0; 
                    for (int k = 0; k < a; k++)
                    {
                        for (int l = 0; l < b; l++)
                        {
                            if(ar[k] > br[l]) sim_rank += old[ar[k]][br[l]];
                            else sim_rank += old[br[l]][ar[k]];
                        }
                    }
                    sim_rank = sim_rank * scale;
                    temp[j.first][j.second] = sim_rank;
                }
            }
            
            for(int k = 0; k < num_nodes; k++){
                for(int l = 0; l < k + 1; l++){
                    old[k][l] = temp[k][l];
                }
            }
        }
        return;
    }
    void print()
    {
        for (int i = 0; i < num_nodes; i++)
        {
            for (int j = 0; j < num_nodes; j++)
            {
                cout << old[i][j] << "      ";
            }
            cout << endl;
        }
    }
};

// function for printing the adjacency list
void print_adj(ECLgraph g){
        for(int i = 0; i < g.nodes/1000; i++){
        cout << i << "->";
        for(auto j: u[i]){
            cout << j << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    // starting time
    auto start = std::chrono::high_resolution_clock::now();

    // getting the graph by reading the egr graph
    const char* filename = "sample_1.egr";
    ECLgraph g;
    g = readECLgraph(filename);

    for(int i = 0; i < g.nodes - 1; i++){
        for(int j = g.nindex[i]; j < g.nindex[i+1]; j++){
            u[g.nlist[j]].push_back(i);
        }
    }
    for(int i = g.nindex[g.nodes - 1]; i < sizeof(g.nlist); i++){
        u[g.nlist[i]].push_back(g.nodes - 1);
    }
    // The adjacency list u only stores the in-neighbours of each node
    // print_adj(g);

    int num_iterations = 8;
    double c = 0.9;

    // creating the object 
    sim simr(num_iterations, c, g.nodes);

    simr.calculate();

    // printing the lower triangular matrix (only the first r rows)
    int r = 5;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < i + 1; j++){
            cout << simr.old[i][j] << " ";
        }
        cout << endl;
    }

    // free the memory
    freeECLgraph(g);
    
    // end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    std::chrono::duration<double> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
    return 0;
}
