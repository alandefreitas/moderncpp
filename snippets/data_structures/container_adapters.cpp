#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>

int main() {
    // Container adapters
    std::stack<int, std::vector<int>> s;
    std::queue<int, std::deque<int>> q;
    std::priority_queue<int, std::vector<int>> p;

    // Print sizes
    std::cout << "s.size(): " << s.size() << '\n';
    std::cout << "q.size(): " << q.size() << '\n';
    std::cout << "p.size(): " << p.size() << '\n';

    // Push back / Append
    s.push(6);
    q.push(6);
    p.push(6);

    std::cout << "s.size(): " << s.size() << '\n';
    std::cout << "q.size(): " << q.size() << '\n';
    std::cout << "p.size(): " << p.size() << '\n';

    // Top
    std::cout << "s.top(): " << s.top() << '\n';
    std::cout << "p.top(): " << p.top() << '\n';

    // Front/Back
    std::cout << "q.front(): " << q.front() << '\n';
    std::cout << "q.back(): " << q.back() << '\n';

    // Pop element
    s.pop();
    q.pop();
    p.pop();

    std::cout << "s.size(): " << s.size() << '\n';
    std::cout << "q.size(): " << q.size() << '\n';
    std::cout << "p.size(): " << p.size() << '\n';

}