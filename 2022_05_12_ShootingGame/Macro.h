#pragma once

/*
* ΩÃ±€≈Ê ∏≈≈©∑Œ
*	Create()
*	Delete()
*	Get()
*/
#define SNG_CREATE(classType)	\
private:\
	static	classType* instance;\
public:\
static	void		Create()\
{\
	if (instance == nullptr)\
	{\
		instance = new classType();\
	}\
}\
static	void		Delete()\
{\
	if (instance != nullptr)\
	{\
		delete instance;\
	}\
}\
static	classType*	Get()\
{\
	if (instance == nullptr)\
		Create();\
	return instance;\
}