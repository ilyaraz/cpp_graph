#pragma once

#include <boost/range/iterator_range.hpp>

#include <vector>

namespace irg {
namespace directed_graph {

struct InputArc {
    int tail;
    int head;

    InputArc()
        : tail(-1)
        , head(-1) {}

    InputArc(int tail, int head)
        : tail(tail)
        , head(head) {}
};

struct Arc {
    int tail;
    int head;
    int id;
};

class DirectedGraph {
public:
    typedef std::vector<Arc>::const_iterator ArcConstIterator;
    typedef boost::iterator_range<ArcConstIterator> ArcConstIteratorRange;

    DirectedGraph(int nodesNumber, const std::vector<InputArc> &arcs);

    int getNodesNumber() const;
    int getArcsNumber() const;

    ArcConstIteratorRange getOutgoingArcs(int nodeID) const;
    ArcConstIteratorRange getIncomingArcs(int nodeID) const;

    ArcConstIterator getOutgoingArc(int arcID) const;
    ArcConstIterator getIncomingArc(int arcID) const;
private:
};

}
}
