namespace Day7.Solution;

public sealed class DirectoryEntry
{
    public DirectoryEntry(string name, DirectoryEntry? parentDirectory = null)
    {
        Name = name;
        ParentDirectory = parentDirectory;
        Level = parentDirectory == null ? 0 : parentDirectory.Level + 1;
    }

    public string Name { get; }
    public int Level { get; }

    public DirectoryEntry? ParentDirectory { get; }
    public ICollection<DirectoryEntry> ChildDirectories { get; } = new List<DirectoryEntry>();
    public ICollection<FileEntry> Files { get; } = new List<FileEntry>();

    public int GetTotalSize()
    {
        return Files.Sum(x => x.Size) + ChildDirectories.Sum(x => x.GetTotalSize());
    }
}