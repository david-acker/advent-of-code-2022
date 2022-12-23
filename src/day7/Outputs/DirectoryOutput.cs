namespace Day7.Solution.Outputs;

public sealed class DirectoryOutput : Line
{
    public DirectoryOutput(string name) : base(LineType.Output)
    {
        Name = name;
    }

    public string Name { get; }

    public override DirectoryEntry Handle(DirectoryEntry currentDirectory)
    {
        currentDirectory.ChildDirectories.Add(new DirectoryEntry(Name, currentDirectory));
        return currentDirectory;
    }
}