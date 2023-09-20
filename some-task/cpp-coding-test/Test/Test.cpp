//
//   NVIDIA Development Tools Team
//       C++ Programming Test
//
// ---------------------------------
//
// This test should be self-explanatory.  All places where you are expected to
// write code are marked with TODO:  Each question is assigned a score.  Please
// see the SCORING comment below.  You are welcome to implement the questions
// in any order.
//
// This project should compile and run as-is, but all the tests will fail.
// Please implement all the TODOs as described below to get all the tests to
// succeed.
//
// You may use whatever other #includes you need.  You may use the C++ STL
// unless otherwise specified.  If you need help with STL (e.g. using fstream
// to read/write files), use the Josuttis book or read through the exercises
// and their tests, which have some file I/O already implemented.
//
// You're welcome to use stdio.h and C-style programming instead, but you'll
// have to convince us either way that your memory management is safe, even
// when ridiculous input values are passed to your functions.
//
// SCORING
// TestHierarchy                   Total = 45 points
//   a. Parser & data structure            15 points
//   b. Test function                      10 points
//   c. PrintHierarchyDepthFirst            5 points
//   d. PrintHierarchyDepthFirstSorted      5 points
//   e. PrintHierarchyBreadthFirst         10 points

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>

// Append data filenames to this string to read/write files in the data folder.
const std::string data_location("../Data/");

#define CHECK(cond, errstream, oss)      \
    if (!(cond))                         \
    {                                    \
        (oss) << errstream << std::endl; \
        return;                          \
    }

// -----------------------------------------------------------------------------
// Problem:
// Create a simple data structure to represent a hierarchy.  Write a parser to
// read files in the following format and store them in your hierarchy structure.
// Then write functions that print a hierarchy in depth-first and breadth-first
// order.  (Ask, or check out the tests, if you're not clear what that means)
//
// Example input file format (note that leading periods specify depth):
//
// grandpa & grandma
// .mom
// ..me
// ...my son
// ...my daughter
// ..my brother
// ..my sister
// ...my nephew
// .aunt gertrude
// ..my annoying cousin
//
// Make sure that you detect nonsensical structures in the input file.  For
// example, the first line should not contain any leading periods, and a line
// with one leading period cannot be followed by a line with more than two
// leading periods.
//
// Because the printing functions are external to your class, you'll need to
// choose what type of interface to expose for those functions to be simple.
// The logic for the printing functions should NOT be contained within the class.

// -----------------------------------------------------------------------------
// TODO: Implement this class
struct Node
{
    std::string parent;
    std::vector<Node> children;
};

enum
{
    Unsorted = 0,
    Sorted = 1
};

class Hierarchy
{
    std::vector<Node> _pHierarchy;

public:
    std::vector<Node> getHierarchy() const { return _pHierarchy; }

    void insertNode(std::string line, std::vector<Node> &hierarchy)
    {
        auto firstDot = std::find(line.begin(), line.end(), '.');
        if (firstDot == line.end())
            hierarchy.push_back({line, std::vector<Node>()});
        else
        {
            line.erase(firstDot);
            insertNode(line, hierarchy.back().children);
        }
    }

    // Return false if any I/O errors occur, otherwise return true.
    bool LoadFromFile(const std::string &infile)
    {
        // NOTE: Feel free to replace the entire implementation of
        // this function.
        std::ifstream ifs(infile.c_str());
        if (!ifs)
        {
            return false;
        }

        std::string line;
        while (std::getline(ifs, line))
        {
            insertNode(line, _pHierarchy);
        }

        return true;
    }
};

// TODO: Implement the following functions.  Print each node on a separate line,
// with leading periods to represent depth.  The depth-first output should be
// identical to the input file, such that Hierarchy::LoadFromFile() can load it.
// The sorted depth-first output should sort the children of each node before
// recursing into their children.  The breadth-first output should print all
// nodes at a given depth before printing any deeper nodes.  See the files
// HierarchyTest_expected_*.txt in the data directory for the expected results.
// Feel free to use helper functions, but don't change the signatures of these
// functions.

