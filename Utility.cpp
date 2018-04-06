#include "Utility.h"

/********** Find element **********/
bool isExist(const vector<int>& vec, int v){
    vector<int>::const_iterator it=find(vec.begin(),vec.end(),v);
    if(it != vec.end())
        return true;
    else
        return false;
}

bool isExist(const vector<Point>& vec, Point p)
{
    vector<Point>::const_iterator it=find(vec.begin(),vec.end(),p);
    if(it != vec.end())
        return true;
    else
        return false;
}

bool isExist(const vector<RealPoint>& vec, Point p)
{
    vector<RealPoint>::const_iterator it=find(vec.begin(),vec.end(),p);
    if(it != vec.end())
        return true;
    else
        return false;
}

int findElement(const vector<Point>& vec, Point p)
{
    int index=-1;
    vector<Point>::const_iterator idP=find(vec.begin(),vec.end(),p);
    if(idP != vec.end())
        index=(idP-vec.begin());
    return index;
}

int findElement(const vector<RealPoint>& vec, Point p)
{
    int index=-1;
    vector<RealPoint>::const_iterator idP=find(vec.begin(),vec.end(),p);
    if(idP != vec.end())
        index=(idP-vec.begin());
    return index;
}
/********** Find element **********/

/********** Distance function **********/
double distancePoints (Point p1, Point p2)
{
    return sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]));
}

double distanceLine(Point p, double a, double b, double c) //Segment : a x + by + c = 0
{
    if(a==0 && b==0)
        return 0;
    return fabs(a*p[0] + b*p[1] + c)/sqrt(a*a+b*b);
}

double distanceLine(Point p, Point s1, Point s2)
{
    double a, b, c;
    //line : ax + by + c = 0
    //(y1 – y2)x + (x2 – x1)y + (x1y2 – x2y1) = 0
    a = s1[1] - s2[1];
    b = s2[0] - s1[0];
    c = s1[0]*s2[1] - s2[0]*s1[1];
    return distanceLine(p, a, b, c);
}

double signedDistanceLine(Point p, double a, double b, double c) //Segment : a x + by + c = 0
{
    if(a==0 && b==0)
        return 0;
    return (a*p[0] + b*p[1] + c)/sqrt(a*a+b*b);
}

double signedDistanceLine(Point p, Point s1, Point s2)
{
    double a, b, c;
    //line : ax + by + c = 0
    //(y1 – y2)x + (x2 – x1)y + (x1y2 – x2y1) = 0
    a = s1[1] - s2[1];
    b = s2[0] - s1[0];
    c = s1[0]*s2[1] - s2[0]*s1[1];
    return signedDistanceLine(p, a, b, c);
}
/********** Distance function **********/

/********* Angle function *********/
//cos(THETA) = a*b / (||a|| ||b||)
//This gives us just the relative angle between a and b, in [0,PI].
double relativeAngle(Point v1, Point v2)
{
    //normalize the vector
    PointVector<2,double> n_v1, n_v2;
    n_v1[0] = v1[0]/(sqrt(v1[0]*v1[0] + v1[1]*v1[1]));
    n_v1[1] = v1[1]/(sqrt(v1[0]*v1[0] + v1[1]*v1[1]));

    n_v2[0] = v2[0]/(sqrt(v2[0]*v2[0] + v2[1]*v2[1]));
    n_v2[1] = v2[1]/(sqrt(v2[0]*v2[0] + v2[1]*v2[1]));

    //float dotProduct = ax*bx + ay*by;
    //float theta = acos( dotProduct / (vec1Len*vec2Len) );
    return acos(n_v1[0]*n_v2[0]+n_v1[1]*n_v2[1]);
}

// angle between three points (p1,p2,p3) = (b,c,a)
//c*c = a*a + b*b - 2abcos(alpha)
double relativeAngle(Point p1, Point p2, Point p3)
{
    if(p1 == p2 || p1 == p3 || p2==p3)
        return 0;
    double a, b, c, ac;
    a = distancePoints(p1,p2);
    b = distancePoints(p2,p3);
    c = distancePoints(p1,p3);
    ac = (c*c-a*a-b*b);
    if(fabs(ac)<1e-6)
        return M_PI/2;
    if(fabs(c-a-b)<1e-6)
        return M_PI;
    //ac=(c*c-a*a-b*b)/(-2*a*b);
    return acos(ac/(-2*a*b));
}

