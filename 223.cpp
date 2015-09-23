/*
223. Rectangle Area

Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overLeft = max(A, E);
        int overBottom = max(B, F);
        int overRight = min(C, G);
        int overTop = min(D, H);
        
        int overArea = 0;
        if(overLeft>=overRight || overBottom>=overTop){
            overArea = 0;
        }else{
            overArea = (overRight-overLeft) * (overTop - overBottom);
        }
        return (C-A)*(D-B) + (G-E)*(H-F) - overArea;
    }
};
