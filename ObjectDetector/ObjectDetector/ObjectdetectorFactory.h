#include "ObjectDetector.h"

namespace od
{
	class ObjectDetectorFactory
	{
	public:
		static ObjectDetector* getObjectDetector(int minContourPoints, int contoursNumber);
	};
}