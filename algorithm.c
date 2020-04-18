#include<stdio.h>
#include"datastructure.h"

// initialize the marks
void initializeMark(Marked marks[],NodeList* nodeHead){
    for(int i=0;i<3941;i++){
       marks[i].val=-1;
    }

    // fill up the id for the structure marks 
    NodeList* pNode = nodeHead;
    int num=0;
        pNode=pNode->next;
        while(pNode!=NULL){ 
            marks[num].id=pNode->spot.id;
            pNode=pNode->next;
            num++;
        }
}

// for a given node id, output the index in marks
int getIndex(long id,Marked marks[]){
        for(int i=0;i<3941;i++){
            if(marks[i].id==id)
                return i;
        }
        return -1;
    }

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
                // printf("%d lat:%lf,lon:%lf dis:%lf\n",adjacentHead->head->spot.id,adjacentHead->head->spot.lat,adjacentHead->head->spot.lon,adjacentHead->head->spot.dis);
                int w=getIndex(adjacentHead->head->spot.id,marked);
                if(marked[w].val==-1){
                    // code here to add edgeTo[w]=v;
                    edgeTo[w]=v;
                    dfs(adjacentHead->head->spot.id,marked,pAdjacent,edgeTo);
                }
                adjacentHead->head=adjacentHead->head->next;
            }
            break;
        }
        adjacentHead=adjacentHead->next;
    }
}

// for a given terminal point, output the path to the start if it exists
 NodeList* pathTo(long id,Marked marked[],long start,int edgeTo[],NodeList* nodeHead){
    if(hasPathTo(id,marked)==-1){
        printf("no path to this node");
         return NULL;
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
    return pathHead;
 }

void enqueue(Queue* qHead, Node item){
    NodeList* old=qHead->last;
    qHead->last=(NodeList*)malloc(sizeof(NodeList));
    qHead->last->next=NULL;
    qHead->last->spot=item;
    if(qHead->n==0)
        qHead->first=qHead->last;
    else
        old->next=qHead->last;
    qHead->n++;
}

Node dequeue(Queue* qHead){
    NodeList* temp=qHead->first;
    qHead->first=qHead->first->next;
    if(qHead->n==0)
        qHead->last=NULL;
    qHead->n--;
    return temp->spot;
}

void visit(Marked marked[], long id, AdjacencyList* pAdjacent, EdgeList* pq){
    int v=getIndex(id,marked);
    if(v==-1){
        printf("There is no such node\n");
        return;
    }
        
    marked[v].val=1;
    EdgeList* pqHead=pq;
    AdjacencyList* adjacentHead=pAdjacent;

    adjacentHead=adjacentHead->next;
    while(adjacentHead!=NULL){
        if(adjacentHead->spot.id==id){
            printf("id=%d\n",id);
            adjacentHead->head=adjacentHead->head->next;   
            while(adjacentHead->head!=NULL){
                printf("%d lat:%lf,lon:%lf dis:%lf\n",adjacentHead->head->spot.id,adjacentHead->head->spot.lat,adjacentHead->head->spot.lon,adjacentHead->head->spot.dis);
                int w=getIndex(adjacentHead->head->spot.id,marked);
                if(marked[w].val==-1){

                    EdgeList* tempEdge=(EdgeList*)malloc(sizeof(EdgeList));
                    tempEdge->next=NULL;

                    Edge temp;
                    temp.x=id;
                    temp.y=adjacentHead->head->spot.id;
                    temp.dis=adjacentHead->head->spot.dis;
                    tempEdge->e=temp;
                    pqHead->next=tempEdge;
                    pqHead=pqHead->next;

                }


                adjacentHead->head=adjacentHead->head->next;
            }
            break;
        }
        adjacentHead=adjacentHead->next;
    }

}

// pop out the minist edge
Edge delMin(EdgeList* pq){
    double min=1000;
    Edge temp;
    EdgeList* edgeHead=pq;
    edgeHead=edgeHead->next;
        while(edgeHead!=NULL){ 
            if(edgeHead->e.dis<min){
                min=edgeHead->e.dis;
                temp.dis=edgeHead->e.dis;
                temp.x=edgeHead->e.x;
                temp.y=edgeHead->e.y;
            }
            edgeHead=edgeHead->next;
        }

    edgeHead=pq;
    if(edgeHead->next->e.dis==min){
        edgeHead->next=edgeHead->next->next;
        return temp;
    }
    edgeHead=edgeHead->next;
        while(edgeHead!=NULL){ 
            if(edgeHead->next->e.dis==min){
                edgeHead->next=edgeHead->next->next;
                return temp;
            }
            edgeHead=edgeHead->next;
        }


        return temp;
}