void print(std::vector<Node> hierarchy, int level, std::ostream &output, int sorted = Unsorted)
{
    if(sorted) std::sort(
        hierarchy.begin(),
        hierarchy.end(),
        [](const Node& lhs, const Node& rhs) {
            return lhs.parent.compare(rhs.parent);
        }
    );

    for (auto &node : hierarchy)
    {
        for (int i = 0; i < level; i++)
            output << ".";
        output << node.parent << std::endl;

        if (!node.children.empty())
            print(node.children, level + 1, output, sorted);
    }
};

void PrintHierarchyDepthFirst(const Hierarchy &h, std::ostream &output)
{
    print(h.getHierarchy(), 0, output);
}

void PrintHierarchyDepthFirstSorted(const Hierarchy &h, std::ostream &output)
{
    print(h.getHierarchy(), 0, output, Sorted);
}

void printNextBreadth(std::vector<Node> hierarchy, int level, std::ostream &output, std::map<int, std::vector<std::string>>& mp)
{
    for(auto node : hierarchy)
    {
        mp[level].push_back(node.parent);
    }
    for(auto node : hierarchy)
    {
        printNextBreadth(node.children, level+1, output, mp);
    }
}

void PrintHierarchyBreadthFirst(const Hierarchy &h, std::ostream &output)
{
    std::map<int, std::vector<std::string>> mp;
    printNextBreadth(h.getHierarchy(), 0, output, mp);
    for(auto& elem : mp)
    {
        for(auto& name : elem.second)
        {
            for(int i = 0; i<elem.first; i++)
                output << ".";
            output << name << std::endl;
        }
    }
}

// TODO: Improve this test method.
// How could you verify your outputs are correct?
// How could you refactor this function to be less repetitive?
void TestHierarchy(std::ostream &error_output)
{
    const std::string failure_msg("Hierarchy tests failed!");

    bool success = false;

    Hierarchy h;
    std::string infile(data_location + "HierarchyTest.txt");
    success = h.LoadFromFile(infile);

    CHECK(success, failure_msg << "  I/O error.", error_output);

    std::string outfile;
    std::string testfile;
    bool identical(false);

    std::ifstream input_file(std::string(data_location + "HierarchyTest.txt").c_str());
    std::string line;
    int n_input = 0;
    while (std::getline(input_file, line))
        n_input++;

    outfile = data_location + "HierarchyTest_output_DFS.txt";
    {
        std::ofstream ofs(outfile.c_str());
        CHECK(ofs, failure_msg << "  I/O error.", error_output);

        PrintHierarchyDepthFirst(h, ofs);

        std::ifstream ifs(outfile.c_str());
        CHECK(ofs, failure_msg << "  No " << outfile << " created" , error_output);

        std::string line;
        int n = 0;
        while (std::getline(ifs, line))
            n++;

        CHECK(n==n_input, failure_msg << "  Parsing failure " , error_output);
    }

    outfile = data_location + "HierarchyTest_output_DFS_sorted.txt";
    {
        std::ofstream ofs(outfile.c_str());
        CHECK(ofs, failure_msg << "  I/O error.", error_output);

        PrintHierarchyDepthFirstSorted(h, ofs);
        
        std::ifstream ifs(outfile.c_str());
        CHECK(ofs, failure_msg << "  No " << outfile << " created" , error_output);

        std::string line;
        int n = 0;
        while (std::getline(ifs, line))
            n++;

        CHECK(n==n_input, failure_msg << "  Parsing failure " , error_output);
    }

    outfile = data_location + "HierarchyTest_output_BFS.txt";
    {
        std::ofstream ofs(outfile.c_str());
        CHECK(ofs, failure_msg << "  I/O error.", error_output);

        PrintHierarchyBreadthFirst(h, ofs);

        std::ifstream ifs(outfile.c_str());
        CHECK(ofs, failure_msg << "  No " << outfile << " created" , error_output);

        std::string line;
        int n = 0;
        while (std::getline(ifs, line))
            n++;

        CHECK(n==n_input, failure_msg << "  Parsing failure " , error_output);
    }
}

// -----------------------------------------------------------------------------

int main()
{
    TestHierarchy(std::cout);

#ifdef _MSC_VER
    // Pause...
    std::cout << std::endl
              << std::endl
              << "Press enter to quit..." << std::endl;
    char c;
    std::cin >> std::noskipws >> c;
#endif

    return 0;
}
