#pragma once

#include "AICreationData.h"
#include "AIRegionBase.h"

//template <class T>
//class AIFactoryBase {
//public:
//    AIFactoryBase();
//    ~AIFactoryBase();
//
//    T* Create(AICreationData& creationData);
//
//    // Add a custom constructor. Takes ownership of the constructor.
//    void AddConstructor(AIConstructorBase<T>* pConstructor);
//};

template <class T>
class AIConstructorBase {
public:
    virtual ~AIConstructorBase() {}
    // Attempts to create an object from the creation data.
    // Pure virtual so that child classes will be forced
    // to implement it.
    virtual T* Create(const AICreationData& cd) = 0;
};

template <class T>
class AIFactoryBase {
public:
    virtual ~AIFactoryBase();
    // Add a custom constructor. Takes ownership.
    void AddConstructor(AIConstructorBase<T>* pCnstr)
    {
        m_Constructors.push_back(pCnstr);
    }
    // Looks through all the constructors for one that
    // can create a region. Any constructor which doesn't
    // know how to handle an object of the creation data's
    // type should simply return NULL.
    T* Create(AICreationData& cd);

private:
    std::vector<AIConstructorBase<T>*> m_Constructors;
};

template <class T>
T* AIFactoryBase<T>::Create(AICreationData& cd)
{
    T* pRetVal = NULL;
    // NOTE: Pay attention to the stop condition - we break
    // out as soon as we find a constructor that can handle
    // this creation data. We want to try them in the
    // reverse order from which they were added, so loop
    // backwards.
    for (int i = (int)m_Constructors.size() - 1; !pRetVal && (i >= 0); --i) {
        pRetVal = m_Constructors[i]->Create(cd);
    }
    //if (!pRetVal)
    //  AI_ERROR_CONFIG("Factory failed to create an object of type '%s'.", cd.GetNode().GetType());
    return pRetVal;
}

template <class T>
T* AIFactoryBase<T>::Create(AICreationData& cd)
{
    T* pRetVal = NULL;
    // Check if this is a global, and if so use the
    // specification node stored on the global manager.
    const AISpecificationNode& node = cd.GetNode();
    const AIString& nodeType = node.GetType();
    if (nodeType == "Global") {
        AIString globalName = node.GetAttributeString("Name");
        const AISpecificationNode* pActualNode = AIGlobalManager::Get().Find(globalName);
        if (!pActualNode) {
            AI_ERROR("Factory does not have a definition "
                     "for a global object named '%s'.",
                globalName.c_str());
        } 
		else 
		{
            // Set the node on the creation data to the
            // actual node for this global, create the
            // object, then set the node on the creation
            // data back to its previous value.
            cd.SetNode(*pActualNode);
            pRetVal = Create(cd);
            cd.SetNode(node);
            return pRetVal;
        }
    }
    // The rest is the same as Listing 4.
}


#define DECLARE_GAIA_FACTORY(_TypeName)                                                        \
    class AI##_TypeName##Base;                                                                 \
                                                                                               \
    class AI##_TypeName##Constructor_Default : public AIConstructorBase<AI##_TypeName##Base> { \
    public:                                                                                    \
        virtual AI##_TypeName##Base* Create(const AICreationData& creationData);               \
    };                                                                                         \
                                                                                               \
    class AI##_TypeName##Factory : public AIFactoryBase<AI##_TypeName##Base> {                 \
    public:                                                                                    \
        AI##_TypeName##Factory()                                                               \
        {                                                                                      \
            AddConstructor(new AI##_TypeName##Constructor_Default);                            \
        }                                                                                      \
    };
//#undef DECLARE_GAIA_FACTORY
//
//AIRegionBase* AIRegionConstructor_Default::Create(const AICreationData& creationData)
//{
//    return nullptr;
//}

template <class T>
class AISingletonBase {
public
    AISingletonBase<T>();
};

#define GAIA_EXECUTE_FACTORY_MACRO(_FACTORY_MACRO) \
    _FACTORY_MACRO(Action)                         \
    _FACTORY_MACRO(Region)                         \
    _FACTORY_MACRO(Target)

GAIA_EXECUTE_FACTORY_MACRO(DECLARE_GAIA_FACTORY);

//class SquareRegion : public AIRegionBase
//{
//};
class AIRegion_Poly : public AIRegionBase {

    // Inherited via AIRegionBase
    virtual bool Init(const AICreationData& cd) override;
    virtual bool IsInRegion(const AIVector& pos) const override;
    virtual bool GetRandomPos(AIVector& outVal) const override;
};

bool AIRegion_Poly::Init(const AICreationData& cd)
{
    return false;
}

bool AIRegion_Poly::IsInRegion(const AIVector& pos) const
{
    return false;
}

bool AIRegion_Poly::GetRandomPos(AIVector& outVal) const
{
    return false;
}

/*template <class T>
class AIRegionBaseConstructor: public AIConstructorBase<T> {
	T * Create(const AICreationData & cd) override;
};*/

template <class T>
T* AIRegionConstructor_Default::Create(const AICreationData& cd)
{
    // figure it out from cd?
    return new AIRegion_Poly();
}

class AiRegionFactory : public AIFactoryBase<AIRegionBase> 
{
	AiRegionFactory()
    {
        AddConstructor(new AIRegionConstructor_Default());
    }

    //AIActionFactory derp();
    //AIFactoryBase<AIRegionBase> derp;
    //AIRegion_PolyConstructor AIPoly;
    //        derp.
    //  }
};