/*
//THETA = atan2(by,bx) - atan2(ay,ax)
//This gives us the relative angle between a and b with a sign, in [-PI,PI]
double signedAngle(Point v1, Point v2)
{
    //theta = atan2(by,bx) - atan2(ay,ax);
    double alpha1 = atan2(v1[1],v1[0]);
    double alpha2 = atan2(v2[1],v2[0]);
    if(alpha1<0) alpha1 += 2*M_PI;
    if(alpha2<0) alpha2 += 2*M_PI;
    return alpha2 - alpha1;
}
*/
// angle between two vectors
double signedAngle(Point v1, Point v2)
{
    double Na = sqrt(v1[0]*v1[0] + v1[1]*v1[1]);
    double Nb = sqrt(v2[0]*v2[0] + v2[1]*v2[1]);
    double C = (v1[0]*v2[0] + v1[1]*v2[1])/(Na*Nb);
    double S = (v1[0]*v2[1] - v1[1]*v2[0]);
    if(S<0)
        return(-acos(C));
    else
        return (acos(C));
}

double signedAngle(Point p1, Point p2, Point p3)
{
    Point v1(p1[0]-p2[0],p1[1]-p2[1]);//p2p1
    Point v2(p3[0]-p2[0],p2[1]-p2[1]);//p2p3
    return signedAngle(v1,v2);
}

// acute angle between three points
double acuteAngle(Point p1, Point p2, Point p3)
{
    Point v1 = Point(p1[0]-p2[0],p1[1]-p2[1]);
    Point v2 = Point(p3[0]-p2[0],p3[1]-p2[1]);
    double angle = atan2(v2[0],-v2[1]) - atan2(v1[0],-v1[1]);
    if(angle<0)
        angle += 2*M_PI; //report angle to (0,2pi)
    if(angle>M_PI)
        angle = 2*M_PI - angle;
    return angle;
}

double simpleAngle(Point p1, Point p2, Point p3)
{
    Point v1 = Point(p1[0]-p2[0],p1[1]-p2[1]);
    Point v2 = Point(p3[0]-p2[0],p3[1]-p2[1]);
    double angle = atan2(v2[0],-v2[1]) - atan2(v1[0],-v1[1]);
    if(angle<0)
        angle += 2*M_PI; //report angle to (0,2pi)
    return angle;
}
/********* Angle function *********/

/******** Trasformation *********/
RealPoint forwardTransformPoint(Point p, const transformation t)
{
    double x=p[0]*cos(t[2])-p[1]*sin(t[2])+t[0];
    double y=p[0]*sin(t[2])+p[1]*cos(t[2])+t[1];
    return RealPoint(x,y);
}

RealPoint backwardTransformPoint(Point p, const transformation t)
{
    double x= (p[0]-t[0])*cos(t[2])+(p[1]-t[1])*sin(t[2]);
    double y=-(p[0]-t[0])*sin(t[2])+(p[1]-t[1])*cos(t[2]);
    return RealPoint(x,y);
}

/******** Trasformation *********/

int pgcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

double cross(const Point &p0, const Point &p1, const Point &p2)
{
    return (p1[0] - p0[0]) * (p2[1] - p0[1]) - (p1[1] - p0[1]) * (p2[0] - p0[0]);
}


/* https://wrf.ecse.rpi.edu//Research/Short_Notes/pnpoly.html
http://alienryderflex.com/polygon
*/
bool isInPolygon(int nvert, double *vertx, double *verty, double testx, double testy)
{
    int i, j;
    bool c = false;
    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if ( ((verty[i]>testy) != (verty[j]>testy)) && //or (vertx[i]>=testx || vertx[j]>=testx) &&
             (testx <= ( (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) ) )
            c = !c;
    }
    return c;
}

bool isInPolygon(int nvert, int *vertx, int *verty, int testx, int testy)
{
    int i, j;
    bool c = false;
    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if ((verty[i]>testy) != (verty[j]>testy)) {
            if((verty[j]-verty[i])>0) {
                if(((testx - vertx[i])*(verty[j]-verty[i])) <= ((vertx[j]-vertx[i])*(testy-verty[i])))
                    c = !c;
            }
            else {
                if(((testx - vertx[i])*(verty[j]-verty[i])) >= ((vertx[j]-vertx[i])*(testy-verty[i])))
                    c = !c;
            }
        }
    }
    return c;
}

bool isInPolygon(const vector<Point>& polygon, Point p)
{
    ///double* x=(double*)malloc(polygon.size()*sizeof(double));
    ///double* y=(double*)malloc(polygon.size()*sizeof(double));
    int* x=(int*)malloc(polygon.size()*sizeof(int));
    int* y=(int*)malloc(polygon.size()*sizeof(int));
    for(size_t i=0; i<polygon.size();i++)
    {
        x[i]=polygon.at(i)[0];
        y[i]=polygon.at(i)[1];
    }
    bool res=isInPolygon(polygon.size(),x,y,p[0],p[1]);
    free(x);
    free(y);
    return res;
}

