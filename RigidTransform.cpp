#include "RigidTransform.h"

/*** Transform points ****/
Image transfomPoints(string filename, transformation T, int obj)
{
    transformation Ttmp;
    int marge = 20;
    Image imageIn = PGMReader<Image>::importPGM(filename);
    Domain domain = imageIn.domain();
    int widthImg = domain.upperBound()[0];
    int heightImg = domain.upperBound()[1];
    //Transform vector of points
    Ttmp[0]=T[0];
    Ttmp[1]=T[1];
    Ttmp[2]=-T[2];
    vector<Point> tvecPts;
    for (int i = 0; i < widthImg; ++i)
        for (int j = 0; j < heightImg; ++j) {
            Point p(i-widthImg/2, j-heightImg/2);
            RealPoint rp=backwardTransformPoint(p,Ttmp);
            Point tp(round(rp[0])+widthImg/2,round(rp[1])+heightImg/2);
            if(!(tp[0]<0 || tp[0]>=widthImg || tp[1]<0 || tp[1]>=heightImg) && imageIn(tp)==obj)
                tvecPts.push_back(Point(i,j));
        }
    //Convert vector to img
    Point pMin,pMax;
    findBoundingBox(tvecPts,pMin,pMax);
    Domain tdomain(pMin-Point(marge,marge),pMax+Point(marge,marge));
    Image imageOut(tdomain);
    for(vector<Point>::iterator it=tvecPts.begin();it!=tvecPts.end();it++)
        imageOut.setValue(*it,OBJ);
    return imageOut;
}
/*** Transform points ****/

/*** Transform polygone ***/
vector<Point> digitizePolygon(const vector<Point>& polyLine)
{
    vector<Point> ptsShape;
    Point pMin,pMax;
    findBoundingBox(polyLine,pMin,pMax);
    for(int x=pMin[0]; x<=pMax[0]; x++)
        for(int y=pMin[1]; y<=pMax[1]; y++) {
            Point p=Point(x,y);
            if(isInPolygon(polyLine,p))
                ptsShape.push_back(p);
        }
    for(size_t it=0; it<polyLine.size()-1; it++) {
        vector<Point> pts=pointAlongEdge(polyLine.at(it),polyLine.at(it+1));
        //cout<<"polyline it="<<it<<" and pts.size="<<pts.size()<<endl;
        if(pts.size()!=0)
            for(size_t it_pts=0; it_pts<pts.size(); it_pts++)
                if(!isExist(ptsShape,pts.at(it_pts)))
                    ptsShape.push_back(pts.at(it_pts));
    }
    //Last segment
    vector<Point> pts=pointAlongEdge(polyLine.back(),polyLine.front());
    //cout<<"polyline it="<<6<<" and pts.size="<<pts.size()<<endl;
    if(pts.size()!=0)
        for(size_t it_pts=0; it_pts<pts.size(); it_pts++)
            if(!isExist(ptsShape,pts.at(it_pts)))
                ptsShape.push_back(pts.at(it_pts));
    return ptsShape;
}

vector<vector<Point> > digitizePolygon(const vector<vector<Point> >& polyLine)
{
    vector<vector<Point> > ptsShape;
    for(size_t it_contour=0; it_contour<polyLine.size(); it_contour++) {
        vector<Point> pts=digitizePolygon(polyLine.at(it_contour));
        ptsShape.push_back(pts);
    }
    return ptsShape;
}

vector<Point> digitizePolygon(const vector<RealPoint>& polyLine)
{
    vector<Point> ptsShape;
    Point pMin,pMax;
    findBoundingBox(polyLine,pMin,pMax);
    for(int x=pMin[0]; x<=pMax[0]; x++)
        for(int y=pMin[1]; y<=pMax[1]; y++) {
            Point p=Point(x,y);
            if(isInPolygon(polyLine,p))
                ptsShape.push_back(p);
        }
    for(size_t it=0; it<polyLine.size()-1; it++) {
        vector<Point> pts=pointAlongEdge(polyLine.at(it),polyLine.at(it+1));
        if(pts.size()!=0)
            for(size_t it_pts=0; it_pts<pts.size(); it_pts++)
                if(!isExist(ptsShape,pts.at(it_pts)))
                    ptsShape.push_back(pts.at(it_pts));
    }
    //Last segment
    vector<Point> pts=pointAlongEdge(polyLine.back(),polyLine.front());
    if(pts.size()!=0)
        for(size_t it_pts=0; it_pts<pts.size(); it_pts++)
            if(!isExist(ptsShape,pts.at(it_pts)))
                ptsShape.push_back(pts.at(it_pts));
    return ptsShape;
}

vector<vector<Point> > digitizePolygon(const vector<vector<RealPoint> >& polyLine)
{
    vector<vector<Point> > ptsShape;
    for(size_t it_contour=0; it_contour<polyLine.size(); it_contour++) {
        vector<Point> pts=digitizePolygon(polyLine.at(it_contour));
        ptsShape.push_back(pts);
    }
    return ptsShape;
}

vector<vector<Point> > transformPolygon(const vector<vector<Point> >& polyLine, vector<vector<RealPoint> >& tPolyLine, transformation t) {
    //Transform polyline
    for(size_t it_contour=0; it_contour<polyLine.size(); it_contour++) {
        vector<RealPoint> l;
        RealPoint p1=findCentroid(polyLine.at(it_contour));
        for(vector<Point>::const_iterator it=polyLine.at(it_contour).begin(); it != polyLine.at(it_contour).end(); it++) {
            RealPoint p2((*it)[0]-p1[0],(*it)[1]-p1[1]);
            RealPoint p3=backwardTransformPoint(p2,t);
            RealPoint p4(p3[0]+p1[0],p3[1]+p1[1]);
            l.push_back(p4);
        }
        tPolyLine.push_back(l);
    }
    //Digitize transformed polyline
    vector<vector<Point> > tPtsShape=digitizePolygon(tPolyLine);
    return tPtsShape;
}
/*** Transform polygone ***/
