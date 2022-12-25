using System.Diagnostics.CodeAnalysis;

namespace Day8.Solution;

public sealed partial class Forest
{
    private sealed class TreeMap
    {
        private readonly Dictionary<int, Dictionary<int, Tree>> _treeMap = new();

        public bool Add(Tree tree)
        {
            if (_treeMap.TryGetValue(tree.X, out var partialTreeMap))
            {
                if (partialTreeMap.ContainsKey(tree.Y))
                {
                    return false;
                }

                partialTreeMap[tree.Y] = tree;
            }
            else
            {
                _treeMap[tree.X] = new()
                {
                    [tree.Y] = tree
                };
            }

            return true;
        }

        public bool TryGet(int x, int y, [NotNullWhen(true)] out Tree? tree)
        {
            if (_treeMap.TryGetValue(x, out var partialTreeMap)
                && partialTreeMap.TryGetValue(y, out var matchingTree))
            {
                tree = matchingTree;
                return true;
            }

            tree = null;
            return false;
        }
    }
}