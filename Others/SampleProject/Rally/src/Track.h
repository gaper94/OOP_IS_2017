#ifndef TRACK_H
#define TRACK_H

#include "common/RallyDefinitions.h"
#include "common/Vector.h"

namespace rally
{

class Track
{
public:
private:
	containers::Vector<CornerType> m_corners;
	containers::Vector<StraightType> m_straights;
	SurfaceType m_eSurfaceType;
};

}
#endif // TRACK_H