#define TESTING
#undef TESTING

using Day8.Solution;

var filePath = Environment.GetCommandLineArgs()[1];

if (!File.Exists(filePath))
{
    Console.WriteLine($"The specified file does not exist: {filePath}");
    return 1;
}

var input = SolutionHelper.ParseInput(File.ReadLines(filePath));
var forest = Forest.Create(input);

#if TESTING
forest.Print();
#endif

Console.WriteLine($"    Part one result: {SolutionHelper.GetPartOneResult(forest)}");
Console.WriteLine($"    Part two result: {SolutionHelper.GetPartTwoResult(forest)}");

return 0;