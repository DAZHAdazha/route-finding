#include<stdio.h>
#include"datastructure.h"

// for a given node id, output whether it has path to the start
int hasPathTo(long id,Marked marked[]){
    int w=getIndex(id,marked);
    if(w==-1)
        return -1;
    return marked[w].val;
}

// depth first search
void dfs(long id,Marked marked[],AdjacencyList* pAdjacent,int edgeTo[]){
    AdjacencyList* adjacentHead=pAdjacent;
    int v=getIndex(id,marked);
    if(v==-1){
        printf("There is no such node\n");
        return;
    }  
    marked[v].val=1;
    // go through the adjacent list for the node v
    adjacentHead=adjacentHead->next;
    while(adjacentHead!=NULL){
        if(adjacentHead->spot.id==id){
            adjacentHead->head=adjacentHead->head->next;   
            while(adjacentHead->head!=NULL){
                int w=getIndex(adjacentHead->head->spot.id,marked);
                if(marked[w].val==-1){
                    edgeTo[w]=v;
                    dfs(adjacentHead->head->spot.id,marked,pAdjacent,edgeTo);
                }
                adjacentHead->head=adjacentHead->head->next;
            }
            break;
        }
        adjacentHead=adjacentHead->next;
    }
    return;
}

// for a given terminal point, output the path to the start if it exists in algorithm dfs
void pathTo(long id,Marked marked[],long start,int edgeTo[],NodeList* nodeHead){
    if(hasPathTo(id,marked)==-1){
        printf("no path to this node");
         return;
    }
    NodeList* pathHead=(NodeList*)malloc(sizeof(NodeList));
    pathHead->next=NULL;
	NodeList* pPath=pathHead;

    for(int i=getIndex(id,marked);i!=getIndex(start,marked);i=edgeTo[i]){
        printf("%d ",marked[i].id);
        NodeList* temp=(NodeList*)malloc(sizeof(NodeList));
        temp->next=NULL;

        Node tempNode;
        tempNode.id=marked[i].id;

        NodeList* pNode=nodeHead;
        pNode=pNode->next;
        while(pNode!=NULL){ 
            if(pNode->spot.id==tempNode.id){
                tempNode.lon=pNode->spot.lon;
                tempNode.lat=pNode->spot.lat;
            }
            pNode=pNode->next;
        }
        temp->spot=tempNode;
        pPath->next=temp; 
        pPath=pPath->next;
    }
        
    printf("%d\n",start);
    NodeList* temp=(NodeList*)malloc(sizeof(NodeList));
    temp->next=NULL;

    Node tempNode;
    tempNode.id=start;

    NodeList* pNode=nodeHead;
    pNode=pNode->next;
    while(pNode!=NULL){ 
        if(pNode->spot.id==tempNode.id){
            tempNode.lon=pNode->spot.lon;
            tempNode.lat=pNode->spot.lat;
        }
        pNode=pNode->next;
    }
    temp->spot=tempNode;
    pPath->next=temp; 
    pPath=pPath->next;
    showNode(pathHead);
    showPath(pathHead);
    printf("The output file 'path.txt' is generated.\n");
    return;
 }

 // integration of dfs algorithm
void findRoute(long start, long end, NodeList* nodeHead, AdjacencyList* pAdjacent){
    NodeList* pNode=nodeHead;
    //initialize the marks
    Marked marks[3941]={0,-1};
    int edgeTo[3941];
    
    initializeMark(marks,pNode);

    // mark sure thr first argument in dfs() is the same as the third argument in pathTo()
    dfs(start,marks,pAdjacent,edgeTo);
    pathTo(end,marks,start,edgeTo,pNode);
    return;
}