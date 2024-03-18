/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
  points.sort((a,b)=>a[0]-b[0]);
  let endPoint = points[0][1];
  let arrows = 1;
  let n = points.length;
  for (let i = 1; i < n; i++) {
      if (points[i][0] > endPoint) {
          arrows++;
          endPoint = points[i][1];
      } else {
          endPoint = Math.min(endPoint, points[i][1]);
      }
  }
  return arrows;
};