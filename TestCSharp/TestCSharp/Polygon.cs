using System;
using System.Collections.Generic;
using System.Text;

namespace TestCSharp
{
    struct Vec2<T>
    {
        public T x;
        public T y;

        public Vec2(T x, T y)
        {
            this.x = x;
            this.y = y;
        }

        public void set(T x, T y)
        {
            this.x = x;
            this.y = y;
        }
        public void setX(T x) { this.x = x; }
        public void setY(T y) { this.y = y; }
    }

    class Polygon
    {
        private List<Vec2<double>> m_vertices;
        
        public Polygon(ref List<Vec2<double>> vertices)
        {
            m_vertices = vertices;
        }

        public void PrintVertices()
        {
            for (int i = 0; i < m_vertices.Count; i++)
                Console.WriteLine("[" + m_vertices[i].x + "," + m_vertices[i].y + "]");
        }

        public double GetPerimeter()
        {
            double perimeter = 0;
            for (int i = 0; i < m_vertices.Count; i++)
            {
                int next = (i == m_vertices.Count - 1) ? 0 : i + 1;
                double temp_x = m_vertices[next].x - m_vertices[i].x;
                double temp_y = m_vertices[next].y - m_vertices[i].y;
                perimeter += Math.Sqrt(temp_x*temp_x + temp_y*temp_y);
            }
            return perimeter;
        }

        public void Move(double x,double y)
        {
            for (int i = 0;i < m_vertices.Count;i++)
            {
                m_vertices[i].set(m_vertices[i].x + x, m_vertices[i].y + y);
            }
        }

        public float GetArea()
        {
            return 0;
        }
    }
}
