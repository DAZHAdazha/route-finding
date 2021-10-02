# route-finding

>  Feng Yunjia
>
> **Planning Stage**
>
> **Summary**

In the second programming project, there were four choices available lists as follow: a chatbot, a library information system, Route finding and The SDL library. My choice was Route Finding which mainly focusing on designing a programme that could compute the best path between 2 points on a map with a given large data set to represent all the footpaths on the Leeds University Campus. This project needed to take in inputs from files and implemented proper data structure along with decent algorithm to find the shortest path between two spots.

## Problem Definition

The problem for this project could be generally described as follow: giving a undirected graph G that contains a vertexes set V(G) and a edges set E(G). For each vertex there is specific coordinate x and y to locate its position, and for each edge, no direction is specified which means e=uv is equivalent to e=vu. The requirement was to find the path between two given vertexes if it existed, and also some extra demanded that to find the shortest path instead.

## Feasibility Study

The feasibility study for this problem was quite clear. There was an important subject in discrete mathematics called Graph Theory which is particularly focused on the realistic problem in graph model like finding a route in a map, connecting wires in a circuit, searching a website in the whole Internet\... Therefore, a lot of refined algorithms had been used in daily industrial production to improve life quality for human kind such as Dijkstra, Prim, Bellman-Ford and so on. In this sense, the feasibility for this problem is clearly workable to implement.

## Requirement Analysis

The basic task for the project was to design a software system that allow user to giving two node id as input while output the data of the path or the shortest path if existed and visualize them to display. However, to made the user more easily to manipulate the system, a friendly GUI was required as long as the test tools should also be provided. Furthermore, the whole project should be properly divided into several module to clarify the code structure plus some necessary annotation to help user to understand basic usage of each function.

## Design Plan

### Large-scale design plan

The aim of designing this project was to simulate the process of giving out two spots in a map and try to solve the problem that to get the shortest way. This was a classic problem that always happen in real life like using the map application to navigate the right way. Furthermore, the algorithm in this task could also be applied in other field like in network flow and task scheduling as they share a basic model. To be more specifically, the input in this particular task was a map, or a file of a data set that contains abundant spots with their coordinates and other information. For

the output was not only to generate a way(that consists of may spots as passing spots) between two spots but also provide a visualization directly through gnuplot. In general, this project should satisfied the requirement that finding the shortest path between two spots with giving a map data set as input, by designing proper data structure with decent algorithm plus clear visualization.

### Medium-scale design plan

For this project, several code modules were required in order to make the structure more clear and easy to manage, also reduced the dependency between modules. First, an input module was necessary to take in the data file and transformed them into standard input with proper data structure for other modules to use. Then, a module for algorithm that could compute for the shortest way in a map with given map data. Moreover, visualization module was also required for visualizing the founded path in the map. At last, a main function should also be consisted as a module to initialize all the programme and generate the output.

### Iterations of design

In general, three iterations were required in total. The simplest application will be build at first for just input module and algorithm module in order to test whether the validity was true for method. For the next phase, visualization was integrated into the whole programme which could also reveal the validity of final result in a more straight-forward way. Similarly, the completed version was built in the end which consists the four components: input, algorithm, visualization and main.

However, some adjustments were integrated to the new iteration to the structure of the code to be more clear: the module input was divided into data process module and test module, where data process contain the functions that handling the input files and initialize the data while the test module was consists of all the "show" functions which could print out all the data in corresponding data structure and other tests. Moreover, the algorithm module was also separated into two modules since two algorithms were implemented(dfs for finding the route, and Dijkstra for finding the shortest route), this action helped implemented two algorithms individually and also more easily to compare them together.

## Test Plan

> **The test plan for the large-scale:**

For the large-scale test plan, the project need a general test and also modular test that built in each module separately. The general test should provide decent GUI and interaction between users and programme, while functionally able to print out corresponding result by giving instruction and also execution of modular tests for each section. For the module test, the test should also output expected results and actual results as well as the comparison. Moreover, module test could run in one single module without communication to other module functions directly.

