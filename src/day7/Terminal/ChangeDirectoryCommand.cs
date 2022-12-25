namespace Day7.Solution.Terminal;

public sealed class ChangeDirectoryCommand : ITerminalLine
{
    public ChangeDirectoryCommand(string directory)
    {
        Directory = directory;
    }

    public string Directory { get; }

    public DirectoryEntry Handle(DirectoryEntry currentDirectory)
    {
        if (Directory == "/" && currentDirectory.Name == "/")
        {
            return currentDirectory;
        }

        if (Directory == "..")
        {
            if (currentDirectory.ParentDirectory is null)
            {
                throw new InvalidOperationException("Already at root directory.");
            }

            return currentDirectory.ParentDirectory;
        }

        return currentDirectory.ChildDirectories.First(x => x.Name == Directory);
    }
}