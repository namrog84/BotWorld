#pragma once

#include "AICreationData.h"
#include "AIString.h"
#include "AIWeightValues.h"


// Convert from some input to some weight value
// Boolean 

// Most weight Functions are likely mapped closely to considerations so...
// DoIFeelConfident(IsInvincible) return 0.7,  else return 0.1.

// Simple Curves
// Float Sequence
// NamedList. 

// For the string, perhaps the consideration feeds in a name of the entity
// e.g. "FlyingShip" returns 1, a "Tank" returns 0.7, a "Sheep" returns 0.1.


class AIWeightFunctionBase {
public:
    AIWeightFunctionBase();
    ~AIWeightFunctionBase();

public:
    // Load the configuration.
    virtual bool Init(const AICreationData& cd) = 0;


	// Weight functions can deliver a result based on the
    // input of a bool, int, float, or string. By default
    // int does whatever float does, while the others all
    // throw an assert if not defined in the subclass.
    virtual const AIWeightValues& CalcBool(bool b);
    virtual const AIWeightValues& CalcInt(int i);
    virtual const AIWeightValues& CalcFloat(float f);
    virtual const AIWeightValues& CalcString(AIString s);


    // Some functions need to know when the associated
    // option is selected/deselected (for example, to pick new
    // random values).
    virtual void Select() {}
    virtual void Deselect() {}
};
