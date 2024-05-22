namespace Graph.Models
{
    public class ResponseDTO(List<string> path, int distance)
    {
        public List<string> Path { get; } = path;
        public int Distance { get; } = distance;
    }
}