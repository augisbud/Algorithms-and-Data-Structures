namespace SubsetEqualZero
{
    public class AlgorithmService : IAlgorithmService
    {
        public List<int>? Compute(List<int> numbers) 
        {           
            var currentSubset = new List<int>();

            List<int>? FindSubsetHelper(int index)
            {
                if (currentSubset.Count > 0 && currentSubset.Sum() == 0)
                    return new List<int>(currentSubset);
                if (index == numbers.Count)
                    return null;

                currentSubset.Add(numbers[index]);
                var withIndex = FindSubsetHelper(index + 1);

                if(withIndex != null)
                    return withIndex;

                currentSubset.RemoveAt(currentSubset.Count - 1); 

                var withoutIndex = FindSubsetHelper(index + 1);

                return withoutIndex;
            }

            return FindSubsetHelper(0);
        }
    }
}