## The test plan for the medium-scale:

For the test module, a test was designed to check whether there was missing data from the original version before handling. In order to show it more clear, four functions were designed to

print out all the data that had been stored in the data structure. The test ran just simply by calling four functions as followed: showNode(), showWay(), showGeom(), showLink(), showAdjacentList(). Before running them, a counter will print out the amount of all the data, and the counter will be running again after the test, variable "amount" were embedded in corresponding function to show the amount of nodes/ ways/ geoms/ links/ adjacent lists. Then two counts will be compared, if it is matched then no data was missing during the processing other wise there exists data leaking.

For the visualization module, the test should be taken by initializing the original data to a map with gnuplot first with the function "showOriginalMap()", then after executing the route-finding algorithm, the path should also be highlighted in the map in gnuplot. The function "showPath()" was defined to represent a found path that generated by algorithm dfs or Dijkstra and take the data structure list as argument, output a text file that could displayed in software gnuplot.

For the dfs module, the test should be taken by asking the user to type in start and end node id(including invalid id) and then test the programme whether give out correct responding(if invalid or no path then prompt user to try again, else output the text file that contain path and print out the path node list.)

For the dijkstra module, the test should be taken by asking the user to type in start and end node id(including invalid id) and then test the programme whether give out correct responding(if invalid or no path then prompt user to try again, else output the text file that contain path and print out the path node list.)

For the main module, the test should be taken by providing a brief GUI that allows user to interacted with the programme in normal usage and also a test mode that to test all the modules in the command line by given instruction.

## Schedule

### Planning schedule:

Three days for implementation one module, the order was mainly define as data structure -\> input -\> visualization -\> algorithm -\> test -\> main. All in total should cover in two weeks due to some module was simple to implement(like main and test).

### Actual execution:

2020/04/07, the project was started by figuring out the planning stage.

2020/04/08, the fundamental implementation of input module was almost finished.

2020/04/10, the input module was complemented as it could show all the data out with different types(node,way,geom,link) by integrating data structure link list. Five methods were created, "input" for initializing and store the data, "showNode(), showWay(), showLink(), showGeom()" were functions that could print out all the data information separately.

2020/04/10, visualization module had been started by drawing out the picture of the whole map through gnuplot.

