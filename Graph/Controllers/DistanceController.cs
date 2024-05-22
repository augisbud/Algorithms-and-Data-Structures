using Graph.Models;
using Graph.Services;
using Microsoft.AspNetCore.Mvc;

namespace Graph.Controllers
{
    [ApiController]
    [Produces("application/json")]
    [Consumes("application/json")]
    [Route("distance")]
    public class DistanceController : ControllerBase
    {
        [HttpPost("/distance", Name = "Find Shortest Path")]
        public ActionResult<ResponseDTO> GetShortestPath([FromBody] InputDTO inputDTO) {
            var distanceService = new DistanceService(inputDTO);

            var responseDTO = distanceService.ShortestPath(inputDTO.Source, inputDTO.Destination);

            if (responseDTO.Distance == int.MaxValue)
                return NotFound();
            else
                return responseDTO;
        }
    }
}