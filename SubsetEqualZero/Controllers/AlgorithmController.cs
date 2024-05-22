using Microsoft.AspNetCore.Mvc;

namespace SubsetEqualZero
{
    [ApiController]
    [Route("algorithm")]
    public class AlgorithmController (IAlgorithmService algorithmService) : ControllerBase
    {
        private readonly IAlgorithmService _algorithmService = algorithmService;

        [HttpPost("compute")]
        [ProducesResponseType(StatusCodes.Status200OK, Type = typeof(ResponseDTO))]
        public IActionResult Compute([FromBody] List<int> numbers)
        {
            var start = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
            var data = _algorithmService.Compute(numbers);

            return Ok(new ResponseDTO(DateTimeOffset.UtcNow.ToUnixTimeMilliseconds() - start, data));
        }
    }
}