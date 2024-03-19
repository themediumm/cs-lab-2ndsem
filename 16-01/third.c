#include <stdio.h>
#include <math.h>


struct Point {
    int x;
    int y;
};


double distanceFromOrigin(struct Point p) {
    return sqrt((double)(p.x * p.x + p.y * p.y));
}

int main() {

    struct Point points[10];


    printf("Enter the coordinates for ten points:\n");
    for (int i = 0; i < 10; ++i) {
        printf("Point %d (x y): ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }


    double minDistance = distanceFromOrigin(points[0]);
    int closestPointIndex = 0;

    for (int i = 1; i < 10; ++i) {
        double distance = distanceFromOrigin(points[i]);
        if (distance < minDistance) {
            minDistance = distance;
            closestPointIndex = i;
        }
    }

    printf("\nThe point closest to the origin is Point %d with coordinates (%d, %d)\n",
           closestPointIndex + 1, points[closestPointIndex].x, points[closestPointIndex].y);

    return 0;
}
