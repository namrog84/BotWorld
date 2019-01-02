#include "AIRegionBase.h"



AIRegionBase::AIRegionBase()
{
}


AIRegionBase::~AIRegionBase()
{
}

bool AICircleRegionBase::Init(const AICreationData & cd)
{
	return false;
}

bool AICircleRegionBase::IsInRegion(const AIVector & pos) const
{
	return false;
}

bool AICircleRegionBase::GetRandomPos(AIVector & outVal) const
{
	return false;
}
