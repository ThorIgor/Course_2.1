using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IgorClassWork
{
    class Program
    {
        class Product
        {
            public string Name { get; set; }
            public double Price { get; set; }
            public DateTime ExpDate { get; set; }
            public Shop Shop { get; set; }

            public override string ToString()
            {
                return Name + ": " + Price + " " + ExpDate + " " + Shop;
            }
        }
        class Shop
        {
            public string Name { get; set;}
            public string City { get; set; }

            public override string ToString()
            {
                return Name + " " + City;
            }
        }

        static void Print<T>(string header, IEnumerable<T> arr)
        {
            Console.WriteLine($"---------------{header}---------------");
            foreach (var item in arr)
                Console.WriteLine(item);
        }

        static void Main(string[] args)
        {
            List<Product> products = new List<Product>(){
                new Product
                {
                    Name = "Milk",
                    Price = 12.5,
                    ExpDate = DateTime.Today - new TimeSpan(TimeSpan.TicksPerDay),
                    Shop = new Shop
                    {
                        Name = "Products",
                        City = "Rivne"
                    }
                },
                new Product
                {
                    Name = "Meet",
                    Price = 57,
                    ExpDate = DateTime.Today + new TimeSpan(TimeSpan.TicksPerDay*4),
                    Shop = new Shop
                    {
                        Name = "Products",
                        City = "Rivne"
                    }
                },
                new Product
                {
                    Name = "Fish",
                    Price = 78,
                    ExpDate = DateTime.Now + new TimeSpan(TimeSpan.TicksPerDay),
                    Shop = new Shop
                    {
                        Name = "Products",
                        City = "Kiev"
                    }
                },
                new Product
                {
                    Name = "Bread",
                    Price = 11.2,
                    ExpDate = DateTime.Now + new TimeSpan(TimeSpan.TicksPerDay*2),
                    Shop = new Shop
                    {
                        Name = "Products",
                        City = "Kiev"
                    }
                }
            };

            var prd1 = products.Where(x => x.Name[0] == 'M');
            Print("Start wiht M", prd1);

            var prd2 = products.Where(x => x.ExpDate > DateTime.Now);
            Print("Exp date is good", prd2);

            var prd3 = products.Where(x => x.Shop?.City == "Kiev");
            Print("Kiev", prd3);
            
        }
    }
}
