namespace Day7.Solution;

public abstract class Line
{
    public Line(LineType type)
    {
        Type = type;
    }

    public LineType Type { get; }

    public enum LineType
    {
        Command,
        Output
    }

    public abstract DirectoryEntry Handle(DirectoryEntry currentDirectory);
}