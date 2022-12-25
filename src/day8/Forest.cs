#define TESTING
#undef TESTING

using System.Diagnostics.CodeAnalysis;

namespace Day8.Solution;

// Behold this monstrosity.
public sealed partial class Forest
{
    private Forest(int[][] input)
    {
        _input = input;

        // The example and actual inputs have the same length and width.
        Size = _input.Length;
    }

    private readonly int[][] _input;
    private readonly TreeMap _treeMap = new();

    public int Size { get; }
    public HashSet<Tree> VisibleTrees { get; } = new();

    public static Forest Create(int[][] input)
    {
        var orientations = Enum.GetValues(typeof(Orientation)).Cast<Orientation>().ToArray();
        var visibilityContext = new VisiblityContext(orientations);

        var forest = new Forest(input);
        
        for (int x = 0; x < forest.Size; x++)
        {
            for (int y = 0; y < forest.Size; y ++)
            {
                foreach (var orientation in orientations)
                {
                    var coordinate = GetCoordinate(x, y, forest.Size, orientation);
                    
                    var treeHeight = input[coordinate.X][coordinate.Y];

                    if (visibilityContext.IsVisible(orientation, treeHeight))
                    {
                        forest.AddTree(coordinate, treeHeight);
                        visibilityContext.SetTallest(orientation, treeHeight);
                    }
                }
            }

            visibilityContext.Reset();
        }

        return forest;
    }

    private void AddTree(Coordinate coordinate, int height)
    {
        var tree = new Tree(coordinate.X, coordinate.Y, height);

        if (_treeMap.Add(tree))
        {
            VisibleTrees.Add(tree);
        }
    }

    public bool TryGetTree(int x, int y, [NotNullWhen(true)] out Tree? tree)
    {
        bool containsTree = _treeMap.TryGet(x, y, out Tree? matchingTree);
        
        tree = matchingTree;
        return containsTree;
    }

    public int GetScenicScore(Tree tree)
    {
        #if TESTING
        Console.WriteLine($"Tree {tree.Height} (X: {tree.X} - Y: {tree.Y})");
        #endif

        int leftScore = GetLeftScore(tree);
        int rightScore = GetRightScore(tree);
        int topScore = GetTopScore(tree);
        int bottomScore = GetBottomScore(tree);

        #if TESTING
        Console.WriteLine($"L: {leftScore} R: {rightScore} T: {topScore} B: {bottomScore}");
        #endif 

        return leftScore * rightScore * topScore * bottomScore;
    }

    private int GetLeftScore(Tree tree)
    {
        #if TESTING
        Console.WriteLine(nameof(GetLeftScore));
        #endif

        int leftScore = 0;
        int x = tree.X - 1;
        while (x >= 0)
        {
            leftScore++;
            var currentHeight = _input[x][tree.Y];

            #if TESTING
            PrintScenicScoreComparison(x, tree.Y, tree.Height, currentHeight);
            #endif

            if (currentHeight >= tree.Height)
            {
                break;
            }
            x--;
        }

        return leftScore;
    }

    private int GetRightScore(Tree tree)
    {
        #if TESTING
        Console.WriteLine(nameof(GetRightScore));
        #endif

        int rightScore = 0;
        int x = tree.X + 1;
        while (x < Size)
        {
            rightScore++;
            var currentHeight = _input[x][tree.Y];

            #if TESTING
            PrintScenicScoreComparison(x, tree.Y, tree.Height, currentHeight);
            #endif
            
            if (currentHeight >= tree.Height)
            {
                break;
            }
            x++;
        }

        return rightScore;
    }

    private int GetTopScore(Tree tree)
    {
        #if TESTING
        Console.WriteLine(nameof(GetTopScore));
        #endif

        int topScore = 0;
        int y = tree.Y - 1;
        while (y >= 0)
        {
            topScore++;
            var currentHeight = _input[tree.X][y];

            #if TESTING
            PrintScenicScoreComparison(tree.X, y, tree.Height, currentHeight);
            #endif

            if (currentHeight >= tree.Height)
            {
                break;
            }
            y--;
        }

        return topScore;
    }

    private int GetBottomScore(Tree tree)
    {
        #if TESTING
        Console.WriteLine(nameof(GetBottomScore));
        #endif

        int bottomScore = 0;
        int y = tree.Y + 1;
        while (y < Size)
        {
            bottomScore++;
            var currentHeight = _input[tree.X][y];

            #if TESTING
            PrintScenicScoreComparison(tree.X, y, tree.Height, currentHeight);
            #endif
            
            if (currentHeight >= tree.Height)
            {
                break;
            }
            y++;
        }
        
        return bottomScore;
    }

    #if TESTING
    private static PrintScenicScoreComparison(int x, int y, int mainTreeHeight, int currentTreeHeight)
    {
        Console.WriteLine($"X: {x} Y: {y} @ {currentTreeHeight} vs. {mainTreeHeight}");
    }
    #endif
}