bool isInPolygon(const vector<vector<Point>>& polygon, Point p)
{
    for(size_t it_p=0; it_p<polygon.size();it_p++)
        if(isInPolygon(polygon.at(it_p),p))
            return true;
    return false;
}

bool isInPolygon(const vector<RealPoint>& polygon, Point p)
{
    double* x=(double*)malloc(polygon.size()*sizeof(double));
    double* y=(double*)malloc(polygon.size()*sizeof(double));
    for(size_t i=0; i<polygon.size();i++)
    {
        x[i]=polygon.at(i)[0];
        y[i]=polygon.at(i)[1];
    }
    bool res=isInPolygon(polygon.size(),x,y,p[0],p[1]);
    free(x);
    free(y);
    return res;
}

void findBoundingBox(const vector<Point>& vec, Point& pMin, Point& pMax)
{
    int minX=vec.at(0)[0], minY=vec.at(0)[1];
    int maxX=vec.at(0)[0], maxY=vec.at(0)[1];
    for(vector<Point>::const_iterator it=vec.begin(); it!=vec.end(); it++)
    {
        if((*it)[0]<minX)
            minX=(*it)[0];
        if((*it)[1]<minY)
            minY=(*it)[1];
        if((*it)[0]>maxX)
            maxX=(*it)[0];
        if((*it)[1]>maxY)
            maxY=(*it)[1];
    }
    pMin=Point(minX,minY);
    pMax=Point(maxX,maxY);
}

void findBoundingBox(const vector<vector<Point> >& vec, Point& pMin, Point& pMax)
{
    vector<Point> pts;
    for(size_t it_vec=0; it_vec<vec.size(); it_vec++)
    {
        Point p1,p2;
        findBoundingBox(vec.at(it_vec),p1,p2);
        pts.push_back(p1);
        pts.push_back(p2);
    }
    findBoundingBox(pts,pMin,pMax);
}

void findBoundingBox(const vector<RealPoint>& vec, Point& pMin, Point& pMax)
{
    double minX=vec.at(0)[0], minY=vec.at(0)[1];
    double maxX=vec.at(0)[0], maxY=vec.at(0)[1];
    for(vector<RealPoint>::const_iterator it=vec.begin(); it!=vec.end(); it++)
    {
        if((*it)[0]<minX)
            minX=(*it)[0];
        if((*it)[1]<minY)
            minY=(*it)[1];
        if((*it)[0]>maxX)
            maxX=(*it)[0];
        if((*it)[1]>maxY)
            maxY=(*it)[1];
    }
    pMin=Point(round(minX)-1,round(minY)-1);
    pMax=Point(round(maxX)+1,round(maxY)+1);
}

RealPoint findCentroid(const vector<Point>& vec)
{
    RealPoint p(0.0,0.0);
    for(vector<Point>::const_iterator it=vec.begin(); it!=vec.end(); it++) {
        p[0]+=(*it)[0];
        p[1]+=(*it)[1];
    }
    p[0]=p[0]/(double)vec.size();
    p[1]=p[1]/(double)vec.size();
    return p;
}

Z3i::Point getLineFromPoint(Point p1, Point p2)
{
    //(y1 – y2)x + (x2 – x1)y + (x1y2 – x2y1) = 0
    int a=p1[1]-p2[1],b=p2[0]-p1[0],c=p1[0]*p2[1]-p1[1]*p2[0];
    return Z3i::Point(a,b,c);
}

Z3i::RealPoint getLineFromPoint(RealPoint p1, RealPoint p2)
{
    //(y1 – y2)x + (x2 – x1)y + (x1y2 – x2y1) = 0
    double a=p1[1]-p2[1],b=p2[0]-p1[0],c=p1[0]*p2[1]-p1[1]*p2[0];
    return Z3i::RealPoint(a,b,c);
}

bool isOnLine(double a, double b, double c, Point p)
{
    return (fabs(a*p[0]+b*p[1]+c)<ESP_DOUBLE);
}

bool isOnLine(int a, int b, int c, Point p)
{
    return (a*p[0]+b*p[1]+c==0);
}
bool isLeftLine(int a, int b, int c, Point p)
{
    return (a*p[0]+b*p[1]+c>0);
}
bool isRightLine(int a, int b, int c, Point p)
{
    return (a*p[0]+b*p[1]+c<0);
}

