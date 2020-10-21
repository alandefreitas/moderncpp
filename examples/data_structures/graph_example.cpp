#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

class graph {
    public:
        graph(size_t n_vertices) : vertices(n_vertices) {};
        graph(size_t n_vertices, int initial_value) : vertices(n_vertices, initial_value) {};
        size_t size() { return vertices.size(); }
        graph& insert_vertex(int value) { vertices.push_back(value); return *this; }
        graph& insert_edge(size_t pos1, size_t pos2) { edges.emplace(pos1,pos2); return *this; }
        graph& insert_edge(std::vector<int>::iterator pos1, std::vector<int>::iterator pos2) { edges.emplace(pos1-vertices.begin(),pos2-vertices.begin()); return *this; }
        int& operator[] (size_t i) { return vertices[i]; }
        std::vector<int>::iterator begin() {return vertices.begin(); }
        std::vector<int>::iterator end() {return vertices.end(); }
        std::vector<int>::iterator vertex_begin() {return vertices.begin(); }
        std::vector<int>::iterator vertex_end() {return vertices.end(); }
        std::unordered_multimap<size_t,size_t>::iterator edge_begin() {return edges.begin(); }
        std::unordered_multimap<size_t,size_t>::iterator edge_end() {return edges.end(); }
        std::pair<std::unordered_multimap<size_t,size_t>::iterator,std::unordered_multimap<size_t,size_t>::iterator> neighbors([[maybe_unused]] std::vector<int>::iterator vertex) {
            return std::make_pair(edges.begin(),edges.end());
        }
    private:
        std::vector<int> vertices;
        std::unordered_multimap<size_t,size_t> edges;
};

int main() {
    std::cout << "Vector:" << std::endl;
    {
        std::vector<int> v = {2,6,4,8,4,9,7};
        v.push_back(3);
        v.emplace_back(4);
        v.pop_back();

        for (auto &&item : v) {
            std::cout << item << " ";
        }
        std::cout << std::endl;

        for (auto iter = v.begin(); iter != v.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Linked lists:" << std::endl;
    {
        std::list<int> v = {2,6,4,8,4,9,7};
        v.push_back(3);
        v.emplace_front(2);
        v.emplace_front(3);
        v.pop_front();

        for (auto &&item : v) {
            std::cout << item << " ";
        }
        std::cout << std::endl;

        for (auto iter = v.begin(); iter != v.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Double ended queue:" << std::endl;
    {
        std::deque<int> v = {2,6,4,8,4,9,7};
        v.push_back(3);
        v.emplace_front(2);
        v.emplace_front(3);
        v.pop_front();

        for (auto &&item : v) {
            std::cout << item << " ";
        }
        std::cout << std::endl;

        for (auto iter = v.begin(); iter != v.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Tree:" << std::endl;
    {
        std::set<int> v = {2,6,4,8,4,9,7};
        v.insert(3);
        v.emplace(2);
        v.erase(8);

        for (auto &&item : v) {
            std::cout << item << " ";
        }
        std::cout << std::endl;

        for (auto iter = v.begin(); iter != v.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Hash tables:" << std::endl;
    {
        std::unordered_set<int> v = {2,6,4,8,4,9,7};
        v.insert(3);
        v.emplace(2);
        v.erase(8);

        for (auto &&item : v) {
            std::cout << item << " ";
        }
        std::cout << std::endl;

        for (auto iter = v.begin(); iter != v.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Graph example: " << std::endl;
    {
        graph v(30);
        std::iota(v.begin(),v.end(),1);

        std::cout << "Vertices" << std::endl;
        for (auto &&item : v) {
            std::cout << item << " ";
        }
        std::cout << std::endl;

        for (auto iter = v.begin(); iter != v.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;

        v.insert_edge(3,6);
        v.insert_edge(7,2);
        v.insert_edge(4,2);
        v.insert_edge(1,8);

        std::cout << "Edges" << std::endl;
        for (auto iter = v.edge_begin(); iter != v.edge_end(); ++iter) {
            std::cout << iter->first << " " << iter->second << std::endl;
        }
        std::cout << std::endl;
    }


    return 0;
}