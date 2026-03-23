using System;

class Circle
{
    public const double PI = 3.14159;
    
    public double Radius;
    
    public double GetArea()
    {
        return PI * Radius * Radius;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Circle circle1 = new Circle();
        circle1.Radius = 5;
        
        Circle circle2 = new Circle();
        circle2.Radius = 3.5;
        
        Console.WriteLine("=== Площади кругов ===");
        Console.WriteLine();
        
        Console.WriteLine("Круг 1:");
        Console.WriteLine($"Радиус: {circle1.Radius}");
        Console.WriteLine($"Площадь: {circle1.GetArea():F2}"); // :F2 округляет до 2 знаков
        Console.WriteLine();
        
        Console.WriteLine("Круг 2:");
        Console.WriteLine($"Радиус: {circle2.Radius}");
        Console.WriteLine($"Площадь: {circle2.GetArea():F2}");
        
        Console.WriteLine("\nЧисло PI (константа класса): " + Circle.PI);
        
        Console.WriteLine("\nНажмите любую клавишу для выхода...");
        Console.ReadKey();
    }
}