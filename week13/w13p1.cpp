
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct vertex {
    int vertexId;
    int matrixId;
    vertex *prev;
    vertex *next;

    vertex() {
        vertexId = matrixId = -1;
        prev = next = NULL;
    }

    vertex(int vertexId) {
        this->vertexId = vertexId;
        matrixId = -1;
        prev = next = NULL;
    }
};

struct edge {
    vertex *src;
    vertex *dst;
    edge *prev;
    edge *next;

    edge() {
        src = dst = NULL;
        prev = next = NULL;
    }

    edge(vertex *src, vertex *dst) {
        this->src = src;
        this->dst = dst;
        prev = next = NULL;
    }
};

class vertexList {
public:
    vertexList() {
        header = new vertex();
        trailer = new vertex();
        header->next = trailer;
        trailer->prev = header;
        header->matrixId = -1;
    }

    void insertVertex(vertex *newVertex) {
        newVertex->prev = trailer->prev;
        newVertex->next = trailer;
        newVertex->matrixId = trailer->prev->matrixId + 1;
        trailer->prev->next = newVertex;
        trailer->prev = newVertex;
    }

    void eraseVertex(vertex *delVertex) {
        for (vertex *cur = delVertex; cur != trailer; cur = cur->next) {
            delVertex->matrixId--;
        }
        delVertex->prev->next = delVertex->next;
        delVertex->next->prev = delVertex->prev;
        delete delVertex;
    }

    vertex *findVertex(int vertexId) {
        for (vertex *cur = header->next; cur != trailer; cur = cur->next) {
            if (cur->vertexId == vertexId) {
                return cur;
            }
        }

        return NULL;
    }

private:
    vertex *header;
    vertex *trailer;

};

class edgeList {
public:
    edgeList() {
        header = new edge();
        trailer = new edge();
        header->next = trailer;
        trailer->prev = header;
    }

    void insertEdge(edge *newEdge) {
        newEdge->prev = trailer->prev;
        newEdge->next = trailer;
        trailer->prev->next = newEdge;
        trailer->prev = newEdge;
    }

    void eraseEdge(edge *delEdge) {
        delEdge->prev->next = delEdge->next;
        delEdge->next->prev = delEdge->prev;
        delete delEdge;
    }

private:
    edge *header;
    edge *trailer;
};

class graph {
public:
    void insertVertex(int vertexId) {
        if (vList.findVertex(vertexId) != NULL) {
            return;
        }

        vertex *newVertex = new vertex(vertexId);

        for (int i = 0; i < edgeMatrix.size(); i++) {
            edgeMatrix[i].push_back(NULL);
        }

        edgeMatrix.push_back(vector<edge *>(edgeMatrix.size() + 1, NULL));
        vList.insertVertex(newVertex);
    }

    void eraseVertex(int vertexId) {
        vertex *delVertex = vList.findVertex(vertexId);
        if (delVertex == NULL) {
            return;
        }

        int matrixId = delVertex->matrixId;
        for (int i = 0; i < edgeMatrix.size(); i++) {
            if (i != matrixId) {
                if (edgeMatrix[i][matrixId] != NULL) {
                    eList.eraseEdge(edgeMatrix[i][matrixId]);
                }
                edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId);
            }
        }
        for (int i = 0; i < edgeMatrix[matrixId].size(); i++) {
            if (edgeMatrix[matrixId][i] != NULL) {
                eList.eraseEdge(edgeMatrix[matrixId][i]);
            }
        }
        edgeMatrix.erase(edgeMatrix.begin() + matrixId);
        vList.eraseVertex(delVertex);
    }

    void insertEdge(int srcVertexId, int dstVertexId) {
        vertex *src = vList.findVertex(srcVertexId);
        vertex *dst = vList.findVertex(dstVertexId);
        if (src == NULL || dst == NULL) {
            return;
        }

        int srcMatrixId = src->matrixId;
        int dstMatrixId = dst->matrixId;

        if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL || edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
            cout << "Exist" << endl;
            return;
        }

        edge *newEdge = new edge(src, dst);
        eList.insertEdge(newEdge);
        edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = newEdge;
    }

    void eraseEdge(int srcVertexId, int dstVertexId) {
        vertex *src = vList.findVertex(srcVertexId);
        vertex *dst = vList.findVertex(dstVertexId);
        if (src == NULL || dst == NULL) {
            return;
        }

        int srcMatrixId = src->matrixId;
        int dstMatrixId = dst->matrixId;

        if (edgeMatrix[srcMatrixId][dstMatrixId] == NULL || edgeMatrix[dstMatrixId][srcMatrixId] == NULL) {
            cout << "None" << endl;
            return;
        }

        eList.eraseEdge(edgeMatrix[srcMatrixId][dstMatrixId]);
        edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = NULL;
    }

    void isAdjacentTo(int srcId, int dstId) {
        vertex *src = vList.findVertex(srcId);
        vertex *dst = vList.findVertex(dstId);

        if (edgeMatrix[src->matrixId][dst->matrixId] == NULL) {
            cout << "False" << endl;
        } else {
            cout << "True" << endl;
        }
    }

private:
    vector<vector<edge *>> edgeMatrix;
    vertexList vList;
    edgeList eList;
};

int main() {
    int tc, n;
    cin >> tc >> n;
    int vID;

    graph graph;
    for (int i = 0; i < n; i++) {
        cin >> vID;
        graph.insertVertex(vID);
    }
    while (tc--) {
        string q;
        int u, v;
        cin >> q >> u >> v;
        if (q == "insertEdge") {
            graph.insertEdge(u, v);
        } else if (q == "eraseEdge") {
            graph.eraseEdge(u, v);
        } else if (q == "isAdjacentTo") {
            graph.isAdjacentTo(u, v);
        }
    }
}