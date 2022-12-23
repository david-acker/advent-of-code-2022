namespace Day7.Solution.Commands;

public sealed class ChangeDirectoryCommand : Line
{
    public ChangeDirectoryCommand(string argument) : base(LineType.Command)
    {
        Argument = argument;
    }

    public string Argument { get; }

    public override DirectoryEntry Handle(DirectoryEntry currentDirectory)
    {
        if (Argument == "/" && currentDirectory.Name == "/")
        {
            return currentDirectory;
        }

        if (Argument == "..")
        {
            if (currentDirectory.ParentDirectory is null)
            {
                throw new InvalidOperationException("Already at root directory.");
            }

            return currentDirectory.ParentDirectory;
        }

        return currentDirectory.ChildDirectories.First(x => x.Name == Argument);
    }
}