/*
1. Need two functions: quickSort adn partition
2. Need a privot
*/
function quickSort(array, left, right) {
  // base case
  if (left>=right) {
    return;
  }

  let p = partition(arr, left, right);
  quickSort(arr, left, p-1);
  quickSort(arr, p+1, right);
}

function partition(arr, left, right) {
  
}