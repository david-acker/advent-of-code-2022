namespace Day7.Solution;

public sealed class FileEntry
{
    public FileEntry(string name, int size)
    {
        Name = name;
        Size = size;
    }

    public string Name { get; set; }
    public int Size { get; set; }
}