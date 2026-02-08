//    internal class work1
//    {
//        internal static int FindMax(int[] numbers)
//        {
//            int maxNumber = numbers[0];
//
//            for (int i = 1; i < numbers.Length; i++)
//            {
//                if (numbers[i] > maxNumber)
//                {
//                    maxNumber = numbers[i];
//                }
//            }
//
//            return maxNumber;
//        }
//
//        internal static void Main(string[] args)
//        {
//            int[] numbers = new int[4] { 1, 3, 4, 5 };
//            Console.WriteLine(FindMax(numbers));
//        }
//    }




internal class work1
{

    internal static int SumRange(int start, int end)
    {
        int sum = 0;

        for (int i = start; i <= end; i++)
        {
            sum += i;
        }

        return sum;
    }

    internal static void Main(string[] args)
    {
        Console.WriteLine(SumRange(1, 5));
        Console.WriteLine(SumRange(3, 7));
        Console.WriteLine(SumRange(-2, 2));
    }
}