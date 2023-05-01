#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Define a structure to represent a disjoint set
typedef struct {
    int parent;
    int rank;
} DisjointSet;

// Find the root of the given element in the disjoint set
int find(DisjointSet* ds, int i) {
    if (ds[i].parent != i) {
        ds[i].parent = find(ds, ds[i].parent);
    }
    return ds[i].parent;
}

// Merge the two sets containing u and v in the disjoint set
void merge(DisjointSet* ds, int u, int v) {
    int u_root = find(ds, u);
    int v_root = find(ds, v);

    if (ds[u_root].rank < ds[v_root].rank) {
        ds[u_root].parent = v_root;
    } else if (ds[u_root].rank > ds[v_root].rank) {
        ds[v_root].parent = u_root;
    } else {
        ds[v_root].parent = u_root;
        ds[u_root].rank++;
    }
}

// Compare function for sorting edges by weight
int compare(const void* a, const void* b) {
    Edge* edge1 = (Edge*) a;
    Edge* edge2 = (Edge*) b;
    return edge1->weight - edge2->weight;
}

// Find the minimum spanning tree of the given graph using Kruskal's algorithm
void kruskal(Edge* edges, int num_edges, int num_vertices) {
    // Allocate memory for the disjoint set
    DisjointSet* ds = (DisjointSet*) malloc(num_vertices * sizeof(DisjointSet));
    for (int i = 0; i < num_vertices; i++) {
        ds[i].parent = i;
        ds[i].rank = 0;
    }

    // Sort the edges by weight
    qsort(edges, num_edges, sizeof(Edge), compare);

    // Initialize variables for the minimum spanning tree
    Edge mst[num_vertices - 1];
    int mst_index = 0;
    int edge_index = 0;

    // Loop through all edges until the minimum spanning tree is complete
    while (mst_index < num_vertices - 1 && edge_index < num_edges) {
        Edge current_edge = edges[edge_index];

        // Check if adding this edge creates a cycle
        int src_root = find(ds, current_edge.src);
        int dest_root = find(ds, current_edge.dest);
        if (src_root != dest_root) {
            // Add the edge to the minimum spanning tree and merge the two sets
            mst[mst_index] = current_edge;
            mst_index++;
            merge(ds, src_root, dest_root);
        }

        edge_index++;
    }

    // Print the minimum spanning tree
    printf("Minimum spanning tree:\n");
    for (int i = 0; i < mst_index; i++) {
        printf("%d - %d (%d)\n", mst[i].src, mst[i].dest, mst[i].weight);
    }

    // Free memory
    free(ds);
}

int main()
{
    Edge edg[] = {
{0, 1, 12},
{0, 5, 9},
{0, 6, 19},
{1, 2, 12},
{1, 6, 11},
{1, 7, 22},
{2, 3, 3},
{2, 7, 13},
{2, 8, 14},
{3, 4, 16},
{3, 8, 2},
{3, 9, 12},
{4, 9, 23},
{5, 6, 19},
{5, 10, 12},
{5, 11, 8},
{6, 7, 13},
{6, 11, 6},
{6, 12, 11},
{7, 8, 3},
{7, 12, 5},
{7, 13, 20},
{8, 9, 19},
{8, 13, 18},
{8, 14, 18},
{9, 14, 12},
{10, 11, 24},
{10, 15, 5},
{10, 16, 10},
{11, 12, 24},
{11, 16, 13},
{11, 17, 21},
{12, 13, 2},
{12, 17, 14},
{12, 18, 7},
{13, 14, 13},
{13, 18, 24},
{13, 19, 7},
{14, 19, 22},
{15, 16, 1},
{15, 20, 6},
{15, 21, 12},
{16, 17, 22},
{16, 21, 6},
{16, 22, 8},
{17, 18, 21},
{17, 22, 25},
{17, 23, 15},
{18, 19, 10},
{18, 23, 18},
{18, 24, 1},
{19, 24, 19},
{20, 21, 10},
{21, 22, 5},
{22, 23, 8},
{23, 24, 15}
};

    kruskal(edg,56,25);
	
}