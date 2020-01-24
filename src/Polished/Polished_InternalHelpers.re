let floatGuard =
    (lowerBoundary: float, upperBoundary: float, value: float): float =>
  if (value > upperBoundary) {
    upperBoundary;
  } else if (value < lowerBoundary) {
    lowerBoundary;
  } else {
    value;
  };

let intGuard = (lowerBoundary: int, upperBoundary: int, value: int): int =>
  if (value > upperBoundary) {
    upperBoundary;
  } else if (value < lowerBoundary) {
    lowerBoundary;
  } else {
    value;
  };