namespace SubsetEqualZero
{
    public class ResponseDTO(long responseTime, List<int>? data) {
        public long ResponseTime { get; } = responseTime;
        public List<int>? Data { get; } = data; 
    }
}