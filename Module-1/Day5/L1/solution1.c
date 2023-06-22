#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of a box
double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

// Function to calculate the total surface area of a box
double calculateSurfaceArea(struct Box* box) {
    double side1 = box->length * box->width;
    double side2 = box->length * box->height;
    double side3 = box->width * box->height;
    return 2 * (side1 + side2 + side3);
}

int main() {
    struct Box box;
    box.length = 4.5;
    box.width = 2.8;
    box.height = 3.2;

    // Accessing members using (*) asterisk or indirection operator and (.) dot operator
    struct Box* boxPtr = &box;
    double volume1 = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    double surfaceArea1 = 2 * ((*boxPtr).length * (*boxPtr).width + (*boxPtr).length * (*boxPtr).height + (*boxPtr).width * (*boxPtr).height);

    // Accessing members using (->) arrow operator
    double volume2 = boxPtr->length * boxPtr->width * boxPtr->height;
    double surfaceArea2 = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);

    printf("Volume (Using (*) operator): %.2f\n", volume1);
    printf("Surface Area (Using (*) operator): %.2f\n", surfaceArea1);
    printf("Volume (Using (->) operator): %.2f\n", volume2);
    printf("Surface Area (Using (->) operator): %.2f\n", surfaceArea2);

    return 0;
}
