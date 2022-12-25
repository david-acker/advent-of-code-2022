#define TESTING
#undef TESTING

using Day7.Solution;

var filePath = Environment.GetCommandLineArgs()[1];

if (!File.Exists(filePath))
{
    Console.WriteLine($"The specified file does not exist: {filePath}");
    return 1;
}

var data = File.ReadLines(filePath);

var directory = Solution.Parse(data);

#if TESTING
directory.Display(showSize: true);
#endif

Console.WriteLine($"    Part one result: {Solution.SolvePartOne(directory)}");
Console.WriteLine($"    Part two result: {Solution.SolvePartTwo(directory)}");

return 0;