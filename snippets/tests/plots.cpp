//[headers Headers
#include <matplot/matplot.h>
//]

int main() {
    //[line_plot Line plot
    matplot::plot(std::vector{1, 2, 3, 4, 5, 6});
    matplot::show();
    //]
    return 0;
}