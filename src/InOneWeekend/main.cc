
#include <iostream>
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
    for (int i = 0; i < image_width; ++i) {
      auto red = double(i) / (image_width - 1);
      auto green = double(j) / (image_height - 1);
      auto blue = 0.0;

      // convert to range of 0 to 255 from the floating representation from
      // before
      int ir = int(255.999 * red);
      int ig = int(255.999 * green);
      int ib = int(255.999 * blue);

      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
}
