#只要是调用了动态链接库中的.h文件的，无论这个调用有多深，都需要将.h文件加到这个模块中
AM_CPPFLAGS= -fPIC\
-I/home/NewHadoop/hadoop/hadoop-1.0.3/src/c++/libhdfs\
-I/home/NewHadoop/java/jdk1.7.0_45/include\
-I/home/NewHadoop/java/jdk1.7.0_45/include/linux

AM_LDFLAGS=-lc -lm -lrt

noinst_LIBRARIES=libtree.a
libtree_a_SOURCES = AVLtree.cpp Heap.cpp Btree.cpp BStree.cpp\
					AVLtree.h Heap.h Btree.h BStree.h  

#libcommon_a_LDFLAGS= -ldl -lm -lpthread
#include_HEADERS=AVLtree.h Heap.h Btree.h BStree.h 
#EXTRA_DIST = AVLtree.h Heap.h Btree.h BStree.h