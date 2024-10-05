#ifndef GRAPH_H
#define GRAPH_H

// Structure representing a graph using an adjacency matrix
struct u_adjacency_matrix {
    int** matrix;  // 2D array representing the adjacency matrix
    int size;      // Number of vertices in the graph
};

/**
 * @brief Creates a new adjacency matrix for an undirected graph of a given size.
 * 
 * @param size The number of vertices in the graph.
 * @return A pointer to the newly created matrix_graph structure.
 */
struct matrix_graph* new_uadjacency_matrix(int size);

/**
 * @brief Adds a connection (edge) between two vertices in the graph.
 * 
 * @param graph A pointer to the matrix_graph structure representing the graph.
 * @param a The first vertex in the edge.
 * @param b The second vertex in the edge.
 */
void add_connection(struct matrix_graph* graph, int a, int b);

/**
 * @brief Performs a breadth-first traversal and prints the graph.
 * 
 * @param graph A pointer to the matrix_graph structure representing the graph.
 */
void breadth_first_print(struct matrix_graph* graph);

/**
 * @brief Performs a depth-first traversal and prints the graph.
 * 
 * @param graph A pointer to the matrix_graph structure representing the graph.
 */
void depth_first_print(struct matrix_graph* graph);

#endif