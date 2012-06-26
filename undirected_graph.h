#pragma once

#include "directed_graph.h"

#include <utility>

namespace irg {
namespace undirected_graph {

struct InputEdge {
    int v1;
    int v2;

    InputArc()
        : v1(-1)
        , v2(-1) {}

    InputArc(int v1, int v2)
        : v1(v1)
        , v2(v2) {}
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
