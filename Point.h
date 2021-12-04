class Point {
  public:
	    float m_x, m_y, m_z;		// coordinates
    Point(float x, float y, float z){
        m_x = x;
        m_y = y;
        m_z = z;
    }
    Point translateY(float distance){
        float x = m_x;
        float y = m_y + distance;
        float z = m_z;

        Point new_point(x, y, z);
        return new_point;
    }
};