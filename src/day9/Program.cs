using Day9.Solution;
using Day9.Solution.Renderer;

if (Environment.GetCommandLineArgs() is not [_, var filePath])
{
    Console.WriteLine($"Must specify an input file.");
    return 1;
}

if (!File.Exists(filePath))
{
    Console.WriteLine($"The specified file does not exist: {filePath}");
    return 1;
}

var instructions = SolutionHelper.Read(File.ReadLines(filePath));

Console.WriteLine($"    Part one result: {SolutionHelper.GetPartOneResult(instructions)}");

return 0;