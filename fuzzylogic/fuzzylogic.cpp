#include <iostream>

#include "Graph.h"
#include "Timer.h"
#include "Triangle.h"
#include "Prim.h"

#include "FuzzySet.h"

int main()
{
    //Timer t;
    ///Graph<fuzzy::Triangle> g;
    // Graph<int> g;

   /* g.randomFill(3);
    g.print();
    t.start();

    g.calculateMst([](auto& adjList) -> std::vector<unsigned> { return Prim::getMst(adjList); });

    t.stop();

   g.PrintMst();
   */
    const std::vector<std::pair<double, double>> s1 = { std::make_pair(0, 0), std::make_pair(3, 1), std::make_pair(6, 0) };
    const std::vector<std::pair<double, double>> s2 = { std::make_pair(3, 0), std::make_pair(6, 1), std::make_pair(9, 0) };
    fuzzy::FuzzySet f1(s1);
    fuzzy::FuzzySet f2(s2);
    const auto f3 = f1 + f2;
    auto v = f3.getSet();
    std::cout << f3 << std::endl;


   // std::cout << "\nElapsed time: " <<t.elapsedMilliseconds() << std::endl;
}