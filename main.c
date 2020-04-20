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
    // dfs(-1887884675,marks,pAdjacent,edgeTo);
    // NodeList* pPath=pathTo(-1887884839,marks,-1887884675,edgeTo,pNode);

    // showNode(pPath);
    // showPath(pPath);


    Queue* mst=(Queue*)malloc(sizeof(Queue));
    mst->n=0;
    mst->first=NULL;
    mst->last=NULL;

    NodeList* pq=(NodeList*)malloc(sizeof(NodeList));
    pq->next=NULL;

    Edge edgeToDijkstra[3941];
    for(int i=0;i<3941;i++){
        edgeToDijkstra[i].x=-1;
        edgeToDijkstra[i].y=-1;
        edgeToDijkstra[i].dis=-1;
    }




    // visit(marks,247293203,pAdjacent,pq);
    // showEdgeList(pq);
    // Edge min=delMin(pq);
    // printf("x=%d,y=%d,dis=%lf\n",min.x,min.y,min.dis);
    // showEdgeList(pq);

    double disTo[3941];
    for(int i=0;i<3941;i++){
        disTo[i]=10000;
    }


    // initializePq(pLink,pq);
    // showEdgeList(pq);

// 注意双向
    dijkstra(pq,disTo,247353859,marks,pAdjacent,edgeToDijkstra);

    // relax(-8847,pAdjacent,disTo,marks,edgeToDijkstra,pq);

    for(int i=0;i<3941;i++){
        printf("i=%d,x=%d,y=%d,dis=%lf\n",i,edgeToDijkstra[i].x,edgeToDijkstra[i].y,edgeToDijkstra[i].dis);
    }

    // for(int i=0;i<3941;i++){
    //     printf("i:%d dis=%lf\n",i,disTo[i]);
    // }

    pathToDijkstra(247353859,disTo,marks,edgeToDijkstra);

    printf("here");
    return 0;
}