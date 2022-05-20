using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NaTusu
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            bool end = false;
            while (!end)
            {
                Console.Clear();
                Console.WriteLine("r - random, e - exit");
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.R:
                        Console.Clear();
                        int main = rand.Next(0, 2);
                        Console.WriteLine(main == 1 ? "Lets go why are you waiting!!!" : "You must work!!!");
                        Console.WriteLine("Press any button");
                        Console.ReadKey();
                        break;
                    case ConsoleKey.E:
                        end = true;
                        break;
                }
            }
        }
    }
}
