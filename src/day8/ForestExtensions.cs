namespace Day8.Solution;

public static class ForestExtensions
{
    public static void Print(this Forest forest)
    {
        var separator = new string('=', forest.Size);
        Console.WriteLine(separator);

        for (int x = 0; x < forest.Size; x++)
        {
            for (int y = 0; y < forest.Size; y++)
            {
                if (forest.TryGetTree(x, y, out var tree))
                {
                    Console.Write(tree.Height);
                }
                else
                {
                    Console.Write('-');
                }
            }

            Console.Write(Environment.NewLine);
        }

        Console.WriteLine(separator);
    }
}