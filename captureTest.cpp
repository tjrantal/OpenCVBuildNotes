/*Modified from the sample at 
	http://docs.opencv.org/modules/highgui/doc/reading_and_writing_images_and_video.html#videocapture
*/

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/videoio/videoio_c.h>
#include <stdio.h>

using namespace cv;

int main(int arc, char** arg)
{
	if (arc < 2){
		std::cout << "Use: captureTest videoFile.avi";
		return 0;
	}
	std::cout << arg[1];
    VideoCapture cap(arg[1]); // open a file
    if(!cap.isOpened())  // check if we succeeded
        return -1;
	
	int frames = (int) cap.get(CV_CAP_PROP_FRAME_COUNT);
    Mat edges;
    namedWindow("edges",1);
    for(int i = 0;i<frames;++i){
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
	cap.~VideoCapture();
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}