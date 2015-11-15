#include "ObjectDetector.h"

namespace od
{
	class MultiContourObjectDetector : public ObjectDetector{

	public:

		OBJECTDETECTOR_API MultiContourObjectDetector();

	private:

		OBJECTDETECTOR_API bool findBaseShape(cv::Mat& baseImage);

		OBJECTDETECTOR_API std::vector<std::vector<std::vector<cv::Point>>> findApproxContours(
			cv::Mat image,
			bool performOpening
			, bool findBaseShape);

		OBJECTDETECTOR_API std::vector<std::vector<std::vector<cv::Point>>> processContours(
			std::vector<std::vector<std::vector<cv::Point>>> approxContours,
			double hammingThreshold,
			double correlationThreshold,
			int* numberOfObject);


		std::vector<std::vector<cv::Point>> _baseShape;
		std::vector<std::vector<cv::Point>> _baseKeypoints;
	};
}