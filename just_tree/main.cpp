#include "mytree.h"

int main()
{
    ExpressionTree tree;

    tree.makeTree();
    int num = tree.doOp();
    std::cout << num << std::endl;
    return 0;
}