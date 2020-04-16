#include<stdio.h>
#include"input.c"
#include"visulization.c"
#include"algorithm.c"
int main(void){

    //handling the input data

    // create nodelist
    NodeList* nodeHead=(NodeList*)malloc(sizeof(NodeList));
    nodeHead->next=NULL;
	NodeList* pNode=nodeHead;
    
    // create waylist
    WayList* wayHead=(WayList*)malloc(sizeof(WayList));
    wayHead->next=NULL;
	WayList* pWay=wayHead;

    // create linklist
    LinkList* linkHead=(LinkList*)malloc(sizeof(LinkList));
    linkHead->next=NULL;
	LinkList* pLink=linkHead;

    // create geomlist
    GeomList* geomHead=(GeomList*)malloc(sizeof(GeomList));
    geomHead->next=NULL;
	GeomList* pGeom=geomHead;

    // create adjacentlist
    AdjacencyList* adjacentHead=(AdjacencyList*)malloc(sizeof(AdjacencyList));
    adjacentHead->next=NULL;
    AdjacencyList* pAdjacent=adjacentHead;


    // initialize and storing the input from the file
    input(pNode,pWay,pLink,pGeom);
    
    // generate adjacent list
    adjacent(pNode,pLink,pAdjacent);

    // show the original map with given data
    // showOriginalMap(pNode,pLink);
    
    // showNode(pNode);
    // showWay(pWay);
    // showLink(pLink);
    // showGeom(pGeom);
    // showAdjacentList(pAdjacent);

    //initialize the marks
    Marked marks[3941]={0,-1};
    int edgeTo[3941];
    initializeMark(marks,pNode);

    // mark sure thr first argument in dfs() is the same as the third argument in pathTo()
    dfs(-1887884675,marks,pAdjacent,edgeTo);
    NodeList* pPath=pathTo(-1887884839,marks,-1887884675,edgeTo,pNode);
    // showNode(pPath);
    showPath(pPath);
    return 0;
}