vector<Point> pointAlongEdge(Point p1, Point p2)
{
    vector<Point> pts;
    int minx=p1[0]<p2[0]?p1[0]:p2[0];
    int maxx=p1[0]>p2[0]?p1[0]:p2[0];
    int miny=p1[1]<p2[1]?p1[1]:p2[1];
    int maxy=p1[1]>p2[1]?p1[1]:p2[1];
    if(p1[0]==p2[0]) {
        for(int i=miny; i<=maxy; i++)
            pts.push_back(Point(p1[0],i));
        return pts;
    }
    if(p1[1]==p2[1]) {
        for(int i=minx; i<=maxx; i++)
            pts.push_back(Point(i,p1[1]));
        return pts;
    }

    Z3i::Point line=getLineFromPoint(p1,p2);
    int a=line[0],b=line[1],c=line[2];
    if(abs(a)<abs(b)) {//dy<dx
        for(int x=minx; x<=maxx; x++) {
            int y=-(a*x+c)/b;
            Point p(x,y);
            if(isOnLine(a,b,c,p))
                pts.push_back(p);
        }
        return pts;
    }
    //else //dy>dx
    for(int y=miny; y<=maxy; y++) {
        int x=-(b*y+c)/a;
        Point p(x,y);
        if(isOnLine(a,b,c,p))
            pts.push_back(p);
    }
    return pts;
}

vector<Point> pointAlongEdge(RealPoint p1, RealPoint p2)
{
    vector<Point>  pts;
    if(fabs(p1[0]-round(p1[0]))<ESP_DOUBLE && fabs(p2[0]-round(p2[0]))<ESP_DOUBLE
            && fabs(p1[1]-round(p1[1]))<ESP_DOUBLE && fabs(p2[1]-round(p2[1]))<ESP_DOUBLE)
        pts=pointAlongEdge(Point(round(p1[0]),round(p1[1])),Point(round(p2[0]),round(p2[1])));
    else if(fabs(p1[0]-p2[0])>ESP_DOUBLE && fabs(p1[1]-p2[1])>ESP_DOUBLE){//Neither vertical or horizontal lines
        int minx=ceil(p1[0]<p2[0]?p1[0]:p2[0]);
        int maxx=floor(p1[0]>p2[0]?p1[0]:p2[0]);
        int miny=ceil(p1[1]<p2[1]?p1[1]:p2[1]);
        int maxy=floor(p1[1]>p2[1]?p1[1]:p2[1]);
        Z3i::RealPoint line=getLineFromPoint(p1,p2);
        //cout<<"minx="<<minx<<", maxx="<<maxx<<", miny="<<miny<<", maxy="<<maxy<<endl;
        double a=line[0],b=line[1],c=line[2];
        if(fabs(a)<fabs(b)) {//dy<dx
            for(int x=minx; x<=maxx; x++) {
                double y=-(a*x+c)/b;
                if(fabs(y-round(y))<ESP_DOUBLE) {
                    Point p(x,(int)y);
                    if(isOnLine(a,b,c,p))
                        pts.push_back(p);
                }
            }
        }
        else {//dy>dx
            for(int y=miny; y<=maxy; y++) {
                double x=-(b*y+c)/a;
                if(fabs(x-round(x))<ESP_DOUBLE) {
                    Point p((int)x,y);
                    if(isOnLine(a,b,c,p))
                        pts.push_back(p);
                }
            }
        }
    }
    //cout<<"pointAlongEdge : pts.size="<<pts.size()<<endl;
    return pts;
}

/***** Get slope ****/
//(Nx,Ny) : normal vector of the line
double getSlope(double Nx,double Ny)
{
    if(fabs(Ny)<1e-6) //vertical line
    {
        if(Nx>0)
            return -1e6; // -INFINITY ?
        else
            return 1e6; //INFINITY ?
    }
    return (-Nx/Ny);
    //return (-Nx/Ny)*(sqrt(Nx*Nx + Ny*Ny));
}

double getSlope(RealPoint N)
{
    double Nx=N[0];
    double Ny=N[1];
    if(fabs(Ny)<1e-6) //vertical line
    {
        if(Nx>0)
            return -1e6; // -INFINITY ?
        else
            return 1e6; //INFINITY ?
    }
    return (-Nx/Ny);
    //return (-Nx/Ny)*(sqrt(Nx*Nx + Ny*Ny));
}

double getSlope(double Nx, double Ny, int sign)
{
    double angle=atan(-Nx/Ny);
    if(sign<0)
    {
        if(angle>0)
            return angle - M_PI;
        return angle;
    }
    else//signe>0
    {
        if(angle<0)
            return angle + M_PI;
        return angle;
    }
}
/***** Get slope ****/
