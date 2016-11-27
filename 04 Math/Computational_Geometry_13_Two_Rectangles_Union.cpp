 struct rect {
      double x1, y1, x2, y2;    // left, bottom, right, and top
    
      rect(){}
      rect(double x1, double y1, double x2, double y2):
        x1(x1), y1(y1), x2(x2), y2(y2)  { canonicalize(); }
    
      void canonicalize() {
        if(dcmp(x1, x2) > 0)  swap(x1, x2);
        if(dcmp(y1, y2) > 0)  swap(y1, y2);
      }
    };
    
    void intersect(rect a, rect b)
    {
        if(b.x2<=a.x1 || b.x1>=a.x2 || b.y2<=a.y1 || b.y1>=a.y2)
        cout<<"No Overlap\n";//No intersection between them
      else
      { //Using the compression method to compress the overlapping area
        if(b.x1 > a.x1)   a.x1 = b.x1;
        if(b.x2 < a.x2)   a.x2 = b.x2;
        if(b.y1 > a.y1)   a.y1 = b.y1;
        if(b.y2 < a.y2)   a.y2 = b.y2;
    
        cout<<a.x1<<" "<<a.y1<<" "<<a.x2<<" "<<a.y2<<"\n"; //the overlap
      }
    }

    
    
    
    // nout = {-2, -1 or CNT} =
    //   {no intersection, inside me, or # of extra-sub-rectangles}
    rect intersectRectangles(rect a, rect b, rect out[4], int &nout)
    {
      nout = -2;
      if(dcmp(b.x2, a.x1) < 0 || dcmp(b.x1, a.x2) > 0
          || dcmp(b.y2, a.y1) < 0 || dcmp(b.y1, a.y2) > 0)
        // Adjust if need boundary edges considered.
        return rect(0, 0, 0, 0); // Do they  intersect? 
    
      nout = -1;
      if(dcmp(b.x1, a.x1) <= 0 && dcmp(b.x2, a.x2) >= 0 &&
          dcmp(b.y1, a.y1) <= 0 && dcmp(b.y2, a.y2)  >= 0)
        return a;     //a Totally inside b
    
       rect t;
       nout = 0;
    
      if(dcmp(b.x1, a.x1) > 0)  t = a, t.x2 = b.x1, a.x1 = b.x1;
      out[nout++] = t; // left
      if(dcmp(b.x2, a.x2) < 0)  t = a, t.x1 = b.x2, a.x2 = b.x2;
      out[nout++] = t; // right
      if(dcmp(b.y1, a.y1) > 0)  t = a, t.y2 = b.y1, a.y1 = b.y1;
      out[nout++] = t; // down
      if(dcmp(b.y2, a.y2) < 0)  t = a, t.y1 = b.y2, a.y2 = b.y2;
      out[nout++] = t; // upper
      return a; // a represent the overlapping
    }
