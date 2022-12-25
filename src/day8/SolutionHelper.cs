using System.Globalization;

namespace Day8.Solution;

public static class SolutionHelper
{
    public static int[][] ParseInput(IEnumerable<string> rawInput)
    {
        return rawInput
            .Select(line => line.Select(CharUnicodeInfo.GetDecimalDigitValue).ToArray())
            .ToArray();
    }

    public static int GetPartOneResult(Forest forest)
    {
        return forest.VisibleTrees.Count;
    }

    public static int GetPartTwoResult(Forest forest)
    {
        int highestScenicScore = 0;

        foreach (var tree in forest.VisibleTrees)
        {
            var scenicScore = forest.GetScenicScore(tree);
            if (scenicScore > highestScenicScore)
            {
                highestScenicScore = scenicScore;
            }
        }

        return highestScenicScore;
    }
}