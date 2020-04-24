#include<stdio.h>
#include"datastructure.h"
// visualization of original map with the given data
void showOriginalMap(NodeList* nodeHead,LinkList* nodeLink){

    NodeList* pNode=nodeHead;
    LinkList* pLink=nodeLink;
    double xmin=100,xmax=-100,ymin=100,ymax=0;

    pNode=pNode->next;
        while(pNode!=NULL){ 
            if(pNode->spot.lon>xmax)
                xmax=pNode->spot.lon;
            if(pNode->spot.lon<xmin)
                xmin=pNode->spot.lon;
            if(pNode->spot.lat>ymax)
                ymax=pNode->spot.lat;
            if(pNode->spot.lat<ymin)
                ymin=pNode->spot.lat;
           
            pNode=pNode->next;
        }
    double xdif,ydif;
    xdif=xmax-xmin;
    ydif=ymax-ymin;

    printf("xdif:%lf,ydif:%lf,xmax:%lf,xmin:%lf,ymax:%lf,ymin:%lf\n",xdif,ydif,xmax,xmin,ymax,ymin);

    FILE *fp = NULL;
    fp = fopen("./originalMap.txt", "w+");
    pLink=pLink->next;
    while(pLink!=NULL){ 
        long x,y;
        int count=0;
        x=pLink->currentLink.nodex;
        y=pLink->currentLink.nodey;
        NodeList* pNode=nodeHead;

        pNode=pNode->next;
        while(pNode!=NULL){ 
            if(pNode->spot.id==x){
                fprintf(fp,"%lf %lf\n",(pNode->spot.lon-xmin)/xdif*1000,(pNode->spot.lat-ymin)/ydif*1000);
                count++;
            }
            if(pNode->spot.id==y){
                fprintf(fp,"%lf %lf\n",(pNode->spot.lon-xmin)/xdif*1000,(pNode->spot.lat-ymin)/ydif*1000);
                count++;
            }
            if(count==2){
                fprintf(fp,"\n");
                fprintf(fp,"\n");
                break;
            }
            pNode=pNode->next;
        }
        pLink=pLink->next;
    }
    fclose(fp);
}

// visualization of path with given node list
void showPath(NodeList* nodeHead){
    FILE *fp = NULL;
    fp = fopen("./path.txt", "w+");
    NodeList* pNode=nodeHead;

    pNode=pNode->next;

    double xdif=0.02399,ydif=0.010314,xmax=-1.540754,xmin=-1.564744,ymax=53.811158,ymin=53.800844;
    while(pNode!=NULL){ 
        fprintf(fp,"%lf %lf\n",(pNode->spot.lon-xmin)/xdif*1000,(pNode->spot.lat-ymin)/ydif*1000);
        pNode=pNode->next;
    }
    fclose(fp);
}