#ifndef LOGICAL_EXPRESSION_INTERPRETER_GRAPHICS_UTILS_HH
#define LOGICAL_EXPRESSION_INTERPRETER_GRAPHICS_UTILS_HH

#include <math.h>
#include <iostream>
#include <graphics.h>
#include "string_utils.hh"
#include "../nodes/node.hh"
using namespace std;

static const int RADIUS = 40;
static const int SPACING = 20;
static const float FONT_SIZE = 12;

//-------------------------------------------------------------------
// FUNCTION: draw_circle_with_text()
// Draws a circle at a given point with radius = RADIUS
// and puts text inside it
//
// PARAMETERS:
// x (int) -> x coordinate of the center of the circle
// y (int) -> y coordinate of the center of the circle
// s (string) -> the text which will be in the circle
//
// RETURNS:
// none
//-------------------------------------------------------------------
void draw_circle_with_text(int x, int y, string s);

//-------------------------------------------------------------------
// FUNCTION: find_max_depth()
// Finds the maximum depth in a given tree recursively
//
// PARAMETERS:
// node (Node*) -> root of the tree that will be searched
// current_depth (int) -> the depth of the recursion
//
// RETURNS:
// (int) - the maximum depth
//-------------------------------------------------------------------
int find_max_depth(Node* node, int current_depth);


//-------------------------------------------------------------------
// FUNCTION: draw_node()
// Draws a node
// Generates its coordinates based on its parent coordinates and the
// depth level of the selected node
// Draws the line between itself and its parent
// Recursively draws all the kid nodes
//
// PARAMETERS:
// node (Node*) -> the node that will be drawn
// level (int) -> the depth level at which the node is in the tree
// max_depth (int) -> the maximum depth in the tree
// parent_x (int) -> the x coordinate of the parent node
// parent_y (int) -> the y coordinate of the parent node
// direction (char) -> '-' or '+' depending whether this is the left or right child of the parent
//
// RETURNS:
// none
//-------------------------------------------------------------------
void draw_node(Node* node, int level, int max_depth, int parent_x, int parent_y, char direction);

//-------------------------------------------------------------------
// FUNCTION: draw_node()
// Draws a tree
// Creates a window based on the depth of the tree
// Draws the root of the tree and recursively draws all the nodes of the tree
//
// PARAMETERS:
// tree (Node*) -> the tree that will be drawn
//
// RETURNS:
// none
//-------------------------------------------------------------------
void draw_tree(Node* tree);

#endif //LOGICAL_EXPRESSION_INTERPRETER_GRAPHICS_UTILS_HH
