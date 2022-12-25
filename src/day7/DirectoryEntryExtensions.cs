namespace Day7.Solution;

public static class DirectoryEntryExtensions
{
    public static void Display(this DirectoryEntry directory, bool showSize = true)
    {
        PrintDirectory(directory, showSize);
        PrintFiles(directory, showSize);

        foreach (var childDirectory in directory.ChildDirectories)
        {
            childDirectory.Display(showSize);
        }
    }

    private static void PrintDirectory(DirectoryEntry directory, bool showSize)
    {
        Console.Write(GetIndent(directory.Level * _indentLevelSize));
        Console.Write($"{directory.Name} (dir) ");

        if (showSize)
        {
            Console.Write(directory.GetTotalSize());
        }

        Console.Write(Environment.NewLine);
    }

    private static void PrintFiles(DirectoryEntry directory, bool showSize)
    {
        var indent = GetIndent((directory.Level + 1) * _indentLevelSize);

        foreach (var file in directory.Files)
        {
            Console.Write(indent);
            Console.Write($"{file.Name} ");

            if (showSize)
            {
                Console.Write(file.Size);
            }

            Console.Write(Environment.NewLine);
        }
    }

    private static string GetIndent(int size) => string.Empty.PadLeft(size);
    private const int _indentLevelSize = 4;
}