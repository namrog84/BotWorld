#pragma once

#include "AICreationData.h"
#include "AIEntityInfo.h"
#include "AIVector.h"

// Can be any location
// typically could be something like a Fixed Position on the map
// Named Entity, or controlled entity or object.

class AITargetBase {
public:
    AITargetBase();
    ~AITargetBase();

    // Load the configuration.
    virtual bool Init(const AICreationData& cd) = 0;
    // Get the target's position. If the target has an
    // entity, it should generally be that entity's
    // position.

	// Whats the difference from AIVectorBase and AIVector?
	// It appears like they are the same...

    virtual const AIVector* GetPosition() const = 0;
    // Not all types of targets have entities. If this one
    // does, get it. NOTE: It's possible for HasEntity() to
    // return true (i.e. this type of target has an entity)
    // but GetEntity() to return NULL (i.e. the entity that
    // this target represents doesn't currently exist). In
    // that case, HasEntity() should return true, but
    // IsValid() should return false.
    virtual AIEntityInfo* GetEntity() const
    {
        return nullptr;
    }

    virtual bool HasEntity() const
    {
        return false;
    }

    // Checks whether the target is valid. For instance, a
    // target that tracks a particular contact by name might
    // become invalid if we don't have contact with that
    // name. Most target types are always valid.
    virtual bool IsValid() const
    {
        return true;
    }
};
