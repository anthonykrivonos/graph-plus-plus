/*
 * File: test-graph.cpp
 * Anthony Krivonos
 * 11/12/2018
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include "graph.h"

using namespace std;

int main(int argc, char** argv) {

      graph g;

      if (argc != 2) {
            cerr << "Usage: " << argv[0] << " datafile\n";
            return 1;
      }

      g.read_graph(argv[1]);
      g.print_graph();
      g.compute_degrees();
      g.print_degrees();

      return 0;
}
