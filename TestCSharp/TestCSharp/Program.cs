using System;
using System.Collections.Generic;

namespace TestCSharp
{

    public class Program
    {
        public Program() { }

        public static void Main(string[] args)
        {
            List<Vec2<double>> verts = new List<Vec2<double>>();
            verts.Add(new Vec2<double>(0, 0));
            verts.Add(new Vec2<double>(4, 3));
            verts.Add(new Vec2<double>(7, 9));
            verts.Add(new Vec2<double>(3, 6));
            verts.Add(new Vec2<double>(2, 2));

            Polygon poly = new Polygon(ref verts);


            for(int i = 0;i < 10000;i++)
            {
                poly.Move(0.01*i,0.1*i);
                poly.PrintVertices();
            }
        }
    }
}
