// CHRISTOPHER NILSSEN - topological_sort.cpp for LAB B CSCI 260 F2402
//
// This program performs a topological sort of courses based on their prerequisites,
// ensuring all prerequisite relationships are satisfied before dependent courses.
// The graph is represented as an adjacency list using linked lists, and Depth-First
// Search (DFS) is used to compute the topological order.
//
// Key components:
// - Node: Defines a linked list node used to represent edges in the graph
// - AdjList: Represents the adjacency list for each course
// - Graph: Encapsulates the graph structure with an array of adjacency lists
// - getCourseIndex: Dynamically maps course names to numeric indices for graph representation
// - topologicalSort: Computes and outputs a valid topological order of courses
//
// Input Format:
// - A text file specifying the number of prerequisite edges, followed by pairs of
//   courses and their prerequisites in the format: "course prerequisite" or "course none"
//
// Output:
// - Prints one possible topological order of the courses as course names


#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

// define max number of courses and edges
const int MAX_COURSES = 100;
const int MAX_EDGES = 100;

// adjacency list node
struct Node {
    int course_index;
    Node *next;
};

// adjacency list
struct AdjList {
    Node *head;
};

// graph structure
struct Graph {
    int num_courses;
    AdjList *list;
};

// create a new node for adj list
Node* createNode(int course_index) {
    Node *newNode = new Node;
    newNode->course_index = course_index;
    newNode->next = nullptr;
    return newNode;
}

// init graph with n courses
Graph* createGraph(int num_courses) {
    Graph *graph = new Graph;
    graph->num_courses = num_courses;
    graph->list = new AdjList[num_courses];
    for (int i = 0; i < num_courses; ++i) {
        graph->list[i].head = nullptr;
    }
    return graph;
}

// add directed edge to graph
void addEdge(Graph *graph, int prereq, int course) {
    Node *newNode = createNode(course);
    newNode->next = graph->list[prereq].head;
    graph->list[prereq].head = newNode;
}

// DFS for topo sort
void dfs(Graph *graph, int course, bool *visisted, int *stack, int &stack_index) {
    visisted[course] = true;
    Node *current = graph->list[course].head;
    while (current) {
        if (!visisted[current->course_index]) {
            dfs(graph, current->course_index, visisted, stack, stack_index);
        }
        current = current->next;
    }
    stack[stack_index--] = course;  // push onto stack
}

// perform topo sort
void topologicalSort(Graph *graph, char course_names[][20]) {
    bool visited[MAX_COURSES] = {false};
    int stack[MAX_COURSES];
    int stack_index = graph->num_courses - 1;

    // run dfs for each unvisited course
    for (int i = 0; i < graph->num_courses; ++i) {
        if (!visited[i]) {
            dfs(graph, i, visited, stack, stack_index);
        }
    }

    //output sorted courses
    cout << "One possible topological sort of the course is:" << endl;
    for (int i = 0; i < graph->num_courses; ++i) {
        cout << course_names[stack[i]] << endl;
    }
}

int main() {
    ifstream file("courses.txt");
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int num_edges;
    file >> num_edges;

    char course_names[MAX_COURSES][20];
    int course_index = 0;
    
    // map course names to indices
    auto getCourseIndex = [&](const char *name) {
        for (int i = 0; i < course_index; ++i) {
            if (strcmp(course_names[i], name) == 0) {
                return i;
            }
        }
        strcpy(course_names[course_index], name);
        return course_index++;
    };

    // read input and construct graph
    Graph *graph = createGraph(MAX_COURSES);
    for (int i = 0; i < num_edges; ++i) {
        char course[20], prereq[20];
        file >> course >> prereq;
        int course_idx = getCourseIndex(course);
        if (strcmp(prereq, "none") == 0) {
            continue;   // no prerequisite
        }
        int prereq_idx = getCourseIndex(prereq);
        addEdge(graph, prereq_idx, course_idx);
    }
    file.close();

    // adjust graph size to match number of courses
    graph->num_courses = course_index;

    // perform topo sort
    topologicalSort(graph, course_names);

    return 0;
}