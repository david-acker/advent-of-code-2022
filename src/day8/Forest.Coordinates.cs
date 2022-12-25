namespace Day8.Solution;

public sealed partial class Forest
{
    private record Coordinate(int X, int Y);

    private enum Orientation
    {
        LeftToRight,
        RightToLeft,
        TopToBottom,
        BottomToTop
    }

    private static Coordinate GetCoordinate(
        int inputX, 
        int inputY,
        int size,
        Orientation orientation)
    {
        var (effectiveX, effectiveY) = orientation switch
        {
            Orientation.LeftToRight => (inputX, inputY),
            Orientation.RightToLeft => (inputX, size - inputY - 1),
            Orientation.TopToBottom => (inputY, size - inputX - 1),
            Orientation.BottomToTop => (size - inputY - 1, size - inputX - 1),
            _ => throw new ArgumentOutOfRangeException(nameof(orientation))
        };

        return new Coordinate(effectiveX, effectiveY);
    }
}