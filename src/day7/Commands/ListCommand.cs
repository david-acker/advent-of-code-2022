namespace Day7.Solution.Commands;

public sealed class ListCommand : Line
{
    public ListCommand() : base(LineType.Command)
    {
    }

    public override DirectoryEntry Handle(DirectoryEntry currentDirectory)
    {
        // Essentially no-op here as the execution of the list command itself isn't used.
        return currentDirectory;
    }
}
