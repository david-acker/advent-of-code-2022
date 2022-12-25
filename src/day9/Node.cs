namespace Day9.Solution;

public sealed class Node
{
    public int X { get; private set; }
    public int Y { get; private set; }

    private int _lastX { get; set; }
    private int _lastY { get; set; }

    public void Move(Direction direction)
    {
        _lastX = X;
        _lastY = Y;

        switch (direction)
        {
            case Direction.Up:
                Y++;
                break;
            case Direction.Down:
                Y--;
                break;
            case Direction.Left:
                X--;
                break;
            case Direction.Right:
                X++;
                break;
        }
    }

    public void Follow(Node node)
    {
        X = node._lastX;
        Y = node._lastY;
    }
}