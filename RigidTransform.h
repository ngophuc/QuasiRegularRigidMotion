#ifndef RIGIDTRANSFORM_H
#define RIGIDTRANSFORM_H

#include "Utility.h"

/*** Transform points ***/
Image transfomPoints(string filename, transformation T);
/*** Transform polygone ***/
vector<vector<Point> > transformPolygon(const vector<vector<Point> >& polyLine, vector<vector<RealPoint> >& tPolyLine, transformation t);

#endif // RIGIDTRANSFORM_H
