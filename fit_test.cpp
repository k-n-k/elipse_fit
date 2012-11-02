#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
#include <highgui.h>

int
main(int argc, char **argv)
{
	cv::Mat src_img;
  //if ((argc < 2) || (src_img = cv::LoadImage (argv[1], CV_LOAD_IMAGE_COLOR)) == 0)
    //return -1;
  //cv::Mat src_img = cv::imread("../../image/stuff.jpg", 1);
  //if(src_img.empty()) return -1; 
  
  src_img = cvLoadImage (argv[1], CV_LOAD_IMAGE_GRAYSCALE);

  cv::Mat gray_img, bin_img;
 // cv::cvtColor(src_img, gray_img, CV_BGR2GRAY);

  gray_img = cvLoadImage (argv[1], CV_LOAD_IMAGE_GRAYSCALE);
  std::vector<std::vector<cv::Point> > contours;
  // 画像の二値化
  cv::threshold(gray_img, bin_img, 0, 255, cv::THRESH_BINARY|cv::THRESH_OTSU);
  
  // 輪郭の検出
 /* cv::findContours(bin_img, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
  
  for(int i = 0; i < contours.size(); ++i) {
    size_t count = contours[i].size();
    if(count < 150 || count > 1000) continue; // （小さすぎる|大きすぎる）輪郭を除外

    cv::Mat pointsf;
    cv::Mat(contours[i]).convertTo(pointsf, CV_32F);
    // 楕円フィッティング
    cv::RotatedRect box = cv::fitEllipse(pointsf);
    // 楕円の描画
    cv::ellipse(src_img, box, cv::Scalar(0,0,255), 2, CV_AA);
  }
*/
  cv::Mat canny_img;
  cv::Canny(gray_img, canny_img, 0, 200);
  cv::namedWindow("canny", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::namedWindow("src", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::imshow("canny", canny_img);
  cv::imshow("src", src_img);
  cv::waitKey(0);
}
