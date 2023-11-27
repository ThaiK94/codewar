

function countPositivesSumNegatives(input) {
  // your code here
  let result=[];
  let count =0;
  let sumOfNegative= 0;
  input.forEach(num => {
  if (num > 0)
  {
    count++;
  }
  else
    {
      sumOfNegative += num
    }
  
  })
  result.push(count)
  result.push(sumOfNegative)
  return result
}