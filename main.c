#include<stdio.h>
#include"input.c"
int main(void){

    //handling the input data

    // create nodelist
    Nodelist* nodeHead=(Nodelist*)malloc(sizeof(Nodelist));
    nodeHead->next=NULL;
	Nodelist* pNode=nodeHead;
    
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

    input(pNode,pWay,pLink,pGeom);
    // showNode(pNode);
    // showWay(pWay);
    // showLink(pLink);
    // showGeom(pGeom);
    return 0;
}