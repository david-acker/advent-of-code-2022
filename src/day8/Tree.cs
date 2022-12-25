namespace Day8.Solution;

public sealed class Tree
{
    public Tree(int x, int y, int height)
    {
        X = x;
        Y = y;
        
        Height = height;
    }
    
    public int X { get; }
    public int Y { get; }

    public int Height { get; }

    public override bool Equals(object? obj)
    {
        if (obj is Tree tree)
        {
            // Height is used for display purposes only; ignore in terms of equality.
            return X == tree.X && Y == tree.Y;
        }

        return false;
    }

    public override int GetHashCode()
    {
        // Pairing function described here: 
        // https://www.cs.upc.edu/~alvarez/calculabilitat/enumerabilitat.pdf
        return X + Convert.ToInt32(Math.Pow((Y + (X + 1) / 2), 2));
    }
}