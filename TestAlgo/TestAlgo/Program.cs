using System;

namespace TestAlgo
{
    class Program
    {
        // note entre [0-100]
        // ponderation entre [0-100]
        static float NotePonderee(float note, float ponderation)
        {
            return (ponderation / 100) * note;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(NotePonderee(90, 20));
        }
    }
}
