namespace Graph.Models
{
    public class InputDTO
    {
        public string Source { get; set; } = "";
        public string Destination { get; set; } = "";
        public List<EdgeDTO> EdgeDTOs { get; set; } = [];
    }
}