namespace Day7.Solution.Terminal;

public sealed class ListCommand : ITerminalLine
{
    public DirectoryEntry Handle(DirectoryEntry currentDirectory)
    {
        // Essentially no-op here as the initial output of the list command itself isn't actually used.
        return currentDirectory;
    }
}
