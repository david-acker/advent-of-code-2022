namespace Day9.Solution;

public sealed class Instruction
{
    public Instruction(Direction direction, int distance)
    {
        Direction = direction;
        Distance = distance;
    }

    public Direction Direction { get; }
    public int Distance { get; }

    public override string ToString()
    {
        return $"{nameof(Instruction)} {Direction} {Distance}";
    }
}

public enum Direction { Up, Right, Down, Left };