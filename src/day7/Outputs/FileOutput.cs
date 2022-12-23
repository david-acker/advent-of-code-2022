namespace Day7.Solution.Outputs;

public sealed class FileOutput : Line
{
    public FileOutput(string name, int size) : base(LineType.Output)
    {
        Name = name;
        Size = size;
    }

    public string Name { get; }
    public int Size { get; }

    public override DirectoryEntry Handle(DirectoryEntry currentDirectory)
    {
        currentDirectory.Files.Add(new DirectoryEntry.FileEntry(Name, Size));
        return currentDirectory;
    }
}