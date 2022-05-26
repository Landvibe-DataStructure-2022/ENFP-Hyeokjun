#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr[10];
bool valid[10][10];

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

    void print() {
        for (edge *cur = header->next; cur != trailer; cur = cur->next) {
            cout << cur->src->vertexId << ' ' << cur->dst->vertexId << endl;
        }
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
            return;
        }

        eList.eraseEdge(edgeMatrix[srcMatrixId][dstMatrixId]);
        edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = NULL;
    }

    void incident(int srcId, int dstId) {
        if(edgeMatrix[srcId][dstId] != NULL){
            valid[srcId][dstId] = true;
        }

        for(int i = 0; i < edgeMatrix[srcId].size(); i++){
            if(edgeMatrix[srcId][i] != NULL){
                if(edgeMatrix[i][dstId] != NULL){
                    valid[srcId][dstId] = true;
                }
            }
        }
    }


private:
    vector<vector<edge *>> edgeMatrix;
    vertexList vList;
    edgeList eList;
};

int main() {
    int vSize;
    int tc;
    int info;
    cin >> vSize >> tc;
    graph graph;
    for (int i = 0; i < vSize; i++) {
        graph.insertVertex(i);
    }


    for (int i = 0; i < vSize; i++) {
        for (int j = 0; j < vSize; j++) {
            cin >> info;
            if (info == 1) {
                graph.insertEdge(i, j);
            }
        }
    }
    while (tc--) {
        int n;
        bool isWrong = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                graph.incident(arr[i] - 1, arr[j] - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!valid[arr[i] - 1][arr[j] - 1]) {
                    cout << 0 << endl;
                    isWrong = true;
                    break;
                }
            }
            if(isWrong) break;
        }

        if(!isWrong) cout << 1 << endl;

    }
}

// arr 안에 있는 vertex의 인접노드 탐색, 인접노드의 인접노드 탐색, 만약 존재하면 valid true 해서 모두 true이면 가능, 아니면 불가능