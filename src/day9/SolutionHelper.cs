#define TESTING
#undef TESTING

using System.Diagnostics;

namespace Day9.Solution;

public static class SolutionHelper
{
    public static IReadOnlyList<Instruction> Read(IEnumerable<string> rawInput)
    {
        return rawInput.Select(ConstructInstruction).ToList();
    }

    private static Instruction ConstructInstruction(string input)
    {
        var parts = input.Split();

        Debug.Assert(parts.Length == 2);

        var direction = ParseDirection(parts[0]);
        var distance = ParseDistance(parts[1]);

        return new Instruction(direction, distance);
    }

    private static Direction ParseDirection(string input)
    {
        return input switch
        {
            "U" => Direction.Up,
            "D" => Direction.Down,
            "L" => Direction.Left,
            "R" => Direction.Right,
            _   => throw new ArgumentException("Invalid direction name.")
        };
    }

    private static int ParseDistance(string input)
    {
        return int.Parse(input);
    }

    public static int GetPartOneResult(IReadOnlyList<Instruction> instructions)
    {
        var visitedCoordinates = new HashSet<Coordinate>();

        var head = new Node();
        var tail = new Node();

        visitedCoordinates.Add(new Coordinate(tail.X, tail.Y));

        foreach (var instruction in instructions)
        {
            #if TESTING
            Console.WriteLine(instruction);
            #endif

            for (int i = 0; i < instruction.Distance; i++)
            {
                head.Move(instruction.Direction);

                if (NeedsToMove(head, tail))
                {
                    tail.Follow(head);

                    visitedCoordinates.Add(new Coordinate(tail.X, tail.Y));
                }

                #if TESTING
                PrintState(visitedCoordinates, head, tail);
                #endif
            }
        }


        return visitedCoordinates.Count;
    }

    private static void PrintState(HashSet<Coordinate> visitedCoordinates, Node head, Node tail)
    {
        const int gridSize = 6;
        Console.WriteLine(new string('=', gridSize));

        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                if (head.X == i && head.Y == j)
                {
                    Console.Write('H');
                }
                else if (visitedCoordinates.Any(x => x.X == i && x.Y == j))
                {
                    if (tail.X == i && tail.Y == j)
                    {
                        Console.Write('T');
                    }
                    else
                    {
                        Console.Write('X');
                    }
                }
                else
                {
                    Console.Write('-');
                }
            }

            Console.Write(Environment.NewLine);
        }

        Console.Write(Environment.NewLine);
    }

    private static bool NeedsToMove(Node head, Node tail)
    {
        var distance = Math.Sqrt(
            Math.Pow(tail.X - head.X, 2) + Math.Pow(tail.Y - head.Y, 2));

        return distance > Math.Sqrt(2);
    }

    private record struct Coordinate(int X, int Y);
}
