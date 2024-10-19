# SimRank Computation
SimRank is a graph-based measure of similarity introduced by Jeh and Widom in 2004. It quantifies the similarity between nodes in a graph based on the idea that two nodes are similar if they are connected to similar nodes.

# Power Method for SimRank
This repository contains the implementation of the Power Method, which is the simplest iterative approach to compute SimRank scores between nodes. The method works by repeatedly refining the similarity scores of nodes based on the scores of their neighbors until convergence. 
The input graph for this code is provided in the .egr format. You can find examples of graphs in this format at the following link, https://userweb.cs.txstate.edu/~burtscher/research/ECLgraph/index.html. The graphs were taken from snap datasets, and converted into .egr format. For example, the "sample_1.egr" file was converted from the sample_1_Gnutella.txt file from large network datasets on snap.

I have also uploaded the parallelized version of the Power Method, implemented using OpenMP. On the device used for testing, 128 cores were available for parallelization. Please adjust the number of threads to match your device's core configuration when using the code.

# How to Compile the Code

1. **For the sequential simrank code:**
  ``` bash
    g++ sim.cpp
  ```

2. **For the Parallel simrank code:**
  ``` bash
    g++ -fopenmp sim_parallel.cpp
  ```

### License

This repository includes several components, all developed by Dr. Martin Burtscher and his research team at Texas State University:

- **ECL_GRAPH.h**: The header file from the **Efficient Compressed Lists Graph (ECL-Graph) Library**.
- **snap2ecl.cpp**: A utility to convert SNAP-formatted graphs into the ECL format for compatibility with the ECL-Graph library.

### ECL-graph converter license

Copyright © 2019 Texas State University. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted for academic, research, experimental, or personal use provided that the following conditions are met:


- Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
- Neither the name of Texas State University nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
For all other uses, please contact the Office for Commercialization and Industry Relations at Texas State University http://www.txstate.edu/ocir/.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

