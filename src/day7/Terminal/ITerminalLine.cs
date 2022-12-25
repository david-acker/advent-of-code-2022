namespace Day7.Solution.Terminal;

public interface ITerminalLine
{
    DirectoryEntry Handle(DirectoryEntry currentDirectory);
}