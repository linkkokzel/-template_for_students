using System;

Console.WriteLine("--- Проверка задачи 1 ---");

Order заказ1 = new Order();
Order заказ2 = new Order();
Order заказ3 = new Order();
Order заказ4 = new Order();

заказ1.DisplayInfo();
заказ2.DisplayInfo();
заказ3.DisplayInfo();
заказ4.DisplayInfo();

Console.WriteLine("\n--- Проверка задачи 2 ---");

Console.WriteLine("Сейчас будем создавать первый объект:");
DatabaseConnector подключение1 = new DatabaseConnector();
подключение1.Connect();

Console.WriteLine("\nСейчас будем создавать второй объект:");
DatabaseConnector подключение2 = new DatabaseConnector();
подключение2.Connect();


// Задача 1
class Order
{
    public static int nextId = 1;

    public int OrderId;


    public Order()
    {
        OrderId = nextId; 
        nextId = nextId + 1;
    }

    public void DisplayInfo()
    {
        Console.WriteLine("Order #" + OrderId);
    }
}

// Задача 2
class DatabaseConnector
{
    public static string connectionString;

    static DatabaseConnector()
    {
        Console.WriteLine("Static constructor called");
        connectionString = "Server=localhost;DB=Test";
    }

    public DatabaseConnector()
    {
        Console.WriteLine("Instance created");
    }

    public void Connect()
    {
        Console.WriteLine("Подключаемся через: " + connectionString);
    }
}