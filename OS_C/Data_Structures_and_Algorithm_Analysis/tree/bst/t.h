#ifndef _Tree_H
#define _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

int Retrieve( Position  P);
SearchTree Delete( SearchTree T, int X);
SearchTree Insert( SearchTree T, int X);
Position FindMax( SearchTree T);
Position FindMin( SearchTree T);
Position Find( SearchTree T, int X);
SearchTree MakeEmpty( SearchTree T);

#endif
