/*
 * File: graph.cpp
 * Anthony Krivonos
 * 11/12/2018
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <string>
#include "graph.h"

using namespace std;

/**
 * Read Graph
 * - O(n)
 * - Reads vertices and edges from text file and adds to the graph.
 * @param file_name The filename of the input text file.
 */
void graph::read_graph(string file_name) {

      // Open the graph file
      ifstream graph_file;
      graph_file.open(file_name);

      // Ensure the graph input file has been opened
      if (graph_file.is_open()) {

            // Store set of vertices from file into vertex_str
            string vertex_str;
            graph_file >> vertex_str;

            // Add vertices to graph, map degrees of each vertex to 0
            for (int i = 0; i < vertex_str.length(); i++) {
                  char c = vertex_str[i];

                  // Add the vertex if it isn't an empty space to the vector
                  // Set the degree of that vertex to 0
                  if (c != ' ') {
                        vertices.push_back(c);
                        degrees[c] = 0;
                  }
            }

            // Add edges to map
            string edge_str;
            while (getline(graph_file, edge_str)) {
                  // Read in the edge
                  edge new_edge;
                  graph_file >> new_edge;

                  // Append edge to list of edges
                  edges.push_back(new_edge);

                  // Reset edge string
                  edge_str = "";
            }

            // Close the file being read
            graph_file.close();
      }
}

/**
 * Print Graph
 * - O(n)
 * - Prints the edges and vertices of the graph, consecutively, in order.
 */
void graph::print_graph() {
      // Output statement
      cout << "Original graph:" << endl;

      // Output edges
      cout << setw(11) << right << "edges:" << endl;
      for (int i = 0; i < edges.size(); i++) {
            // Output edge
            cout << setw(9) << left << "" << edges.at(i) << endl;
      }

      // Output vertices
      cout << setw(11) << right << "vertices:" << endl;
      for (int i = 0; i < vertices.size(); i++) {
            // Output vertex as "x"
            cout << setw(9) << left << "" << setw(10) << vertices.at(i) << endl;
      }

      // Add a line space
      cout << endl;
}

/**
 * Compute Degrees
 * - O(n)
 * - Loops through edges and increments the degree of each vertex in the edge within the degree map.
 */
void graph::compute_degrees() {
      // Reset each degree in the map
      map<char, int>::iterator it;
      for (it = degrees.begin(); it != degrees.end(); it++) {
            // Set the degree of the vertex to 0
            degrees[it->first] = 0;
      }

      // Loop through edges and increment
      for (int i = 0; i < edges.size(); i++) {
            edge e = edges.at(i);
            // Increment the degree of both the from and to vectors
            degrees[e.v_from] += 1;
            degrees[e.v_to] += 1;
      }
}

/**
 * Print Degrees
 * - O(n)
 * - Prints the degree of each vertex (number of times it appears in an edge) in order.
 */
void graph::print_degrees() {
      // Output statement
      cout << "Degrees of vertices in the graph:" << endl;

      // Output degree pairs
      map<char, int>::iterator it;
      for (it = degrees.begin(); it != degrees.end(); it++) {
            cout << setw(7) << left << "" << setw(4) << it->first << setw(4) << it->second << endl;
      }
}

/**
 * Input Overload
 * - O(1)
 * - Converts a "(x,y)" format string into an edge from vertex "x" to vertex "y".
 * - Updates the reference-passed edge e with the parsed to/from vertices.
 * @param &is An input stream passed by reference.
 * @param &e An edge passed by reference.
 * @returns An input stream of the given edge e.
 */
istream &operator >> (istream &is, edge &e) {

      // Read the edge string
      string edge_str;
      is >> edge_str;

      // Get splitting indices
      unsigned index_vertex_from = edge_str.find("(") + 1;
      unsigned index_delimiter = edge_str.find(",");
      unsigned index_vertex_to = index_delimiter + 1;
      unsigned index_close_paren = edge_str.find(")");

      // Read vertices from and to
      e.v_from = edge_str.substr(index_vertex_from, index_delimiter - index_vertex_from)[0];
      e.v_to = edge_str.substr(index_vertex_to, index_close_paren - index_vertex_to)[0];

      return is;
}

/**
 * Output Overload
 * - O(1)
 * @param &os An output stream passed by reference.
 * @param &e An edge passed by reference.
 * @returns An output stream of the given edge e in "(x,y)" format.
 */
ostream &operator << (ostream &os, const edge &e) {
      // Format edge string as "(x, y)"
      os << "(" << e.v_from << "," << e.v_to << ")";
      return os;
}
