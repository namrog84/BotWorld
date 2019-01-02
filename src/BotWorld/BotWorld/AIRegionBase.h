#pragma once

#include "AICreationData.h"
#include "AIVector.h"

// Represents a region of space with an inside an an outside

// May be a circle, rectangle, polygon or other forms of regions
// So long as some location may be considered inside or outside.



class AIRegionBase {
public:
    AIRegionBase();
    ~AIRegionBase();


    // Load the configuration.
    virtual bool Init(const AICreationData& cd) = 0;
    // Test if a specified position is within the region
    virtual bool IsInRegion(const AIVector& pos) const = 0;

	
    // Set the outVal parameter to a random position within the region
    // NOTE: IT MAY BE POSSIBLE FOR THIS TO FAIL on some types of regions. It returns success.
	// Perhaps returns false if there is no room or the region is empty?
    virtual bool GetRandomPos(AIVector& outVal) const = 0;

};

class AICircleRegionBase : public AIRegionBase
{
	AICircleRegionBase(const AICreationData & cd) {}
	// Inherited via AIRegionBase
	virtual bool Init(const AICreationData & cd) override;
	virtual bool IsInRegion(const AIVector & pos) const override;
	virtual bool GetRandomPos(AIVector & outVal) const override;
};