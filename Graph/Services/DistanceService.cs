using Graph.Models;

namespace Graph.Services
{
    public class DistanceService
    {
        private readonly int numVertices;
        private readonly List<List<int>> adjacencyMatrix = [];
        private readonly Dictionary<string, int> cityToIndex = [];
        private readonly Dictionary<int, string> indexToCity = [];

        public DistanceService(InputDTO inputDTO)
        {
            var cities = new List<string>(); 
            foreach(var edgeDTO in inputDTO.EdgeDTOs)
            {
                cities.Add(edgeDTO.Source);
                cities.Add(edgeDTO.Destination);
            }

            numVertices = cities.Distinct().Count();

            for (int i = 0; i < numVertices; i++)
            {
                adjacencyMatrix.Add(new List<int>(new int[numVertices]));
                for (int j = 0; j < numVertices; j++)
                {
                    adjacencyMatrix[i][j] = int.MaxValue;
                }
            }

            foreach(var edgeDTO in inputDTO.EdgeDTOs)
            {
                var sourceIndex = GetIndex(edgeDTO.Source);
                var destinationIndex = GetIndex(edgeDTO.Destination);
                adjacencyMatrix[sourceIndex][destinationIndex] = edgeDTO.Distance;
                adjacencyMatrix[destinationIndex][sourceIndex] = edgeDTO.Distance;
            }
        }

        private int GetIndex(string city)
        {
            if (!cityToIndex.TryGetValue(city, out int value))
            {
                var index = cityToIndex.Count;
                value = index;
                cityToIndex[city] = value;
                indexToCity[index] = city;
            }
            return value;
        }

        public ResponseDTO ShortestPath(string source, string destination)
        {
            var sourceIndex = GetIndex(source);
            var destinationIndex = GetIndex(destination);
            var distance = new int[numVertices];
            var parent = new int[numVertices];
            var visited = new bool[numVertices];

            for (var i = 0; i < numVertices; i++)
            {
                distance[i] = int.MaxValue;
                parent[i] = -1;
            }

            distance[sourceIndex] = 0;

            for (var count = 0; count < numVertices - 1; count++)
            {
                var u = MinDistance(distance, visited);
                visited[u] = true;

                for (var v = 0; v < numVertices; v++)
                {
                    if (!visited[v] && adjacencyMatrix[u][v] != int.MaxValue && distance[u] != int.MaxValue &&
                        distance[u] + adjacencyMatrix[u][v] < distance[v])
                    {
                        parent[v] = u;
                        distance[v] = distance[u] + adjacencyMatrix[u][v];
                    }
                }
            }

            var path = new List<string>();
            int current = destinationIndex;
            while (current != -1)
            {
                path.Add(indexToCity[current]);
                current = parent[current];
            }
            path.Reverse();

            return new ResponseDTO(path, distance[destinationIndex]);
        }

        private int MinDistance(int[] distance, bool[] visited)
        {
            var min = int.MaxValue;
            var minIndex = -1;

            for (var v = 0; v < numVertices; v++)
            {
                if (!visited[v] && distance[v] <= min)
                {
                    min = distance[v];
                    minIndex = v;
                }
            }

            return minIndex;
        }
    }
}