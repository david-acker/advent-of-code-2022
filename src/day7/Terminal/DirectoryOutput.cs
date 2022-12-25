namespace Day7.Solution.Terminal;

public sealed class DirectoryOutput : ITerminalLine
{
    public DirectoryOutput(string directoryName)
    {
        DirectoryName = directoryName;
    }

    public string DirectoryName { get; }

    public DirectoryEntry Handle(DirectoryEntry currentDirectory)
    {
        currentDirectory.ChildDirectories.Add(new DirectoryEntry(DirectoryName, currentDirectory));
        return currentDirectory;
    }
}