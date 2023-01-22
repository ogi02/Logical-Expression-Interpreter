#include "graphics_utils.hh"

void draw_circle_with_text(int x, int y, string s) {
    // get text length
    int len = get_length(s);
    // draw circle
    circle(x, y, RADIUS);
    // get horizontal and vertical alignment of text
    float horizontal_alignment = len * FONT_SIZE / 2;
    float vertical_alignment = FONT_SIZE;
    // convert string to char array
    char text[len + 1];
    text[len] = '\0';
    for (int i = 0; i < len; i++) {
        text[i] = s[i];
    }
    // draw text
    outtextxy((x-horizontal_alignment), (y-vertical_alignment), text);
}

int find_max_depth(Node* node, int current_depth) {
    current_depth++;
    // try to go to the left
    int left_depth = current_depth;
    if (node->left()) {
        left_depth = find_max_depth(node->left(), current_depth);
    }
    int right_depth = current_depth;
    // try to go to the right
    if (node->right()) {
        right_depth = find_max_depth(node->right(), current_depth);
    }
    // return bigger depth
    return max(left_depth, right_depth);
}

void draw_node(Node* node, int level, int max_depth, int parent_x, int parent_y, char direction) {
    // ensure there is no endless loop
    if (level > max_depth) {
        return;
    }

    // define x and y for circle
    // 1 radius for the child, 1 for the parent and 1 for the margin
    int y = parent_y + 3 * RADIUS, x;
    if (direction == '-') {
        // goes to the left
        // goes further to the left if it is at a higher level to avoid overlapping of nodes
        x = parent_x - (pow(2, (max_depth - level)) * RADIUS);
    } else {
        // goes to the right
        // goes further to the right if it is at a higher level to avoid overlapping of nodes
        x = parent_x + (pow(2, (max_depth - level)) * RADIUS);
    }

    // get string value of node
    string text = node->string_value();
    draw_circle_with_text(x, y, text);

    // draw line to parent
    line(x, y - RADIUS, parent_x, parent_y + RADIUS);

    // draw left and right if they exist
    if (node->left()) {
        draw_node(node->left(), level + 1, max_depth, x, y, '-');
    }
    if (node->right()) {
        draw_node(node->right(), level + 1, max_depth, x, y, '+');
    }
}

void draw_tree(Node* tree) {
    // find max depth to determine window size
    int max_depth = find_max_depth(tree, 0);

    // define width and height of window
    // pow(2, max_depth - 1) * RADIUS * 2 -> every depth level has two times more
    // nodes than the previous
    // SPACING * 2 -> spacing left and right
    int width = pow(2, max_depth - 1) * RADIUS * 2 + SPACING * 2;
    // max_depth * RADIUS * 2 -> every node
    // (max_depth - 1) * RADIUS -> space between nodes
    // SPACING * 2 -> spacing up and down
    int height = max_depth * RADIUS * 2 + (max_depth - 1) * RADIUS + SPACING * 2;

    // create window
    initwindow(width, height);
    // configure text style
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

    // draw first node
    string text = tree->string_value();
    // middle of screen
    int x = width / 2;
    // from top to bottom
    int y = RADIUS + SPACING;
    draw_circle_with_text(x, y, text);

    // draw left and right nodes
    if (tree->left()) {
        draw_node(tree->left(), 2, max_depth, x, y, '-');
    }
    if (tree->right()) {
        draw_node(tree->right(), 2, max_depth, x, y, '+');
    }
}
