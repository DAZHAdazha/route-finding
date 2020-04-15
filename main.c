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
    //showOriginalMap(pNode,pLink);
    
    // showNode(pNode);
    // showWay(pWay);
    // showLink(pLink);
    // showGeom(pGeom);
    // showAdjacentList(pAdjacent);

    Marked marks[3941]={0,-1};
    for(int i=0;i<3941;i++){
       marks[i].val=-1;
    }
    int edgeTo[3941];

    // fill up the id for the structure marks 
    pNode = nodeHead;
    int num=0;
        pNode=pNode->next;
        while(pNode!=NULL){ 
            marks[num].id=pNode->spot.id;
            pNode=pNode->next;
            num++;
        }


    dfs(-8847,marks,pAdjacent,edgeTo);
    pathTo(983404907,marks,-8847,edgeTo);
    return 0;
}