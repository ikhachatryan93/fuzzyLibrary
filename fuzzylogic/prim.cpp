#include "Prim.h"

#include "Graph.h"
#include "GradedMeanIntegration.h"
#include "Triangle.h"

#include <vector>
#include <algorithm>

// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST  
template <typename T>
unsigned minKey(std::vector<T> key, std::vector<bool> mstSet)
{
    // Initialize min value  
    double min = DBL_MAX;
    unsigned min_index = 0;

    for (unsigned v = 0; v < key.size(); v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v], min_index = v;
        }
    }

    return min_index;
}

std::vector<unsigned> Prim::getMst(std::vector<std::vector<int>>& adjMatrix)
{
    const auto size = adjMatrix.size();

    // Array to store constructed MST  
    std::vector<unsigned> parent(size);

    // Key values used to pick minimum weight edge in cut  
    std::vector<int> key(size, INT32_MAX);

    // To represent set of vertices not yet included in MST  
    std::vector<bool> mstSet(size, false);

    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST  

    // The MST will have V vertices  
    // The MST will have V vertices  
    for (unsigned count = 0; count < size - 1; count++)
    {
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey<int>(key, mstSet);

        // Add the picked vertex to the MST Set  
        mstSet[u] = true;

        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST  
        for (unsigned v = 0; v < size; v++)

            // graph[u][v] is non zero only for adjacent vertices of m  
            // mstSet[v] is false for vertices not yet included in MST  
            // Update the key only if graph[u][v] is smaller than key[v]  
            if (adjMatrix[u][v] && mstSet[v] == false && adjMatrix[u][v] < key[v])
                parent[v] = u, key[v] = adjMatrix[u][v];
    }

    return parent;
}

std::vector<unsigned> Prim::getMst(std::vector<std::vector<double>>& adjMatrix)
{
    const auto size = adjMatrix.size();

    // Array to store constructed MST  
    std::vector<unsigned> parent(size);

    // Key values used to pick minimum weight edge in cut  
    std::vector<double> key(size, DBL_MAX);

    // To represent set of vertices not yet included in MST  
    std::vector<bool> mstSet(size, false);

    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST  

    // The MST will have V vertices  
    // The MST will have V vertices  
    for (unsigned count = 0; count < size - 1; count++)
    {
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey<double>(key, mstSet);

        // Add the picked vertex to the MST Set  
        mstSet[u] = true;

        for (unsigned v = 0; v < size; v++)
            // graph[u][v] is non zero only for adjacent vertices of m  
            // mstSet[v] is false for vertices not yet included in MST  
            // Update the key only if graph[u][v] is smaller than key[v]  
            if (adjMatrix[u][v] && mstSet[v] == false && adjMatrix[u][v] < key[v])
                parent[v] = u, key[v] = adjMatrix[u][v];
    }
    return parent;
}



void convertToCrispValues(const std::vector<std::vector<fuzzy::Triangle>>& fuzzyAdjMatrix, std::vector<std::vector<double>>& crispAdjMatrix) {
    crispAdjMatrix.resize(fuzzyAdjMatrix.size(), std::vector<double>(fuzzyAdjMatrix.size()));
   /* for (unsigned i = 0; i < fuzzyAdjMatrix.size(); ++i) {
        crispAdjMatrix[i].resize(fuzzyAdjMatrix[i].size());
        for (unsigned j = 0; j < fuzzyAdjMatrix.size(); ++j) {
            crispAdjMatrix[i][j] = fuzzy::GradedMeanIntegration::defuzzify(&(fuzzyAdjMatrix[i][j]));
        }
    }
    */
    for (unsigned i = 0; i < fuzzyAdjMatrix.size(); ++i) {
        for (unsigned j = i; j < fuzzyAdjMatrix.size(); ++j) {
            const auto v = fuzzy::GradedMeanIntegration::defuzzify(&(fuzzyAdjMatrix[i][j]));
            crispAdjMatrix[i][j] = v;
            crispAdjMatrix[j][i] = v;
        }
    }
}


std::vector<unsigned> Prim::getMstCrisp(std::vector<std::vector<fuzzy::Triangle>>& adjMatrix)
{
    const auto size = adjMatrix.size();

    std::vector<std::vector<double>> crispAdjMatrix;
    convertToCrispValues(adjMatrix, crispAdjMatrix);

    // Array to store constructed MST  
    std::vector<unsigned> parent(size);

    // Key values used to pick minimum weight edge in cut  
    std::vector<double> key(size, DBL_MAX);

    // To represent set of vertices not yet included in MST  
    std::vector<bool> mstSet(size, false);

    // Always include first vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST  

    fuzzy::Triangle costFN = fuzzy::Triangle();

    // The MST will have V vertices  
    for (unsigned count = 0; count < size - 1; count++)
    {
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey<double>(key, mstSet);

        // Add the picked vertex to the MST Set  
        mstSet[u] = true;

        for (unsigned v = 0; v < size; v++) {
            if (crispAdjMatrix[u][v] && mstSet[v] == false && crispAdjMatrix[u][v] < key[v]) {
                parent[v] = u, key[v] = crispAdjMatrix[u][v];
            }
        }
    }

    for (unsigned v = 1; v < size; v++) {
        costFN.add(
            adjMatrix[parent[v]][v]
        );
    }
    std::cout << "Final cost = " << fuzzy::GradedMeanIntegration::defuzzify(&costFN);
    return parent;
}

std::vector<unsigned> Prim::getMstFuzzy(std::vector<std::vector<fuzzy::Triangle>>& adjMatrix)
{
    const auto size = adjMatrix.size();

    std::vector<std::vector<double>> crispAdjMatrix;
    convertToCrispValues(adjMatrix, crispAdjMatrix);

    // Array to store constructed MST  
    std::vector<unsigned> parent(size);

    // Key values used to pick minimum weight edge in cut  
    std::vector<double> key(size, DBL_MAX);

    // To represent set of vertices not yet included in MST  
    std::vector<bool> mstSet(size, false);

    // Always include first vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST  

    fuzzy::Triangle costFN = fuzzy::Triangle();

    // The MST will have V vertices  
    for (unsigned count = 0; count < size - 1; count++)
    {
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey<double>(key, mstSet);

        // Add the picked vertex to the MST Set  
        mstSet[u] = true;

        for (unsigned v = 0; v < size; v++) {
            if (crispAdjMatrix[u][v] && mstSet[v] == false && crispAdjMatrix[u][v] < key[v]) {
                parent[v] = u, key[v] = crispAdjMatrix[u][v];
            }
        }
    }

    for (unsigned v = 1; v < size; v++) {
        costFN.add(
            adjMatrix[parent[v]][v]
        );
    }
    std::cout << "Final cost = " << fuzzy::GradedMeanIntegration::defuzzify(&costFN);
    return parent;
}