//#define TEST

using Day7.Solution.Commands;
using Day7.Solution.Extensions;
using Day7.Solution.Outputs;

namespace Day7.Solution;

public class Solution
{
    public static DirectoryEntry Parse(IEnumerable<string> input)
    {
        var rootDirectory = new DirectoryEntry("/");
        var currentDirectory = rootDirectory;

        int index = 0;
        foreach (var line in input)
        {
            var parsedLine = ParseLine(line.Split());

            try
            {
                currentDirectory = parsedLine.Handle(currentDirectory);
            }
            catch
            {
                Console.WriteLine("An exception occurred while handling the following line:");
                Console.WriteLine($"Line Number: {index}");
                Console.WriteLine($"Line Data:   {line}");

                #if TEST
                Console.WriteLine(new string('=', 50));
                rootDirectory.Display();
                Console.WriteLine(new string('=', 50));
                #endif
                
                throw;
            }
            
            index++;
        }

        return rootDirectory;
    }

    public static int SolvePartOne(DirectoryEntry directory)
    {
        static int CrawlDirectoryTree(DirectoryEntry directory)
        {
            var totalSize = directory.GetTotalSize();

            var result = totalSize <= 100_000 ? totalSize : 0;

            foreach (var childDirectory in directory.ChildDirectories)
            {
                result += CrawlDirectoryTree(childDirectory);
            }
            
            return result;
        }

        return CrawlDirectoryTree(directory);
    }

    public static int SolvePartTwo(DirectoryEntry directory)
    {
        int requiredSize = 30_000_000 - (70_000_000 - directory.GetTotalSize());

        int CrawlDirectoryTree(DirectoryEntry directory)
        {
            int directorySize = directory.GetTotalSize();
            if (directorySize < requiredSize)
            {
                return int.MaxValue;
            }

            var closestSize = directorySize;

            foreach (var childDirectory in directory.ChildDirectories)
            {
                var closestSizeForChildDirectory = CrawlDirectoryTree(childDirectory);
                if (closestSizeForChildDirectory < closestSize)
                {
                    closestSize = closestSizeForChildDirectory;
                }
            }

            return closestSize;
        }

        return CrawlDirectoryTree(directory);
    }

    private static Line ParseLine(string[] lineComponents)
    {
        return lineComponents switch
        {
            ["$", "ls"] => new ListCommand(),
            ["$", "cd", var argument] => new ChangeDirectoryCommand(argument),
            ["dir", var directoryName] => new DirectoryOutput(directoryName),
            [var size, var fileName] => new FileOutput(fileName, int.Parse(size)),
            _ => throw new ArgumentException($"Failed to parse line: {string.Join(" ", lineComponents)}")
        };
    }
}