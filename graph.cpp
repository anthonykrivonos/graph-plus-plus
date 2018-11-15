/*
File: graph.h
Anthony Krivonos
11/12/2018
*/

#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <string>
#include "graph.h"

using namespace std;

graph::graph() {}

void graph::read_graph(string file_name) {
      ofstream graph_file;
      graph_file.open(file_name);

      // Store set of vertices from file into vertex_str.
      string vertex_str;
      getline(graph_file, vertex_str);

      // Add vertices to graph, map degrees of each vertex to 0
      for(char& c : vertex_str) {
            vertices.push_back(c);
            degrees[c] = 0;
      }

      // Add edges to map
      while (getline(graph_file, edge_str)) {



            // Create an edge between these vertices
            edge new_edge = new edge(vertex_from, vertex_to);

            // Append edge to list of edges
            edges.push_back(new_edge);

            // Reset edge string
            edge_str = "";
      }

      graph_file.close();
}

void map::print_graph() {
      // Output statement
      cout << "Original graph:" << endl;

      // Output edges
      cout << setw(11) << right << "edges:" << endl;
      for (int i = 0; i < edges.size(); i++) {
            cout << setw(9) << left << "" << setw(10) << "(" << edges.at(i).v_from << "," << edges.at(i).v_to << ")" << endl;
      }

      // Output vertices
      cout << setw(11) << right << "vertices:" << endl;
      for (int i = 0; i < vertices.size(); i++) {
            cout << setw(9) << left << "" << setw(10) << vertices.at(i) << endl;
      }
}

void graph::compute_degrees() {
      // Reset each degree in the map
      for (it = degrees.begin(); it != degrees.end(); it++) {
            degrees[it->first] = 0;
      }

      // Loop through edges and increment
      for (int i = 0; i < edges.size(); i++) {
            degrees[edge.v_from] += 1;
            degrees[edge.v_to] += 1;
      }
}

void graph::print_degrees() {
      // Output statement
      cout << "degrees of vertices in the graph:" << endl;

      // Output degree pairs
      for (it = degrees.begin(); it != degrees.end(); it++) {
            cout << setw(9) << left << "" << setw(4) << it->first << setw(4) << it->second << endl;
      }
}

friend istream &operator >> (istream &is, edge &e) {

      // Read the edge string
      string edge_str;
      is >> edge_str;

      // Get splitting indices
      unsigned index_vertex_from = edge_str.find("(") + 1;
      unsigned index_delimiter = edge_str.find(",");
      unsigned index_vertex_to = delimiter + 1;
      unsigned index_close_paren = edge_str.find(")");

      // Read vertices from and to
      edge.v_from = edge_str.substr(index_vertex_from, index_delimiter - index_vertex_from)[0];
      edge.v_to = edge_str.substr(index_vertex_to, index_close_paren - index_vertex_to)[0];

      return is;
}

friend ostream &operator << (ostream &os, const edge &e) {
      os << "(" << edge.v_from << "," << edge.v_to << ")" << endl;
      return os;
}
