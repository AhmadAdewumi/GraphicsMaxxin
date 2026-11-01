
#include "color.h"
#include <chrono>
#include <iostream>
#include <ostream>
#include <thread>

int main() {
  // image
  int image_width = 256;
  int image_height = 256;

  // render
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  /*
   * j -> vertical axis
   * i -> horizontal axis
   */
  for (int j = 0; j < image_height; ++j) {
    std::clog << "\rScanlines Remaining: " << (image_height - j) << ' '
              << std::flush;

    std::this_thread::sleep_for(std::chrono::milliseconds(5));

    for (int i = 0; i < image_width; ++i) {
      auto pixel_color = color(double(i) / (image_width - 1),
                               double(j) / (image_height - 1), 0);

      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.                 \n";
}
