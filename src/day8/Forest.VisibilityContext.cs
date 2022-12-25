namespace Day8.Solution;

public sealed partial class Forest
{
    private sealed class VisiblityContext
    {
        private const int _defaultHeight = -1;
        private readonly Dictionary<Orientation, int> _tallestTreeMap;

        public VisiblityContext(IEnumerable<Orientation> orientations)
        {
            _tallestTreeMap = orientations.ToDictionary(x => x, x => _defaultHeight);
        }

        public bool IsVisible(Orientation orientation, int currentHeight)
        {
            return currentHeight > _tallestTreeMap[orientation];
        }

        public void SetTallest(Orientation orientation, int newHeight)
        {
            if (newHeight <= _tallestTreeMap[orientation])
            {
                throw new ArgumentException("New height does not exceed the current height.", nameof(newHeight));
            }

            _tallestTreeMap[orientation] = newHeight;
        }

        public void Reset()
        {
            foreach (var orientation in _tallestTreeMap.Keys)
            {
                _tallestTreeMap[orientation] = _defaultHeight;
            }
        }
    }
}