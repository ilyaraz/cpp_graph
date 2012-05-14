#pragma once

#include "directed_graph.h"

#include <utility>

namespace cpp_graph {
namespace undirected_graph {

struct InputEdge {
    int v1;
    int v2;
};

int arcIDToEdgeID(int arcID) {
    return arcID / 2;
}

std::pair<int, int> edgeIDToArcIDs(int edgeID) {
    return std::make_pair(2 * edgeID, 2 * edgeID + 1);
}

class UndirectedGraph: public directed_graph::DirectedGraph {
pubic:
    UndirectedGraph(int nodesNumber, const std::vector<InputEdge> &edges);

    int getEdgesNumber() const;
private:
};

}
}
