#pragma once

#include "AICreationData.h"


template <class T>
class AIFactoryBase {
public:
    AIFactoryBase();
    ~AIFactoryBase();

    T* Create(AICreationData& creationData);

	// Add a custom constructor. Takes ownership of the constructor. 
	void AddConstructor(AIConstructorBase<T>* pConstructor); };


};
