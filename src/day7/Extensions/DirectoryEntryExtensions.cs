namespace Day7.Solution.Extensions;

public static class DirectoryEntryExtensions
{
    private const int IndentLevelSize = 4;

    public static void Display(this DirectoryEntry directory, bool showSize = true)
    {
        Console.Write(Indent(directory.Level * IndentLevelSize));
        Console.Write($"{directory.Name} (dir) ");
        if (showSize)
        {
            Console.Write(directory.GetTotalSize());
        }
        Console.Write(Environment.NewLine);

        var fileIndent = Indent((directory.Level + 1) * IndentLevelSize);
        foreach (var file in directory.Files)
        {
            Console.Write(fileIndent);
            Console.Write($"{file.Name} ");
            if (showSize)
            {
                Console.Write(file.Size);
            }
            Console.Write(Environment.NewLine);
        }

        foreach (var childDirectory in directory.ChildDirectories)
        {
            childDirectory.Display(showSize);
        }
    }

    private static string Indent(int size) => string.Empty.PadLeft(size);
}