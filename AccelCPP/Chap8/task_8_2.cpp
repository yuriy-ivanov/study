// task_8_2.cpp : Defines the entry point for the console application.
//
// Implement next STL algos:
// equal(b, e, d)
// find(b, e, t)
// copy(b, e, d)
// remove_copy_if(b, e, d, p)
// transform(b, e, d, f)
// accumulate(b, e, t)
// search(b, e, b2, e2) - not ready
// find_if(b, e, p)
// remove_copy(b, e, d, t)
// remove(b, e, t)
// partition(b, e, p) - not ready

#include "stdafx.h"

template <class T> bool equal(T b, T e, T d)
{
	while (b != e)
	{
		if (*b++ != *d++) return false;
	}
	return true;
}

template <class It, class Val> It find(It b, It e, const Val& val)
{
	while (b != e)
	{
		if (*b == val) return b;
		++b;
	}
	return b;
}

template <class It> void copy(It b, It e, It d)
{
	for( ; b != e; b++) *d++ = *b;
}

template <class It, class Pred> void remove_copy_if(It b, It e, It d, Pred f)
{
	for( ; b != e; b++) if (!f(*b)) *d++ = *b;
}

template <class It, class Pred> void transform(It b, It e, It d, Pred f)
{
	for( ; b != e; b++) *d++ = f(*b);
}

template <class It, class Val> Val accumulate(It b, It e, const Val& val)
{
	Val ret(val);
	for( ; b != e; b++) ret += *b;
	return ret;
}

template <class It, class Pred> It find_if(It b, It e, Pred f)
{
	for( ; b != e; b++) if (f(*b)) return b;
}

template <class It, class Val> void remove_copy(It b, It e, It d, const Val& val)
{
	for( ; b != e; b++) if (*b != val) *d++ = *b;
}

template <class It, class Val> It remove(It b, It e, const Val& val)
{
	It ret(b);
	for( ; b != e; b++) if (*b == val) *ret++ = *b;
	return ret;
}

template <class It, class Pred> It partition(It b, It e, Pred f)
{
	//not ready
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

