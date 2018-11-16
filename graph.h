/*
 * File: graph.h
 * Anthony Krivonos
 * 11/12/2018
 */

#include <vector>
#pragma once
using namespace std;

struct edge {
      char v_from;
      char v_to;
};

class graph {
      public:
            graph() {}
            void read_graph(string file_name);
            void print_graph();
            void compute_degrees();
            void print_degrees();
      private:
            vector<char> vertices;
            vector<edge> edges;
            map<char, int> degrees;
};

istream &operator >> ( istream &is, edge &e );
ostream &operator << ( ostream &os, const edge &e );
