#ifndef NEPOLISTS
#define NEPOLISTS

#include <list>

/**
 * The following functions are copied from NEPODefs.h in the RobotArdu plugin. It would be
 * nice if we can include them instead of copying them.
 */


template<typename T>
std::list<T> &_createListRepeat(unsigned count, T e);

template<typename T>
T _getListElementByIndex(std::list<T> &list, unsigned index);

template<typename T>
T _getAndRemoveListElementByIndex(std::list<T> &list, unsigned index);

template<typename T>
void _removeListElementByIndex(std::list<T> &list, unsigned index);

/*
 * The only known situation where the cast of P to T would be needed is for int to double
 * in other cases T and P will be the same type. If only one template parameter is used
 * then the match void setListElementByIndex(std::list<double>, int, int) would not be possible
 */

template<typename T, typename P>
void _setListElementByIndex(std::list<T> &list, unsigned index, P value);

template<typename T, typename P>
void _insertListElementBeforeIndex(std::list<T> &list, unsigned index, P value);

template<typename T, typename P>
int _getFirstOccuranceOfElement(std::list<T> &list, P value);

template<typename T, typename P>
int _getLastOccuranceOfElement(std::list<T> &list, P value);

template<typename T>
std::list<T> &_getSubList(std::list<T> &list, int startIndex, int endIndex);

double _getListSum(std::list<double> &list);

double _getListMin(std::list<double> &list);

double _getListMax(std::list<double> &list);

double _getListMedian(std::list<double> &list);

double _getListAverage(std::list<double> &list);

double _getListStandardDeviation(std::list<double> &list);

template<typename T>
int ArrayLen(std::list<T> &list);

#endif
