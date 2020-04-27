#include<stdio.h>
#include<stdlib.h>
#include"datastructure.h"

// push a item into queue
void enqueue(Queue* qHead, Node item){
    NodeList* TempNode=(NodeList*)malloc(sizeof(NodeList));
    TempNode->next=NULL;
    TempNode->spot=item;
    NodeList* nodeHead=qHead->head;
    while(nodeHead->next!=NULL){ 
        nodeHead=nodeHead->next;
    }
    nodeHead->next=TempNode;
    qHead->n++;
    return;
}

// pop out the minist item in the queue
Node delMin(Queue* pq){
	double min=99999;
    NodeList* nodeHead=pq->head;
    nodeHead=nodeHead->next;
    while(nodeHead!=NULL){ 
    	if(nodeHead->spot.dis<min){
    		min=nodeHead->spot.dis;
		}
        nodeHead=nodeHead->next;
    }
    nodeHead=pq->head;
    while(nodeHead!=NULL){
    	if(nodeHead->next->spot.dis==min){
    		Node temp;
    		temp.id=nodeHead->next->spot.id;
    		temp.dis=nodeHead->next->spot.dis;
            NodeList* Temp=nodeHead->next;
            free(Temp);
    		nodeHead->next=nodeHead->next->next;
    		(pq->n)--;
    		return temp;
		}
		nodeHead=nodeHead->next;
	}
}

// return the boolean value of whether the queue contain the item
int contain(Queue* pq,long id){
	NodeList* nodeHead=pq->head;
    nodeHead=nodeHead->next;
    while(nodeHead!=NULL){ 
    	if(id==nodeHead->spot.id)
    		return 1;
        nodeHead=nodeHead->next;
    }
	return 0;
}

// change value of the item in the queue if exists 
void change(Queue* pq,long id,long dis){
    NodeList* nodeHead=pq->head;
    nodeHead=nodeHead->next;
    while(nodeHead!=NULL){ 
    	if(id==nodeHead->spot.id){
    		nodeHead->spot.dis=dis;
    		return;
		}
        nodeHead=nodeHead->next;
    }
	return;
}

// importent step in algorithm Dijkstra, to find current shortest path for given start point
void relax(long id, AdjacencyList* pAdjacent,double disTo[],Marked marked[],Edge edgeTo[],Queue* pq){ 
    long v=getIndex(id,marked);
    AdjacencyList* adjacentHead=pAdjacent;
    adjacentHead=adjacentHead->next;
    while(adjacentHead!=NULL){
        if(adjacentHead->spot.id==id){
            adjacentHead->head=adjacentHead->head->next;   
            while(adjacentHead->head!=NULL){
                long w=getIndex(adjacentHead->head->spot.id,marked);
                if(disTo[w]>disTo[v]+adjacentHead->head->spot.dis){
                    disTo[w]=disTo[v]+adjacentHead->head->spot.dis;
                    Edge temp;
                    temp.x=id;
                    temp.y=adjacentHead->head->spot.id;
                    temp.dis=adjacentHead->head->spot.dis;
                    edgeTo[w]=temp;
                    if(contain(pq,adjacentHead->head->spot.id)==1){     
                        change(pq,adjacentHead->head->spot.id,disTo[w]); 
                    }
                    else{
                        Node tempNode;
                        tempNode.id=adjacentHead->head->spot.id;
                        tempNode.dis=disTo[w];
                        enqueue(pq,tempNode);
                     }
                }
                adjacentHead->head=adjacentHead->head->next;
            }
            break;
        }
        adjacentHead=adjacentHead->next;
    }
    return;
}

// to find the shortest path to all other nodes with the given start node
void dijkstra(Queue* pq, double disTo[], long start, Marked marked[],AdjacencyList* pAdjacent,Edge edgeTo[]){
    int s=getIndex(start,marked);
    if(s==-1){
        printf("there is no such node\n");
        return;
    }
    else{
        disTo[s]=0;
        Node tempNode;
        tempNode.id=start;
        tempNode.dis=0;
        enqueue(pq,tempNode);
        while(pq->n!=0){ 
            long id=delMin(pq).id;
            relax(id,pAdjacent,disTo,marked,edgeTo,pq);
        }
    }
    return;
}

// return the boolean value of whether has path in Dijkstra algorithm
int hasPathToDijkstra(long id,Marked marked[],double disTo[]){
    if(disTo[getIndex(id,marked)]<100000)
        return 1;
    else
        return 0;
}

// for a given terminal point, output the path to the start if it exists in algorithm Dijkstra
void pathToDijkstra(long id,double disTo[], Marked marked[],Edge edgeTo[],NodeList* nodeHead){
    if(hasPathToDijkstra(id,marked,disTo)){
        int v=getIndex(id,marked);
        printf("node=%d,dis=%lf\n",id,0.0);
        double length=0;
        NodeList* pPath=(NodeList*)malloc(sizeof(NodeList));
        pPath->next=NULL;
        NodeList* pHead=pPath;
        Node tempNode=getNode(id,nodeHead);
        NodeList* TempNode=(NodeList*)malloc(sizeof(NodeList));
        TempNode->next=NULL;
        TempNode->spot=tempNode;
        pHead->next=TempNode;
        pHead=pHead->next;
        for(Edge e=edgeTo[v];e.dis!=-1;e=edgeTo[getIndex(e.x,marked)]){
            printf("node=%d,dis=%lf\n",e.x,e.dis);
            length+=e.dis;
            Node tempNode=getNode(e.x,nodeHead);
            NodeList* TempNode=(NodeList*)malloc(sizeof(NodeList));
            TempNode->next=NULL;
            TempNode->spot=tempNode;
            pHead->next=TempNode;
            pHead=pHead->next;
        }
        printf("path length:%lf\n",length);
        showNode(pPath);
        showPath(pPath);
        printf("The output file 'path.txt' is generated.\n");
    }
    else{
        printf("there is no path\n");
        return;
    }
    return;
}

// destroy the queue
void destroyQueue(Queue* qHead){
    while(qHead->n!=0){
        delMin(qHead);
    }
    return;
}

// intergration of Dijkstra Algorithm
void findShortestRoute(long start, long end,NodeList* nodeHead,AdjacencyList* pAdjacent){
    NodeList* pNode=nodeHead;
    Marked marks[3941]={0,-1};
    initializeMark(marks,pNode);
     Edge edgeToDijkstra[3941];
    for(int i=0;i<3941;i++){
        edgeToDijkstra[i].x=-1;
        edgeToDijkstra[i].y=-1;
        edgeToDijkstra[i].dis=-1;
    }
    double disTo[3941];
    for(int i=0;i<3941;i++){
        disTo[i]=100000;
    }
    Queue* pq=(Queue*)malloc(sizeof(Queue));
    NodeList* tempNode=(NodeList*)malloc(sizeof(NodeList));
    tempNode->next=NULL;
    pq->head=tempNode;
    pq->n=0;
    dijkstra(pq,disTo,start,marks,pAdjacent,edgeToDijkstra);
    pathToDijkstra(end,disTo,marks,edgeToDijkstra,nodeHead);
    destroyQueue(pq);
    return;
}

