# SimRank Computation
SimRank is a graph-based measure of similarity introduced by Jeh and Widom in 2004. It quantifies the similarity between nodes in a graph based on the idea that two nodes are similar if they are connected to similar nodes.

# Power Method for SimRank
This repository contains the implementation of the Power Method, which is the simplest iterative approach to compute SimRank scores between nodes. The method works by repeatedly refining the similarity scores of nodes based on the scores of their neighbors until convergence. 
The input graph for this code is provided in the .egr format. You can find examples of graphs in this format at the following link, https://userweb.cs.txstate.edu/~burtscher/research/ECLgraph/index.html. The graphs were taken from snap datasets, and converted into .egr format. For example, the "sample_1.egr" file was converted from the sample_1_Gnutella.txt file from large network datasets on snap.
