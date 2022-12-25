namespace Day7.Solution.Terminal;

public sealed class FileOutput : ITerminalLine
{
    public FileOutput(string fileName, int size)
    {
        FileName = fileName;
        Size = size;
    }

    public string FileName { get; }
    public int Size { get; }

    public DirectoryEntry Handle(DirectoryEntry currentDirectory)
    {
        currentDirectory.Files.Add(new FileEntry(FileName, Size));
        return currentDirectory;
    }
}