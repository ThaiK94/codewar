
// Complete the solution so that it reverses the string passed into it.

// 'world'  =>  'dlrow'
// 'word'   =>  'drow'

function solution(str){
    let newString =''
    for (let i = str.length; i >= 0 ; i--)
      {
        newString += str.charAt(i)
      }
    return newString
  }

solution (ello)