> ![images](https://github.com/DAZHAdazha/route-finding/blob/master/images/1.jpg)

2020/04/12, data structure adjacent list was implemented which could show all the adjacent nodes for each node.

2020/04/13, started the algorithm module by finishing the function dfs(depth first search) that could search the adjacent list with depth first.

2020/04/14, finished the basic part of algorithm module by implementing function hasTo(), pathTo() which could find out a path between two given nodes if it exists with dfs method.

![images](https://github.com/DAZHAdazha/route-finding/blob/master/images/2.jpg)

2020/04/16, improved the algorithm and visualization module by adding the judgement of the validity of node ID and a function showPath() to output data file which could use gnuplot to show in graph, the path is shown as below:(the red line is the path)

2020/04/18, implemented the data structure edgeList and corresponding functions as the preparation for algorithm Dijkstra in order to find the shorts path.

2020/04/20, implemented Dijkstra algorithm. However, there still some bugs existed. 2020/04/21, completed the raw version of Dijkstra algorithm.

2020/04/23, Dijkstra algorithm completed also with the visualization.

> ![images](https://github.com/DAZHAdazha/route-finding/blob/master/images/3.jpg)

2020/04/24, brief GUI was integrated into the programme.

2020/04/26, re-construct all the modules, divided the algorithm.c into dfs.c and dijkstra.c. Besides, a module test.c was added.

2020/04/27, modular test were integrated into module visualization and data process as visualizationTest() and dataProcessTest(). Additionally, all the destroy functions were defined to free all the data that stored in data structure.

2020/05/27, a function computeDis() was added into the dfs.c, to provide the functionality to display the length for each and in total. Moreover, small changes to the print steam by removing some redundancy to make it more clear.

To see more project iteration versions could visit my Github repository where stored 15 commits, the address was listed as follow:

> [<span class="underline">https://github.com/DAZHAdazha/route-finding</span>](https://github.com/DAZHAdazha/route-finding)
>
> **Modular structure of the code:**
>
> **A list of modules for the application:**

1.  dataProcess.c: a module that used to handling the input data while also initialize and process data into normal form.

2.  visualization.c: a module that used to generate output files that could display graph in software gnuplot by giving data.

3.  dfs.c: a module that contain the algorithm of DFS(depth first search), which could find out a path between two given nodes.

4.  djikstra.c: a module that contain the algorithm of Dijkstra, which could find out a shortest path between two given nodes.

5.  main.c: a module that provide a brief GUI which allow user to manipulate the whole programme to run tests or find route.

6.  test.c: a module that consists of many test tools, in order to test the validity of the

programme.

7.  datastructure.h: a module that provide basic data structure for the programme.

## A list of functions in each module:

1.  dataProcess.c:

    1.  void (NodeList\* pNode,WayList\* pWay,LinkList\* pLink,GeomList\* pGeom): process the input data then store them into corresponding data structure.

    2.  void initializeMark(Marked marks\[\],NodeList\* nodeHead):

> initialize the array "marks", which will be used in algorithm dfs to store the status of each node has the path to the start point.

3.  int getIndex(long id, Marked marks\[\]):

> for a given node id, output the corresponding index in array "marks".

4.  Node getNode(long id,NodeList\* nodeHead): output the node with the given input node id.

5.  void adjacent(NodeList\* pNode,LinkList\* linkHead,AdjacencyList\* adjacentHead): generate the adjacent list for each node.

6.  void destroyNodeList(NodeList\* pNode): destroy the node list and free the memory.

7.  void destroyLinkList(LinkList\* pLink): destroy the link list and free the memory.

8.  void destroyWayList(WayList\* pWay): destroy the way list and free the memory.

9.  void destroyGeomList(GeomList\* pGeom): destroy the geom list and free the memory.

10.  void destroyAdjacentList(AdjacencyList\* pAdjacent): destroy the adjacent list and free the memory.

11.  int dataProcessTest():

> execute the modular test which will show all the data that store in the memory.

2.  visualization.c:

    1.  void showOriginalMap(NodeList\* nodeHead,LinkList\* nodeLink):

> visualization of original map with the given data, which could display graph in software gnuplot.

2.  void showPath(NodeList\* nodeHead):

> visualization of path with given node list, which could display graph in software gnuplot.

3.  int visualizationTest(): execute the modular test.

&nbsp;

3.  dfs.c:

    1.  int hasPathTo(long id,Marked marked\[\]):

> for a given node id, output whether it has path to the start.

2.  void dfs(long id,Marked marked\[\],AdjacencyList\* pAdjacent,int edgeTo\[\]): algorithm depth first search, to find out a route between two nodes if it exists.

3.  void pathTo(long id, Marked marked\[\], long start, int edgeTo\[\], NodeList\* nodeHead, LinkList\* linkHead):

> for a given terminal point, output the path to the start if it exists in algorithm dfs.

4.  void findRoute(long start, long end, NodeList\* nodeHead, AdjacencyList\* pAdjacent, LinkList\* pLink):

> integration of dfs algorithm.

5.  double computeDis(long x, long y, LinkList\* linkHead): compute the distance between two nodes.

&nbsp;

4.  dijkstra.c:

    1.  void enqueue(Queue\* qHead, Node item): push a node into the queue.

    2.  Node delMin(Queue\* pq):

> pop out the minimum node in the queue.

3.  int contain(Queue\* pq,long id):

> return the Boolean value of whether the queue contain the node.

4.  void change(Queue\* pq,long id,long dis): change value of the node in the queue if exists.

5.  void relax(long id, AdjacencyList\* pAdjacent, double disTo\[\], Marked marked\[\], Edge edgeTo\[\], Queue\* pq):

> an important step in algorithm Dijkstra, which used to find current shortest path for given start node.

6.  void dijkstra(Queue\* pq, double disTo\[\], long start, Marked marked\[\], AdjacencyList\* pAdjacent, Edge edgeTo\[\]):

> to find the shortest path to all other nodes with the given start node.

7.  int hasPathToDijkstra(long id,Marked marked\[\],double disTo\[\]): return the Boolean value of whether has path in Dijkstra algorithm.

8.  void pathToDijkstra(long id, double disTo\[\], Marked marked\[\], Edge edgeTo\[\], NodeList\* nodeHead):

> for a given terminal point, output the path to the start if it exists in algorithm Dijkstra.

9.  void findShortestRoute(long start, long end, NodeList\* nodeHead, AdjacencyList\* pAdjacent):

> intergration of Dijkstra Algorithm.

10. void destroyQueue(Queue\* qHead):

> destroy the queue and free the memory.

5.  main.c:

    1.  int main(void):

> provide a brief GUI that allow user to use this programme for tests and find route.

6.  test.c:

    1.  void showNode(NodeList\* nodeHead): test for go through all the \<node\>.

    2.  void showLink(LinkList\* linkHead): test for go through all the \<link\>.

    3.  void showWay(WayList\* wayHead): test for go through all the \<way\>.

    4.  void showGeom(GeomList\* geomHead): test for go through all the \<geom\>.

    5.  void showAdjacentList(AdjacencyList\* adjacentHead):

> test for go through all the adjacent list.

6.  void showEdgeList(EdgeList\* edgeHead): test for go through all the edge list.

7.  void showQueue(Queue\* pq):

> test for go through all the queue.

## A list of header files :

\(1\) datastructure.h: define several data structure like list, queue, node and other useful data structure to store corresponding data for other module to use.

# The project:

## Description of design strategy:

1.  **Planning for a high level:**

In a high level planning, this project was mainly divided into 7 modules: data structure, data process, visualization, dfs, dijkstra, test, main. Some of the parts contained modular tests inside the section in order to reduce the coupling and dependency between modules.

Data structure: this module was designed at first that contain the basic data structure like node, link, list, queue and corresponding manipulating methods that other modules might use to store or process data.

Data process: this module was created as the input interface to the data files, it could also process and initialize given data and stored into appropriate data structure that mentioned before.

Visualization: this module was used for display text file into graph by using the software gnuplot, it is the output interface of the programme.

Dfs: this module was the algorithm module in the programme which provide a serious of methods to find out the route between two nodes if the path exists.

Dijkstra: this module was also the algorithm module in the programme which provide a serous of methods to find out the shortest route between two nodes if the path exists.

Test: this module was designed to carry out most of the basic tests that contain in the programme in order to test the validity of the results.

Main: this module was created as a brief GUI that allow user to manipulate the programme by implemented two modes: normal mode and test mode, the former could normally used to find the route between two nodes while the later could run all the tests in the programme.

## Design iterations:

For this project, a raw version was implemented by integrated each module one by one as iterations. Then, a demo for the project was created that could run for basic functionality which contain five modules: input, data structure, visualization, algorithm, main. However, the previous iteration was not flawless, thus the updated iteration was re-designed with 7 different modules: data structure, data process, visualization, dfs, dijkstra, test, main. While this iteration was improved for clear structure and less coupling and dependency between modules plus test was integrated in some important parts. Moreover, for more detailed iterations, 15 code submits were update in my Github repository:

![images](https://github.com/DAZHAdazha/route-finding/blob/master/images/4.jpg)

## Specific application features associated with each iteration:

The specific application features for each iteration list as below:

The raw version of iteration: had basic function for each module to call separately, could only finish several basic functionality, mainly used in testing and developing stage.

The demo version of iteration: had 5 different modules, demonstrated basic functionality like given out two id, then programme output the path text file that could display in software gnuplot, with also implemented some of the tests.

The final version of iteration: had 7 different modules, with the full functionality and GUI that allow user to interact with the programme to carry on tests and normal usage. The previous algorithm module was divided into two new modules dfs and dijkstra since two different algorithms were implemented(dfs for search the route, dijkstra for find out the shortest route). Besides, the input module was also separated into two new modules named data process and test, while the former handling the input data and initializing them into standard data structure form, the later provide several tests to print out the result in the programme. The final version provide better customer experience and more detailed tests.

Moreover, the 15 commits for iterations on my Github repository were supplemented with detailed specific application features in each submit, the address was listed as follow: [<span class="underline">https://github.com/DAZHAdazha/route-finding</span>](https://github.com/DAZHAdazha/route-finding)

# Personal reflection:

## What went well with this project? Include specific areas of the work, programming, design or testing.

For this project, some of the testing part and designing stage went well.

For instance, when beginning this task, 7 modules were designed as follow: data process, visualization, dfs, dijkstra, test, main, data structure. Then, each module could be implemented

separately with corresponding methods, which could reduce the coupling between modules plus coding more easily. Take data structure as example, by planning the appropriate data structure at first like list, queue, node, link and so on, it was efficient and convenient to put the data structure into usage in other modules when storing and processing the data.

The draft planning was taken as photo listed below:

![images](https://github.com/DAZHAdazha/route-finding/blob/master/images/5.jpg)

In the testing parts, several tests were designed and taken places in order to test the validity of the programme. For example, a counter was integrated before and after process the input data, the comparison of the two values will tell that whether data missing exists. Additionally, "show" methods were implemented in the test.c file for all data structures such as showNode(), showLink(), showQueue() and so on. They could be helpful when checking and testing results by providing direct results.

In a nut shell, it is clear to know that decent planning will bring out much convenience and efficiency while good testing methods could also help validate the results and also improving the programme.

## What was the hardest part of this work? Why, and what will you do to address this for the future?

For this project, some of the programming part was hard.

For instance, in the module dijkstra, my implementation of prior queue was mistakenly wrong, thus problems kept existing to my programme while I could not figure it out. Finally, when I go through the programme cautiously again with tests for the data structure then I found where the bug was.

Another problem that I had encountered with was module visualization. The difficulties did not exist in coding part but the output using the software gnuplot. Due to the lack of familiarity of gnuplot, I could not generate a graph properly. However, after I went searching for a lot of

information online, I managed to display the map using relative coordinates that translating from absolute longitude and latitude, and also the formation of many different edges should be two blank lines between each could work for a clear graph.

Generally, I had learned that module tests for each section should be done carefully before communicate to other parts and it was necessary to search useful information online in advance to get acquainted with the software I do not know.

## What have you learned from this process that you can apply to future programming work in C and other languages?

For this project, as I had mentioned before, the planning stages are utmost important due to it determine the time costs and efficiency that will last for the whole project, it was wise to consider the bigger picture before actions. Besides, individual modules should have separate tests for their own to avoid debugging for all code even if it only had mistakes for single module while this step should be done for each module was finished instead of the whole project. However, when comparing language C to other high-level languages like JAVA and Python, though C has high efficiency as its advantages, the lack of error/exception system and garbage collection make programmer should be more careful when designing and implementing corresponding modules. While the ideology in the project was the same, the coding part was never the only step in project constructing, a system and step flow should be build in order to execute better performance and efficiency.

# Reference

Algorithm Dijkstra: [<span class="underline">https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm</span>](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) Algorithms Fourth Edition,Robert Sedgewick and Kevin Wayne: [<span class="underline">https://algs4.cs.princeton.edu/44sp/</span>](https://algs4.cs.princeton.edu/44sp/)

