#include <memory>
#include <vector>

using namespace std;

// пишем дерево
/*
 * слабые указатели связаны с shared
 */
struct Node {
//    shared_ptr<Node> parent;
    vector<shared_ptr<Node>> v; // печалька

    weak_ptr<Node> parent; // лучше

};