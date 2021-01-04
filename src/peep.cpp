#include <opencv2/opencv.hpp>

#include <string>

int main(int argc, char** argv) {	
	std::string to_fn = argv[1];
	
	cv::namedWindow("Viewport", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap{0};
	if(!cap.isOpened()) return -1;

	int frame_w = (int) cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int frame_h = (int) cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	
	cv::Size size{frame_w, frame_h};
	double fps = cap.get(cv::CAP_PROP_FPS);

	cv::VideoWriter writer;
	writer.open(to_fn, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

	cv::Mat frame;
	for(;;) {
		cap >> frame;
		if(frame.empty()) break;

		cv::Mat down_i;
		cv::pyrDown(frame, down_i);
		cv::imshow("Viewport", down_i);

		writer << down_i;

		if (cv::waitKey(3) == 27) break;
	}
	cap.release();
}
