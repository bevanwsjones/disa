// ---------------------------------------------------------------------------------------------------------------------
// MIT License
// Copyright (c) 2022 Bevan W.S. Jones
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// ---------------------------------------------------------------------------------------------------------------------
// File Name:
// Description:
// ---------------------------------------------------------------------------------------------------------------------

#include "gtest/gtest.h"

#include "graph_utilities.h"

using namespace Disa;

// Unit test for LevelTraversal using Google Test
TEST(test_graph_utilities, level_traversal_single_start_vertex) {
  Adjacency_Graph graph_saad = Adjacency_Graph({{0, 6}, {0, 8},
                                               {1, 7}, {1, 8}, {1, 10}, {1, 12},
                                               {2, 6}, {2, 7}, {2, 9},
                                               {3, 11}, {3, 12}, {3, 14},
                                               {4, 9}, {4, 10}, {4, 11}, {4, 13},
                                               {5, 13}, {5, 14},
                                               {6, 7}, {6, 8},
                                               {7, 8}, {7, 9}, {7, 10},
                                               {9, 10},
                                               {10, 11}, {10, 12},
                                               {11, 12}, {11, 13}, {11, 14},
                                               {13, 14}});


    std::vector<std::size_t> expected_levels = {0, 2, 2, 4, 4, 6, 1, 2, 1, 3, 3, 4, 3, 5, 5};
    EXPECT_EQ(expected_levels, level_traversal(graph_saad, 0));

    expected_levels = std::vector<std::size_t>({3, 1, 3, 1, 2, 3, 3, 2, 2, 2, 1, 1, 0, 2, 2});
    EXPECT_EQ(expected_levels, level_traversal(graph_saad, 12));
}

TEST(test_graph_utilities, level_traversal_multi_start_vertex) {
  Adjacency_Graph graph_saad = Adjacency_Graph({{0, 6}, {0, 8},
                                                {1, 7}, {1, 8}, {1, 10}, {1, 12},
                                                {2, 6}, {2, 7}, {2, 9},
                                                {3, 11}, {3, 12}, {3, 14},
                                                {4, 9}, {4, 10}, {4, 11}, {4, 13},
                                                {5, 13}, {5, 14},
                                                {6, 7}, {6, 8},
                                                {7, 8}, {7, 9}, {7, 10},
                                                {9, 10},
                                                {10, 11}, {10, 12},
                                                {11, 12}, {11, 13}, {11, 14},
                                                {13, 14}});

  std::vector<std::size_t> levels(graph_saad.size_vertex(), std::numeric_limits<std::size_t>::max());
  levels[0] = 0;
  levels[1] = 0;
  levels[3] = 0;
  std::queue<size_t> queue({0, 1, 3});
  level_traversal(graph_saad, queue, levels);
  std::vector<std::size_t> expected_levels = {0, 0, 2, 0, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1};
  EXPECT_EQ(expected_levels, levels);
}

TEST(test_graph_utilities, level_traversal_end_at_level){
  EXPECT_TRUE(false);
}

TEST(test_graph_utilities, pseudo_peripheral_vertex) {
  Adjacency_Graph graph_saad = Adjacency_Graph({{0, 6}, {0, 8},
                                                {1, 7}, {1, 8}, {1, 10}, {1, 12},
                                                {2, 6}, {2, 7}, {2, 9},
                                                {3, 11}, {3, 12}, {3, 14},
                                                {4, 9}, {4, 10}, {4, 11}, {4, 13},
                                                {5, 13}, {5, 14},
                                                {6, 7}, {6, 8},
                                                {7, 8}, {7, 9}, {7, 10},
                                                {9, 10},
                                                {10, 11}, {10, 12},
                                                {11, 12}, {11, 13}, {11, 14},
                                                {13, 14}});

  std::cout<<"\n"<<pseudo_peripheral_vertex(graph_saad, 11);
  std::cout<<"\n";
  EXPECT_TRUE(false);
}