#include<stdio.h>
#include"dataProcess.c"
#include"visulization.c"
#include"algorithm.c"
int main(void){
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
    
    // show the original map with given data
    // showOriginalMap(pNode,pLink);
    
    // showNode(pNode);
    // showWay(pWay);
    // showLink(pLink);
    // showGeom(pGeom);
    // showAdjacentList(pAdjacent);
    char choice;
    long start,end;
    while(1){
        printf("--------------------------------------------------\n");
        printf("This programme is used to find the route in a map.\n");
        printf("Two algorithms are implemented as options\n");
        printf("a.Find a route(dfs)\n");
        printf("b.Find the shortest route(Dijkstra)\n");
        printf("c.End the programme\n");
        printf("Please type in a, b or c to choose.\n");
        scanf("%c",&choice);
        if(choice=='a'){
            printf("Please type in the start node id and end node id.\ne.g. -1887884675 -1887884872\n");
            scanf("%d %d",&start,&end);
            printf("--------------------------DFS---------------------------\n");
            // generate adjacent list
            adjacent(pNode,pLink,pAdjacent);
            // find the route by given two nodes, implemented by dfs
            findRoute(start,end,pNode,pAdjacent);
            printf("--------------------------------------------------------\n");
        }
        else if(choice=='b'){
            printf("Please type in the start node id and end node id.\ne.g. -1887884675 -1887884872\n");
            scanf("%d %d",&start,&end);
            printf("-----------------------Dijkstra---------------------------\n");
            // generate adjacent list
            adjacent(pNode,pLink,pAdjacent);
            // find the shortest route by given two nodes, implemented by Dijkstra
            findShortestRoute(start,end,pNode,pAdjacent);
            printf("----------------------------------------------------------\n");
        }
        else if(choice=='c'){
            printf("Good bye!\n");
            return 0;
        }
        else{
            printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}