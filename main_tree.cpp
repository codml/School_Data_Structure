#include <stdlib.h>
#include "mytree.h"

int main()
{
    ExpressionTree tree;

    tree.makeTree();
    std::cout << "output: " << tree.doOp() << std::endl;
    return (0);
}