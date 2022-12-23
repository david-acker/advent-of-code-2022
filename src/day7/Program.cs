//#define TEST

using Day7.Solution;
using Day7.Solution.Extensions;

var filePath = Environment.GetCommandLineArgs()[1];

if (!File.Exists(filePath))
{
    Console.WriteLine($"The specified file does not exist: {filePath}");
    return 1;
}

var data = File.ReadLines(filePath);

var directory = Solution.Parse(data);

#if TEST
directory.Display(showSize: true);
#endif

Console.WriteLine($"    Part one result: {Solution.SolvePartOne(directory)}");
Console.WriteLine($"    Part two result: {Solution.SolvePartTwo(directory)}");

return 0;